
package firmament.component.entity;

import firmament.component.base.FEntityComponent;
import firmament.core.FConfig;
import firmament.core.FEntity;
import firmament.core.FEntityFactory;
import firmament.core.FEvent;
import firmament.core.FProperty;
import firmament.core.FVector;
import firmament.process.timer.FTimer;
import firmament.event.FPhysicsCollisionEvent;
import firmament.util.loader.FDataLoader;
import firmament.util.FLog;
import firmament.core.FEntityCollection;
/*
    Class: FEventMapperComponent
    maps events on the entity of a type to another event of a different type.
*/
class FMovementComponent extends FLinearTweenComponent {
    
    private var _ent:FEntity;
    private var _props:Map<String,FProperty>;
    private var _target:Map<String,FProperty>;
    private var _direction:Map<String,Dynamic>;
    private var _triggers:FConfig;

    private var _paused:Bool;
    private var _hasError:Bool;

    public function new(gameInstance:firmament.core.FGame){
        super(gameInstance);
        _props = new Map();
        _target = new Map();
        _direction = new Map();
        useStep(true);
    }

    override private function setup(config:FConfig) {
        // waits for body to be created
        on( _entity , "componentsInited", this, configure );
    }

    private function configure(e:FEvent) {
        var entConf:FConfig = FDataLoader.loadData( _config.getNotNull('entity',Dynamic) );
        var entColl:FEntityCollection = _entity.getGameInstance().queryEntities( {filters:{type:{typeId: entConf.getNotNull("typeId",String) } } } );
        for( ent in entColl ) {
            _ent = ent;
            break;
        }

        if(_ent == null ) {
            return;
        }

        _paused = _config.get("paused",Bool,false);

        var properties:FConfig = Reflect.field(_config,"properties");
        for( prop in properties.fields() ) {
            var propMapping = properties.get(prop);
            _props.set(prop, _entity.getProperty(propMapping) );
            _target.set(prop, _ent.getProperty(prop) );
        }

        on(_entity, "endContactCollision", handleEndContact );

        if( _config.hasField('listeners') ) {
            var listeners:FConfig = _config.get('listeners',Dynamic);
            for( type in listeners.fields() ) {
                var callback:Dynamic = null;
                switch( type ) {
                    case "pause": callback = handlePauseEvent;
                    case "unpause" : callback = handleUnpauseEvent;
                    case "reverse" : callback = handleReverseEvent;
                    case "limit" : break; // trigger only
                }
                if( callback != null ) {
                   _entity.on(_entity, listeners.get(type), this, callback);
                }
            }
        }
        _triggers = _config.get('triggers',Dynamic,null);

        updateDirection();
    }

    private function handlePauseEvent(e:FEvent) {
        if( _paused == false ) {
            _paused = true;
            log("Pausing!");
            if(_triggers.hasField('pause')) {
                _entity.trigger(new FEvent(_triggers.get('pause',String)));
            }
        }
    }

    private function handleUnpauseEvent(e:FEvent) {
        if( _paused == true ) {
            _paused = false;
            log("Unpausing, caculating direction");
            updateDirection();
            if(_triggers.hasField('unpause')) {
                _entity.trigger(new FEvent(_triggers.get('unpause',String)));
            }
        }
    }

    private function handleReverseEvent(e:FEvent) {
        if(_triggers.hasField('reverse')) {
            _entity.trigger(new FEvent(_triggers.get('reverse',String)));
        }

        for( key in _direction.keys() ) {
            // Reverse the direction
            switch(_props.get(key).type){
                case Float,Int: {
                    _direction.set(key,0-_direction.get(key));
                }
                case FVector: {
                    var dir:FVector = _direction.get(key);
                    dir.x = 0-dir.x;
                    dir.y = 0-dir.y;
                    _direction.set(key,dir);
                }
            }
        }
    }

    private function handleEndContact(e:FPhysicsCollisionEvent) {
        var othEnt = e.getOtherEntity(_entity);
        if( _ent != null && othEnt.getTypeId() == _ent.getTypeId()) {
            if( _paused == true ) {
                log("Limit reached, but component is paused");
                return;
            }
            updateDirection();
            if(_triggers.hasField('limit')) {
                log("Limit reached");
                _entity.trigger(new FEvent(_triggers.get('limit',String)));
            }
        }
    }

    private function updateDirection() {
        for( key in _props.keys() ) {
            var cur:FProperty = _props.get(key);
            var dst:FProperty = _target.get(key);

            // Update the items direction
            switch(cur.type){
                case Float,Int: {
                    _direction.set(key,
                        (dst.getFloat() - 
                            cur.getFloat()) > 0?1:-1);
                }
                case FVector: {
                    var dir:FVector = new FVector();
                    var currentVal:FVector = cur.getDynamic();
                    var targetVal:FVector = dst.getDynamic();
                    dir.x = (targetVal.x - currentVal.x > 0)?1:-1;
                    dir.y = (targetVal.y - currentVal.y > 0)?1:-1;
                    _direction.set(key,dir);
                }
            }
        }
    }

    override public function step( delta:Float ){
        if( _paused ){
            return;
        }
        if( _ent == null ) {
            configure(null);
        }
        for( item in _props.keys() ) {
            var key:String = item;
            var cur:FProperty = _props.get(key);
            var dst:FProperty = _target.get(key);
            var targetVal:Dynamic = null;
            var calcSpeed:Float = _config.get("speed",dst.type) * delta;

            // Move in Direction of target
            switch(cur.type){
                case Float,Int: {
                    targetVal = cur.getFloat();
                    targetVal += (calcSpeed * _direction.get(key));
                }
                case FVector: {
                    var currentVal:FVector = cur.getDynamic();
                    var targetVal:FVector = dst.getDynamic();
                    var direction:FVector = _direction.get(key);
                    targetVal.x += (calcSpeed * direction.x);
                    targetVal.y += (calcSpeed * direction.y);
                }
            }
            cur.set( targetVal );
        }
    }

    override public function getType(){
        return "movementComponent";
    }
}
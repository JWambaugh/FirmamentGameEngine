
package firmament.component.event;

import firmament.component.base.FEntityComponent;
import firmament.core.FConfig;
import firmament.core.FEntity;
import firmament.core.FEvent;
import firmament.util.FLog;
import firmament.util.FRepository;
import tjson.TJSON;
/*
    Class: FEventMapperComponent
    maps events on the entity of a type to another event of a different type.
*/
class FSetRepositoryComponent extends FEntityComponent{
    
    var repository:FConfig;
    var eventTrigger:String;

    public function new(gameInstance:firmament.core.FGame){
        super(gameInstance);
    }

    private function listenEventFunc(E:FEvent=null){
    
        // walk through the properties
        var store = FRepository.getInstance();
        // var fields:Array<String> = Reflect.fields();
        for( key in repository.fields() ) {
            try {
                var value:Dynamic = repository.get(key);
                if( Reflect.hasField(value,'*property*') ) {
                    value = _entity.getProp( Reflect.field(value,'*property*') );
                    log( "Property value - " + value );
                }
                store.set( key, value );
                log( "Set repository <"+key+"> " + store.get( key ) );
            } catch (e : Dynamic) {
                FLog.error( e );
                throw e;
            }
        }

        // trigger event
        try {
            _entity.trigger(
                new FEvent(this._config.getNotNull('trigger',String)));
        } catch(e:Dynamic) {}
    }

    override public function init(config:FConfig){
        repository = config.getNotNull('repository');

        var eventListen:String = config.getNotNull('listen',String);
        if( eventListen != null ) { // not optional
            _entity.on(eventListen,this,listenEventFunc);
        }
    }

    override public function getType(){
        return "setrepository";
    }

}
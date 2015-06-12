
package firmament.component.event;

import firmament.component.base.FEntityComponent;
import firmament.core.FConfig;
import firmament.core.FEntity;
import firmament.core.FEvent;
import firmament.process.timer.FTimer;
import firmament.util.FLog;
/*
    Class: FEventMapperComponent
    maps events on the entity of a type to another event of a different type.
*/
class FSetPropertiesComponent extends FEntityComponent{
    
    var eventTrigger:String;

    public function new(gameInstance:firmament.core.FGame){
        super(gameInstance);
    }

    private function listenEventFunc(E:FEvent=null){
        // walk through the properties
        var fields:Array<Dynamic> = FConfig.filterFields(
                                            Reflect.fields(
                                                _config.get('properties')
                                            )
                                    );
        for( key in fields ) {
            try {
                var eprop = _entity.getProperty(key);
                _entity.setPropertyValue( 
                        key, _config.getNotNull(['properties',key], eprop.type) );
                log( "Set property <"+key+"> " + _entity.getPropertyValue(key) );
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
        config.getNotNull('properties'); // evaluation for error purposes

        var eventListen:String = config.getNotNull('listen',String);
        _entity.on(eventListen,this,listenEventFunc);
    }

    override public function getType(){
        return "setproperties";
    }

}
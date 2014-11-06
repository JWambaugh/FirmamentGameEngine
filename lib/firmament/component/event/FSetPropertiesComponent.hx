
package firmament.component.event;

import firmament.component.base.FEntityComponent;
import firmament.core.FConfig;
import firmament.core.FEntity;
import firmament.core.FEvent;
import firmament.util.FLog;
import firmament.process.timer.FTimer;
/*
    Class: FEventMapperComponent
    maps events on the entity of a type to another event of a different type.
*/
class FSetPropertiesComponent extends FEntityComponent{
    
    var properties:FConfig;
    var eventTrigger:String;

    public function new(){
        super();
    }

    private function listenEventFunc(E:FEvent=null){
    
        // walk through the properties
        var fields:Array<String> = Reflect.fields(properties);
        for( key in fields ) {
            var value:Dynamic = null;
            switch(key){
                case "positionY":
                    value = properties.get(key,Int);
                case "speed":
                    value = properties.get(key,Float);
                default:
                    value = properties.get(key);
            }
            try {
                _entity.setPropertyValue( key, value );
            } catch(e : Dynamic) {
                FLog.error( haxe.Json.stringify(e) );
            }
        }

        // trigger event
        try {
            _entity.trigger(
                new FEvent(this._config.getNotNull('trigger',String)));
        } catch(e:Dynamic) {
            FLog.error( e );
        }
    }

    override public function init(config:FConfig){
        properties = config.getNotNull('properties');

        var eventListen:String = config.getNotNull('listen',String);
        if( eventListen != null ) { // not optional
            _entity.on(eventListen,this,listenEventFunc);
        }
    }

    override public function getType(){
        return "setproperties";
    }

}

package firmament.component.event;

import firmament.component.base.FEntityComponent;
import firmament.core.FConfig;
import firmament.core.FEntity;
import firmament.core.FEvent;
import firmament.process.timer.FTimer;
import firmament.scene.FScene;
import firmament.util.FLog;
/*
    Class: FEventMapperComponent
    maps events on the entity of a type to another event of a different type.
*/
class FSetScenePropertiesComponent extends FEntityComponent{
    
    var _properties:FConfig;
    var eventTrigger:String;

    public function new(gameInstance:firmament.core.FGame){
        super(gameInstance);
    }

    private function listenEventFunc(E:FEvent=null){
        // walk through the properties
        var fields:Array<String> = Reflect.fields(_properties);
        var scene:FScene = _entity.getGameInstance().getCurrentScene();
        for( key in fields ) {
            try {
                var eprop = scene.getProperty(key);
                var value = _properties.getNotNull(key, eprop.type );
                scene.setPropertyValue( key, value );
                log( "Set scene property <"+key+"> " + scene.getPropertyValue(key) );
            } catch (e : Dynamic) {
                FLog.error( e );
            }
        }

        // trigger event
        try {
            _entity.trigger(
                new FEvent(this._config.getNotNull('trigger',String)));
        } catch(e:Dynamic) {}
    }

    override public function init(config:FConfig){
        _properties = config.getNotNull('properties');

        var eventListen:String = config.getNotNull('listen',String);
        if( eventListen != null ) { // not optional
            on(_entity,eventListen,this,listenEventFunc);
        }
    }

    override public function getType(){
        return "setSceneProperties";
    }

}
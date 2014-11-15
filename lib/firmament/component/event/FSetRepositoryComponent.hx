
package firmament.component.event;

import firmament.component.base.FEntityComponent;
import firmament.core.FConfig;
import firmament.core.FEntity;
import firmament.core.FEvent;
import firmament.util.FLog;
import firmament.util.FRepository;
/*
    Class: FEventMapperComponent
    maps events on the entity of a type to another event of a different type.
*/
class FSetRepositoryComponent extends FEntityComponent{
    
    var repository:FConfig;
    var eventTrigger:String;

    public function new(){
        super();
    }

    private function listenEventFunc(E:FEvent=null){
    
        // walk through the properties
        var repoInstance = FRepository.getInstance();
        var fields:Array<String> = Reflect.fields(repository);
        FLog.msg( "Keys <"+fields+"> ");
        for( key in fields ) {
            try {
                FLog.msg( "Key <"+key+"> ");
                var value = repository[key];
                FLog.msg( "Value <"+value+"> ");
                FLog.msg( "Instance <"+repoInstance+"> ");
                repoInstance.set( key, value );
                FLog.msg( "Set repository <"+key+"> " + repoInstance.get( key ) );
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

package firmament.scene.component;

import firmament.core.FConfig;
import firmament.core.FEvent;
import firmament.scene.FSceneComponent;
import firmament.util.FLog;
import firmament.util.FStatistics;

class FSceneSetStatisticsComponent extends FSceneComponent {

	private var _statistics:FStatistics;

	public function new(gameInstance:Dynamic) 
	{
		super(gameInstance);
		_statistics = FStatistics.getInstance();
	}

    private function listenEventFunc(E:FEvent=null){
        // walk through the properties
        var fields:Array<Dynamic> = _config.fields('properties');
        for( key in fields ) {
            try {
                var eprop = _statistics.getProperty(key);
                _statistics.setPropertyValue( 
                        key, _config.getNotNull(['properties',key], eprop.type) );
                log( "Set stat <"+key+"> " + _statistics.getPropertyValue(key) );
            } catch (e : Dynamic) {
                FLog.error( e );
                throw e;
            }
        }

        // trigger event
        try {
            _scene.trigger(
                new FEvent(_config.getNotNull('trigger',String)));
        } catch(e:Dynamic) {}
    }

	override public function init(config:FConfig):Void {
		config.getNotNull('properties'); // evaluation for error purposes

		var eventListen:String = config.getNotNull('listen',String);
        _scene.on(eventListen,this,listenEventFunc);
	}

	override public function destruct(){
        super.destruct();
	}
}
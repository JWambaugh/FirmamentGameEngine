
package firmament.component.entity;

import firmament.component.base.FEntityComponent;
import firmament.core.FConfig;
import firmament.core.FEntity;
import firmament.core.FEvent;
import firmament.core.FGame;
import firmament.core.FProperty;
import firmament.core.FVector;

class FFollowEntityComponent extends FEntityComponent  {
	
	var _target:FEntity = null;
	var _paused:Bool = false;
	var _triggers:FConfig = null;
	var _prevDelta:Map<String,Dynamic>;

	public function new(){
		super();
		_prevDelta = new Map();
	}

	/*
	{
		"componentName" : "followEntity"
		,"entity": "bunny"
		,"paused": false // start paused
		,"behavior" : {
			"type" : "elastic"
			,"speed" : {"min":0.0,"max":10.0}
		    ,"acceleration" : {"min":0.0,"max":10.0}
		    ,"angle" : {"min" : 0.0, "max" : 0.0 }
		    // ,"offset" : {"x":0,"y":0} // how do i work this in?
		}
		,"properties" : [
			"position"
			,"angle"
		]
		,"listeners" : {
			"pause" : "beginCollide",
			"start": "followEntity"
		}
		,"triggers" : {
			"pause" : "beginCollide",
			"start": "followEntity"
			"reached": "matchedTarget"
		}
	}
	*/

	public function pause(event:FEvent) {
		_paused = true;
		if( _triggers != null ) {
			try {
				_entity.trigger( new FEvent(_triggers.getNotNull("pause")) );
			} catch (e:Dynamic) {}
		}
	}

	public function start(event:FEvent) { 
		_paused = false;
		if( _triggers != null ) {
			try {
				_entity.trigger( new FEvent(_triggers.getNotNull("start")) );
			} catch (e:Dynamic) {}
		}
	}

	override public function init(config:FConfig){
		super.init(null);

		// this is the first avail time we can call this
		useStep(true);
		_paused = _config.get("paused",Bool,false);
		var listeners:FConfig = _config.get("listeners",Dynamic,{});
		for( action in listeners.fields() ) {
			switch(action) {
				case "start":
					on( _entity, listeners.get(action,String),null,start);
				case "pause":
					on( _entity, listeners.get(action,String),null,pause);
			}
		}

		_triggers = _config.get("triggers",Dynamic);
	}

	private function entityQuery() :FEntity {
		// --- validate earlier
		var entName:String = _config.getNotNull("entity",String);
		var query = {"selector" : "all","filters" : {"type" : {"typeId": entName } } };
		// --- validate earlier
		var game:FGame = _entity.getGameInstance();
		var collection:firmament.core.FEntityCollection = game.queryEntities(query);
		if( collection.length > 1) {
			throw "Entity <"+entName+"> found "+collection.length+" matches, when only expecting 1";
		} else if (collection.length < 1 ) {
			throw "Entity <"+entName+"> not found";
		}
		return collection[0];
	}

	private function delegatorSnap(delta:Float,prop:FProperty,behavior:FConfig):Bool {
		var property:String = prop.getKey();
		var _targetValue:Dynamic = _target.getProp(property);
		_entity.setProp(property,_targetValue);
		return false;
	}

	private function delegatorElastic(delta:Float,prop:FProperty,behavior:FConfig):Bool {
		var speedRange:FConfig = behavior.get("speed",Dynamic,{});
		var speed = { "min" : delta * speedRange.get("min",Float,0), 
					  "max" : delta * speedRange.get("max",Float,0) };
		var property:String = prop.getKey();
		switch(prop.type) {
			case  FVector: {
				var _targetPos:FVector = _target.getProp(property);
				var _selfPos:FVector = _entity.getProp(property);
				var distance:FVector = _targetPos.copy();
				var previous = ( ! _prevDelta.exists(property) ) 
									? {"x":0.0,"y":0.0}
									: _prevDelta.get(property);
				distance.subtract(_selfPos);
/*if( !(distance.x == 0 && distance.y == 0) ) {
	trace("Span - ("+ delta +") " + distance );
}*/
				// floaty version of done
				if ( distance.lengthSquared() < 0.00001 ) {
					return true;
				}

				if( (speed.max > 0) && (distance.lengthSquared() > (speed.max * speed.max) ) ) {
					distance = distance.makeUnit();
					distance.multiply(speed.max);
				}
				// side effect, distance can be modified
				if( (speed.min > 0) && (distance.lengthSquared() < (speed.min * speed.min) ) ) {
					distance = distance.makeUnit();
					distance.multiply(speed.min);
				}
				_prevDelta.set(property,distance);
/*if( !(distance.x == 0 && distance.y == 0) ) {
	trace("Increment - ("+ delta +")" + distance );
}*/
				_selfPos.add( distance );
				_entity.setProp(property,_selfPos);
			}
			case Float,Int: {
				var _targetPos:Float = _target.getProp(property);
				var _selfPos:Float = _entity.getProp(property);
				var distance:Float = _targetPos - _selfPos;
				var previous = ( ! _prevDelta.exists(property) ) 
									? 0.0
									: _prevDelta.get(property);
				// floaty version of done
				if ( distance < 0.00001 ) {
					return true;
				}

				if( distance * delta > speed.max ) {
					distance = speed.max;
				}
				// side effect, distance can be modified
				if( distance * delta < speed.min ) {
					distance = speed.min;
				}
				_prevDelta.set(property,distance);
				_entity.setProp(property,_selfPos + distance);
			}
		}
		return false;
	}

	private var tweenDelegator:Float->FProperty->FConfig->Bool;

	override public function step(delta:Float) {
		// Do nothing if I'm paused
		if( _paused ) {return;}
		try {
			if( _target == null ) {
				_target = entityQuery();
			}
			// check to see if my entity exists

			var properties:FConfig = _config.getNotNull("properties");
			var reached:Bool = true;
			for( property in properties.fields() ) {
				var behavior:FConfig = properties.get(property,Dynamic,{});
				if(behavior.get("type",String) == "elastic") {
					reached = delegatorElastic(delta,_target.getProperty(property),behavior) && reached;
				} else {
					reached = delegatorSnap(delta,_target.getProperty(property),behavior) && reached;
				}
			}

			if( reached == true ) {
				if( _triggers != null ) {
					try {
						_entity.trigger( new FEvent(_triggers.getNotNull("reached")) );
					} catch (e:Dynamic) {}
				}
			}
		} catch(e:Dynamic) {
			trace( e );
		}
	}

	override public function getType(){
		return "followEntity";
	}	
}
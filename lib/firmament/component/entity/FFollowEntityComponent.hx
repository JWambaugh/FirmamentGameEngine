package firmament.component.entity;

import firmament.component.base.FEntityComponent;
import firmament.core.FConfig;
import firmament.core.FEntity;
import firmament.core.FEvent;
import firmament.core.FGame;
import firmament.core.FProperty;
import firmament.core.FVector;
import firmament.core.FCamera;

class FFollowEntityComponent extends FEntityComponent {
	
	var _target:FEntity = null;
	var _paused:Bool = false;
	var _triggers:FConfig = null;
	var _prevDelta:Map<String,Dynamic>;
	var _zeroVector:FVector;
	var _reached:Bool = false; // prohibits sending of the reached trigger without changing states

	public function new(gameInstance:firmament.core.FGame){
		super(gameInstance);
		_prevDelta = new Map();
		_zeroVector = new FVector(0,0);
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
		if( _paused == false ) {
			_paused = true;
			if( _triggers != null ) {
				try {
					_entity.trigger( new FEvent(_triggers.getNotNull("pause")) );
				} catch (e:Dynamic) {}
			}
		}
	}

	public function start(event:FEvent) { 
		if( _paused == true ) {
			_paused = false;
			if( _triggers != null ) {
				try {
					_entity.trigger( new FEvent(_triggers.getNotNull("start")) );
				} catch (e:Dynamic) {}
			}
		}
	}

	override public function init(config:FConfig){
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
		var offset = behavior.get("offset",prop.type,null);
		if( offset != null ) {
			switch(prop.type) {
				case FVector: {
					var finalPosition:FVector = _targetValue.copy();
					finalPosition.add( offset );
					_targetValue = finalPosition;
				}
				case Int,Float: {
					_targetValue += offset;
				}
			}
		}
		_entity.setProp(property,_targetValue);
		return true;
	}

	private function delegatorTrack(delta:Float,prop:FProperty,behavior:FConfig):Bool {
		var tolerence:Float = behavior.get("tolerence",Float,0.00001);
		var angleRange:FConfig = behavior.get("angle",Dynamic,{});
		var speedRange:FConfig = behavior.get("speed",Dynamic,{});
		var offset = behavior.get("offset",prop.type,null);
		var speed = { "min" : delta * speedRange.get("min",Float,0), 
					  "max" : delta * speedRange.get("max",Float,0) };
		var angle = { "min" : angleRange.get("min",Float,0) / 180.0 * Math.PI
					 ,"max" : angleRange.get("max",Float,0) / 180.0 * Math.PI};

		var property:String = prop.getKey();
		switch(prop.type) {
			case  FVector: {
				var _targetPos:FVector = _target.getProp(property);
				var _selfPos:FVector = _entity.getProp(property);
				var distance:FVector = _targetPos.copy();
				var previous:FVector = ( ! _prevDelta.exists(property) ) 
									? _zeroVector.copy()
									: _prevDelta.get(property);

				distance.subtract(_selfPos);

				// floaty version of done
				if ( distance.lengthSquared() < tolerence ) {
					return true;
				}

				if( angle.min != 0 || angle.max != 0 ) {
					var angleTo:Float = distance.angleBetween( _selfPos );
					if (angleTo < 0) {angleTo += 2 * Math.PI;}
					var ang:Null<Float> = null;
					if( angle.max > 0 && ( Math.abs(angleTo) > angle.max ) ) {
						ang = angle.max;
					}
					if( angle.min > 0 && ( Math.abs(angleTo) < angle.min ) ) {
						ang = angle.min;
					}
					if( ang != null ) {
						var temp:FVector = distance.copy();
						// flip these to go backwards from the dest
						var s:Float = -Math.cos(ang);
						var c:Float = Math.sin(ang);
						distance.x = (temp.x * c - temp.y * s);
						distance.y = (temp.x * s + temp.y * c);
					}
				}

				if( (speed.max != 0) || (speed.min != 0) ) {
					var spd:Null<Float> = null;
					if( (speed.max > 0) && (distance.lengthSquared() > (speed.max * speed.max) ) ) {
						spd = speed.max;
					}
					// side effect, distance can be modified
					if( (speed.min > 0) && (distance.lengthSquared() < (speed.min * speed.min) ) ) {
						spd = speed.min;
					}
					if( spd != null ) {
						distance = distance.makeUnit();
						distance.multiply(spd);
					}
				}

				_prevDelta.set(property,distance);
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
				if ( distance < tolerence ) {
					return true;
				}

				// how would angle work here?

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
		if( _paused ) { 
			return; 
		}
		try {
			if( _target == null ) {
				_target = entityQuery();
			}
			// check to see if my entity exists

			var properties:FConfig = _config.getNotNull("properties");
			var reached:Bool = true;
			for( property in properties.fields() ) {
				var behavior:FConfig = properties.get(property,Dynamic,{});
				var atPosition:Bool = false;
				switch( behavior.get("type",String) ){
					case "track":
						atPosition = delegatorTrack(delta,_target.getProperty(property),behavior);
					default:
						atPosition = delegatorSnap(delta,_target.getProperty(property),behavior);
				}
				reached = reached && atPosition;
			}

			if( reached == true && _reached != reached ) {
				if( _triggers != null ) {
					try {
						_entity.trigger( new FEvent(_triggers.getNotNull("reached")) );
					} catch (e:Dynamic) {}
				}
			}
			_reached = reached;
		} catch(e:Dynamic) {
			trace( e );
		}
	}

	override public function getType(){
		return "followEntity";
	}	
}
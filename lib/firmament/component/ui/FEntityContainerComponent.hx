
package firmament.component.ui;

import firmament.component.base.FEntityComponent;
import firmament.core.FVector;
import firmament.core.FEntity;
import firmament.core.FGame;
import firmament.util.loader.FDataLoader;
import firmament.core.FEntityFactory;
import firmament.core.FEvent;




/**
 * A component that is a container for other entities.
 * When this entity moves, all entities it contains also move the same.
 */
class FEntityContainerComponent extends FEntityComponent  {
	var _position:FVector;
	var _entities:Array<FEntity>;
	var _game:FGame;
	public function new(){
		super();
		_entities = new Array();
		
	}

	override public function init(config:Dynamic){
		on(_entity,FEntity.COMPONENTS_INITIALIZED,function(e:FEvent){
			_position = _entity.getPhysicsComponent().getPosition().copy();
		});
		_game = _entity.getGameInstance();
		on(_game,FGame.AFTER_STEP,afterStep);
		if(Std.is(config.entities,Array)){
			for (ent in cast(config.entities,Array<Dynamic>)){
				if(Std.is(ent,String)){
					ent = FDataLoader.loadData(ent);
				}
				//trace(Std.string(ent));
				var childEntity = FEntityFactory.createEntity(ent,_entity.getGameInstance().getInstanceName());
				this.addEntity(childEntity);
			}
		}
	}

	private function afterStep(e:FEvent){
		var diff:FVector = _entity.getPhysicsComponent().getPosition().copy();
		diff.subtract(_position);
		for(entity in _entities){
			var pc = entity.getPhysicsComponent();
			var pos = pc.getPosition();
			pc.setPosition(new FVector(pos.x+diff.x,pos.y+diff.y));
		}
	}

	override public function getType(){
		return "entityContainer";
	}	

	public function addEntity(entity:FEntity){
		_entities.push(entity);
	}
}
package firmament.component.entity;


import firmament.component.base.FEntityComponent;
import firmament.component.physics.FBox2DComponent;
import firmament.core.FEntity;
import firmament.core.FEntityFactory;
import firmament.core.FEvent;
import firmament.core.FGame;
import firmament.core.FPropertyDefinition;
import firmament.core.FVector;
import firmament.event.FPhysicsCollisionEvent;
import firmament.util.FEntityUtils;
import firmament.util.FMisc;
import firmament.util.loader.FDataLoader;


class FChildComponent extends FEntityComponent{
    private var _childEntity:FEntity;
    public function new(gameInstance:firmament.core.FGame){
        super(gameInstance);
        _childEntity = null;
    }



    override public function init(config:firmament.core.FConfig){
        var entConfig:Dynamic = null ;
        var childString:String = config.get("entity",String);

        if(childString != null){
            //assume string is file name
            log("Child entity - " + childString);
            entConfig = FDataLoader.loadData(childString);
        }

        if(entConfig == null)
           entConfig = config.getNotNull('entity');

        var childPhysicsComponent = {
             "componentName":"childPhysics"
             ,"parent":_entity
        };

        if(Std.is(entConfig.components,Array)){
            cast(entConfig.components, Array<Dynamic>).push(childPhysicsComponent);
        }else{
            Reflect.setField(entConfig.components,"childPhysics",childPhysicsComponent);
        }

        _childEntity = FEntityFactory.createEntity(entConfig);
    }

    override public function onActivate(){
        _childEntity.setActive(true);
    }

    override public function onDeactivate(){
        _childEntity.setActive(false);
    }

     override public function getProperties():Array<FPropertyDefinition>{
        var props:Array<FPropertyDefinition> = [
            {
                key:'children'
                ,type:Array
                ,getter:getChild
                ,setter:setChild
                ,sortOrder:1
            }
        ];
        return props;
    }

    public function getChild(children:Array<FEntity>):Array<FEntity>{
        if(children == null)children = new Array();
        children.push(_childEntity);
        return children;
    }

    public function setChild(child:Array<FEntity>){
        //setter does nothing
    }

    override public function getType(){
        return "child";
    }

    override public function destruct(){
        _entity.getGameInstance().doAfterStep(_childEntity.destruct);
        super.destruct();
    }

}
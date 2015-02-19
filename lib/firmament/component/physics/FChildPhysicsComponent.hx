package firmament.component.physics;



import firmament.component.base.FEntityComponent;
import firmament.component.physics.FPhysicsComponentInterface;
import firmament.core.FComputedProperty;
import firmament.core.FConfig;
import firmament.core.FEntity;
import firmament.core.FEvent;
import firmament.core.FGame;
import firmament.core.FPolygonShape;
import firmament.core.FProperty;
import firmament.core.FPropertyDefinition;
import firmament.core.FPropertyInterface;
import firmament.core.FShape;
import firmament.core.FVector;
import firmament.core.FWorldPositionalInterface;
import firmament.world.FBox2DWorld;
import firmament.world.FNoPhysicsWorld;
import firmament.world.FWorld;
import haxe.Timer;

/**
 * 
 * @author Jordan Wambaugh
 */

class FChildPhysicsComponent extends FNoPhysicsComponent implements FPhysicsComponentInterface
{
    
    
    private var _parentEntity:FEntity;

    private var _relativePosition:FVector;


    private var _relativeAngle:Float;

    private var _relativeAngularVelocity:Float;


    public function new(gameInstance:firmament.core.FGame) 
    {
        super(gameInstance);
    }

    public function setParentEntity(parent:FEntity){
        _parentEntity = parent;
    }
    
    override public function init(config:FConfig):Void {
        _world = cast(_entity.getGameInstance().getWorld("noPhysics"),FNoPhysicsWorld);
        registerEventHandlers();

        _parentEntity = config.get("parent", FEntity, _parentEntity);
        
        
        _position = config.getVector('position',_position);
        _width = config.getNotNull('width',Float,1.0);
        _height = config.getNotNull('height',Float,1.0);
        _linearVelocity = config.getVector('linearVelocity',_linearVelocity);
        _angularVelocity = config.get('angularVelocity',Float,_angularVelocity);
        _angle = config.get('angle');
        _fixedRotation = config.get('fixedRotation',Bool,_fixedRotation);
        _allowSleep = config.get('allowSleep',Bool,true);
        _positionZ = config.get('positionZ',Float,_positionZ);


        if (config.hasField('maxLifeSeconds')) {
            Timer.delay(function() { this._entity.delete(); }, Math.floor(config.get('maxLifeSeconds',Float) * 1000));
        }
        
        
        if(config.get('alwaysRender',Bool,false) ){
            _world.addToAlwaysRenderList(_entity);
        }
        _world.addEntity(this._entity);
        
        buildShape();
    }


    override public function getProperties():Array<FPropertyDefinition>{
        var props:Array<FPropertyDefinition> = [
            {
                key:'position'
                ,type:FVector
                ,getter:getPosition
                ,setter:setPosition
                ,sortOrder:1
            }
            ,{
                key:"positionX"
                ,type:Float
                ,getter:getPositionX
                ,setter:setPositionX
                ,sortOrder:1
            }
            ,{
                key:"positionY"
                ,type:Float
                ,getter:getPositionY
                ,setter:setPositionY
                ,sortOrder:1
            }
            ,{
                key:"positionZ"
                ,type:Float
                ,getter:getPositionZ
                ,setter:setPositionZ
                ,sortOrder:1
            }
            ,{
                key:"angle"
                ,type:Float
                ,getter:getAngle
                ,setter:setAngle
                ,sortOrder:1
            }
            ,{
                key:"angularVelocity"
                ,type:Float
                ,getter:getAngularVelocity
                ,setter:setAngularVelocity
                ,sortOrder:1
            }
            ,{
                key:"linearVelocity"
                ,type:FVector
                ,getter:getLinearVelocity
                ,setter:setLinearVelocity
                ,sortOrder:1
            }
            ,{
                key:"relativePosition"
                ,type:FVector
                ,getter:getRelativePosition
                ,setter:setRelativePosition
                ,sortOrder:1
            }
            ,{
                key:"relativeAngle"
                ,type:Float
                ,getter:getRelativeAngle
                ,setter:setRelativeAngle
                ,sortOrder:1
            }
            ,{
                key:"relativeAngularVelocity"
                ,type:Float
                ,getter:getRelativeAngularVelocity
                ,setter:setRelativeAngularVelocity
                ,sortOrder:1
            }
           
        ];
        return props;
    }

    override public function  getPosition(p:FVector=null):FVector {
        return _parentEntity.getProp('position');
    }
    
    override public function setPosition(pos:FVector) {
        //does nothing since position is calculated from the parent.
        // if(_deleted)return;
        // var oldTopX = _position.x - _width/2;
        // var oldTopY = _position.y - _height/2;
        
        // _position=pos;
        // _world.updatePositionState(this,oldTopX,oldTopY);
    }

    override public function setPositionXY(x:Float,y:Float){
        //does nothing since position is calculated from the parent.

        // if(_deleted)return;
        // firmament.util.FLog.debug('setPositionXY called');

        // var oldTopX = _position.x - _width/2;
        // var oldTopY = _position.y - _height/2;
        
        // _position.x=x;
        // _position.y=y;
        // if(_world!=null)        
        //   _world.updatePositionState(this,oldTopX,oldTopY);
    }

    override public function setPositionX(x:Float){
        //does nothing since position is calculated from the parent.

       // setPositionXY(x, _position.y);
    }

    override public function setPositionY(y:Float){
        //does nothing since position is calculated from the parent.

        //setPositionXY(_position.x, y);
    }

    override public function getPositionX(p:Float=0):Float{
        return this.getPosition().x;
    }

    override public function getPositionY(p:Float=0):Float{
        return this.getPosition().y;
    }
    
    override public function setAngle(a:Float):Void {
         //does nothing since angle is calculated from the parent.
        //_angle = a;
    }
    
    override public function getAngle(p:Float=0):Float {
        return _parentEntity.getProp('angle');
    }
    
    override public function applyLinearForce(v:FVector,?point:FVector=null):Void {
        _isSleeping = false;
        _world.updateSleepState(this);
        //_linearVelocity.add(v);
        // TODO (JCMW): Support second param
    }

    override public function setLinearVelocity(vel:FVector) {
        _isSleeping = false;
        _world.updateSleepState(this);
        //_linearVelocity = vel;
    }
    
    override public function getLinearVelocity(p:FVector=null):FVector {
        return _linearVelocity;
    }

    override public function setAngularVelocity(omega:Float):Void {
        _world.updateSleepState(this);
        //_angularVelocity = omega;
    }

    

    override public function getAngularVelocity(p:Float=0):Float {
        return _angularVelocity;
    }

    override public function addAngularVelocity(omega:Float) {
        _isSleeping=false;
    //    var ome = this.getAngularVelocity();
    //    this.setAngularVelocity(ome+omega); 
    }
    


    //gets called by the world when the world is updating their positions
    override public function onWorldStep(delta:Float){
        if(_angularVelocity!=0){
            setAngle(_angle + _angularVelocity * delta);
        }

        if(_linearVelocity.x!=0 || _linearVelocity.y!=0){
            setPositionXY(_position.x+_linearVelocity.x * delta, _position.y + _linearVelocity.y * delta);
        }
    }

    //getters and setters for relatives
    public function getRelativePosition(p:FVector=null):FVector {
        return _relativePosition;
    }

    public function setRelativePosition(pos:FVector):Void {
        _world.updateSleepState(this);
        _relativePosition = pos;
    }

    public function getRelativeAngle(p:Float=0):Float {
        return _relativeAngle;
    }

    public function setRelativeAngle(angle:Float):Void {
        _world.updateSleepState(this);
        _relativeAngle = angle;
    }


    public function getRelativeAngularVelocity(p:Float=0):Float {
        return _relativeAngularVelocity;
    }

    public function setRelativeAngularVelocity(omega:Float):Void {
        _world.updateSleepState(this);
        _relativeAngularVelocity = omega;
    }


    

}
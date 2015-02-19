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

class FNoPhysicsComponent extends FEntityComponent implements FPhysicsComponentInterface 
{
	
	
	private var _positionZ:Float;
	private var _position:FVector;
	private var _world:FNoPhysicsWorld;
	private var _angle:Float;
	private var _fixedRotation:Bool;
	private var _allowSleep:Bool;
	private var _isSleeping:Bool;
	private var _isActive:Bool;
	private var _angularVelocity:Float;
	private var _linearVelocity:FVector;
	private var _width:Float;
	private var _height:Float;
	private var _shape:FPolygonShape;
	private var _deleted:Bool;


	public function new(gameInstance:firmament.core.FGame) 
	{
		super(gameInstance);
		
		_position = new FVector(0,0);
		_isSleeping = false;
		_isActive = true;
		_linearVelocity = new FVector(0,0);
		_positionZ = 0;
		_deleted = false;
		_angle = 0;
        _width=0;
        _height=0;
        _world = null;
	}
	
	override public function init(config:FConfig):Void {
		_world = cast(_entity.getGameInstance().getWorld("noPhysics"),FNoPhysicsWorld);
		registerEventHandlers();
		
		
		_position = config.getVector('position',_position);
		_width = config.getNotNull('width',Float);
		_height = config.getNotNull('height',Float);
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
        ];
        return props;
    }

	private function buildShape(){
		_shape = new FPolygonShape([
			new FVector(-_width/2,-_height/2)
			,new FVector(-_width/2,_height/2)
			,new FVector(_width/2,_height/2)
			,new FVector(_width/2,-_height/2)
			]);
	}
		
	private function registerEventHandlers(){
		on(_entity,FEntity.ACTIVE_STATE_CHANGE, onActiveStateChange);
	}

	private function removeEventHandlers(){
		_entity.removeEventListener(this);
	}	
	
	public function onActiveStateChange(e:FEvent){
			deactivate();
	}

	function deactivate(?e:FEvent=null){
		this._isActive = _entity.isActive();
		_world.updateSleepState(this);
	}

	public function  getPosition(p:FVector=null) {
		return _position;
	}
	
	public function setPosition(pos:FVector) {
		if(_deleted)return;
		var oldTopX = _position.x - _width/2;
		var oldTopY = _position.y - _height/2;
		
		_position=pos;
		_world.updatePositionState(this,oldTopX,oldTopY);
	}

	public function setPositionXY(x:Float,y:Float){
		if(_deleted)return;
        firmament.util.FLog.debug('setPositionXY called');

		var oldTopX = _position.x - _width/2;
		var oldTopY = _position.y - _height/2;
		
		_position.x=x;
		_position.y=y;
        if(_world!=null)        
		  _world.updatePositionState(this,oldTopX,oldTopY);
	}

	public function setPositionX(x:Float){
		setPositionXY(x, _position.y);
	}
	public function setPositionY(y:Float){
        firmament.util.FLog.debug('setPositionY called');
		setPositionXY(_position.x, y);
	}

	public function getPositionX(p:Float=0):Float{
		return this.getPosition().x;
	}

	public function getPositionY(p:Float=0):Float{
		return this.getPosition().y;
	}
	
	public function setAngle(a:Float):Void {
		_angle = a;
	}
	
	public function getAngle(p:Float=0):Float {
		return _angle;
	}
	
	public function applyLinearForce(v:FVector,?point:FVector=null):Void {
		_isSleeping = false;
		_world.updateSleepState(this);
		_linearVelocity.add(v);
		// TODO (JCMW): Support second param
	}

	public function setLinearVelocity(vel:FVector) {
		_isSleeping = false;
		_world.updateSleepState(this);
		_linearVelocity = vel;
	}
	
	public function getLinearVelocity(p:FVector=null):FVector {
		return _linearVelocity;
	}

	public function setAngularVelocity(omega:Float):Void {
		_world.updateSleepState(this);
	    _angularVelocity = omega;
	}

	public function getAngularVelocity(p:Float=0):Float {
	    return _angularVelocity;
	}

	public function addAngularVelocity(omega:Float) {
		_isSleeping=false;
		var ome = this.getAngularVelocity();
	    this.setAngularVelocity(ome+omega);	
	}
	
	public function getPositionZ(p:Float=0):Float {
		return _positionZ;
	}

	public function setPositionZ(p:Float):Void {
		_positionZ = p;
	}

	public function setWorld(world:FWorld):Void{
		_world = cast(world);
	}

	public function getWorld(){
		return _world;
	}

	override public function getType():String {
		return "physics";
	}

	public function hasShapes():Bool{
		return false;
	}

	public function isSleeping(){
		return _isSleeping;
	}

	public function getWidth():Float{
		return _width;
	}

	public function getHeight():Float{
		return _height;
	}

	public function getTopX(){
		return _position.x - _width/2;
	}

	public function getTopY(){
		return _position.y - _height/2;
	}

	public function getBottomX(){
		return _position.x + _width/2;
	}

	public function getBottomY(){
		return _position.y + _height/2;
	}

	public function getShapes():Array<FShape>{
		return [_shape];
	}


    //gets called by the world when the world is updating their positions
    public function onWorldStep(delta:Float){
        if(_angularVelocity!=0){
            setAngle(_angle + _angularVelocity * delta);
        }

        if(_linearVelocity.x!=0 || _linearVelocity.y!=0){
            setPositionXY(_position.x+_linearVelocity.x * delta, _position.y + _linearVelocity.y * delta);
        }
    }

	override public function destruct(){
		_deleted = true;
		_world.deleteEntity(_entity);
		removeEventHandlers();
	}

}
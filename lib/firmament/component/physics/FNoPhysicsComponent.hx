package firmament.component.physics;


import firmament.component.base.FEntityComponent;
import firmament.component.physics.FPhysicsComponentInterface;
import firmament.core.FBox2DWorld;
import firmament.core.FEntity;
import firmament.core.FGame;
import firmament.core.FVector;
import firmament.core.FNoPhysicsWorld;
import firmament.core.FWorldPositionalInterface;
import haxe.Timer;
import nme.events.Event;

/**
 * Class: FBox2DComponent
 * @author Jordan Wambaugh
 */

class FNoPhysicsComponent extends FEntityComponent, implements FPhysicsComponentInterface, implements FWorldPositionalInterface 
{
	
	
	private var zPosition:Float;
	private var position:FVector;
	private var world:FNoPhysicsWorld;
	private var _angle:Float;
	private var _fixedRotation:Bool;
	private var _allowSleep:Bool;
	private var _isSleeping:Bool;
	private var _isActive:Bool;
	private var _angularVelocity:FVector;
	private var _linearVelocity:FVector;
	public function new() 
	{
		super();
		this.world = cast(FGame.getInstance().getWorld("noPhysics"),FNoPhysicsWorld);
		this.position = new FVector(0,0);
		_isSleeping = false;
		_isActive = true;
		_linearVelocity = new FVector(0,0);
		_angularVelocity = new FVector(0,0);
	}
	
	override public function init(config:Dynamic):Void {
		registerEventHandlers();
		
		
		if(Std.is(config.position,FVector)){
			this.position = config.position;
		}
		else if(Reflect.isObject(config.position)){
			this.position = new FVector(config.position.x,config.position.y);
		}
		else {
			this.position = new FVector(0, 0);
		}
		

		if(Std.is(config.linearVelocity,FVector)){
			this._linearVelocity = config.linearVelocity;
		}
		else if(Reflect.isObject(config.linearVelocity)){
			this._linearVelocity = new FVector(config.linearVelocity.x,config.linearVelocity.y);
		}
		else {
			this._linearVelocity = new FVector(0, 0);
		}


		if(Std.is(config.angularVelocity,FVector)){
			this._angularVelocity = config.angularVelocity;
		}
		else if(Reflect.isObject(config.angularVelocity)){
			this._angularVelocity = new FVector(config.angularVelocity.x,config.angularVelocity.y);
		}
		else {
			this._angularVelocity = new FVector(0, 0);
		}
		
	
		if(Std.is(config.angle,Float))
			_angle = config.angle;
		_fixedRotation = false;

		if(Std.is(config.fixedRotation,Bool)){
			_fixedRotation = config.fixedRotation;
		}

		if (Std.is(config.allowSleep, Bool)) {
			_allowSleep = config.allowSleep;
		}


		if (Std.is(config.maxLifeSeconds, Float)) {
			Timer.delay(function() { this._entity.delete(); }, Math.floor(config.maxLifeSeconds * 1000));
		}
		
		this.world.addEntity(this._entity);
	}
		
	private function registerEventHandlers(){
		_entity.addEventListener(FEntity.ACTIVE_STATE_CHANGE, onActiveStateChange);
	}
	
	public function onActiveStateChange(e:Event){
			deactivate();
	}

	function deactivate(?e:Event=null){
			this._isActive_ = _entity.isActive();
		}

	public function  getPosition() {
		return this.position;
	}
	
	public function setPosition(pos:FVector) {
		this.position=pos;
	}

	public function getPositionX():Float{
		return this.getPosition().x;
	}

	public function getPositionY():Float{
		return this.getPosition().y;
	}
	
	public function setAngle(a:Float):Void {
		_angle = a;
	}
	
	public function getAngle():Float {
		return _angle;
	}
	
	public function setLinearVelocity(vel:FVector) {
		_isSleeping = true;
		_linearVelocity = vel;
	}
	
	public function getLinearVelocity():FVector {
		return _linearVelocity;
	}

	public function addLinearVelocity(velocity:FVector){
		_isSleeping = true;
		vel.add(_linearVelocity);
	}

	public function setAngularVelocity(omega:Float):Void {
	    _angularVelocity = omega;
	}

	public function getAngularVelocity():Float {
	    return _angularVelocity
	}

	public function addAngularVelocity(omega:Float) {
		_isSleeping=false;
		var ome = this.getAngularVelocity();
	    this.setAngularVelocity(ome+omega);	
	}
	
	public function getZPosition():Float {
		return zPosition;
	}
	public function setZPosition(p:Float):Void {
		zPosition = p;
	}
	public function setWorld(world:FWorld):Void{
		this.world = world;
	}

	public function getWorld(){
		return this.world;
	}

	override public function getType():String {
		return "physics";
	}

	public function hasShapes():Bool{
		return true;
	}

	//TODO: Cache the response from this for speed
	public function getShapes():Array<B2Shape>{
		
		return null;
	}



}
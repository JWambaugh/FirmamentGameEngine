package firmament.component.physics;


import firmament.component.base.FEntityComponent;
import firmament.component.physics.FPhysicsComponentInterface;
import firmament.core.FEntity;
import firmament.core.FGame;
import firmament.core.FPolygonShape;
import firmament.core.FShape;
import firmament.core.FVector;
import firmament.core.FWorldPositionalInterface;
import firmament.world.FBox2DWorld;
import firmament.world.FNoPhysicsWorld;
import firmament.world.FWorld;
import haxe.Timer;
import nme.events.Event;


/**
 * FBox2DComponent
 * @author Jordan Wambaugh
 */

class FNoPhysicsComponent extends FEntityComponent, implements FPhysicsComponentInterface, implements FWorldPositionalInterface 
{
	
	
	private var _zPosition:Float;
	private var position:FVector;
	private var world:FNoPhysicsWorld;
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
	public function new() 
	{
		super();
		this.world = cast(FGame.getInstance().getWorld("noPhysics"),FNoPhysicsWorld);
		this.position = new FVector(0,0);
		_isSleeping = false;
		_isActive = true;
		_linearVelocity = new FVector(0,0);
		_zPosition = 0;
		_deleted = false;
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

		if(Std.is(config.width,Float)){
			_width = config.width;
		}else{
			throw "no width specified.";
		}
		
		if(Std.is(config.height,Float)){
			_height = config.height;
		}else{
			throw "no height specified.";
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


		if(Std.is(config.angularVelocity,Float)){
			this._angularVelocity =  config.angularVelocity;
		}
		else {
			this._angularVelocity = 0;
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

		if(Std.is(config.zPosition,Float)){
			_zPosition = config.zPosition;
		}

		if (Std.is(config.maxLifeSeconds, Float)) {
			Timer.delay(function() { this._entity.delete(); }, Math.floor(config.maxLifeSeconds * 1000));
		}
		
		
		if(Std.is(config.alwaysRender,Bool) && config.alwaysRender==true){
			this.world.addToAlwaysRenderList(_entity);
		}
		this.world.addEntity(this._entity);

		buildShape();
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
		_entity.addEventListener(FEntity.ACTIVE_STATE_CHANGE, onActiveStateChange);
	}

	private function removeEventHandlers(){
		_entity.removeEventListener(FEntity.ACTIVE_STATE_CHANGE, onActiveStateChange);
	}	
	
	public function onActiveStateChange(e:Event){
			deactivate();
	}

	function deactivate(?e:Event=null){
		this._isActive = _entity.isActive();
	}

	public function  getPosition() {
		return this.position;
	}
	
	public function setPosition(pos:FVector) {
		if(_deleted)return;
		var oldTopX = position.x - _width/2;
		var oldTopY = position.y - _height/2;
		
		this.position=pos;
		world.updatePositionState(this,oldTopX,oldTopY);
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
	
	public function applyLinearForce(v:FVector,?point:FVector=null):Void {
		_isSleeping = false;
		world.updateSleepState(this);
		_linearVelocity.add(v);
		// TODO (JCMW): Support second param
	}

	public function setLinearVelocity(vel:FVector) {
		_isSleeping = false;
		world.updateSleepState(this);
		_linearVelocity = vel;
	}
	
	public function getLinearVelocity():FVector {
		return _linearVelocity;
	}

	public function setAngularVelocity(omega:Float):Void {
		world.updateSleepState(this);
	    _angularVelocity = omega;
	}

	public function getAngularVelocity():Float {
	    return _angularVelocity;
	}

	public function addAngularVelocity(omega:Float) {
		_isSleeping=false;
		var ome = this.getAngularVelocity();
	    this.setAngularVelocity(ome+omega);	
	}
	
	public function getZPosition():Float {
		return _zPosition;
	}

	public function setZPosition(p:Float):Void {
		_zPosition = p;
	}

	public function setWorld(world:FWorld):Void{
		this.world = cast(world);
	}

	public function getWorld(){
		return this.world;
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
		return this.position.x - _width/2;
	}

	public function getTopY(){
		return this.position.y - _height/2;
	}

	public function getBottomX(){
		return this.position.x + _width/2;
	}

	public function getBottomY(){
		return this.position.y + _height/2;
	}
	public function getShapes():Array<FShape>{
		return [_shape];
	}
	override public function destruct(){
		_deleted = true;
		world.deleteEntity(_entity);
		removeEventHandlers();
	}

}
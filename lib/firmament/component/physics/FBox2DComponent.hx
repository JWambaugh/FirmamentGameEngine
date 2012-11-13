package firmament.component.physics;


import box2D.collision.shapes.B2CircleShape;
import box2D.collision.shapes.B2PolygonShape;
import box2D.collision.shapes.B2Shape;
import box2D.common.math.B2Vec2;
import box2D.dynamics.B2Body;
import box2D.dynamics.B2BodyDef;
import box2D.dynamics.B2Fixture;
import box2D.dynamics.B2FixtureDef;
import firmament.component.base.FEntityComponent;
import firmament.component.physics.FPhysicsComponentInterface;
import firmament.core.FBox2DWorld;
import firmament.core.FEntity;
import firmament.core.FGame;
import firmament.core.FVector;
import firmament.core.FWorld;
import firmament.core.FWorldPositionalInterface;
import haxe.Timer;
import nme.events.Event;

/**
 * Class: FBox2DComponent
 * @author Jordan Wambaugh
 */

class FBox2DComponent extends FEntityComponent, implements FPhysicsComponentInterface, implements FWorldPositionalInterface 
{
	
	public var body:B2Body;
	private var zPosition:Float;
	private var position:FVector;
	private var world:FWorld;
	public function new() 
	{
		super();
		this.world = FGame.getInstance().getWorld("box2d");
		this.position = new FVector(0,0);
		zPosition = 0;
	}
	
	override public function init(config:Dynamic):Void {
		registerEventHandlers();
		var def:B2BodyDef = new B2BodyDef();
		var fixtureDef:B2FixtureDef = new B2FixtureDef();
		
		if(Std.is(config.position,FVector)){
			def.position = cast(config.position,B2Vec2);
		}
		else if(Reflect.isObject(config.position)){
			def.position = new B2Vec2(config.position.x,config.position.y);
		}
		else {
			def.position = cast(new FVector(0, 0),B2Vec2);
		}
		def.userData = this;
		
		
		if(Std.is(config.zPosition,Float)){
			this.setZPosition(config.zPosition);
		}

		if(config.type == 'dynamic')
			def.type = B2Body.b2_dynamicBody;
		else if(config.type == 'kinematic')
			def.type = B2Body.b2_kinematicBody;
		else def.type = B2Body.b2_staticBody;
		
		
		
		var physWorld:FBox2DWorld = cast world;
		if(Std.is(config.angle,Float))
			def.angle = config.angle;
		def.fixedRotation = false;

		if(Std.is(config.fixedRotation,Bool)){
			def.fixedRotation = config.fixedRotation;
		}

		if (Std.is(config.allowSleep, Bool)) {
			def.allowSleep= config.allowSleep;
		}


		body = physWorld.getB2World().createBody(def);
		
		
		
		if (Std.is(config.maxLifeSeconds, Float)) {
			Timer.delay(function() { this._entity.delete(); }, Math.floor(config.maxLifeSeconds * 1000));
		}
		
		if(Std.is(config.shapes,Array))
		for (shape in cast(config.shapes, Array<Dynamic>)) {
				var shapeDef = new B2FixtureDef();
				if (shape.type == 'circle') {
					if (!Std.is(shape.radius, Float)) {
						shape.radius = 1;
					}
					shapeDef.shape = new B2CircleShape(shape.radius);
				}
				
				if (shape.type == 'box') {
					var s:B2PolygonShape = new B2PolygonShape();
					s.setAsBox(shape.width/2, shape.height/2);
					shapeDef.shape = s;
				}
				if (shape.type == 'polygon') {
					var s:B2PolygonShape = new B2PolygonShape();
					
					s.setAsVector(shape.vectors);
					
					shapeDef.shape = s;
				}
				
				if (Std.is(shape.density, Float))
					shapeDef.density = shape.density;
				if (Std.is(shape.friction, Float))
					shapeDef.friction = shape.friction;
				if (Std.is(shape.restitution, Float))
					shapeDef.restitution= shape.restitution;
				
					
				if (Std.is(shape.collisionCategory, Int)) {
						shapeDef.filter.categoryBits = shape.collisionCategory;
				}else if (Std.is(config.collisionCategory, Int)) {
					shapeDef.filter.categoryBits = config.collisionCategory;
				}
				
				if (Std.is(shape.collidesWith, Int)) {
						shapeDef.filter.maskBits = shape.collisionCategory;
				}else if (Std.is(config.collidesWith, Int)) {
					shapeDef.filter.maskBits = config.collidesWith;
				}

				if(Std.is(shape.isSensor,Bool)){
					shapeDef.isSensor=shape.isSensor;
				}

				body.createFixture(shapeDef);
		}
		
		
		this.world.addEntity(this._entity);
		trace("zPOsition: " +zPosition);
	}
		
	private function registerEventHandlers(){
		_entity.addEventListener(FEntity.ACTIVE_STATE_CHANGE, onActiveStateChange);
	}
	
	public function onActiveStateChange(e:Event){

		//we need to do this after the step to be safe.
		if(world.insideStep()){
			FGame.getInstance().addEventListener(FGame.AFTER_STEP,deactivate);
		}else{
			deactivate();
		}
		

	}

	function deactivate(?e:Event=null){
			this.body.setActive(_entity.isActive());
			FGame.getInstance().removeEventListener(FGame.AFTER_STEP,deactivate);
			//trace("deactivated:"+_entity.isActive());
		}

	public function  getPosition() {
		this.position.x = this.body.getPosition().x;
		this.position.y = this.body.getPosition().y;
		return this.position;
	}
	
	public function setPosition(pos:FVector) {
		this.body.setPosition(new B2Vec2(pos.x, pos.y));
		this.position=pos;
	}

	public function getPositionX():Float{
		return this.getPosition().x;
	}

	public function getPositionY():Float{
		return this.getPosition().y;
	}
	
	public function setAngle(a:Float):Void {
		this.body.setAngle(a);
	}
	
	public function getAngle():Float {
		return this.body.getAngle();
	}
	
	public function setLinearVelocity(vel:FVector) {
		this.body.setAwake(true);
		this.body.setLinearVelocity(new B2Vec2(vel.x, vel.y));
	}
	
	public function getLinearVelocity():FVector {
		return new FVector(this.body.getLinearVelocity().x, this.body.getLinearVelocity().y);
	}

	public function addLinearVelocity(velocity:FVector){
		this.body.setAwake(true);
		var vel = this.body.getLinearVelocity();
		vel.add(velocity);
	}

	public function setAngularVelocity(omega:Float):Void {
	    this.body.setAngularVelocity(omega);	
	}

	public function getAngularVelocity():Float {
	    return this.body.getAngularVelocity();	
	}

	public function addAngularVelocity(omega:Float) {
		this.body.setAwake(true);
		var ome = this.body.getAngularVelocity();
	    this.body.setAngularVelocity(ome+omega);	
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
		var fixture = this.body.getFixtureList();
		var shapes = new Array<B2Shape>();
		while (fixture != null) {
			shapes.push(fixture.getShape());
			fixture = fixture.getNext();
		}
		return shapes;
	}



}
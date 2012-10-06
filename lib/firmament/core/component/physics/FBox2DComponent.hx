package firmament.core.component.physics;
import firmament.core.component.FEntityComponent;
import firmament.core.component.physics.FPhysicsEntityComponentInterface;

import box2D.collision.shapes.B2CircleShape;
import box2D.collision.shapes.B2PolygonShape;
import box2D.common.math.B2Vec2;
import firmament.core.FEntity;
import box2D.dynamics.B2Body;
import box2D.dynamics.B2BodyDef;
import box2D.dynamics.B2FixtureDef;
import box2D.dynamics.B2Fixture;
import box2D.collision.shapes.B2Shape;
import haxe.Timer;

/**
 * ...
 * @author Jordan Wambaugh
 */

class FBox2DComponent extends FEntityComponent, implements FPhysicsEntityComponentInterface, implements FWorldPositionalInterface 
{
	
	public var body:B2Body;
	private var zPosition:Float;
	private var position:FVector;
	private var world:FWorld;
	public function new() 
	{
		super();
	}
	
	override public function init(config:Dynamic):Void {
		super.init(config);
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
		
		
		if(config.type == 'dynamic')
			def.type = B2Body.b2_dynamicBody;
		else if(config.type == 'kinematic')
			def.type = B2Body.b2_kinematicBody;
		else def.type = B2Body.b2_staticBody;
		
		
		
		var physWorld:FBox2DWorld = cast world;
		if(Std.is(config.angle,Float))
			def.angle = config.angle;
		def.fixedRotation = false;
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
				body.createFixture(shapeDef);
		}
		
		
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
		this.body.setLinearVelocity(new B2Vec2(vel.x, vel.y));
	}
	
	public function getLinearVelocity():FVector {
		return new FVector(this.body.getLinearVelocity().x, this.body.getLinearVelocity().y);
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
}
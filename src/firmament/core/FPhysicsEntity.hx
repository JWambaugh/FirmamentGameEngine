package firmament.core;

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
import nme.display.Bitmap;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FPhysicsEntity extends FEntity
{

	public var body:B2Body;
	
	
	public function new(world:FPhysicsWorld,config:Dynamic) 
	{
		super(world, config);
		
		if (Std.is(config.sprite,Bitmap)) {
			this.renderer = new FSpriteRenderer();
		}
		else this.renderer = new FWireframeRenderer();
		var def:B2BodyDef = new B2BodyDef();
		var fixtureDef:B2FixtureDef = new B2FixtureDef();
		
		if(Std.is(config.position,FVector)){
			def.position = config.position;
		}else {
			def.position = new FVector(0, 0);
		}
		def.userData = this;
		
		if(config.type=='dynamic')
			def.type = B2Body.b2_dynamicBody;
		else def.type = B2Body.b2_staticBody;
		var physWorld:FPhysicsWorld = cast world;
		if(Std.is(config.angle,Float))
			def.angle = config.angle;
		def.fixedRotation = false;
		body = physWorld.getB2World().createBody(def);
		
		//body.createFixture2(new B2CircleShape(1));
		
		
		
		if (Std.is(config.maxLifeSeconds, Float)) {
			Timer.delay(function() { this.delete(); }, Math.floor(config.maxLifeSeconds * 1000));
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
	
	override function  getPosition() {
		this.position.x = this.body.getPosition().x;
		this.position.y = this.body.getPosition().y;
		return this.position;
	}
	
	override function setPosition(pos:FVector) {
		this.body.setPosition(new B2Vec2(pos.x, pos.y));
	}
	
	override public function getAngle():Float {
		return this.body.getAngle();
	}
	
	public function setLinearVelocity(vel:FVector) {
		this.body.setLinearVelocity(new B2Vec2(vel.x, vel.y));
	}
	
	public function getLinearVelocity():FVector {
		return new FVector(this.body.getLinearVelocity().x, this.body.getLinearVelocity().y);
	}
	
	override public function getShapes():Array<B2Shape> {
		var fixture = this.body.getFixtureList();
		var shapes = new Array<B2Shape>();
		while (fixture != null) {
			shapes.push(fixture.getShape());
			fixture = fixture.getNext();
		}
		return shapes;
	}
	override public function hasShapes() {
		return true;
	}
	
	
	
	public function delete() {
		trace("seppukku!");
		cast(this.world,FPhysicsWorld).removeEntity(this);
	}
}
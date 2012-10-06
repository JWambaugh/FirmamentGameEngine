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
import nme.display.BitmapData;
/**
 * Class: FPhysicsEntity
 * Entity class for physics-based entities 
 * 
 * Extends: <FEntity>
 * 
 * 
 */
 

 
class FPhysicsEntity extends FEntity
{

	public var body:B2Body;
	
	/**
	 * Constructor: new
	 * 
	 * Parameters:
		* world - [<FPhysicsWorld>]
		* config - [Dynamic] A config object with properties specifying details for this entity. See 'Config Parameters' below.
	 *
	 * Config Paramers:
		 * - All parameters except shapes are optional.
		 * shapes - [Array<Dynamic>] Array of config objects spicifying the shapes that make up the entity. See 'Shape Config Parameters' below)
		 * imageScale - [Float] The initial scale value for the sprite. Def: 100
		 * sprite  - [BitmapData] The image to use as a sprite for this entity. Def: none (wireframe)
		 * type - [String] The type of entity to create. Possible values: 'dynamic', 'static', 'kinematic'. Def: static
		 * position - [<FVector>] The starting position for the entity in the world. Def: 0,0
		 * maxLifSeconds - [Int] number of seconds until the entity should automatically die (only set if desired). Def: 0
	 * 
	 * Shape Config Parameters:
		 * 
	 * 
	 */
	public function new(world:FPhysicsWorld,config:Dynamic) 
	{
		super(world, config);
		
		
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
		super.setPosition(pos);
	}
	
	override public function setAngle(a:Float):Void {
		this.body.setAngle(a);
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
		
		cast(this.world,FPhysicsWorld).removeEntity(this);
	}
}
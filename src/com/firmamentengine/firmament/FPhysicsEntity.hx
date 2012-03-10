package com.firmamentengine.firmament;

import box2D.collision.shapes.B2CircleShape;
import box2D.collision.shapes.B2PolygonShape;
import com.firmamentengine.firmament.FEntity;
import box2D.dynamics.B2Body;
import box2D.dynamics.B2BodyDef;
import box2D.dynamics.B2FixtureDef;
import box2D.dynamics.B2Fixture;

/**
 * ...
 * @author Jordan Wambaugh
 */

class FPhysicsEntity extends FEntity
{

	var body:B2Body;
	
	public function new(world:FPhysicsWorld,config:Dynamic) 
	{
		super(world,config);
		this.renderer = new FSpriteRenderer();
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
				
				if (Std.is(shape.density, Float))
					shapeDef.density = shape.density;
				if (Std.is(shape.friction, Float))
					shapeDef.friction = shape.friction;
				if (Std.is(shape.restitution, Float))
					shapeDef.restitution= shape.restitution;
				
				body.createFixture(shapeDef);
		}
		
		
		
		
	}
	
	override function  getPosition() {
		this.position.x = this.body.getPosition().x;
		this.position.y = this.body.getPosition().y;
		return this.position;
	}
	
	override public function getAngle():Float {
		return this.body.getAngle();
	}
	
}
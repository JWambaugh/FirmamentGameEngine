package com.firmamentengine.firmament;

import box2D.collision.shapes.B2CircleShape;
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
		this.renderer = new FWireframeRenderer();
		var def:B2BodyDef = new B2BodyDef();
		var fixtureDef:B2FixtureDef = new B2FixtureDef();
		
		if(Std.is(config.position,FVector)){
			def.position = config.position;
		}else {
			def.position = new FVector(0, 0);
		}
		def.userData = this;
		def.type = B2Body.b2_dynamicBody;
		
		var physWorld:FPhysicsWorld = cast world;
		
		body = physWorld.getB2World().createBody(def);
		body.createFixture2(new B2CircleShape(1));
		
		
		
		
	}
	
	override function  getPosition() {
		this.position.x = this.body.getPosition().x;
		this.position.y = this.body.getPosition().y;
		return this.position;
	}
	
}
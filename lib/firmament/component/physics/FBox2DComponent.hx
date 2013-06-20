package firmament.component.physics;


import box2D.collision.shapes.B2CircleShape;
import box2D.collision.shapes.B2PolygonShape;
import box2D.collision.shapes.B2Shape;
import box2D.common.math.B2Vec2;
import box2D.dynamics.B2Body;
import box2D.dynamics.B2BodyDef;
import box2D.dynamics.B2Fixture;
import box2D.dynamics.B2FixtureDef;
import box2D.dynamics.joints.B2DistanceJointDef;
import box2D.dynamics.joints.B2RevoluteJointDef;
import box2D.dynamics.joints.B2WeldJointDef;
import firmament.component.base.FEntityComponent;
import firmament.component.physics.FPhysicsComponentInterface;
import firmament.world.FBox2DWorld;
import firmament.core.FCircleShape;
import firmament.core.FEntity;
import firmament.core.FEntityFactory;
import firmament.core.FGame;
import firmament.core.FPolygonShape;
import firmament.core.FShape;
import firmament.core.FVector;
import firmament.world.FWorld;
import firmament.core.FWorldPositionalInterface;
import firmament.util.FMisc;
import firmament.util.loader.FDataLoader;
import haxe.Timer;
import flash.events.Event;

/**
 * Class: FBox2DComponent
 * @author Jordan Wambaugh
 */

class FBox2DComponent extends FEntityComponent implements FPhysicsComponentInterface implements FWorldPositionalInterface 
{

	public var body:B2Body;
	private var zPosition:Float;
	private var position:FVector;
	private var world:FWorld;
	private var _parentEntity:FEntity;
	public function new() 
	{
		super();
		
		this.position = new FVector(0,0);
		zPosition = 0;
		_parentEntity = null;
	}
	
	override public function init(config:Dynamic):Void {
		this.world = _entity.getGameInstance().getWorld("box2d");
		registerEventHandlers();
		var def:B2BodyDef = new B2BodyDef();
		var fixtureDef:B2FixtureDef = new B2FixtureDef();
		
		if(Std.is(config.position,FVector)){
			def.position = cast(config.position,B2Vec2);
		}
		else if(Reflect.isObject(config.position) && Std.is(config.position.x,Float) && Std.is(config.position.y,Float)){
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
		if(Std.is(config.angle,Float)){
			def.angle = config.angle;
		}

		//fixedRotation
		def.fixedRotation = false;
		if(Std.is(config.fixedRotation,Bool)){
			def.fixedRotation = config.fixedRotation;
		}

		//allowSleep
		if (Std.is(config.allowSleep, Bool)) {
			def.allowSleep= config.allowSleep;
		}

		//isBullet
		if(Std.is(config.bullet,Bool)){
			def.bullet = config.bullet;
		}

		body = physWorld.getB2World().createBody(def);
		
		if(body==null){
			throw "error creating body. config: "+Std.string(config);
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
		
		if(Std.is(config.alwaysRender,Bool) && config.alwaysRender==true){
			this.world.addToAlwaysRenderList(_entity);
		}


		//process joints
		if(Std.is(config.joints,Array))
		for (joint in cast(config.joints, Array<Dynamic>)) {
			createJointEntity(joint);
		}
		
		this.world.addEntity(this._entity);
	}
		
	private function registerEventHandlers(){
		_entity.addEventListener(FEntity.ACTIVE_STATE_CHANGE, onActiveStateChange);
	}
	
	private function removeEventHandlers(){
		_entity.removeEventListener(FEntity.ACTIVE_STATE_CHANGE, onActiveStateChange);
	}

	/*
		Function: createJointEntity
		creates an entity and a joint between this entity an the new one.
	*/
	public function createJointEntity(joint:Dynamic){
		var physWorld:FBox2DWorld = cast world;
		if(Std.is(joint.entity,String)){
			joint.entity = FDataLoader.loadData(joint.entity);
		}
		var mergeConfig:Dynamic = {components:{physics:{}}};
		if(joint.entity == null){
			throw("joint entity is null");
		}

		if(Reflect.isObject(joint.positionOffset)){
			mergeConfig.components.physics.position={x:getPositionX()+joint.positionOffset.x,y:getPositionY()+joint.positionOffset.y};
		}else{
			mergeConfig.components.physics.position = getPosition();
		}

		if(Std.is(joint.zPositionOffset,Float)){
			mergeConfig.components.physics.zPosition=getZPosition()+joint.zPositionOffset;
		}

		if(Std.is(joint.angleOffset,Float)){
			mergeConfig.components.physics.angle = getAngle()+joint.angleOffset;
		}else{
			mergeConfig.components.physics.angle = getAngle();
		}
		FMisc.mergeInto(mergeConfig,joint.entity);
		//trace(Std.string(joint.entity));
		var childEntity = FEntityFactory.createEntity(joint.entity);
		cast(childEntity.getPhysicsComponent(), FBox2DComponent).setParentEntity(_entity);

		if(joint.type == 'weld'){
			var def = new B2WeldJointDef();
			def.initialize(this.body,cast(childEntity.getPhysicsComponent(),FBox2DComponent).body,body.getWorldCenter());
			physWorld.getB2World().createJoint(def);
		}
		if(joint.type == 'distance'){
			var def = new B2DistanceJointDef();
			def.initialize(this.body,cast(childEntity.getPhysicsComponent(),FBox2DComponent).body,body.getWorldCenter(),cast(childEntity.getPhysicsComponent(),FBox2DComponent).body.getWorldCenter());
			physWorld.getB2World().createJoint(def);
		}
		if(joint.type == 'revolute'){
			var def = new B2RevoluteJointDef();
			def.initialize(this.body,cast(childEntity.getPhysicsComponent(),FBox2DComponent).body,body.getWorldCenter());
			if(Std.is(joint.motorSpeed,Float)){
				def.enableMotor=true;
				def.motorSpeed=joint.motorSpeed;
			}
			if(Std.is(joint.maxMotorTorque,Float)){
				def.enableMotor=true;
				def.maxMotorTorque=joint.maxMotorTorque;
			}

			physWorld.getB2World().createJoint(def);
		}
		childEntity.dispatchEvent(new Event('ParentJointCreated'));
		return childEntity;
	}

	public function onActiveStateChange(e:Event){

		//we need to do this after the step to be safe.
		if(world.insideStep()){
			FMisc.doLater(function(){deactivate();});
		}else{
			deactivate();
		}
		

	}

	function deactivate(?e:Event=null){
			this.body.setActive(_entity.isActive());
			//trace("deactivated:"+_entity.isActive());
		}

	public function  getPosition() {
		if(body == null)throw("BODY IS NULL!!!"+_entity.getTypeId());
		this.position.x = this.body.getPosition().x;
		this.position.y = this.body.getPosition().y;
		return this.position;
	}
	
	public function setPosition(pos:FVector) {
		this.body.setPosition(new B2Vec2(pos.x, pos.y));
		this.position=pos;
	}

	public function setPositionXY(x:Float,y:Float){
		this.position.set(x,y);
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

	public function applyLinearForce(v:FVector,?point:FVector=null):Void {
		this.body.setAwake(true);
		var applyAtPoint = point==null?this.body.getWorldCenter():point;
		this.body.applyForce(v,applyAtPoint);
	}
	
	public function setLinearVelocity(vel:FVector) {
		this.body.setAwake(true);
		this.body.setLinearVelocity(new B2Vec2(vel.x, vel.y));
	}
	
	public function getLinearVelocity():FVector {
		return new FVector(this.body.getLinearVelocity().x, this.body.getLinearVelocity().y);
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
	public function getShapes():Array<FShape>{
		var fixture = this.body.getFixtureList();
		var shapes = new Array<FShape>();
		while (fixture != null) {
			var b2Shape = fixture.getShape();

			if(b2Shape.getType() == B2Shape.e_polygonShape){
				var fvecs = new Array<FVector>();
				for( vec in cast(b2Shape,B2PolygonShape).m_vertices){
					fvecs.push(new FVector(vec.x,vec.y));
				}
				shapes.push(new FPolygonShape(fvecs));
			}
			if(b2Shape.getType() == B2Shape.e_circleShape){
				var s:B2CircleShape = cast(b2Shape);
				var p = s.getLocalPosition();
				shapes.push(new FCircleShape(s.m_radius,new FVector(p.x,p.y)));
			}



			fixture = fixture.getNext();
		}
		return shapes;
	}
	
	override public function destruct(){
		this.removeEventHandlers();
		world.deleteEntity(_entity);
	}

	public function getParentEntity(){
		return _parentEntity;
	}

	public function setParentEntity(entity:FEntity){
		_parentEntity = entity;
	}


}
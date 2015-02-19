package firmament.component.physics;


import box2D.collision.shapes.B2CircleShape;
import box2D.collision.shapes.B2PolygonShape;
import box2D.collision.shapes.B2Shape;
import box2D.collision.shapes.B2ShapeType;
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
import firmament.core.FCircleShape;
import firmament.core.FComputedProperty;
import firmament.core.FEntity;
import firmament.core.FEntityFactory;
import firmament.core.FEvent;
import firmament.core.FGame;
import firmament.core.FPolygonShape;
import firmament.core.FPropertyDefinition;
import firmament.core.FProperty;
import firmament.core.FPropertyInterface;
import firmament.core.FShape;
import firmament.core.FVector;
import firmament.core.FWorldPositionalInterface;
import firmament.util.FLog;
import firmament.util.FMisc;
import firmament.util.loader.FDataLoader;
import firmament.world.FBox2DWorld;
import firmament.world.FWorld;
import haxe.Timer;

/**
 * Class: FBox2DComponent
 * @author Jordan Wambaugh
 */

class FBox2DComponent extends FEntityComponent implements FPhysicsComponentInterface 
{

	public var body:B2BodyS;
	private var positionZ:Float;
	private var position:FVector;
	private var world:FWorld;
	private var _parentEntity:FEntity;
    private var def:B2BodyDef;

	public function new(gameInstance:firmament.core.FGame) 
	{
		super(gameInstance);
		
		this.position = new FVector(0,0);
		positionZ = 0;
		_parentEntity = null;
        this.world = null;
        this.body = null;
        def = new B2BodyDef();
	}
	
	override public function init(config:Dynamic):Void {
        var cf:firmament.core.FConfig = config;
		this.world = _entity.getGameInstance().getWorld("box2d");
		registerEventHandlers();
		
		var fixtureDef:B2FixtureDef = new B2FixtureDef();
		
		if(Std.is(config.position,FVector)){
			def.position = cast(config.position,B2Vec2);
		}
		else if(Reflect.isObject(config.position) && Std.is(config.position.x,Float) && Std.is(config.position.y,Float)){
			def.position = new B2Vec2(config.position.x,config.position.y);
		}
		
		def.userData = this;
		
		
		if(Std.is(config.positionZ,Float)){
		  this.setPositionZ(config.positionZ);
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

					// convert to b2vector
					var vectors:Array<B2Vec2> = new Array();
FLog.msg("Vectors - " + shape.vectors );
					for( vect in cast(shape.vectors,Array<Dynamic>)){
						// var vect = Reflect.field(shape.vectors,field);
FLog.msg("Vector - " + vect );
						vectors.push( new B2Vec2( vect.x,vect.y ) );
					}
FLog.msg("Composed - " + vectors);
					s.setAsVector(vectors);
					
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
						shapeDef.filter.maskBits = shape.collidesWith;
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
		on(_entity,FEntity.ACTIVE_STATE_CHANGE, onActiveStateChange);
	}
	
	private function removeEventHandlers(){
		_entity.removeEventListener(this);
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

		if(Std.is(joint.positionZOffset,Float)){
			mergeConfig.components.physics.positionZ=getPositionZ()+joint.positionZOffset;
		}

		if(Std.is(joint.angleOffset,Float)){
			mergeConfig.components.physics.angle = getAngle()+joint.angleOffset;
		}else{
			mergeConfig.components.physics.angle = getAngle();
		}
		FMisc.mergeInto(mergeConfig,joint.entity);
		//firmament.util.FLog.debug(Std.string(joint.entity));
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
		childEntity.trigger(new FEvent('ParentJointCreated'));
		return childEntity;
	}

	public function onActiveStateChange(e:FEvent){

		//we need to do this after the step to be safe.
		if(world.insideStep()){
			FMisc.doLater(function(){deactivate();});
		}else{
			deactivate();
		}
		

	}

	function deactivate(e:FEvent=null){
		this.body.setActive(_entity.isActive());
		//firmament.util.FLog.debug("deactivated:"+_entity.isActive());
	}


	public function  getPosition(p:FVector=null) {
		if(body == null)throw("BODY IS NULL!!!"+_entity.getTypeId());
		this.position.x = this.body.getPosition().x;
		this.position.y = this.body.getPosition().y;
		return this.position;
	}
	
	public function setPosition(pos:FVector) {
        this.position=pos;
        var p = new B2Vec2(pos.x, pos.y);
        if(body!=null)
		  this.body.setPosition(p);
        else
            def.position = p;
		
	}

	public function setPositionXY(x:Float,y:Float){
		setPosition(new FVector(x,y));
	}

	public function setPositionX(x:Float){
        setPosition(new FVector(x,this.position.y));
	
	}
	public function setPositionY(y:Float){
        setPosition(new FVector(this.position.x,y));
	}

	public function getPositionX(p:Float=0):Float{
		return this.getPosition().x;
	}

	public function getPositionY(p:Float=0):Float{
		return this.getPosition().y;
	}
	
	public function setAngle(a:Float):Void {
        if(body!=null)
            this.body.setAngle(a);
        else
            def.angle = a;

	}
	
	public function getAngle(a:Float=0):Float {
		return this.body.getAngle();
	}

	public function applyLinearForce(fv:FVector,?fpoint:FVector=null):Void {
		this.body.setAwake(true);
		var v = new B2Vec2(fv.x,fv.y);
		
		var applyAtPoint:B2Vec2;
		if(fpoint==null){
			var p = this.body.getWorldCenter();
			applyAtPoint = new B2Vec2(p.x,p.y);
		}else{
			applyAtPoint = new B2Vec2(fpoint.x,fpoint.y);
		}
		this.body.applyForce(v,applyAtPoint);
	}
	
	public function setLinearVelocity(vel:FVector) {
        var v =new B2Vec2(vel.x, vel.y);
        if(body!=null){
    		this.body.setAwake(true);
    		this.body.setLinearVelocity(v);
        }else{
            def.linearVelocity = v;
        }
	}
	
	public function getLinearVelocity(v:FVector=null):FVector {
		return new FVector(this.body.getLinearVelocity().x, this.body.getLinearVelocity().y);
	}

	public function setAngularVelocity(omega:Float):Void {
        if(body!=null)
	       this.body.setAngularVelocity(omega);	
        else
            def.angularVelocity =omega;
	}

	public function getAngularVelocity(a:Float=0):Float {
	    return this.body.getAngularVelocity();	
	}

	public function addAngularVelocity(omega:Float) {
		this.body.setAwake(true);
		var ome = this.body.getAngularVelocity();
	    this.body.setAngularVelocity(ome+omega);
	}
	
	public function getPositionZ(z:Float=0):Float {
		return positionZ;
	}
	public function setPositionZ(p:Float):Void {
		positionZ = p;
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

			if(b2Shape.getType() == B2ShapeType.POLYGON_SHAPE){
				var fvecs = new Array<FVector>();
				for( vec in cast(b2Shape,B2PolygonShape).m_vertices){
					fvecs.push(new FVector(vec.x,vec.y));
				}
				shapes.push(new FPolygonShape(fvecs));
			}
			if(b2Shape.getType() == B2ShapeType.CIRCLE_SHAPE){
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
package firmament.scene.component;

import firmament.core.FCamera;
import firmament.core.FConfig;
import firmament.core.FVector;
import firmament.core.FEntity;
import firmament.core.FEntityFactory;
import firmament.core.FEntityPool;
import firmament.core.FEvent;
import firmament.core.FPropertyDefinition;
import firmament.scene.FSceneComponent;
import firmament.util.loader.FDataLoader;
import firmament.component.physics.FNoPhysicsComponent;

class FTiledScroller extends FSceneComponent {

  var _entities:Array<FEntity>;
  var _widthHeight:FVector;
  var _topLeft:FVector;
  var _bottomRight:FVector;
  var _screenWidthHeight:FVector;
  var _maxEntities:Int;

  public function new(gameInstance:Dynamic) {
    super(gameInstance);
    _entities = new Array();
    _maxEntities = 10;
    useStep(true);
  }

  override public function init(config:FConfig):Void {

    _enableDebug = config.get('debug',Bool,false);
    _maxEntities = config.get('max',Int,_maxEntities);

    /*
      {
        "entity" : "string" | FConfig,
        "postitionY" : number | property
        "speed" : number | Property, // meters per second
        "paused" : bool,
        "listeners" : {
          "start" : "",
          "stop" : ""
        },
        "triggers" : {
          "update" : "",
          "switch" : "",
        }
      }
    */

    var camera:FCamera = _gameInstance.getCamera();
    // get screen dimensions
    var zoom:Float = camera.getZoom();
    _topLeft = camera.getTopLeftPosition();
    _bottomRight = camera.getBottomRightPosition();
    _screenWidthHeight = new FVector( _bottomRight.x - _topLeft.x, _bottomRight.y - _topLeft.y );

log("TopLeft/BottomRight " + Std.string(_topLeft) + "/" + Std.string(_bottomRight) );
    var ent:FEntity = getNextEntity();
    var phys:FNoPhysicsComponent = cast(ent.getPhysicsComponent(), FNoPhysicsComponent);
    // get the dimensions from an entity
    _widthHeight = new FVector(phys.getWidth(), phys.getHeight());
log("WidthHeight " + Std.string(_widthHeight) );
    // figure out how many need to be displayed
    var entityCount = Math.ceil( ( _bottomRight.x - _topLeft.x ) / _widthHeight.x );
log("Entities to fill screen " + entityCount );
    var objCenter:FVector = new FVector(_topLeft.x + _widthHeight.x / 2, ent.getProp('positionY'));
log("Center of first entity " + objCenter );
    _entities.push(ent);
    // create the necessary count
log("Need to create - " + entityCount);
    for(i in 1...entityCount) {
      if( _entities.length >= _maxEntities ) { break; }
      ent = getNextEntity();
      _entities.push(ent);
    }
    
    // position them across the screen
    for( e in _entities ) {
      e.setProp('positionX',objCenter.x);
      objCenter.x += _widthHeight.x; // optimize by only doing once
    }

    // activate them
    for ( e in _entities ) {
      e.setActive(true);
    }
  }

  override public function step(delta:Float){
    // measure
    var sample:Bool = (Math.random() <= .1);
    var max:FVector = new FVector(0,0), min:FVector = new FVector(0,0);
    var halfWidth:Float = _widthHeight.x / 2, halfHeight:Float = _widthHeight.y / 2;
    for ( e in _entities ) {
      var center:FVector = e.getProp('position');
      var locmin_x = center.x - halfWidth, locmin_y = center.y - halfHeight;
      var locmax_x = center.x + halfWidth, locmax_y = center.y + halfHeight;
      if( max.x < locmax_x ) { max.x = locmax_x; }
      if( max.y < locmax_y ) { max.y = locmax_y; }
      if( min.x > locmin_x ) { min.x = locmin_x; }
      if( min.y > locmin_y ) { min.y = locmin_y; }
    }

    // check to see if I need to add another entity
    var i = max.x;
    while( i < _bottomRight.x ) {
      /*if( sample ) {
        // log( "Adding Entities " + (_bottomRight.x - i) );
      }*/
      if( _entities.length >= _maxEntities ) { break; }
      _entities.push( getNextEntity() );
      i+=_widthHeight.x;
    }

    // figure out the position necessary to fill in the hole
    var base:Float = Math.min(_topLeft.x,min.x); // choose the smallest
    while( base < min.x ) {
      /*if( sample ) {
      // log( "Finding base position - " + i);
      }*/
      base+=_widthHeight.x;
    }

    // shift all of the tiles
    var speed:Float = _config.get('speed',Float,0) * delta; // this is to correct for rounding errors
    if(sample) {
      log( "Translating by " + speed );
    }
    base += halfWidth - speed;
    for( e in _entities ) {
      // var pos:Float = e.getProp('positionX');
      // log( "Shifting entity " + pos + " -> " + base );
      if( sample ) {
        log( "Shifting entity to " + base );
      }
      e.setProp('positionX',base);
      if( e.isActive() == false ) {e.setActive( true ); }
      base += _widthHeight.x;
    }

    if( sample ) {
      log( "Number of active entities " + _entities.length );
    }

    while( _entities.length > 0 ) {
      var ent:Null<FEntity> = _entities[0];
      var min:Float = ent.getProp('positionX') + halfWidth; // right edge
      if( min >= _topLeft.x ) {break;}
      _entities.shift(); // remove from array
      ent.destruct(); // remove
      ent = null; // destroy reference
    }
  }

  private function getNextEntity(): FEntity {
    // this can be a list or a string
    var pool:FEntityPool;
    var sEntity:String = _config.getNotNull('entity',String);
    log("Attempting to create new entity " + _config.get("entity") );
    if( sEntity.indexOf("pool:") != 0 ) {
      // create a new pool for this object
      log("entity " + sEntity + " is not a pool, creating pool");
      var cEntity:FConfig = FDataLoader.loadData(sEntity);
      pool = new FEntityPool( cEntity, 1 );
      _gameInstance.getPoolManager()
                      .addPool( pool );
      // update the _config object with the pool tag, so I don't try to create this again
      _config["entity"] = "pool:" + pool.getEntityTypeId(); // this could have been an object ..
                                                        // so this statement here would break
                                                        // if it was an array or something else
    } else {
      var sPool = sEntity.substr(5);
      log("entity " + sEntity + " is a pool");
      pool = _gameInstance.getPoolManager().getPool(sPool);
    }

    log("Getting entity - " + _config.get("entity") + " (pool count "+ pool.count +")" );
    var ent:FEntity = pool.getEntity();
    ent.setActive(false);
    return ent;

  }

  /*override public function getProperties():Array<FPropertyDefinition> {
    // props limit number of controllers to 1
    var props:Array<FPropertyDefinition> = [
          //{
          //    key:'cameraPosition'
          //    ,type:FVector
          //    ,getter:getPosition
          //    ,setter:setPosition
          //}
      ];
      return props;
  }*/

  override public function destruct(){
    super.destruct();
    while ( _entities.length > 0 ) {
      var ent:Null<FEntity> = _entities.pop(); // faster to pop than shift
      ent.destruct();
      ent = null;
    }
  }
}

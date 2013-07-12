package firmament.world.grid;

import firmament.core.FVector;
import firmament.world.grid.FGridCell;
import firmament.core.FEntity;
/**
 *
 *
 */
class FGridWorldSector{

	var _topLeftPosition:FVector;
	var _width:Int;
	var _height:Int;
	var _grid:Array<Array<FGridCell>>;

	public function new(width:Int,height:Int,topLeft:FVector){
		_topLeftPosition = topLeft;
		_width = width;
		_height = height;
		initializeGrid();
	}

	/**
	 * returns the FGridCell object for the provided sector-relative position
	 *
	 */
	public function getCellAtSectorPos(x:Int,y:Int):FGridCell{
		validateSectorPos(x,y);
		return _grid[x][y];
	}

	/**
	 * returns an array of entities for the provided sector-relative position
	 *
	 */
	public function getEntitiesAtSectorPos(x:Int,y:Int):Array<FEntity>{
		return getCellAtSectorPos(x,y).getEntities();
	}

	private function initializeGrid(){
		_grid = new Array<Array<FGridCell>>();
		for(x in 0..._width){
			_grid.push(new Array<FGridCell>());
			for(y in 0..._height){
				_grid[x].push(new FGridCell());
			}
		}
	}

	private function validateSectorPos(x:Int,y:Int){
		if(x<0 || x>=_width || y<0 || y>=_height){
			throw "sector position of "+x+','+y+' is not valid.';
		}
	}




}


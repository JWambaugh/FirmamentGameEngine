
package firmament.ui;


import nme.display.Sprite;
import nme.events.MouseEvent;
import firmament.core.FVector;
import firmament.ui.FVirtualJoystick;

class FAutoVirtualJoystick extends Sprite{

	var _mouseDown:Bool;
	var _stick:FVirtualJoystick;
	public function new(width:Float,height:Float,?classes:Array<String> = null){
		super();

		this.graphics.beginFill(0xFFFFFF,.005);
		this.graphics.drawRect(0,0,width,height);
		this.addEventListener(MouseEvent.MOUSE_DOWN,mouseDown);
		this.addEventListener(MouseEvent.MOUSE_UP,mouseUp);
		_mouseDown = false;
		_stick = new FVirtualJoystick(classes);
	}

	private function mouseDown(e:MouseEvent){
		_stick.x=e.localX;
		_stick.y=e.localY;
		this.addChild(_stick);
		_stick.mouseDown(e);
	}
	
	private function mouseUp(e:MouseEvent){
		_mouseDown = false;
		this.removeChild(_stick);
	}
	
	public function getValue():FVector{
		return _stick.getValue();
	}


}
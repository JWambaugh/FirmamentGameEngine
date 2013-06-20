package firmament.ui;


import flash.display.Sprite;
import flash.events.MouseEvent;
import firmament.core.FVector;
import firmament.ui.FStyle;
import flash.events.TouchEvent;
import flash.events.Event;
class FVirtualJoystick extends Sprite{

	var _stick:Sprite;
	var _mouseDown:Bool;
	

	var _radius:Float;
	


	public function new(?classes:Array<String> = null){
		var style =  FStyle.getStyleObj(classes);
		_radius = 50;
		if(Std.is(style.joystickRadius,Float)){
			_radius = style.joystickRadius;
		}

		super();
		_stick = new Sprite();
		_stick.graphics.lineStyle(3,0xFFFFFF,.4);
		_stick.graphics.beginFill(0xFFFFFF,.4);
		_stick.graphics.drawCircle(0,0,_radius/2);
		_stick.graphics.endFill();
		this.addChild(_stick);

		this.graphics.lineStyle(3,0xFFFFFF,.4);
		this.graphics.beginFill(0xFFFFFF,.1);
		this.graphics.drawCircle(0,0,_radius);

		this.addEventListener(MouseEvent.MOUSE_DOWN,mouseDown);
		this.addEventListener(MouseEvent.MOUSE_UP,mouseUp);
		this.addEventListener(MouseEvent.MOUSE_MOVE,mouseMove);
		this.addEventListener(TouchEvent.TOUCH_BEGIN, mouseDown);
		this.addEventListener(TouchEvent.TOUCH_MOVE, mouseMove);
		this.addEventListener(TouchEvent.TOUCH_END, mouseUp);
		this.addEventListener(MouseEvent.MOUSE_OUT, mouseUp);
		_mouseDown = false;
	}

	public function mouseDown(e:MouseEvent){
		_mouseDown = true;
		
	}
	public function mouseUp(e:MouseEvent){
		_mouseDown = false;
		_stick.x = 0;
		_stick.y= 0;
		this.dispatchEvent(new Event("f_mouseup"));
	}
	private function mouseMove(e:MouseEvent){
		if(!_mouseDown)return;
		var point = new FVector(e.stageX - this.x,e.stageY - this.y);
		var distance = point.distanceTo(new FVector(0,0));
		if(distance > _radius){
			var angle = Math.atan2(point.y , point.x);
			_stick.x = Math.cos(angle) * _radius;
			_stick.y = Math.sin(angle) * _radius;
		}else{
			_stick.x = point.x;
			_stick.y = point.y;
		}
		
	}

	public function getValue():FVector{
		return new FVector(_stick.x/_radius,_stick.y/_radius);
	}
	



}
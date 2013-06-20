package firmament.ui;
import flash.display.DisplayObject;
import flash.display.Sprite;
import flash.geom.Rectangle;
import flash.events.MouseEvent;
import firmament.ui.layout.FHBox;
import firmament.ui.layout.FVBox;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FScroller extends FWidget
{
/*
	var canvas:DisplayObject;
	var rect:Rectangle;
	var w:Int;
	var h:Int;
	//var layout:FH
	var _buttons:Map<String,FWidget>;

	public function new(width, height, canvas:DisplayObject, buttons:Map<String,FWidget>) 
	{
		super();
		this.w = width;
		this.h = height;

		_buttons = buttons;

		


	}


	public function setLeftButton(b:FWidget){
		//this.removeChild(leftButton);
		leftButton = b;
		this.addChild(b);

	}

	
	public function setCanvas(c:DisplayObject) {
		this.canvas = c;
		rect = new Rectangle();
		rect.width = w;
		rect.height = h;
		c.x = 0;
		c.y = 0;
		this.addChild(c);
		c.scrollRect = rect;
		checkSize();
	}

	public function checkSize(){
		if(canvas.width > this.w){

		}else{

		}

		if(canvas.h > this.h){
			this.addChild(upButton);
			this.addChild(downButton);
		}else{
			this.removeChild(upButton);
			this.removeChild(downButton);
		}
	}
	
	public function scrollDown(?e:MouseEvent=null) {
		rect.y += 10;
		this.canvas.scrollRect = rect;
	}
	public function scrollUp(?e:MouseEvent=null) {
		rect.y -= 10;
		this.canvas.scrollRect = rect;
	}

	public function scrollRight(?e:MouseEvent=null) {
		rect.x += 10;
		this.canvas.scrollRect = rect;
	}
	public function scrollLeft(?e:MouseEvent=null) {
		rect.x -= 10;
		this.canvas.scrollRect = rect;
	}
*/
}
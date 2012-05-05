package firmament.ui;
import nme.display.DisplayObject;
import nme.display.Sprite;
import nme.geom.Rectangle;
import nme.events.MouseEvent;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FScroller extends Sprite
{

	var canvas:DisplayObject;
	var rect:Rectangle;
	var w:Int;
	var h:Int;
	
	var downButton:FSmallButton;
	var upButton:FSmallButton;
	public function new(width,height) 
	{
		super();
		this.w = width;
		this.h = height;
		
		upButton = new FSmallButton("^", width, 0, scrollUp);
		this.addChild(upButton);
		
		downButton = new FSmallButton("V", width, height, scrollDown);
		downButton.y -= downButton.height;
		this.addChild(downButton);
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
	}
	
	public function scrollDown(?e:MouseEvent=null) {
		rect.y += 10;
		this.canvas.scrollRect = rect;
	}
	public function scrollUp(?e:MouseEvent=null) {
		rect.y -= 10;
		this.canvas.scrollRect = rect;
	}
}
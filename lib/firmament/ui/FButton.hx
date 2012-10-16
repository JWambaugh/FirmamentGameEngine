package firmament.ui;
import nme.display.Sprite;
import nme.events.MouseEvent;
import nme.events.Event;
import nme.Lib;
/**
 * Class: FButton
 * @author Jordan Wambaugh
 */

class FButton extends FWidget
{

	var text:FTextLabel;
	var currentColor:Int;
	var regularColor:Int;
	var hoverColor:Int;
	var clickColor:Int;
	
	
	/**
	 * Constructor: new
	 * creates a new button. Can optionally take x and y coordinates, and a function to fire when clicked.
	 * the onclick parameter must be a function that accepts a MouseEvent object and return Void.
	 */
	public function new(?text:String="",?x:Int=0,?y:Int=0,?onClick:MouseEvent -> Void=null) 
	{
		super();
		this.x = x;
		this.y = y;
		this.regularColor = 0xFFFFFF;
		this.hoverColor = 0xEEF0FF;
		this.clickColor = 0xAACCFF;
		this.currentColor = this.regularColor;
		
		this.text = new FTextLabel(text, 1, 1);
		this.addChild(this.text);
		this.draw();
		this.addEventListener(MouseEvent.MOUSE_OVER, this.onOver );
		this.addEventListener(MouseEvent.MOUSE_OUT, this.onOut );
		this.addEventListener(MouseEvent.MOUSE_DOWN, this.onDown );
		this.addEventListener(MouseEvent.MOUSE_UP, this.onUp );
		
		if (onClick != null) {
			this.addEventListener(MouseEvent.CLICK, onClick);
		}
	}
	
	public function draw(?e:Event) {
		this.graphics.clear();
		this.graphics.beginFill(this.currentColor);
		this.graphics.lineStyle(2, 0x555555);
		trace("width: "+this.text.width);
		this.graphics.drawRoundRect(0, 0, this.text.width+2, this.text.height+2,5);
		this.graphics.endFill();
	}
	
	private function onOver(e:MouseEvent) {
		
		this.currentColor = this.hoverColor;
		this.draw();
	}
	private function onOut(e:MouseEvent) {
		this.currentColor = this.regularColor;
		this.draw();
	}
	
	private function onDown(e:MouseEvent) {
		
		this.currentColor = this.clickColor;
		this.draw();
	}
	private function onUp(e:MouseEvent) {
		this.currentColor = this.regularColor;
		this.draw();
	}
	
	public function setText(t:String) {
		this.text.text = t;
		this.draw();
	}
	
}

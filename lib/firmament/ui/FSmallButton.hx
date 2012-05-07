package firmament.ui;
import nme.events.MouseEvent;
import nme.events.Event;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FSmallButton extends FButton
{

	public function new(?text:String="",?x=0,?y=0,?onClick:MouseEvent -> Void=null) 
	{
		super(text, x, y,onClick);
		this.regularColor = 0xCCEEFF;
		this.currentColor = this.regularColor;
		this.text.x = 1;
		this.text.y = -2;
		this.draw();
	}
	
	override public function draw(?e:Event) {
		this.graphics.clear();
		this.graphics.beginFill(this.currentColor);
		this.graphics.lineStyle(1, 0x555555);
		this.graphics.drawRect(0, 0, this.text.width+1, this.text.height-5);
		this.graphics.endFill();
	}
	
}

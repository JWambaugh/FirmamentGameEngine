package firmament.ui.layout;
import nme.display.DisplayObject;


/**
 * ...
 * @author Jordan Wambaugh
 */

class FVBox extends FLayout
{

	
	public function new(?children:Array<DisplayObject>=null) 
	{
		super(children);
		
	}
	
	
	override public function layoutChildren() {
		this.contentHeight = 0;
		for (x in 0 ... this.numChildren) {
			var child = this.getChildAt(x);
			this.contentHeight += this.padding;
			child.y =  this.contentHeight;
			this.contentHeight += cast(child.height);
			child.x = 0;
		}
	}
}
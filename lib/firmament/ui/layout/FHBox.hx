package firmament.ui.layout;
import nme.display.DisplayObject;


/**
 * ...
 * @author Jordan Wambaugh
 */

class FHBox extends FLayout
{

	
	public function new(?children:Array<DisplayObject>=null) 
	{
		super(children);
		
	}
	
	
	override public function layoutChildren() {
		this.contentWidth = 0;
		for (x in 0 ... this.numChildren) {
			var child = this.getChildAt(x);
			this.contentWidth += this.padding;
			child.x =  this.contentWidth;
			this.contentWidth += cast(child.width);
			child.y = 0;
		}
		super.layoutChildren();

	}
	
	
}
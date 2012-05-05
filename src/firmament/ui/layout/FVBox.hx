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
	
	override public function addChild(child:DisplayObject):DisplayObject {
		this.contentHeight += this.padding;
		child.y =  this.contentHeight;
		this.contentHeight += cast(child.height);
		child.x = 0;
		return super.addChild(child);
	}
	
	
	
}
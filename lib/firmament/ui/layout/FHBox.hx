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
	
	override public function addChild(child:DisplayObject):DisplayObject {
		this.contentWidth += this.padding;
		child.x =  this.contentWidth;
		this.contentWidth += cast(child.width);
		child.y = 0;
		return super.addChild(child);
	}
	
	
	
}
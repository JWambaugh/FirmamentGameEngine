package firmament.ui.layout;
import nme.display.DisplayObjectContainer;
import nme.display.DisplayObject;
import nme.display.Sprite;

/**
 * ...
 * @author Jordan Wambaugh
 */

 
 enum LayoutAlignment {
	center;
	top; 
	left; 
	right;
 }
 
class FLayout extends Sprite
{

	var padding:Int;
	var alignment:LayoutAlignment;
	var contentWidth:Int;
	var contentHeight:Int;
	
	public function new(?children:Array<DisplayObject>=null) 
	{
		super();
		this.padding = 5;
		this.contentWidth = 0;
		this.contentHeight = 0;
		if (children != null) this.addChildren(children);
	}
	
	
	public function setAlignment(a:LayoutAlignment) {
		this.alignment = a;
	}
	
	public function setPadding(p:Int) {
		this.padding = p;
	}
	
	public function addChildren(children:Array<DisplayObject> ) {
		for (child in children) {
			this.addChild(child);
		}
	}
	
}
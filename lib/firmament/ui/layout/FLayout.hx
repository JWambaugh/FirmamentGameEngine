package firmament.ui.layout;
import firmament.ui.FWidget;
import flash.display.DisplayObjectContainer;
import flash.display.DisplayObject;
import flash.display.Sprite;
import flash.events.Event;

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
 
class FLayout extends FWidget
{

	var padding:Int;
	var alignment:LayoutAlignment;
	var contentWidth:Int;
	var contentHeight:Int;
	var addingChildren:Bool;
	public function new(?children:Array<DisplayObject>=null) 
	{
		super();
		this.padding = 5;
		this.contentWidth = 0;
		this.contentHeight = 0;
		this.addingChildren = false;
		if (children != null) this.addChildren(children);
	}
	
	
	public function setAlignment(a:LayoutAlignment) {
		this.alignment = a;
	}
	
	public function setPadding(p:Int) {
		this.padding = p;
	}
	
	public function addChildren(children:Array<DisplayObject> ) {
		this.addingChildren = true;
		for (child in children) {
			this.addChild(child);
		}
		this.layoutChildren();
		this.addingChildren = false;
	}
	override public function addChild(child:DisplayObject):DisplayObject {
		
		super.addChild(child);
		child.addEventListener(FWidget.RESIZED,layoutChildrenEvent);
		//optimization. If we're inside a call to addChildren, don't layout yet.
		if(!this.addingChildren){
			this.layoutChildren();
		}
		return child;
	}
	override public function removeChild(child:DisplayObject):DisplayObject{
		super.removeChild(child);
		this.layoutChildren();
		return child;
	}
	private function layoutChildrenEvent(e:Event){
		layoutChildren();
	}
	public function layoutChildren() {
		this.dispatchEvent(new Event(FWidget.RESIZED));
	}
	
}
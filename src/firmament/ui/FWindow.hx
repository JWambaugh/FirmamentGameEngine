package firmament.ui;
import nme.display.DisplayObjectContainer;
import nme.display.Sprite;
import nme.events.Event;
import nme.events.MouseEvent;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FWindow extends Sprite
{

	var canvas:DisplayObjectContainer;
	var title:String;
	var canvasOffsetY:Int;
	var canvasOffsetX:Int;
	var titleLabel:FTextLabel;
	var titleBar:Sprite;
	
	var mouseOffsetX:Float;
	var mouseOffsetY:Float;
	
	var backgroundColor:Int;
	var titleColor:Int;
	var minimizeButton:FSmallButton;
	var closeButton:FSmallButton;
	var expandButton:FSmallButton;
	var expanded:Bool;
	public function new() 
	{
		super();
		trace('does trace work!!!');
		
		this.backgroundColor = 0xF0F0F0;
		this.titleColor = 0xCCDDFF;
		
		this.expanded = true;
		
		this.canvas = null;
		this.canvasOffsetY = 30;
		this.canvasOffsetX = 5;
		this.titleBar = new Sprite();
		this.titleBar.x = 1;
		this.titleBar.y = 1;
		
		closeButton = new FSmallButton("X",2,2);
		this.titleBar.addChild(closeButton);
		
		minimizeButton = new FSmallButton("-",17,2);
		minimizeButton.addEventListener(MouseEvent.CLICK, collapse);
		this.titleBar.addChild(minimizeButton);
		
		expandButton = new FSmallButton("+",17,2);
		expandButton.addEventListener(MouseEvent.CLICK, expand);
		expandButton.visible = false;
		this.titleBar.addChild(expandButton);
		
		
		this.addChild(this.titleBar);
		this.titleLabel = new FTextLabel("",30);
		this.titleBar.addChild(this.titleLabel);
		
		
		
		this.titleBar.addEventListener(MouseEvent.MOUSE_DOWN, this.onMouseDown);
		
		this.titleBar.addEventListener(MouseEvent.MOUSE_UP, this.onMouseUp );
		
		

		trace(this.width);
	}
	
	
	public function setTitle(t:String) {
		this.title = t;
		this.titleLabel.text = t;
	}
	
	public function setCanvas(c:DisplayObjectContainer) {
		if (this.canvas != null) {
			this.removeChild(this.canvas);
		}
		this.canvas = c;
		this.addChild(this.canvas);
		this.canvas.y = this.canvasOffsetY;
		this.canvas.x = this.canvasOffsetX;
		this.draw();
		this.canvas.addEventListener(Event.ADDED, this.draw);
	}
	
	public function drawTitleBar() {	
		this.titleBar.graphics.clear();
		this.titleBar.graphics.beginFill(this.titleColor);
		if(this.expanded){
			this.titleBar.graphics.drawRoundRect(0, 0, this.canvas.width + 13, 20, 10);
		}else {
			this.titleBar.graphics.drawRoundRect(0, 0, this.width-4, 20, 10);
		}
		this.titleBar.graphics.endFill();
	}
	
	public function drawWindow() {
		this.graphics.clear();
		this.graphics.beginFill(this.backgroundColor);
		this.graphics.lineStyle(2, 0x111111);
		if(this.expanded){
			this.graphics.drawRoundRect(0, 0, this.canvas.width+15, this.canvas.height+40,10);
		}else {
			this.graphics.drawRoundRect(0, 0, this.width+2, this.height+2,10);
		}
		this.graphics.endFill();
	}
	
	public function draw(?e:Event = null) {
		this.drawWindow();
		this.drawTitleBar();
		
	}
	
	public function onMouseDown(e:MouseEvent) {
		
		this.startDrag();
	}
	public function onMouseUp(e:MouseEvent) {
		
		this.stopDrag();
	}
	
	public function collapse(?e:MouseEvent) {
		this.expanded = false;
		this.removeChild(this.canvas);
		this.draw();
		this.minimizeButton.visible = false;
		this.expandButton.visible = true;
	}
	
	public function expand(?e:MouseEvent) {
		this.expanded = true;
		this.addChild(this.canvas);
		this.draw();
		this.minimizeButton.visible = true;
		this.expandButton.visible = false;
		
	}
	
	
}
package firmament.ui;
import nme.display.Sprite;
import nme.Lib;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FDialog 
{

	public static function alert(body:String, ?title="Alert") {
		var window:FWindow = new FWindow(true,false);
		window.setTitle(title);
		var canvas = new Sprite();
		var message = new FTextLabel(body);
		canvas.addChild(message);
		message.multiline = true;
		
		var closeButton = new FButton("Close",cast(message.textWidth /2-15), cast(message.textHeight+10) , window.close);
		
		canvas.addChild(closeButton);
		
		
		window.setCanvas(canvas);
		var stage = Lib.current.stage;
		stage.addChild(window);
		
		
		window.x = stage.stageWidth/2 - window.width / 2;
		window.y = stage.stageHeight/2 - window.height / 2;
		
		return window;
	}
	
}
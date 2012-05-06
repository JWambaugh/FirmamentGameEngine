package firmament.ui;
import nme.display.Sprite;
import nme.Lib;
import nme.events.MouseEvent;
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
	
	public static function prompt(body:String, onEnter:String->Void, ?title="Prompt",?text:String="") {
		var window:FWindow = new FWindow(true,false);
		window.setTitle(title);
		var canvas = new Sprite();
		var message = new FTextLabel(body);
		
		canvas.addChild(message);
		message.multiline = true;
		
		
		var input = new FLineEdit(text, cast(message.textWidth / 2 - 50), cast(message.textHeight + 10));
		canvas.addChild(input);
		
		var okButton = new FButton("Ok", cast(message.textWidth / 2 - 10), cast(message.textHeight + 40) , function(e:MouseEvent) {
			window.close();
			onEnter(input.text);
		});
		
		canvas.addChild(okButton);
		
		
		window.setCanvas(canvas);
		var stage = Lib.current.stage;
		stage.addChild(window);
		
		
		window.x = stage.stageWidth/2 - window.width / 2;
		window.y = stage.stageHeight/2 - window.height / 2;
		
		return window;
	}
}
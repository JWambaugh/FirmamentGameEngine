package firmament.ui;
import nme.text.TextField;
import nme.text.TextFormat;

/**
 * ...
 * @author Jordan Wambaugh
 */

class FTextField extends TextField
{

	public function new(?text:String="",?x:Int=0,?y:Int=0) 
	{
		super();
		this.text = text;
		this.x = x;
		this.y = y;
		var format = new TextFormat();
		format.font = 'helvetica';
		this.setTextFormat(format);
	}
	
}
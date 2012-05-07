package firmament.ui;
import nme.text.TextFieldType;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FLineEdit extends FTextField
{

	public function new(?text:String="",?x:Int=0,?y:Int=0) 
	{
		super(text,x,y);
		this.height = 20;
		this.type = TextFieldType.INPUT;
		this.border = true;
		this.backgroundColor = 0xFFFFFF;
		this.background = true;
	}
	
}
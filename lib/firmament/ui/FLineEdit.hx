package firmament.ui;
import flash.text.TextFieldType;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FLineEdit extends FTextField
{

	public function new(?text:String="",?x:Int=0,?y:Int=0,?width:Int=100) 
	{
		super(text,x,y,width);
		this.textField.height = 20;
		this.textField.type = TextFieldType.INPUT;
		this.textField.border = true;
		this.textField.backgroundColor = 0xFFFFFF;
		this.textField.background = true;
		
	}
	
}
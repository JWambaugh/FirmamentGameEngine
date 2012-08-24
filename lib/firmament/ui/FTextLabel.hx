package firmament.ui;

/**
 * ...
 * @author Jordan Wambaugh
 */

class FTextLabel extends FTextField
{

	public function new(?text:String="",?x:Int=0,?y:Int=0) 
	{
		super(text, x, y);
	//	this.height = 20;
		this.textField.selectable = false;
		if(text!=""){
			this.textField.width = this.textField.textWidth + 5;
			//this.height = this.textHeight + 5;
		}
	}
	
}

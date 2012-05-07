package firmament.ui;
import nme.display.Sprite;
import firmament.ui.layout.FHBox;
import nme.events.Event;
import nme.events.MouseEvent;

/**
 * ...
 * @author Jordan Wambaugh
 */

class FFloatEntry extends Sprite
{

	var valEdit:FLineEdit;
	var increment:Float;
	public static inline var VALUE_CHANGED="valueChanged";
	public function new(v:Float=0.0,?increment:Float=1.0) 
	{
		super();
		
		this.increment = increment;
		this.addChild(new FHBox([
				new FSmallButton("<", 0, 0, function(e:MouseEvent) { this.valEdit.text = Std.string(Std.parseFloat(this.valEdit.text)-increment); this.dispatchEvent(new Event(VALUE_CHANGED)); } )
				,valEdit = new FLineEdit(Std.string(v),0,0,30)
				,new FSmallButton(">", 0, 0, function(e:MouseEvent) { this.valEdit.text =Std.string(Std.parseFloat(this.valEdit.text)+increment); this.dispatchEvent(new Event(VALUE_CHANGED));})
			]));
		valEdit.addEventListener(Event.CHANGE, function(e:Event) {this.dispatchEvent(new Event(VALUE_CHANGED)); } );
	}
	
	public function setValue(v:Float) {
		this.valEdit.text = Std.string(v);
	}
	
	public function getValue():Float {
		if (this.valEdit.text == '') return 0;
		return Std.parseFloat(this.valEdit.text);
	}
		
		
}
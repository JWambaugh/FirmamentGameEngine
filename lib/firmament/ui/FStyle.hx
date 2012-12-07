package firmament.ui;
import nme.text.TextField;
import nme.text.TextFormat;
import nme.Assets;
import firmament.util.FMisc;





/**
 * ...
 * @author Jordan Wambaugh
 */

class FStyle
{

	static var global:Dynamic;
	static var classes:Dynamic;
		
	private static function init(){
		if(global == null){
			global = {
						
			
			};
			classes = {};
		}
	}


	private static function getClass(className:String){
		init();
		var o = Reflect.field(classes,className);
		if(o==null) {
			Reflect.setField(classes,className,{});	
			 o = Reflect.field(classes,className);
		}
		return o;
	}

	public static function getStyleObj(?classes:Array<String>=null):Dynamic{
		init();
		if(classes == null)classes = [];
		var o = Reflect.copy(global);
		for(cls in classes){
			var c=getClass(cls);
			FMisc.cloneInto(c,o);
		}
		return o;
	}

	public static function setStyleObj(cls:String,obj:Dynamic){
		init();

		if(cls=="")
			FMisc.cloneInto(obj,global);
		else
			FMisc.cloneInto(obj,getClass(cls));

	}

	public static function getStyleKey(key:String,?classes:Array<String>=null){
		var o = getStyleObj(classes);
		return Reflect.field(o,key);
	}
	
}




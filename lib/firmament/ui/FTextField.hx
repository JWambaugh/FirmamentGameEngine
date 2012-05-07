package firmament.ui;
import nme.text.TextField;
import nme.text.TextFormat;
import nme.Assets;
import firmament.ui.FStyle;
import firmament.ui.FStyleHelper;
/**
 * ...
 * @author Jordan Wambaugh
 */


class FTextField extends TextField
{

	public function new(?text:String="", ?x:Int=0, ?y:Int=0, ?width:Int=100, ?classes:Array<String>=null) 
	{
		super();
		var style =  FStyle.getStyleObj(classes);
		
		
		var format = new TextFormat (style.fontName,style.fontSize,style.fontColor,style.fontBold,style.fontItalic,style.fontUnderline,style.fontUrl,style.fontTarget,style.fontAlign,style.fontLeftMargin,style.fontRightMargin,style.fontIndent,style.fontLeading); 
		this.defaultTextFormat = format;
		
		this.text = text;
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = this.textHeight*FStyleHelper.get(style,'fontHeightMultiplier',1);
				
	}
	
}

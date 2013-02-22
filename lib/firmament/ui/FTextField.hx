package firmament.ui;
import nme.text.TextField;
import nme.text.TextFormat;
import nme.Assets;
import firmament.ui.FStyle;
import firmament.ui.FStyleHelper;
import nme.events.Event;
/**
 * ...
 * @author Jordan Wambaugh
 */


class FTextField extends FWidget
{
	public var textField:TextField;
	public var  text(getText,setText ):String;
	public var  textHeight(getTextHeight,null ):Float;
	public var  textWidth(getTextWidth , null):Float;
	public var multiline(getMultiline, setMultiline):Bool;
	
	public function new(?text:String="", ?x:Int=0, ?y:Int=0, ?width:Int=100, ?classes:Array<String>=null) 
	{
		super();
		this.textField = new TextField();
		this.addChild(textField);
		var style =  FStyle.getStyleObj(classes);
		
		var format = new TextFormat (style.fontName,style.fontSize,style.fontColor,style.fontBold,style.fontItalic,style.fontUnderline,style.fontUrl,style.fontTarget,style.fontAlign,style.fontLeftMargin,style.fontRightMargin,style.fontIndent,style.fontLeading); 
		this.textField.defaultTextFormat = format;
		
		this.textField.text = text;
		this.x = x;
		this.y = y;
		this.textField.width = width;
		this.textField.height = this.textField.textHeight*FStyleHelper.get(style,'fontHeightMultiplier',1)+FStyleHelper.get(style,'fontHeightAdd',1);
		textField.addEventListener(Event.CHANGE, function(e:Event) {this.dispatchEvent(e); } );
	}
	
	function getText():String { return textField.text; }
	function setText(t:String):String { return textField.text = t; }
	function getTextHeight() { return textField.textHeight; }
	function getTextWidth() { return textField.textWidth; }
	function getMultiline() { return textField.multiline; }
	function setMultiline(m:Bool):Bool { return textField.multiline = m; }
}

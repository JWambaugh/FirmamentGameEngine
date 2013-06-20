package firmament.ui;
import flash.text.TextField;
import flash.text.TextFormat;
import openfl.Assets;
import firmament.ui.FStyle;
import firmament.ui.FStyleHelper;
import flash.events.Event;
/**
 * ...
 * @author Jordan Wambaugh
 */


class FTextField extends FWidget
{
	public var textField:TextField;
	public var  text(get,set ):String;
	public var  textHeight(get,null ):Float;
	public var  textWidth(get , null):Float;
	public var multiline(get, set):Bool;
	
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
	
	function get_text():String { return textField.text; }
	function set_text(t:String):String { return textField.text = t; }
	function get_textHeight() { return textField.textHeight; }
	function get_textWidth() { return textField.textWidth; }
	function get_multiline() { return textField.multiline; }
	function set_multiline(m:Bool):Bool { return textField.multiline = m; }
}

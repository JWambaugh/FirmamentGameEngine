package firmament.core;



import nme.events.EventDispatcher;
import nme.events.Event;
import nme.events.MouseEvent;
import nme.events.KeyboardEvent;




class FInput{
	var observable:EventDispatcher;
	var pressedKeys:Array<Int>;
	var mainButtonPressed:Bool;
	var localX:Float;
	var localY:Float;
	var stageX:Float; 
	var stageY:Float;
	var keyStatus:Array<Bool>;
	var _keyMap:Dynamic;

	public function new(o:EventDispatcher){
		this.observable = o;
		this.localX = 0;
		this.localY = 0;
		this.stageX = 0;
		this.stageY = 0;
		this.keyStatus = new Array<Bool>();
		this.defineKeyMap();
		//initialize our array. there must be a better way to do this.
		for(i in 0...256){
			keyStatus.push(false);
		}

		o.addEventListener(MouseEvent.CLICK, this.mouseEvent);
		o.addEventListener(MouseEvent.MOUSE_MOVE, this.mouseEvent);
		o.addEventListener(KeyboardEvent.KEY_DOWN,this.keyboardEventDown);
		o.addEventListener(KeyboardEvent.KEY_UP,this.keyboardEventUp);
		
	}
	
	public function mouseEvent(e:MouseEvent) {
		this.localX = e.localX;
		this.localY = e.localY;
		this.stageX = e.stageX;
		this.stageY = e.stageY;
	}


	public function keyboardEventDown(e:KeyboardEvent) {
		this.keyStatus[e.keyCode] = true;
		//trace(e.keyCode);
	}
	public function keyboardEventUp(e:KeyboardEvent) {
		this.keyStatus[e.keyCode]=false;
	}

	
	public function getLocalX() {
		return localX;
	}
	
	public function getLocalY() {
		return localY;
	}
	
	public function getStageX() {
		return stageX;
	}
	
	public function getStageY() {
		return stageY;
	}


	public function isKeyPressed(keyCode:Int):Bool{
		if(keyCode<256 && keyCode >=0)
			return this.keyStatus[keyCode];
		throw "Invalid keycode";
	}

	public function isKeyNamePressed(keyName:String):Bool{
		return this.keyStatus[getKeyCode(keyName)];
	}

	public function getKeyCode(keyName:String):Int{
		return Reflect.field(_keyMap,keyName);
	}

	//Flash keymap. 
	//from http://people.uncw.edu/tompkinsj/112/FlashActionScript/keyCodes.htm
	#if(flash)
	public function defineKeyMap(){
		_keyMap = {
			"backspace"		:	8,
			"enter"			:	13,
			"shift"			:	16,
			"ctrl"			:	17,
			"alt"			:	18,
			"capslock"		:	20,
			"esc"			:	27,
			"space"			:	32,
			"0"				:	48,
			"1"				:	49,
			"2"				:	50,
			"3"				:	51,
			"4"				:	52,
			"5"				:	53,
			"6"				:	54,
			"7"				:	55,
			"8"				:	56,
			"9"				:	57,
			"a"				:	65,
			"b"				:	66,
			"c"				:	67,
			"d"				:	68,
			"e"				:	69,
			"f"				:	70,
			"g"				:	71,
			"h"				:	72,
			"i"				:	73,
			"j"				:	74,
			"k"				:	75,
			"l"				:	76,
			"m"				:	77,
			"n"				:	78,
			"o"				:	79,
			"p"				:	80,
			"q"				:	81,
			"r"				:	82,
			"s"				:	83,
			"t"				:	84,
			"u"				:	85,
			"v"				:	86,
			"w"				:	87,
			"x"				:	88,
			"y"				:	89,
			"z"				:	90,
			";"				:	186,
			"="				:	187,
			","				:	188,
			"-"				:	189,
			"."				:	190,
			"/"				:	191,
			"`"				:	192,
			"["				:	219,
			"\\"			:	220,
			"]"				:	221,
			"'"				:	222,
			")"				:	48,
			"!"				:	49,
			"@"				:	50,
			"#"				:	51,
			"$"				:	52,
			"%"				:	53,
			"^"				:	54,
			"&"				:	55,
			"*"				:	56,
			"("				:	57,
			"A"				:	65,
			"B"				:	66,
			"C"				:	67,
			"D"				:	68,
			"E"				:	69,
			"F"				:	70,
			"G"				:	71,
			"H"				:	72,
			"I"				:	73,
			"J"				:	74,
			"K"				:	75,
			"L"				:	76,
			"M"				:	77,
			"N"				:	78,
			"O"				:	79,
			"P"				:	80,
			"Q"				:	81,
			"R"				:	82,
			"S"				:	83,
			"T"				:	84,
			"U"				:	85,
			"V"				:	86,
			"W"				:	87,
			"X"				:	88,
			"Y"				:	89,
			"Z"				:	90,
			":"				:	186,
			"+"				:	187,
			"<"				:	188,
			"_"				:	189,
			">"				:	190,
			"?"				:	191,
			"~"				:	192,
			"{"				:	219,
			"|"				:	220,
			"}"				:	221,
			"'"				:	222,
			"numenter"		:	13,
			"num0"			:	96,
			"num1"			:	97,
			"num2"			:	98,
			"num3"			:	99,
			"num4"			:	100,
			"num5"			:	101,
			"num6"			:	102,
			"num7"			:	103,
			"num8"			:	104,
			"num9"			:	105,
			"num*"			:	106,
			"num+"			:	107,
			"num-"			:	109,
			"num."			:	110,
			"num/"			:	111,
			"PgUp"			:	33,
			"PgDown"		:	34,
			"End"			:	35,
			"Home"			:	36,
			"leftarrow"		:	37,
			"uparrow"		:	38,
			"rightarrow"	:	39,
			"downarrow"		:	40,
			"Ins"			:	45,
			"Delete"		:	46,
			"*"				:	106,
			"+"				:	107,
			"-"				:	109,
			"/"				:	111,
			"Pause"			:	19,
			"PageUp"		:	33,
			"PageDown"		:	34,
			"ScrollLock"	:	145,
			"left"			:	37,
			"up"			:	38,
			"right"			:	39,
			"down"			:	40,
			"F1"			:	112,
			"F2"			:	113,
			"F3"			:	114,
			"F4"			:	115,
			"F5"			:	116,
			"F6"			:	117,
			"F7"			:	118,
			"F8"			:	119,
			"F9"			:	120,
			"F10"			:	121,
			"F11"			:	122,
			"F12"			:	123
		};
	}
	#else
	//TODO: define CPP keymap
	public function defineKeyMap(){
		_keyMap = {};
	}
	#end



	
}




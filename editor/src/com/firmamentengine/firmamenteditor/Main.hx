package com.firmamentengine.firmamenteditor;

import nme.display.StageAlign;
import nme.display.StageScaleMode;
import nme.Lib;
import wx.Frame;
import wx.EventID;
import wx.Sizer;
import nme.events.Event;
import nme.events.MouseEvent;
/**
 * ...
 * @author Jordan Wambaugh
 */

class Main 
{
	

   var mFrame : wx.Frame;
   var mStage : wx.NMEStage;

   function new()
   {
      mFrame = wx.Frame.create(null,"NME Frame");
      var count = 0;

      var me = this;
      mFrame.onSize = function(evt) { me.layout(); evt.skip=true; }

      mStage = wx.NMEStage.create(mFrame,null,null,{width:300,height:300});

      var s = new nme.display.Sprite();
      var gfx = s.graphics;
      gfx.beginFill(0xff0000);
      gfx.drawCircle(100,100,100);
      mStage.stage.addChild(s);
      mStage.stage.frameRate = 10;
      mStage.stage.addChild( new nme.display.FPS(10,10) );
      s.addEventListener(MouseEvent.MOUSE_OVER, function(_) trace("Over!") );
      s.addEventListener(MouseEvent.MOUSE_DOWN, function(_) trace("Down!") );
      s.addEventListener(MouseEvent.MOUSE_UP, function(_) trace("Up!") );
      mStage.stage.addEventListener(MouseEvent.MOUSE_MOVE, function(e) trace("Move:" + e.localX+","+e.localY) );
      s.addEventListener(Event.ENTER_FRAME, function(_) s.x = (s.x+1) % 200 );

      var tf = new nme.text.TextField();
      tf.text = "Hello!";
      tf.type = nme.text.TextFieldType.INPUT;
      tf.x = 20;
      tf.y = 200;
      mStage.stage.addChild(tf);

	  
      wx.App.setTopWindow(mFrame);
      mFrame.shown = true;
   }

   function layout()
   {
      mStage.size = mFrame.clientSize;
   }

   public static function main()
   {
      wx.App.boot( function(){ new Main(); } );
   }
}
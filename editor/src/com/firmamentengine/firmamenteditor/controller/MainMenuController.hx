package com.firmamentengine.firmamenteditor.controller;

import haxe.ui.toolkit.core.*;
import haxe.ui.toolkit.core.XMLController;
import com.firmamentengine.firmamenteditor.ui.ToolBar;
import haxe.ui.toolkit.events.MenuEvent;

class MainMenuController extends XMLController {

	
	public function new() {
		var resourceId:String = "assets/mainMenuUI.xml";
		super(resourceId);

		attachEvent("menuMapButton", MenuEvent.SELECT, function(e:MenuEvent) {
				switch (e.menuItem.id) {
					case "loadButton":
						ToolBar.load();
					case "saveButton":
						ToolBar.save();
					default:
				}
			});
	}
}
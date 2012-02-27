class ApplicationMain
{
	
	public static function main()
	{
		nme.Lib.setPackage("Jordan Wambaugh", "Firmamenthx", "com.firmamentengine.firmament", "1.0.0");
		
		
		nme.display.Stage.shouldRotateInterface = function(orientation:Int):Bool
		{
			
			if (orientation == nme.display.Stage.OrientationLandscapeLeft || orientation == nme.display.Stage.OrientationLandscapeRight)
			{
				return true;
			}
			return false;
			
		}
		
		nme.Lib.create(function()
			{
				com.firmamentengine.firmament.Main.main();
			},
			800, 480,
			60,
			0xFFFFFF,
			(true ? nme.Lib.HARDWARE : 0) |
			(true ? nme.Lib.RESIZABLE : 0) |
			(1 == 4 ? nme.Lib.HW_AA_HIRES : 0) |
			(1 == 2 ? nme.Lib.HW_AA : 0),
			"Firmament.hx"
		);
		
	}
	
	
	public static function getAsset(inName:String):Dynamic
	{
		
		return null;
	}
	
}
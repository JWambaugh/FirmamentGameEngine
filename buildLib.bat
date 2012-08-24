set path="C:\Program Files\WinRAR\";%path%
del haxelib\*.zip
mkdir haxelib
mkdir haxelib\firmament
xcopy  lib\*.* haxelib\firmament /e /y
haxe -xml haxelib\firmament\haxedoc.xml bin\flash\haxe\debug.hxml
cd haxelib
winrar.exe a -afzip firmament.zip firmament
cd ..
cd tools
haxe -main Cli -neko run.n -cp ../lib -lib hxJson2 -lib nme
cd..
copy tools\run.n haxelib\firmament
xcopy tools\templates haxelib\firmament\templates\ /e /y
cd haxelib
haxelib test firmament.zip
cd ..

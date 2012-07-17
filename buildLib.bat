mkdir haxelib
mkdir haxelib\firmament
cp -r lib\* haxelib\firmament
haxe -xml haxelib\firmament\haxedoc.xml bin\flash\haxe\debug.hxml
zip -r firmament.zip haxelib\firmament
cd tools
haxe -main Cli -neko run.n -cp ../lib -lib hxJson2 -lib nme
cd..
copy tools\run.n haxelib\firmament

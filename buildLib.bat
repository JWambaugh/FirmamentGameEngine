mkdir haxelib
mkdir haxelib\firmament
cp haxelib.xml haxelib\firmament
cp -r src\firmament haxelib\firmament
haxe -xml haxelib\firmament\haxedoc.xml bin\flash\haxe\debug.hxml
zip -r firmament.zip haxelib\firmament
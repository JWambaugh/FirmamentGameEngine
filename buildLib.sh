rm -rf haxelib
mkdir haxelib
mkdir haxelib/firmament
cp -r lib/* haxelib/firmament
cd tools
haxe -main Cli -neko run.n -cp ../lib -lib hxJson2 -lib nme
cd ..
cp tools/run.n haxelib/firmament
cp -r tools/templates haxelib/firmament
#use xmlstarlet to filter the xml document file to only show firmament items
#./xml ed -d "//class[contains(@path,'firmament')=false]" -d "//typedef[contains(@path,'firmament')=false]" -d "//enum[contains(@path,'firmament')=false]" haxelib/firmament/haxedoc.xml.tmp > haxelib/firmament/haxedoc.xml
#rm  haxelib/firmament/haxedoc.xml.tmp 

#build the editor and package in haxelib

cd editor
nme build FirmamentEditor.nmml neko
cp bin/mac/neko/obj/ApplicationMain.n ../haxelib/firmament/FirmamentEditor.n
cp -r assets ../haxelib/firmament/
cd ..
cd haxelib
zip -r firmament.zip firmament
cd ..

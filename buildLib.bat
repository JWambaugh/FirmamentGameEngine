set path="C:\Program Files\WinRAR\";%path%
del haxelib\*.zip
mkdir haxelib
mkdir haxelib\firmament
xcopy  lib\*.* haxelib\firmament /e /y
cd tools
haxe -main Cli -neko run.n -cp ../lib -lib hxJson2 -lib nme
cd..
copy tools\run.n haxelib\firmament
xcopy tools\templates haxelib\firmament\templates\ /e /y

cd haxelib
winrar.exe a -afzip firmament.zip firmament
haxelib test firmament.zip
cd ..

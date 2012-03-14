haxe -xml docs.xml bin\flash\haxe\debug.hxml
chxdoc -o docs --includeOnly=com.firmamentengine.* docs.xml
del docs.xml
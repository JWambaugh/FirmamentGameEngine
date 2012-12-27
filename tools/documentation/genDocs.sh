rm -rf ../../docs/*
haxe documentationProject.hxml
./chxdoc -o ../../docs -f documentation.xml --config=chxdocConfig.xml

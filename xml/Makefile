CFLAGS	:=-g
tagter	:=XML_serv XML_cli
default:$(tagter)
XML_serv:
	buildserver -s XML -o XML_serv -f XML_serv.cpp -f -ltxml
XML_cli:
	buildclient -f XML_cli.cpp -o XML_cli -f -ltxml
install:
	cp XML_serv /home/tuxedo/tuxedo11gR1/app/
uninstall:
	-rm -rf /home/tuxedo/tuxedo11gR1/app/XML_serv 
clean:
	-rm -rf $(tagter) access.*
echo:
	echo TUXDIR:$(TUXDIR)
	echo tagter:$(tagter)
	echo CFLAGS:$(CFLAGS)
.PHONY:
	default clean install

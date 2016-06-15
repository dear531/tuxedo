CFLAGS	:=-g
tagter	:=XML_serv XML_cli
default:$(tagter)
	buildserver -s XML -o XML_serv -f XML_serv.cpp -f -ltxml
	buildclient -f XML_cli.cpp -o XML_cli -f -ltxml
install:
	cp XML_serv /home/oracle/tuxedo11gR1/app/
uninstall:
	-rm -rf /home/oracle/tuxedo11gR1/app/XML_serv 
clean:
	-rm -rf $(tagter) access.*
echo:
	echo TUXDIR:$(TUXDIR)
	echo tagter:$(tagter)
	echo CFLAGS:$(CFLAGS)
.PHONY:
	default clean install

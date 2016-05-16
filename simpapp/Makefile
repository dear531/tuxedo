tagter	:=simpserv simpcl wsimpcl
default:$(tagter)
	buildserver -o simpserv -f simpserv.c -s TOUPPER
	buildclient -o wsimpcl -f simpcl.c -w #workstation listener
	buildclient -o simpcl -f simpcl.c
install:
	cp simpserv /home/oracle/tuxedo11gR1/app/
uninstall:
	-rm -rf /home/oracle/tuxedo11gR1/app/simpserv
clean:
	-rm -rf $(tagter) access.*
echo:
	echo TUXDIR:$(TUXDIR)
	echo tagter:$(tagter)
.PHONY:
	default clean install

tagter	:=simpserv wsimpcl simpcl

default:$(tagter)
simpserv:simpserv.c
	buildserver -o simpserv -f simpserv.c -s TOUPPER
wsimpcl:simpcl.c
	buildclient -o wsimpcl -f simpcl.c -w #workstation listener
simpcl:simpcl.c
	buildclient -o simpcl -f simpcl.c
install:
	cp simpserv /home/tuxedo/tuxedo11gR1/app/
uninstall:
	-rm -rf /home/tuxedo/tuxedo11gR1/app/simpserv
clean:
	-rm -rf $(tagter) access.*
echo:
	echo TUXDIR:$(TUXDIR)
	echo tagter:$(tagter)
.PHONY:
	default clean install

tagter	:=simpserv simpcl wsimpcl CARRAY_serv CARRAY_cli
default:$(tagter)
	buildserver -o simpserv -f simpserv.c -s TOUPPER
	buildclient -o wsimpcl -f simpcl.c -w
	buildclient -o simpcl -f simpcl.c
	buildserver -o CARRAY_serv -f CARRAY_serv.c -s ARRAY_SERV
	buildclient -o CARRAY_cli -f CARRAY_cli.c
install:
	cp simpserv simpcl /home/oracle/tuxedo11gR1/app/
	cp CARRAY_serv serv.jpg /home/oracle/tuxedo11gR1/app/
uninstall:
	-rm -rf /home/oracle/tuxedo11gR1/app/simpcl
	-rm -rf /home/oracle/tuxedo11gR1/app/simpserv
	-rm -rf /home/oracle/tuxedo11gR1/app/CARRAY_serv
	-rm -rf /home/oracle/tuxedo11gR1/app/serv.jpg
clean:
	-rm -rf $(tagter) access.*
echo:
	echo TUXDIR:$(TUXDIR)
	echo tagter:$(tagter)
.PHONY:
	default clean install

default:simpserv simpcl
	/home/oracle/tuxedo11gR1/tux.env 
	buildserver -o simpserv -f simpserv.c -s TOUPPER
	buildclient -o simpcl -f simpcl.c
install:
	cp simpserv simpcl /home/oracle/tuxedo11gR1/bin/
uninstall:
	-rm -rf /home/oracle/tuxedo11gR1/bin/simpcl
	-rm -rf /home/oracle/tuxedo11gR1/bin/simpserv
clean:
	-rm -rf simpcl simpserv access.*
.PHONY:
	default clean install

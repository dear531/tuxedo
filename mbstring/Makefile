tagter	:=MBSTRING_serv MBSTRING_cli
default:$(tagter)
MBSTRING_serv:
	buildserver -f MBSTRING_serv.c -o MBSTRING_serv -s ECHO
MBSTRING_cli:
	buildclient -f MBSTRING_cli.c -o MBSTRING_cli
install:
	cp MBSTRING_serv /home/oracle/tuxedo11gR1/app/
uninstall:
	-rm -rf /home/oracle/tuxedo11gR1/app/MBSTRING_serv 
clean:
	-rm -rf $(tagter) access.*
echo:
	echo TUXDIR:$(TUXDIR)
	echo tagter:$(tagter)
.PHONY:
	default clean install

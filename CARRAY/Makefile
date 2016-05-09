tagter	:=CARRAY_serv CARRAY_cli
default:$(tagter)
	buildserver -o CARRAY_serv -f CARRAY_serv.c -s ARRAY_SERV
	buildclient -o CARRAY_cli -f CARRAY_cli.c
install:
	cp CARRAY_serv serv.jpg /home/oracle/tuxedo11gR1/app/
uninstall:
	-rm -rf /home/oracle/tuxedo11gR1/bin/CARRAY_serv
	-rm -rf /home/oracle/tuxedo11gR1/bin/serv.jpg
clean:
	-rm -rf $(tagter) access.*
echo:
	echo TUXDIR:$(TUXDIR)
	echo tagter:$(tagter)
.PHONY:
	default clean install

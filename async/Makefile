tagter	:=ASYNC_serv FML_cli
default:$(tagter)
	buildserver -f ASYNC_serv.c -o ASYNC_serv -s ASYNC
	buildclient -f ASYNC_cli.c -o ASYNC_cli
install:
	cp ASYNC_serv /home/oracle/tuxedo11gR1/app/
uninstall:
	-rm -rf /home/oracle/tuxedo11gR1/app/ASYNC_serv 
clean:
	-rm -rf $(tagter) access.*
echo:
	echo TUXDIR:$(TUXDIR)
	echo tagter:$(tagter)
.PHONY:
	default clean install

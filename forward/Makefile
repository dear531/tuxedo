tagter	:=forwarda forwardb forward_cli
default:$(tagter)
forwarda:
	buildserver -f forwarda.c -o forwarda -s FORWARD_A
forwardb:
	buildserver -f forwardb.c -o forwardb -s FORWARD_B
forward_cli:
	buildclient -f forward_cli.c -o forward_cli
install:
	-cp forwarda /home/oracle/tuxedo11gR1/app/
	-cp forwardb /home/oracle/tuxedo11gR1/app/
uninstall:
	-rm -rf /home/oracle/tuxedo11gR1/app/forwarda 
	-rm -rf /home/oracle/tuxedo11gR1/app/forwardb
clean:
	-rm -rf $(tagter) access.* a.out
echo:
	echo TUXDIR:$(TUXDIR)
	echo tagter:$(tagter)
.PHONY:
	default clean install

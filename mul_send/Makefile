CFLAGS  :=-g
tagter	:=CONV_serv CONV_cli
default:$(tagter)
	viewc32 -n -d /home/oracle/tuxedo11gR1/udataobj/ viewrecord.v 
	buildserver -f CONV_serv.c -o CONV_serv -s GETRECORDS
	buildclient -f CONV_cli.c -o CONV_cli
install:
	-cp CONV_serv customerinfo.data /home/oracle/tuxedo11gR1/app/
uninstall:
	-rm -rf /home/oracle/tuxedo11gR1/app/CONV_serv
	-rm -rf /home/oracle/tuxedo11gR1/app/customerinfo.data
clean:
	-rm -rf $(tagter) access.* a.out
echo:
	echo TUXDIR:$(TUXDIR)
	echo tagter:$(tagter)
.PHONY:
	default clean install

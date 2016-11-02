CFLAGS  :=-g
tagter	:=CONV_serv CONV_cli
default:$(tagter)
/home/oracle/tuxedo11gR1/udataobj/viewrecord.V:
	viewc32 -n -d /home/oracle/tuxedo11gR1/udataobj/ viewrecord.v 
CONV_serv:/home/oracle/tuxedo11gR1/udataobj/viewrecord.V
	buildserver -f CONV_serv.c -o CONV_serv -s GETRECORDS
CONV_cli:/home/oracle/tuxedo11gR1/udataobj/viewrecord.V
	buildclient -f CONV_cli.c -o CONV_cli
install:
	-cp CONV_serv customerinfo.data /home/oracle/tuxedo11gR1/app/
uninstall:
	-rm -rf /home/oracle/tuxedo11gR1/app/CONV_serv
	-rm -rf /home/oracle/tuxedo11gR1/app/customerinfo.data
clean:
	-rm -rf $(tagter) access.* a.out /home/oracle/tuxedo11gR1/udataobj/viewrecord.V viewrecord.h
echo:
	echo TUXDIR:$(TUXDIR)
	echo tagter:$(tagter)
.PHONY:
	default clean install

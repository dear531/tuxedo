CFLAGS  :=-g
tagter	:=NOTIFY_serv NOTIFY_cli
default:$(tagter)
NOTIFY_serv:
	buildserver -f NOTIFY_serv.c -o NOTIFY_serv -s NOTIFY
NOTIFY_cli:
	buildclient -f NOTIFY_cli.c -o NOTIFY_cli
install:
	-cp NOTIFY_serv /home/oracle/tuxedo11gR1/app/
uninstall:
	-rm -rf /home/oracle/tuxedo11gR1/app/NOTIFY_serv
clean:
	-rm -rf $(tagter) access.* a.out
echo:
	echo TUXDIR:$(TUXDIR)
	echo tagter:$(tagter)
.PHONY:
	default clean install

#1.tmshutdown -y
#2.make && make install
#3.tmboot -y
#4. ./emdeb_cli
tagter	:=emdeb_serv emdeb_cli
default:$(tagter)
emdeb_serv:
	buildserver -o emdeb_serv -f emdeb_serv.c -s EMDEB
emdeb_cli:
	buildclient -o emdeb_cli -f emdeb_cli.c
install:
	cp emdeb_serv /home/oracle/tuxedo11gR1/app/
uninstall:
	-rm -rf /home/oracle/tuxedo11gR1/app/emdeb_serv
	-rm -rf /home/oracle/tuxedo11gR1/app/friend.V
clean:
	-rm -rf $(tagter) access.*
echo:
	echo TUXDIR:$(TUXDIR)
	echo tagter:$(tagter)
	echo $(VPATH)
.PHONY:
	default clean install

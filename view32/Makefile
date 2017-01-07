#1.tmshutdown -y
#2.make && make install
#3.tmboot -y
#4. ./VIEW_cli
tagter	:=VIEW_serv VIEW_cli
default:$(tagter)
VIEW_serv:
	buildserver -o VIEW_serv -f VIEW_serv.c -s ADD_FRIEND
VIEW_cli:
	buildclient -o VIEW_cli -f VIEW_cli.c
install:
	cp VIEW_serv /home/tuxedo/tuxedo11gR1/app/
uninstall:
	-rm -rf /home/tuxedo/tuxedo11gR1/app/VIEW_serv
	-rm -rf /home/tuxedo/tuxedo11gR1/app/friend.V
clean:
	-rm -rf $(tagter) access.*
echo:
	echo TUXDIR:$(TUXDIR)
	echo tagter:$(tagter)
	echo $(VPATH)
.PHONY:
	default clean install

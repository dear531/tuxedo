tagter	:=VIEW_serv VIEW_cli
default:$(tagter)
	buildserver -o VIEW_serv -f VIEW_serv.c -s ADD_FRIEND
	buildclient -o VIEW_cli -f VIEW_cli.c
head_binary:
	#create current direct friend.h and $APPDIR binary friend.V
	viewc32 -n -y -d $$APPDIR friend.v
install:
	cp VIEW_serv /home/oracle/tuxedo11gR1/app/
uninstall:
	-rm -rf /home/oracle/tuxedo11gR1/bin/VIEW_serv
	-rm -rf /home/oracle/tuxedo11gR1/bin/friend.V
clean:
	-rm -rf $(tagter) access.*
echo:
	echo TUXDIR:$(TUXDIR)
	echo tagter:$(tagter)
	echo $(VPATH)
.PHONY:
	default clean install

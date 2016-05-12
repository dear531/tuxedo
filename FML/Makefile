tagter	:=FML_serv FML_cli
default:$(tagter)
	buildserver -f FML_serv.c -o FML_serv -s FML32
	buildclient -f FML_cli.c -o FML_cli
mkfmlh:
	mkfldhdr32 friend.fml
install:
	cp FML_serv /home/oracle/tuxedo11gR1/app/
uninstall:
	-rm -rf /home/oracle/tuxedo11gR1/app/FML_serv 
clean:
	-rm -rf $(tagter) access.*
echo:
	echo TUXDIR:$(TUXDIR)
	echo tagter:$(tagter)
.PHONY:
	default clean install

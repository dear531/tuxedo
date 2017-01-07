tagter	:=FML_serv FML_cli
default:$(tagter)
FML_serv:
	buildserver -f FML_serv.c -o FML_serv -s FML32
FML_cli:
	buildclient -f FML_cli.c -o FML_cli
install:
	cp FML_serv /home/tuxedo/tuxedo11gR1/app/
uninstall:
	-rm -rf /home/tuxedo/tuxedo11gR1/app/FML_serv 
clean:
	-rm -rf $(tagter) access.*
echo:
	echo TUXDIR:$(TUXDIR)
	echo tagter:$(tagter)
.PHONY:
	default clean install

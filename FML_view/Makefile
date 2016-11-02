tagter	:=FML_VIEW_serv FML_VIEW_cli
default:$(tagter)
FML_VIEW_serv:
	buildserver -o FML_VIEW_serv -f FML_VIEW_serv.c -s FVs
FML_VIEW_cli:
	buildclient -o FML_VIEW_cli -f FML_VIEW_cli.c
install:
	cp FML_VIEW_serv /home/oracle/tuxedo11gR1/app/
uninstall:
	-rm -rf /home/oracle/tuxedo11gR1/app/FML_VIEW_serv
clean:
	-rm -rf $(tagter) access.*
echo:
	echo TUXDIR:$(TUXDIR)
	echo tagter:$(tagter)
.PHONY:
	default clean install

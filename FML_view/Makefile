tagter	:=FML_VIEW_serv FML_VIEW_cli
default:$(tagter)
	buildserver -o FML_VIEW_serv -f FML_VIEW_serv.c -s FVs
	buildclient -o FML_VIEW_cli -f FML_VIEW_cli.c
fml_head:
	mkfldhdr32 friendfv.fml
head_binary:
	viewc32 -n -d $$APPDIR friendfv.v
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

tagter	:=mul sub var emdeb_cli
default:$(tagter)
	viewc32 -n -d $$TUXDIR/udataobj data.v
	buildserver -f mul.c -o mul -s MUL
	buildserver -f sub.c -o sub -s SUB
	buildserver -f var.c -o var -s VAR
	buildclient -f emdeb_cli.c -o emdeb_cli
install:
	-cp mul /home/oracle/tuxedo11gR1/app/
	-cp sub /home/oracle/tuxedo11gR1/app/
	-cp var /home/oracle/tuxedo11gR1/app/
uninstall:
	-rm -rf /home/oracle/tuxedo11gR1/app/mul 
	-rm -rf /home/oracle/tuxedo11gR1/app/sub
clean:
	-rm -rf $(tagter) access.*
echo:
	echo TUXDIR:$(TUXDIR)
	echo tagter:$(tagter)
.PHONY:
	default clean install

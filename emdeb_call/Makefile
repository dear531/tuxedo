tagter	:=mul sub var emdeb_cli
default:$(tagter)
/home/oracle/tuxedo11gR1/udataobj/data.V:
	viewc32 -n -d $$TUXDIR/udataobj data.v
mul:
	buildserver -f mul.c -o mul -s MUL
sub:
	buildserver -f sub.c -o sub -s SUB
var:
	buildserver -f var.c -o var -s VAR
emdeb_cli:
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

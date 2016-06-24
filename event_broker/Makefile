CFLAGS  :=-g
tagter	:=Subscriber Poster
default:$(tagter)
	viewc32 -n -d /home/oracle/tuxedo11gR1/udataobj/ stockdata.v
	buildclient -f Subscriber.c -o Subscriber
	buildclient -f Poster.c -o Poster
clean:
	-rm -rf $(tagter) access.* a.out
echo:
	echo TUXDIR:$(TUXDIR)
	echo tagter:$(tagter)
.PHONY:
	default clean install

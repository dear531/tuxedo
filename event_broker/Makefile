CFLAGS  :=-g
tagter	:=Subscriber Poster
default:$(tagter)
stockdata.h:
	viewc32 -n -d /home/oracle/tuxedo11gR1/udataobj/ stockdata.v
Subscriber:stockdata.h
	buildclient -f Subscriber.c -o Subscriber
Poster:stockdata.h
	buildclient -f Poster.c -o Poster
clean:
	-rm -rf $(tagter) access.* a.out stockdata.h
echo:
	echo TUXDIR:$(TUXDIR)
	echo tagter:$(tagter)
.PHONY:
	default clean install

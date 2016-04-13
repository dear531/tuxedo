#include <stdio.h>
#include <atmi.h>

#if defined(__STDC__) || defined(__cplusplus)
int main(int argc, char *argv[])
#else
main(argc, argv)
int argc;
char *argv[];
#endif
{
	char *sendbuf, *rcvbuf, *ptr;
	char *msg = "Tuxedo is powerful!";
	long sendlen, rcvlen;
	int ret;

	if (tpinit((TPINIT*)NULL) == -1) {
		(void)fprintf(stderr, "Tpinit failed\n");
		exit(EXIT_FAILURE);
	}
	if (argc != 2) {
		ptr = msg;
	} else {
		ptr = argv[1];
	}
	sendlen = (long)strlen(ptr);
	if ((sendbuf = (char *)tpalloc("STRING", NULL, sendlen+1)) == NULL) {
		(void)fprintf(stderr, "Error allocating buff send\n");
		tpfree(sendbuf);
		tpterm();
		exit(EXIT_FAILURE);
	}
	(void)strcpy(sendbuf, ptr);
	ret = tpcall("TOUPPER", (char *)sendbuf, 0,
			(char**)&rcvbuf, &rcvlen, 0);
	if (ret == -1) {
		(void)fprintf(stderr, "Can't send request to service TOUPPER\n");
		(void)fprintf(stderr, "Tperrno = %d\n", tperrno);
		fprintf(stderr, "tpcall error :%s\n",
				tpstrerror(tperrno));
		fprintf(stdout, "sendbuf :%s\n", sendbuf);
		fprintf(stdout, "rcvbuf :%s\n", rcvbuf);
		tpfree(sendbuf);
		tpfree(rcvbuf);
		tpterm();
		exit(EXIT_FAILURE);
	}
	(void)fprintf(stdout, "Original string is :%s\n", ptr);
	(void)fprintf(stdout, "Return string is :%s\n", rcvbuf);
	tpfree(sendbuf);
	tpfree(rcvbuf);
	tpterm();
	return 0;
}

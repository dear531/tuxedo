#include <stdio.h>
#include <atmi.h>
#include <string.h>

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
	long sendlen, rcvlen = 0;
	int ret;

	if (tpinit((TPINIT*)NULL) == -1) {
		(void)fprintf(stderr, "Tpinit failed\n");
		fprintf(stderr, "tpinit error :%s\n",
				tpstrerror(tperrno));
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
	if ((rcvbuf = (char *)tpalloc("STRING", NULL, sendlen+1)) == NULL) {
		(void)fprintf(stderr, "Error allocating buff send\n");
		tpfree(rcvbuf);
		tpterm();
		exit(EXIT_FAILURE);
	}
	(void)strcpy(sendbuf, ptr);
	char src[] = "TOUPPER";
	ret = tpcall(src, (char *)sendbuf, 0L, (char **)&rcvbuf, (long *)&rcvlen, 0L);
	if (ret == -1) {
		(void)fprintf(stderr, "Can't send request to service TOUPPER\n");
		(void)fprintf(stderr, "Tperrno = %d\n", tperrno);
		fprintf(stderr, "tpcall error :%s\n",
				tpstrerror(tperrno));
		tpfree(sendbuf);
		tpfree(rcvbuf);
		tpterm();
		exit(EXIT_FAILURE);
	}
	(void)fprintf(stdout, "Original string is :%s\n", ptr);
	(void)fprintf(stdout, "Return string is :%s\n", rcvbuf);
	if (NULL != sendbuf) {
		tpfree(sendbuf);
	}
	if (NULL != rcvbuf) {
		tpfree(rcvbuf);
	}
	tpterm();
	return 0;
}

#include <stdio.h>
#include <atmi.h>
#include <string.h>
#include <errno.h>

int
#if defined(__STDC__) || defined(__cplusplus)
main(int argc, char *argv[])
#else
main(argc, argv)
int argc;
char *argv[]
#endif
{
	char send_str[] = "abcd";
	char *send_buff = NULL;
	long sendlen = 0;
	long recvlen = 0;
	/* tpinit */
	if (-1 == tpinit((TPINIT *)NULL))
	{
		fprintf(stderr, "tpinit error -- %s\n", strerror(errno));
		goto failure;
	}
	sendlen = strlen(send_str) + 1;
	fprintf(stdout, "sendlen :%ld\n", sendlen);
	/* tpalloc */
	if (NULL == (send_buff = tpalloc("STRING", NULL, sendlen)))
	{
		fprintf(stderr, "tpalloc error -- %s\n", tpstrerror(tperrno));
		goto failure;
	}
	memcpy(send_buff, send_str, sendlen);
	/* tpcall */
#if 0
int tpcall(char *svc, char *idata, long ilen, char **odata, long 
	   *olen, long flags)
#endif
	if (-1 == tpcall("ECHO", send_buff, sendlen, &send_buff, &recvlen, 0))
	{
		fprintf(stderr, "tpcall error -- %s\n", tpstrerror(tperrno));
		goto failure;
	}
	fprintf(stdout, "send_buff :%s\n", send_buff);
failure:
	/* tpterm */
	if (NULL != send_buff)
		tpfree(send_buff);
	tpterm();
}

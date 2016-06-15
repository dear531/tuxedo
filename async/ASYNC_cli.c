#include <stdio.h>
#include <atmi.h>
#include <string.h>
#include <errno.h>
#include "public.h"

#define ARRAY_NUM	10

int
#if defined(__STDC__) || defined(__cplusplus)
main(int argc, char *argv[])
#else
main(argc, argv)
int argc;
char *argv[];
#endif
{
	int *send_buff = NULL;
	int *recv_buff = NULL;
	int i = 0, j = 0;
	int cd[ARRAY_NUM] = {0};
	int return_cd = 0;
	long recv_len = 0;
	/* tpinit */
	if (-1 == tpinit((TPINIT *)NULL))
	{
		fprintf(stderr, "tpinit error -- %s\n", tpstrerror(tperrno));
		goto failure;
	}
	/* tpalloc */
	send_buff = (int *)tpalloc("STRING", NULL, sizeof(*send_buff) * SYNC_MAX);
	recv_buff = (int *)tpalloc("STRING", NULL, sizeof(*recv_buff) * SYNC_MAX);
	if (NULL == send_buff || NULL == recv_buff)
	{
		fprintf(stderr, "tpalloc error -- %s\n", tpstrerror(tperrno));
		goto failure;
	}
	for (i = 0; ARRAY_NUM > i; i++)
	{
		/* tpacall */
#if 0
int tpacall(char *svc, char *data, long len, long flags)
#endif
		memset(send_buff, 0x00, sizeof(*send_buff) * SYNC_MAX);
#if 1
		for (j = 0; SYNC_MAX > j; j++)
		{
			send_buff[j] = i;
			fprintf(stdout, "send_buff[%d]:%d %p\n", j,
					send_buff[j], send_buff + j);
		}
#endif
		if (-1 == (cd[i] = tpacall("ASYNC", (char *)send_buff,
						sizeof(*send_buff), 0L)))
		{
			fprintf(stderr, "tpacall %d error -- %s\n", i, tpstrerror(tperrno));
			goto failure;
		}
	}
	for (i = 0; ARRAY_NUM > i; i++)
	{
		/* tpgetrply */
#if 0
int tpgetrply(int *cd, char **data, long *len, long flags)
#endif
		if (-1 == tpgetrply(&return_cd, (char **)&recv_buff, &recv_len, TPSIGRSTRT|TPGETANY))
		{
			fprintf(stderr, "tpgetrply error -- %s\n",
					tpstrerror(tperrno));
			goto failure;
		}
		for (j = 0; ARRAY_NUM > j; j++)
		{
			if (return_cd == cd[j])
			{
				fprintf(stdout, "async_data[%d] sum :%s\n", j, recv_buff);
				break;
			}
		}
	}
failure:
	/* tpfree */
	if (NULL != send_buff)
		tpfree((char *)send_buff);
	if (NULL != recv_buff)
		tpfree((char *)recv_buff);
	/* tpterm */
	tpterm();
}

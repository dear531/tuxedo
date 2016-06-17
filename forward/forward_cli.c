#include <stdio.h>
#include <atmi.h>

#include "public.h"

int
#if defined(__STDC__) || defined(__cplusplus)
main(int argc, char *argv[])
#else
main(argc, argv)
int argc;
char *argv[];
#endif
{
	char *data = NULL;
	long recvlen = 0;
	int i = 0;
	/* tpinit */
	if (-1 == tpinit((TPINIT *)NULL))
	{
		fprintf(stderr, "tpinit error -- %s\n", tpstrerror(tperrno));
		goto failure;
	}
	fprintf(stdout, "sizeof(*data) * array_num :%d\n", sizeof(*data) * ARRAY_NUM);
	/* tpalloc */
	if (NULL == (data = tpalloc("STRING", NULL, sizeof(*data) * ARRAY_NUM)))
	{
		fprintf(stderr, "tpalloc error -- %s\n", tpstrerror(tperrno));
		goto failure;
	}

	for (i = 0; ARRAY_NUM > i; i++)
	{
		data[i] = 'a' + i;
	}

	/* tpcall */
	if (-1 == tpcall("FORWARD_A", data, sizeof(*data) * ARRAY_NUM, &data, &recvlen, 0L))
	{
		fprintf(stderr, "tpcall error -- %s\n", tpstrerror(tperrno));
		goto failure;
	}
	for (i = 0; ARRAY_NUM > i; i++)
	{
		fprintf(stdout, "data[%d] :%c\n", i, data[i]);
	}
failure:
	/* tpfree */
	if (NULL != data)
		tpfree(data);
	/* tpterm */
	tpterm();
}

#include <atmi.h>
#include <stdio.h>
#include <string.h>
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
	struct emdeb_data *data = NULL;
	long recvlen = 0;
	/* tpinit */
#if 0
int tpinit(TPINIT *tpinfo)
#endif
	if (-1 == tpinit((TPINIT *)NULL))
	{
		fprintf(stderr, "tpint error -- %s\n", tpstrerror(tperrno));
		goto failure;
	}
	/* tpalloc */
#if 0
char * tpalloc(char *type, char *subtype, long size)
#endif
	if (NULL == (data = (struct emdeb_data *)tpalloc("VIEW32", "emdeb_data", sizeof(*data))))
	{
		fprintf(stderr, "tpalloc error -- %s\n", tpstrerror(tperrno));
		goto failure;
	}
	memset(data, 0x00, sizeof(*data));
	/* tpcall */
#if 0
int tpcall(char *svc, char *idata, long ilen, char **odata, long
		   *olen, long flags)
#endif
#if 0
	data->num1 = 3;
	data->num2 = 2;
	if (-1 == tpcall("SUB", (char *)data, (long)sizeof(*data), (char **)&data, &recvlen, 0L))
	{
		fprintf(stderr, "tpcall error -- %s\n", tpstrerror(tperrno));
		goto failure;
	}
	fprintf(stdout, "num1 %d + num2 %d = result %d\n",
			data->num1, data->num2, data->result);
	data->num1 = 3;
	data->num2 = 2;
	if (-1 == tpcall("MUL", (char *)data, (long)sizeof(*data), (char **)&data, &recvlen, 0L))
	{
		fprintf(stderr, "tpcall error -- %s\n", tpstrerror(tperrno));
		goto failure;
	}
	fprintf(stdout, "num1 %d + num2 %d = result %d\n",
			data->num1, data->num2, data->result);
#else
	data->num1 = 3;
	data->num2 = 2;
	if (-1 == tpcall("VAR", (char *)data, (long)sizeof(*data), (char **)&data, &recvlen, 0L))
	{
		fprintf(stderr, "tpcall error -- %s\n", tpstrerror(tperrno));
		goto failure;
	}
	fprintf(stdout, "%d*%d - %d*%d = %d\n",
			data->num1, data->num1, data->num2, data->num2, data->result);
#endif
failure:
	/* tpfree */
	if (NULL != data)
		tpfree((char *)data);
	/* tpterm */
	tpterm();
	return 0;
}

#include <stdio.h>
#include <atmi.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include "stockdata.h"

int
#if defined(__STDC__) || defined(__cplusplus)
main(int argc, char * argv[])
#else
main(argc, argv)
int argc;
char *argv[];
#endif
{
	struct stockdata *tradebuf = NULL;
	int i = 0;
	FILE *fp = NULL;
	char stocksymbol[5] = {0};
	int numofshares = 0;
	float pricepershare = 0.0;
	time_t currtime;
	char tradetime[15] = {0};
	char tmp[1024] = {0};

	/* tpinit */
	if (-1 == tpinit((TPINIT *)NULL))
	{
		fprintf(stderr, "tpinit error -- %s\n", tpstrerror(tperrno));
		goto failure;
	}
	/* tpalloc */
#if 0
char * tpalloc(char *type, char *subtype, long size)
#endif
	if (NULL == (tradebuf = (struct stockdata *)tpalloc("VIEW32", "stockdata", sizeof(*tradebuf))))
	{
		fprintf(stderr, "tpalloc error -- %s\n", tpstrerror(tperrno));
		goto failure;
	}
	/* fopen */
	if (NULL == (fp = fopen("stocktrades.data", "r")))
	{
		fprintf(stderr, "fopen error -- %s\n", strerror(errno));
		goto failure;
	}
	/* tppost */
	for (i = 0; 3 > i; i++)
	{
		memset(stocksymbol, 0x00, sizeof(stocksymbol));
		fscanf(fp, "%s%d%f", stocksymbol, &numofshares, &pricepershare);
#if 1
		fprintf(stdout, "%s, %d, %f\n", stocksymbol, numofshares, pricepershare);
#endif
#if 0
int tppost(char *eventname, char *data, long len, long flags)
#endif
		strcpy(tradebuf->stocksymbol, stocksymbol);
		tradebuf->numofshares = numofshares;
		tradebuf->pricepershare = pricepershare;
		currtime = time(NULL);
		memset(tradetime, 0x00, sizeof(tradetime));	
		strftime(tradetime, sizeof(tradetime), "%I:%M:%S %p", localtime(&currtime));
		strcpy(tradebuf->tradetime, tradetime);
#if 1
        fprintf(stdout, " stocksymbol :%s, tradetime :%s, numofshares :%d, pricepershare :%f\n",
                tradebuf->stocksymbol, tradebuf->tradetime, tradebuf->numofshares, tradebuf->pricepershare);
#endif
		if (-1 == tppost(stocksymbol, (char *)tradebuf, sizeof(*tradebuf), TPNOBLOCK))
		{
			fprintf(stderr, "tppost error -- %s\n", tpstrerror(tperrno));
			goto failure;
		}
		sleep(1);
	}
failure:
	/* fclose */
	if (NULL != fp)
		fclose(fp);
	/* tpfree */
	if (NULL != tradebuf)
		tpfree((char *)tradebuf);
	/* tpterm */
	tpterm();
}

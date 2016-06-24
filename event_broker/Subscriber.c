#include <atmi.h>
#include <string.h>
#include <errno.h>
#include "stockdata.h"

void unsolfunc(char *data, long len, long flags)
{
	struct stockdata *tradebuf = (struct stockdata *)data;
	if (NULL == data)
		return;
	fprintf(stdout, " stocksymbol :%s, tradetime :%s, numofshares :%d, pricepershare :%f\n",
		tradebuf->stocksymbol, tradebuf->tradetime, tradebuf->numofshares, tradebuf->pricepershare);
}
#if 0
void (*tpsetunsol (void (_TMDLLENTRY *)(*disp) (char *data, long len, long flags))) (char *data, long
		len, long flags)
#endif

int
#if defined(__STDC__) || defined(__cplusplus)
main(int argc, char *argv[])
#else
main(argc, argv)
int argc;
char *argv[];
#endif
{
	void (*unsolback)(char *, long, long);
	long sub_headle = 0;
	int i = 0;
	/* tpinit */
#if 0
int tpinit(TPINIT *tpinfo) 
#endif
	if (-1 == tpinit((TPINIT *)NULL))
	{
		fprintf(stderr, "tpinit error -- %s\n", tpstrerror(tperrno));
		goto failure;
	}
	/* tpsetunsol */
	if (TPUNSOLERR == (unsolback = tpsetunsol(unsolfunc)))
	{
		fprintf(stderr, "tpsetunsol error -- %s\n", tpstrerror(tperrno));
		goto failure;
	}
	/* tpsubscribe */
#if 0
long tpsubscribe(char *eventexpr, char *filter, TPEVCTL *ctl, long flags)
#endif
	if (-1 == (sub_headle = tpsubscribe(".*", NULL, NULL, TPSIGRSTRT)))
	{
		fprintf(stderr, "tpsubscribe error -- %s\n", tpstrerror(tperrno));
		goto failure;
	}
	/* tpchkunsol */
	for (i = 0; 50 > i; i++)
	{
		tpchkunsol();
		sleep(1);
	}
failure:
#if 0
int tpunsubscribe(long subscription, long flags)
#endif
	/* tpunsubscribe */
	if (-1 != sub_headle)
		tpunsubscribe(sub_headle, TPSIGRSTRT);
	/* tpterm */
	tpterm();
	/* restore backup unsol */
	tpsetunsol(unsolfunc);
	return 0;
}

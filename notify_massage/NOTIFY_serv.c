#include <atmi.h>
#include <userlog.h>
#include <string.h>

void
#if defined(__STDC__) || defined(__cplusplus)
NOTIFY(TPSVCINFO *rqst)
#else
NOTIFY(rqst)
TPSVCINFO *rqst;
#endif
{
	char *line = NULL;
	int ret = TPSUCCESS;
	int i = 0;
	if (NULL == (line = tpalloc("STRING", NULL, 80L)))
	{
		userlog("tpalloc error -- %s", tpstrerror(tperrno));
		ret = TPFAIL;
		goto failure;
	}
	for (i = 0; 10 > i; i++)
	{
		memset(line, 0x00, 80);
		sprintf(line, "notify %d", i);
#if 0
int tpnotify(CLIENTID *clientid, char *data, long len, long flags)
#endif
		tpnotify(&rqst->cltid, line, 80L, TPNOBLOCK);
	}
failure:
#if 0
void tpreturn(int rval, long rcode, char *data, long len, long flags) 
#endif
	tpreturn(ret, 0L, rqst->data, rqst->len, 0L);
}

#include <userlog.h>
#include <atmi.h>

void
#if defined(__STDC__) || defined(__cplusplus)
ECHO(TPSVCINFO *rqst)
#else
ECHO(rqst)
TPSVCINFO * rqst;
#endif
{
	char encode[20] = {0};
#if 0
tpgetmbenc (char *bufp, char *enc_name, long flags)
#endif
	tpgetmbenc(rqst->data, encode, 0L);
	tpconvmb(&rqst->data, (int *)&rqst->len, getenv("TPMBENC"), 0);
	tpreturn(TPSUCCESS, 0L, rqst->data, rqst->len, 0L);
}

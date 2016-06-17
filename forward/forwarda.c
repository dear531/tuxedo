#include <atmi.h>
#include <userlog.h>

#include "public.h"

int
#if defined(__STDC__) || defined(__cplusplus)
FORWARD_A(TPSVCINFO *rqst)
#else
FORWARD_A(rqst)
TPSVCINFO *rqst;
#endif
{
	int i = 0;
	for (i = 0; ARRAY_NUM > i; i++)
	{
		userlog("before ^ data[%d] :%c", i, rqst->data[i]);
		rqst->data[i] ^ 32;
		userlog("data[%d] :%c", i, rqst->data[i]);
	}
#if 0
void tpforward(char *svc, char *data, long len, long flags)
#endif
	tpforward("FORWARD_B", rqst->data, rqst->len, 0L);
}

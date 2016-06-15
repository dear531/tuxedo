#include <atmi.h>
#include <userlog.h>
#include <stdlib.h>
#include <string.h>
#include "public.h"

#if defined(__STDC__) || defined(__cplusplus)
ASYNC(TPSVCINFO *rqst)
#else
ASYNC(rqst)
TPSVCINFO *rqst;
#endif
{
#if 0
void tpreturn(int rval, long rcode, char *data, long len, long
		flags) 
#endif
	userlog("this is ASYNC_serv");
	int *data = (int *)rqst->data;
	int sum = 0, i = 0;
	sum = 0;
	for (i = 0; SYNC_MAX > i; i++)
	{
		sum += data[i];
		userlog("data[%d] :%d, %p", i, data[i], data + i);
	}
	userlog("sum :%d", sum);
	memset(rqst->data, 0x00, rqst->len);
	sprintf(rqst->data, "%d", sum);
	tpreturn(TPSUCCESS, 0L, rqst->data, rqst->len, 0L);
}

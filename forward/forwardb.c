#include <atmi.h>

#include "public.h"

int
#if defined(__STDC__) || defined(__cpulsplus)
FORWARD_B(TPSVCINFO *rqst)
#else
FORWARD_B(rqst)
TPSVCINFO *rqst;
#endif
{
	int i = 0, j = 0;
	char tmp = 0;
	for (i = 0; ARRAY_NUM - 1 > i; i++)
	{
		for (j = 0; ARRAY_NUM - 1 - i > j; j++)
		{
			if (rqst->data[j] < rqst->data[j + 1])
			{
				tmp = rqst->data[j];
				rqst->data[j] = rqst->data[j + 1];
				rqst->data[j + 1] = tmp;
			}
		}
	}
	for (i = 0; ARRAY_NUM > i; i++)
	{
		userlog("rqst->data[%d]:%c", i, rqst->data[i]);
	}
	tpreturn(TPSUCCESS, 0L, rqst->data, rqst->len, 0L);
}

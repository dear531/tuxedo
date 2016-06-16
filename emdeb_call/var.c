#include <atmi.h>
#include <userlog.h>
#include "public.h"

/* variance */
/* a*a - b*b */
int
#if defined(__STDC__) || defined(__cplusplus)
VAR(TPSVCINFO *rqst)
#else
VAR(rqst)
TPSVCINFO *rqst;
#endif
{
	struct emdeb_data data;
	struct emdeb_data *tmpdata;
	long recvlen = 0;
	int mul1 = 0, mul2 = 0;
	data = *(struct emdeb_data*)(rqst->data);
	tmpdata = (struct emdeb_data *)rqst->data;
	tmpdata->num1 = data.num1;
	tmpdata->num2 = data.num1;
	tmpdata->result = 0;
	if (-1 == tpcall("MUL", (char *)rqst->data, rqst->len, &rqst->data, &recvlen, 0L))
	{
		userlog("tpcall error -- %s", tpstrerror(tperrno));
		goto failure;
	}
	tmpdata = (struct emdeb_data *)rqst->data;
	mul1 = tmpdata->result;
	tmpdata->num1 = data.num2;
	tmpdata->num2 = data.num2;
	tmpdata->result = 0;
	if (-1 == tpcall("MUL", (char *)rqst->data, rqst->len, &rqst->data, &recvlen, 0L))
	{
		userlog("tpcall error -- %s", tpstrerror(tperrno));
		goto failure;
	}
	tmpdata = (struct emdeb_data *)rqst->data;
	mul2 = tmpdata->result;
	tmpdata->num1 = mul1;
	tmpdata->num2 = mul2;
	tmpdata->result = 0;
	if (-1 == tpcall("SUB", (char *)rqst->data, rqst->len, &rqst->data, &recvlen, 0L))
	{
		userlog("tpcall error -- %s", tpstrerror(tperrno));
		goto failure;
	}
	tmpdata = (struct emdeb_data *)rqst->data;
	tmpdata->num1 = data.num1;
	tmpdata->num2 = data.num2;
	tpreturn (TPSUCCESS, 0L, rqst->data, rqst->len, 0L);
failure:
	tpreturn (TPFAIL, 0L, rqst->data, rqst->len, 0L);
}

#include <atmi.h>
#include <userlog.h>
#include "public.h"

int
#if defined(__STDC__) || defined(__cplusplus)
MUL(TPSVCINFO *rqst)
#else
MUL(rqst)
tpsvcinfo *rqst;
#endif
{
	struct emdeb_data *data = (struct emdeb_data *)rqst->data;
	data->result = data->num1 * data->num2;
	tpreturn(TPSUCCESS, 0L, rqst->data, rqst->len, 0L);
}

#include <fml32.h>
#include <stdio.h>
#include <atmi.h>

#include "friend.fml.h"

int
#if defined(__STDC__) || defined(__cplusplus)
FML32(TPSVCINFO *rqst)
#else
FML32(rqst)
TPSVCINFO *rqst;
#endif
{
	userlog("welcome FML server");
#if 1
	long friend_id = 0;
	char fname[10] = {0};
	char fmobile[14] = {0};
	struct Fbfr32 *transb = (struct Fbfr32 *)rqst->data;
	friend_id = (long)Fvall32(transb, FRIEND_ID, 0);
	(void)Fget32(transb, FNAME, 0, fname, 0);
	(void)Fget32(transb, FMOBILE, 0, fmobile, 0);
	userlog("friend_id :%ld,fname :%s, fmobile:%s",
			friend_id, fname, fmobile);
#endif
	tpreturn(TPSUCCESS, 0, (char *)transb, 0L, 0);
}

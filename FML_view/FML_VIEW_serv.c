#include <atmi.h>
#include <userlog.h>
#include <fml32.h>
#include "friendfv.fml.h"

int
#if defined(__STDC__) || defined(__cplusplus)
FVs(TPSVCINFO *rqst)
#else
FVs(rqst)
TPSVCINFO *rqst;
#endif
{
	/* tpinit */
#if 0
extern int	_TMDLLENTRY tpinit _((TPINIT _TM_FAR *));
#endif
	tpinit((TPINIT *)NULL);
	struct Fbfr32 *fbfr = NULL;
	fbfr = (struct Fbfr32 *)rqst->data;
	long friend_id = 2;
	if (-1 == Fchg32(fbfr, FRIEND_ID, 0, (char *)&friend_id, sizeof(friend_id)))
	{
		userlog("Fchg32 error :%s Fstrerror32 :%s",
				tpstrerror(tperrno), Fstrerror32(Ferror32));
	}
	char fname[10] = {0};
	(void)Fget32(fbfr, FNAME, 0, fname, 0);
	userlog("file %s fname :%s", __FILE__, fname);
	/* tpreturn */
#if 0
extern void	_TMDLLENTRY tpreturn _((int, long, char *, long, long));
#endif
	userlog("this is %s", __func__);
	tpreturn(TPSUCCESS, 0L, (char *)fbfr, 0L, 0L);
}

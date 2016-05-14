#include <stdio.h>
#include <sqlcode.h>
#include <userlog.h>
#include <atmi.h>
#include "friend.h"

void
#if defined(_STDC__) || defined(__cplusplus)
ADD_FRIEND(TPSVCINFO *transb)
#else
ADD_FRIEND(transb)
TPSVCINFO *transb;
#endif
{
	struct friend *transv = NULL;
	transv = (struct friend*)transb->data;
#if 0
	friend_id = transv->friend_id;
	memcpy(fname, transv->fname);
	memcpy(fmobile, transv->fmobile);
#endif
	userlog("%s %s %d", __FILE__, __func__, __LINE__);
	userlog("mobile:%s name:%s id:%ld",
			transv->fmobile, transv->fname, transv->friend_id);
	transv->friend_id = 5L;
	tpreturn(TPSUCCESS, 0, transb->data, 0L, 0);
}

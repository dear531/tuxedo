#include <atmi.h>
#include <fml1632.h>
#include <friend.h>
#include <friendfml.h>

int
#if defined(__STDC__) || defined(__cplusplus)
TPSVRINIT(int argc, char *argv[])
#else
TPSVRINIT(argc, argv)
int argc;
char *argv[];
#endif
{
	userlog("welcome EMDEB server");
}

int
#if defined(__STDC__) || defined(__cplusplus)
EMDEB(TPSVCINFO *rqst)
#else
EMDEB(rqst)
TPSVCINFO *rqst;
#endif
{
	/* tpreturn */
	struct Fbfr32 *fbfr = (struct Fbfr32 *)rqst->data;
#if 0
Fget32(FBFR32 *fbfr, FLDID32 fieldid, FLDOCC32 oc, char *value,
		  FLDLEN32 *maxlen)
#endif
	FVIEWFLD fviewfld;
	FLDLEN32 len = 0;
	struct friend *friendvp = NULL;
	if (-1 == Fget32(fbfr, RECVIEW, 0, (char *)&fviewfld, &len))
	{
		userlog("Fget32 error :%s", Fstrerror32(Ferror32));
		goto failure;
	}
	userlog("fviewfld.vname :%s", fviewfld.vname);
	friendvp = (struct friend*)fviewfld.data;
	userlog("fviewfld.data->friend_id :%ld", friendvp->friend_id);
	userlog("friendvp->fname :%s", friendvp->fname);
	tpreturn(TPSUCCESS, 0L, rqst->data, 0L, 0L);
failure:
	tpreturn(TPFAIL, 0L, rqst->data, 0L, 0L);
}

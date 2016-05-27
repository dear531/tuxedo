#include <stdio.h>
#include <atmi.h>
#include <fml1632.h>
#include <string.h>
#include "friendfv.h"
#include "friendfv.fml.h"

int
#if defined(__STDC__) || defined(__cplusplus)
main(int argc, char *argv[])
#else
main(argc, argv)
int argc;
char *argv[];
#endif
{
	/* tpinit */
#if 0
extern int	_TMDLLENTRY tpinit _((TPINIT _TM_FAR *));
#endif
	tpinit((TPINIT *)NULL);
	/* tpalloc */
#if 0
extern char	_TM_FAR * _TMDLLENTRY tpalloc _((char _TM_FAR *, char _TM_FAR *, long));
#endif
	struct friendfv *friendfvp = NULL;
#if 0
friendp = (struct friend *)tpalloc("VIEW32", "friend", sizeof(*friendp))
#endif
	if (NULL == (friendfvp = (struct friendfv *)tpalloc("VIEW32", "friendfv", sizeof(*friendfvp))))
	{
		fprintf(stderr, "tpalloc error line:%d :%s\n",
				__LINE__, tpstrerror(tperrno));
		goto failure;
	}
	/* tpcall */
#if 0
int tpcall(char *svc, char *idata, long ilen, char **odata, long *olen, long flags)
#endif
	long rcv_len = 0;
	friendfvp->friend_id = 0L;
	memcpy(friendfvp->fname, "JQ", sizeof("JQ"));
	memcpy(friendfvp->fmobile, "13344445555", sizeof("13344445555"));

	struct Fbfr32 *fbfr = NULL;
#if 1
	if (NULL == (fbfr = (struct Fbfr32 *)tpalloc("FML32", NULL, 0)))
	{
		fprintf(stderr, "tpalloc error line :%d :%s\n",
				__LINE__, tpstrerror(tperrno));
		goto failure;
	}
#else
	if (NULL == (fbfr = (struct Fbfr32 *)Falloc32(1024, 1)))
	{
				F_error32("Falloc32 error");
		goto failure;
	}
#endif
#if 0
int Fvstof32(FBFR32 *fbfr, char *cstruct, int mode, char *view)
#endif
	if (-1 == Fvstof32(fbfr, (char *)friendfvp, FCONCAT, "friendfv"))
	{
		fprintf(stderr, "Fvstof32 error :%s\n", Fstrerror32(Ferror32));
		goto failure;
	}
	fprintf(stdout, "Fvstof32 friend_id :%ld, fname :%s, fmobile :%s\n",
			friendfvp->friend_id, friendfvp->fname, friendfvp->fmobile);
	char fname[10] = {0};
#if 0
	(void)Fget32(fbfr, FNAME, 0, fname, 0);
	fprintf(stdout, "Fadd32 and Fget32 fname :%s\n", fname);
	Fadd32(fbfr, FNAME, friendfvp->fname, sizeof(friendfvp->fname));
#endif
	Fprint32(fbfr);

	if (-1 == tpcall("FVs", (char *)fbfr, 0L, (char **)&fbfr, &rcv_len, 0L))
	{
		fprintf(stderr, "tpcall error :%s\n", tpstrerror(tperrno));
		goto failure;
	}

	memset(fname, 0x00, sizeof(fname));
	(void)Fget32(fbfr, FNAME, 0, fname, 0);
	fprintf(stdout, "tpcall and Fget32 fname :%s\n", fname);

	if (-1 == Fvftos32(fbfr, (char *)friendfvp, "friendfv"))
	{
		fprintf(stderr, "Fvftos32 error :%s\n", Fstrerror32(Ferror32));
		goto failure;
	}

	fprintf(stdout, "friend_id :%ld, fname :%s, fmobile :%s\n",
			friendfvp->friend_id, friendfvp->fname, friendfvp->fmobile);
failure:
	/* tpfree */
	if (NULL != friendfvp)
		tpfree((char *)friendfvp);
	if (NULL != fbfr)
		tpfree((char *)fbfr);
	/* tpterm */
	tpterm();
}

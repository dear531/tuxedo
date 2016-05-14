#include <stdio.h>
#include <atmi.h>
#include <string.h>
#include "friend.h"

int
#if defined (__STDC__) || (__cplusplus)
main(int argc, char *argv[])
#else
main(argc, argv)
int argc;
char *argv[];
#endif
{
	struct friend *friendp = NULL;
	/* tpinit */
#if 0
/* tpinit(3) interface structure */
struct	tpinfo_t {
	char	usrname[MAXTIDENT+2];	/* client user name */
	char	cltname[MAXTIDENT+2];	/* application client name */
	char	passwd[MAXTIDENT+2];	/* application password */
	char	grpname[MAXTIDENT+2];	/* client group name */
	long	flags;			/* initialization flags */
	long	datalen;		/* length of app specific data */
	long	data;			/* placeholder for app data */
};
typedef	struct	tpinfo_t TPINIT;
#endif
	if (-1 == tpinit((TPINIT *)NULL))
	{
		fprintf(stderr, "tpinit failure :%s\n",
				tpstrerror(tperrno));
		goto failure;
	}
	/* tpalloc */
#if 0
extern char	_TM_FAR * _TMDLLENTRY tpalloc _((char _TM_FAR *, char _TM_FAR *, long));
#endif
	if (NULL == (friendp = (struct friend *)tpalloc("VIEW32", "friend", sizeof(*friendp))))
	{
		fprintf(stderr, "tpalloc failure :%s\n",
				tpstrerror(tperrno));
		goto failure;
	}
	/* tpcall */
#if 0
extern int	_TMDLLENTRY tpcall _((char _TM_FAR *, char _TM_FAR *, long, char _TM_FAR * _TM_FAR *, long _TM_FAR *, long));
#endif
	friendp->friend_id = 1;
	memcpy(friendp->fname, "Snna", sizeof("Snna"));
	memcpy(friendp->fmobile, "13644445555", sizeof("13644445555"));
	long send_len = 0;
	fprintf(stdout, "before tpcall friendp->friend_id:%ld\n", friendp->friend_id);
	if (-1 == tpcall("ADD_FRIEND", (char *)friendp, sizeof(*friendp),
				(char **)&friendp, &send_len, 0))
	{
		fprintf(stderr, "tpcall failure :%s\n",
				tpstrerror(tperrno));
		goto failure;
	}
failure:
	fprintf(stdout, "after tpcall friendp->friend_id:%ld\n", friendp->friend_id);
	/* tpfree */
	if (NULL != friendp)
		tpfree((char *)friendp);
	/* tpterm */
	tpterm();
}

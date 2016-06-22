#include <atmi.h>
#include <stdio.h>
#include <string.h>

#if 0
void (*tpsetunsol (void (_TMDLLENTRY *)(*disp) (char *data, long len, long
				flags))) (char *data, long len, long flags)
#endif
void mynotify(char *data, long len, long flags)
{
	fprintf(stdout, "data %s\n", data);
}
int
#if defined(__STDC__) || defined(__cplusplus)
main(int argc, char *argv[])
#else
main(argc, argv)
int argc;
char *argv[];
#endif
{
#if 0
char * tpalloc(char *type, char *subtype, long size)
#endif
	TPINIT *tpinfop = NULL;
	char *recvbuf = NULL;
	long recvlen = 0;
	if (NULL == (tpinfop = (TPINIT *)tpalloc("TPINIT", NULL, sizeof(*tpinfop))))
	{
		fprintf(stderr, "tpalloc error -- %s\n", tpstrerror(tperrno));
		goto failure;
	}
	if (NULL == (recvbuf = tpalloc("STRING", NULL, 80L)))
	{
		fprintf(stderr, "tpalloc error -- %s\n", tpstrerror(tperrno));
		goto failure;
	}
#if 0
struct	tpinfo_t {
	char	usrname[MAXTIDENT+2];	/* client user name */
	char	cltname[MAXTIDENT+2];	/* application client name */
	char	passwd[MAXTIDENT+2];	/* application password */
	char	grpname[MAXTIDENT+2];	/* client group name */
	long	flags;			/* initialization flags */
	long	datalen;		/* length of app specific data */
	long	data;			/* placeholder for app data */
};
#endif
	memcpy(tpinfop->usrname, "JQ", sizeof("JQ"));
	memcpy(tpinfop->cltname, "TELLER", sizeof("TELLER"));
	tpinfop->flags = TPU_DIP;
	if (-1 == tpinit(tpinfop))
	{
		fprintf(stderr, "tpinit error -- %s\n", tpstrerror(tperrno));
		goto failure;
	}
#if 0
void (*tpsetunsol (void (_TMDLLENTRY *)(*disp) (char *data, long len, long
				flags))) (char *data, long len, long flags)
#endif
	if (TPUNSOLERR == tpsetunsol(mynotify))
	{
		fprintf(stderr, "tpsetunsol error -- %s\n", tpstrerror(tperrno));
		goto failure;
	}
#if 0
int tpcall(char *svc, char *idata, long ilen, char **odata, long
		   *olen, long flags)
#endif
	if (-1 == tpcall("NOTIFY", NULL, 0L, &recvbuf, &recvlen, 0L))
	{
		fprintf(stderr, "tpcall error -- %s\n", tpstrerror(tperrno));
		goto failure;
	}
failure:
	if (NULL != recvbuf)
		tpfree(recvbuf);
	if (NULL != tpinfop)
		tpfree((char *)tpinfop);
	tpterm();
}

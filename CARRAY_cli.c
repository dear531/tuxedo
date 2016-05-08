#include <stdio.h>
#include <atmi.h>

#if (__STDC__) || (__cplusplus)
	main(int argc, char *argv[])
#else
	main(argc, argv)
	int argc;
	char *argv[];
#endif
{
	char *bitmap = NULL;
	long rcv_len = 0;
	FILE *fp = NULL;
	long i = 0L;
#if 0
#define MAXTIDENT	30		/* max len of a /T identifier */
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
extern int      _TMDLLENTRY tpinit _((TPINIT _TM_FAR *));
#endif
	/* 1:tpinit */
	if (-1 == (tpinit((TPINIT*)NULL))) {
		fprintf(stderr, "tpinit failure %s\n", tpstrerror(tperrno));
		goto failure;
	}
#if 0
extern char     _TM_FAR * _TMDLLENTRY tpalloc _((char _TM_FAR *, char _TM_FAR *, long));
#endif
	if (NULL == (bitmap = tpalloc("CARRAY", NULL, 1024 * 1024)))
	{
#if 0
extern char 	_TM_FAR * _TMDLLENTRY tpstrerror _((int));
#endif
		fprintf(stderr, "tpalloc failure :%s\n", tpstrerror(tperrno));
		tpterm();
		goto failure;
	}
#if 0
extern int      _TMDLLENTRY tpcall _((char _TM_FAR *, char _TM_FAR *, long, char _TM_FAR *
			_TM_FAR *, long _TM_FAR *, long));

#endif
	if (-1 == tpcall("ARRAY_SERV", bitmap, 1024 * 1024, &bitmap, &rcv_len, 0L))
	{
		fprintf(stderr, "tpcall failure :%s\n", tpstrerror(tperrno));
		tpterm();
		goto failure;
	}
	if (NULL == (fp = fopen("cli.jpg", "w+")))
	{
		tpterm();
		goto failure;
	}
	for (i = 0; i < rcv_len; i++)
	{
		fputc(bitmap[i], fp);
	}
failure:
	if (NULL != fp)
		fclose(fp);
	if (NULL != bitmap)
		tpfree(bitmap);
}

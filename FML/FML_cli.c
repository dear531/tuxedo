#include <fml32.h>
#include <atmi.h>
#include <string.h>
#include <friendfml.h>

int
#if defined(__STDC__) || defined(__cplusplus)
main(int arg, char *argv[])
#else
main(argc, argv)
int argc;
char *argv[];
#endif
{
	/* tpinit */
	if (-1 == tpinit((TPINIT *)NULL))
	{
		fprintf(stderr, "tpinit failure :%s\n",
				tpstrerror(tperrno));
		goto failure;
	}
	/* tpalloc */
	FBFR32 *fbfr = NULL;
	if (NULL == (fbfr = (FBFR32 *)tpalloc("FML32", NULL, 0L)))
	{
		fprintf(stderr, "tpalloc failure :%s\n",
				tpstrerror(tperrno));
		goto failure;
	}
#if 0
int Fadd32(FBFR32 *fbfr, FLDID32 fieldid, char *value, FLDLEN32 len)
#endif
	long fid = 2L;
	Fadd32((FBFR32 *)fbfr, FRIEND_ID, (char *)&fid, (FLDLEN32)0);

	char buff[32] = {0};
	memcpy(buff, "JQ", sizeof("JQ"));
	Fadd32((FBFR32 *)fbfr, FNAME, (char *)buff, (FLDLEN32)0);
	memset(buff, 0x00, sizeof("JQ"));
	memcpy(buff, "13677778888", sizeof("13677778888"));
	Fadd32((FBFR32 *)fbfr, FMOBILE, (char *)buff, (FLDLEN32)0);
	memset(buff, 0x00, sizeof("13677778888"));

	/* tpcall */
#if 0
int tpcall(char *svc, char *idata, long ilen, char **odata, long
		   *olen, long flags)
#endif

	long rcv_len = 0;
	if (-1 == tpcall("FML32", (char *)fbfr, 0L, (char **)&fbfr, &rcv_len, 0L))
	{
		fprintf(stderr, "tpcall failure :%s\n",
				tpstrerror(tperrno));
		goto failure;
	}
	(void)Fget32(fbfr, FRIEND_ID, 0, (char *)&fid, 0);
	fprintf(stdout, "fid :%ld\n", fid);
	char fname[10] = {0};
	(void)Fget32(fbfr, FNAME, 0, fname, 0);
	fprintf(stdout, "fname :%s\n", fname);
	char fmobile[14] = {0};
	(void)Fget32(fbfr, FMOBILE, 0, fmobile, 0);
	fprintf(stdout, "fmobile :%s\n", fmobile);
failure:
	/* tpfree */
	if (NULL != fbfr)
		tpfree((char *)fbfr);
	/* tpterm */
	tpterm();
}

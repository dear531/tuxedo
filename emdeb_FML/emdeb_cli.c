#include <atmi.h>
#include <fml1632.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <friend.h>
#include <friendfml.h>

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
	struct Fbfr32 *fbfr = NULL, *fbfrin = NULL;
	struct friend *friendvp = NULL;
	char *bitmap = NULL;
	FILE *fp = NULL;
	int i = 0;
	int len = 0;
	long rcvbflen = 0;
	FVIEWFLD fviewfld;
	if (-1 == tpinit((TPINIT*)NULL))
	{
		fprintf(stderr, "tpinit error :%s\n",
				tpstrerror(tperrno));
		goto failure;
	}
	/* tpalloc */
	if (NULL == (fbfrin = (struct Fbfr32 *)tpalloc("FML32", NULL, 0)))
	{
		fprintf(stderr, "tpalloc error :%s\n",
				tpstrerror(tperrno));
		goto failure;
	}
	if (NULL == (friendvp = (struct friend *)tpalloc("VIEW32", "friend", sizeof(*friendvp))))
	{
		fprintf(stdout, "tpalloc error :%s\n",
				tpstrerror(tperrno));
		goto failure;
	}
	friendvp->friend_id = 0L;
	memcpy(friendvp->fname, "JQ", sizeof("JQ"));
	memcpy(friendvp->fmobile, "133xxxx5555", sizeof("133xxxx5555"));
	if (-1 == Fvstof32(fbfrin, (char *)friendvp, FCONCAT, "friend"))
	{
		fprintf(stderr, "Fvstof32 error :%s\n",
				Fstrerror32(Ferror32));
		goto failure;
	}
	Fprint(fbfrin);
	if (NULL == (fp = fopen("bitmap.jpg", "r")))
	{
		fprintf(stderr, "fopen error :%s\n", strerror(errno));
		goto failure;
	}
	if (-1 == fseek(fp, 0, SEEK_END))
	{
		fprintf(stderr, "fseek error :%s\n",
				strerror(errno));
	}
	len = ftell(fp) + 1;
	fseek(fp, 0, SEEK_SET);
	if (0 >= len)
		len = 1024 * 1024;

	if (NULL == (bitmap = tpalloc("CARRAY", NULL, len)))
	{
		fprintf(stderr, "tpalloc error :%s\n",
				tpstrerror(tperrno));
		goto failure;
	}
	i = 0;
	while (0 == feof(fp))
	{
		bitmap[i++] = fgetc(fp);
	}
	if (NULL == (fbfr = (struct Fbfr32 *)tpalloc("FML32", NULL, 2 * 1024 * 1024)))
	{
		fprintf(stderr, "tpalloc error :%s\n",
				tpstrerror(tperrno));
		goto failure;
	}
#if 1
	if (-1 == Fadd32(fbfr, PHOTO, (char *)bitmap, i-1))
	{
		fprintf(stderr, "Fadd32 error :%s\n",
				Fstrerror32(Ferror32));
		goto failure;
	}
#endif
	if (-1 == Fadd32(fbfr, RECFML, (char *)fbfrin, Fsizeof32(fbfr)))
	{
		fprintf(stderr, "Fadd32 error :%s\n",
				Fstrerror32(Ferror32));
		goto failure;
	}
	fviewfld.data = (char *)friendvp;
	memcpy(fviewfld.vname, "friend", sizeof("friend"));
	
	if (-1 == Fadd32(fbfr, RECVIEW, (char *)&fviewfld, sizeof(*friendvp)))
	{
		fprintf(stderr, "%s %d Fadd32 error :%s\n",
				__FILE__, __LINE__, Fstrerror32(Ferror32));
		goto failure;
	}
	Fprint(fbfr);
	if (-1 == tpcall("EMDEB", (char *)fbfr, Fsizeof(fbfr), (char **)&fbfr, (long *)&rcvbflen, 0L))
	{
		fprintf(stderr, "tpcalll error :%s\n",
				tpstrerror(tperrno));
		goto failure;
	}
	
	/* tpcall */
failure:
	if (NULL != fbfr)
		tpfree((char *)fbfr);
	if (NULL != fbfrin)
		tpfree((char *)fbfrin);
	if (NULL != friendvp)
		tpfree((char *)friendvp);
	if (NULL != fp)
		fclose(fp);
	/* tpterm */
	tpterm();
}

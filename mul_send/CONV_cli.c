#include <atmi.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "viewrecord.h"

int
#if defined(__STDC__) || defined(__cplusplus)
main(int argc, char *argv[])
#else
main(argc, argv)
int argc;
char *argv[];
#endif
{
	int cd = 0;
	struct viewrecord *recordp = NULL;
	long recvlen = 0, revent = 0;
	int count = 0;
	tpinit((TPINIT *)NULL);
	/* tpconnect */
#if 0
int tpconnect(char *svc, char *data, long len, long flags)
#endif
	if (-1 == (cd = tpconnect("GETRECORDS", (char *)NULL, 0L, TPRECVONLY|TPSIGRSTRT)))
	{
		fprintf(stderr, "tpconnect error -- %s\n", tpstrerror(tperrno));
		goto failure;
	}
#if 0
char * tpalloc(char *type, char *subtype, long size)
#endif
	if (NULL == (recordp = (struct viewrecord *)tpalloc("VIEW32", "viewrecord", sizeof(*recordp))))
	{
		fprintf(stderr, "tpalloc error -- %s\n", tpstrerror(tperrno));
		goto failure;
	}
#if 0
int tprecv(int cd, char **data, long *len, long flags, long 
		   *revent)
#endif
	count = 0;
	while (-1 != tprecv(cd, (char **)&recordp, &recvlen, TPSIGRSTRT, &revent))
	{
		fprintf(stdout, "f_name:%s\n", recordp->f_name);
		fprintf(stdout, "l_name:%s\n", recordp->l_name);
		fprintf(stdout, "address:%s\n", recordp->address);
		fprintf(stdout, "city:%s\n", recordp->city);
		fprintf(stdout, "state:%s\n", recordp->state);
		fprintf(stdout, "zipcode:%s\n", recordp->zipcode);
		memset(recordp, 0x00, sizeof(*recordp));
		fprintf(stdout, "count :%d\n", count++);
	}
#if 0
	if (TPSUCCESS == tperrno && TPEV_SVCSUCC == revent)
	{
		tpdiscon(cd);
		goto failure;
	}
#endif
failure:
	/* tpterm */
	tpterm();
}

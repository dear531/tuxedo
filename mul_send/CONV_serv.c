#include <atmi.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <userlog.h>
#include "viewrecord.h"

#define MXSTR	80

static struct viewrecord *bufptr = NULL;
int
#if defined(__STDC__) || defined(cpulsplus)
tpsvrinit(int argc, char *argv[])
#else
tpsvrinit(argc, argv)
int argc;
char *argv[];
#endif
{
	userlog("tpsvrinit");
	if (NULL == (bufptr = (struct viewrecord *)tpalloc("VIEW32", "viewrecord", (long)sizeof(*bufptr))))
	{
		userlog("tpinit error -- %s", tpstrerror(tperrno));
		return -1;
	}
	return 0;
}

#define file	"customerinfo.data"
void
#if defined(__STDC__) || defined(cpulsplus)
GETRECORDS(TPSVCINFO *msg)
#else
GETRECORDS(msg)
TPSVCINFO *msg;
#endif
{
	userlog("this is %s", __func__);
	FILE *fp = NULL;
	long ret = TPSUCCESS;
	int cd = 0;
	char input[sizeof(struct viewrecord) + 1] = {0};
	cd = msg->cd;
	long revnt = 0;
	/* fopen */
	if (NULL == (fp = fopen(file, "r")))
	{
		userlog("fopen error -- %s\n", strerror(errno));
		goto failure;
		ret = TPFAIL;
	}
	/* tpsend */
	while (NULL != fgets(input, sizeof(input), fp))
	{
		strcpy(bufptr->f_name, strtok(input, "\t"));
		strcpy(bufptr->l_name, strtok(NULL, "\t"));
		strcpy(bufptr->address, strtok(NULL, "\t"));
		strcpy(bufptr->city, strtok(NULL, "\t"));
		strcpy(bufptr->state, strtok(NULL, "\t"));
		strcpy(bufptr->zipcode, strtok(NULL, "\n"));
#if 0
int tpsend(int cd, char *data, long len, long flags, long *revent)
#endif
		if (-1 == tpsend(cd, (char *)bufptr, sizeof(*bufptr), TPSIGRSTRT, &revnt))
		{
			userlog("tpsend error -- %s", tpstrerror(errno));
			ret = TPFAIL;
			goto failure;
		}
#if 0
		userlog("f_name:%s", bufptr->f_name);
		userlog("l_name:%s", bufptr->l_name);
		userlog("address:%s", bufptr->address);
		userlog("city:%s", bufptr->city);
		userlog("state:%s", bufptr->state);
		userlog("zipcode:%s", bufptr->zipcode);
#endif
	}
failure:
	/* fclose */
	if (NULL != fp)
		fclose(fp);
	/* tpreturn */
	tpreturn(ret, 0L, NULL, 0L, 0L);
}

void tpsvrdone(void)
{
	userlog("tpsvrdone");
	if (NULL != bufptr)
	{
		tpfree((char *)bufptr);
		bufptr = NULL;
	}
}

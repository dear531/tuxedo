#include <stdio.h>
#include <ctype.h>
#include <atmi.h>
#include <userlog.h>

#if 0
struct tpsvcinfo {
#define XATMI_SERVICE_NAME_LENGTH  128
	char	name[XATMI_SERVICE_NAME_LENGTH];/* service name invoked */
	long	flags;		/* describes service attributes */
	char	*data;		/* pointer to data */
	long	len;		/* request data length */
	int	cd;		/* connection descriptor */
	long	appkey;		/* application authentication client key */
	CLIENTID cltid;		/* client identifier for originating client */
};
typedef struct tpsvcinfo TPSVCINFO;
#endif
void
#if defined (__STDC__) || (__cplusplus)
ARRAY_SERV(TPSVCINFO *rqst)
#else
ARRAY_SERV(rqst)
TPSVCINFO *rqst;
#endif
{
	long i = 0L;
	FILE *fp = NULL;
	int flags = 0;
	if (NULL == (fp = fopen("serv.jpg", "r")))
	{
		userlog("fopoen failure :%s\n", tpstrerror(tperrno));
		flags = TPFAIL;
		goto failure;
	}
	else
	{
		for (i = 0; 0 == feof(fp); i++)
		{
			rqst->data[i] = fgetc(fp);
		}
		flags = TPSUCCESS;
	}
failure:
	if (NULL != fp)
		fclose(fp);
#if 0
extern void     _TMDLLENTRY tpreturn _((int, long, char *, long, long));
#endif
	tpreturn(flags, 0, rqst->data, (long)i, 0);
}

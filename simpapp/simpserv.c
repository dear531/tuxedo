#include <stdio.h>
#include <ctype.h>
#include <atmi.h>
#include <userlog.h>

#if defined(__STDC__) || defined(__cplusplus)
	tpsvrinit(int argc, char *argv[])
#else
	tpsvrinit(argc, argv)
	int argc;
	char **argv;
#endif
{
	argc = argc;
	argv = argv;
	userlog("Welcome to the simple server");
	return 0;
}
#ifdef __cplusplus
	extern "C"
#endif
#if defined(__STDC__) || defined(__cplusplus)
	void TOUPPER(TPSVCINFO *rqst)
#else
	void TOUPPER(rqst)
	TPSVCINFO *rqst;
#endif
{
	int i;
	for (i = 0; i < rqst->len - 1; i++)
		rqst->data[i] = toupper(rqst->data[i]);
	userlog("client accpet");
	tpreturn(TPSUCCESS, 0, rqst->data, 0L, 0);
}

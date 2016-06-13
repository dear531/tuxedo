#include <atmi.h>
#include <userlog.h>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/framework/MemBufInputSource.hpp>

using namespace xercesc;
using namespace std;

#ifdef __cplusplus
extern "C"
#endif
int
#if defined(__STDC__) || defined(__cplusplus)
XML(TPSVCINFO *rqst)
#else
XML(rqst)
TPSVCINFO *rqst;
#endif
{
	XMLPlatformUtils::Initialize();
	tpreturn(TPSUCCESS, 0L, (char *)rqst->data, 0L, 0L);
}

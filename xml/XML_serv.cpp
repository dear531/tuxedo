#include <atmi.h>
#include <userlog.h>
#include <xercesc/framework/MemBufInputSource.hpp>
#include <xercesc/dom/deprecated/DOM_NodeList.hpp>
#include <xercesc/dom/deprecated/DOM_Document.hpp>
#include <xercesc/dom/deprecated/DOMParser.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/deprecated/DOM_Node.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <string.h>
#include <errno.h>

using namespace xercesc;
using namespace std;

char *localbuff = (char *)NULL;
static const char *bufId = "mybuf";
static long friend_id = 0;
static char fname[10] = {0};
static char fmobile[14] = {0};

int SubTree(DOM_Node node)
{
	userlog("this func %s", __func__);
	DOM_NodeList children = node.getChildNodes();
	for (int i = 0; i < children.getLength(); i++)
	{
		DOM_Node nod = children.item(i);
		if (nod.getNodeType() == DOM_Node::ELEMENT_NODE)
		{
			if (nod.getNodeName().equals("friend_id"))
			friend_id = atol(nod.getFirstChild().getNodeValue().transcode());
			else if (nod.getNodeName().equals("fname"))
			strcpy(fname, nod.getFirstChild().getNodeValue().transcode());
			else if (nod.getNodeName().equals("fmobile"))
			{
				strcpy(fmobile, nod.getFirstChild().getNodeValue().transcode());
				userlog("friend_id :%ld, fname :%s, fmobile :%s",
						friend_id, fname, fmobile);
			}
		}
	}
	return 0;
}

int TopTree(DOM_Node node)
{
	userlog("this func %s", __func__);
	if (node.getNodeType() == DOM_Node::ELEMENT_NODE)
	{
		if (node.getNodeName().equals("friend"))
		{
			SubTree(node);
		}
		else
		{
			DOM_NodeList children = node.getChildNodes();
			for (int i = 0; i < children.getLength(); i++)
				TopTree(children.item(i));
		}
		userlog("node.getNodeName :%s", node.getNodeValue());
	}
	return 0;
}

int parseXMLBuffer(char **xmlbuf)
{
	userlog("this func %s", __func__);
	int errorCount;
	if (NULL == (localbuff = (char *)malloc(sizeof(char *) * 2048)))
	{
		userlog("malloc error :%s", strerror(errno));
		return -1;
	}
	XMLPlatformUtils::Initialize();
	
	MemBufInputSource *memBufIS =
		new MemBufInputSource((const XMLByte *)*xmlbuf,
				strlen(*xmlbuf) - 1, bufId, true);
	if (NULL == memBufIS)
	{
		userlog("MemBufInputSource error :%s", strerror(errno));
		return -1;
	}
	DOMParser *parser = new DOMParser;
	if (NULL == parser)
	{
		userlog("DOMParser error :%s", strerror(errno));
		return -1;
	}
	parser->parse(*memBufIS);
	if ((errorCount = parser->getErrorCount()) == 0)
	{
		DOM_Document document = parser->getDocument();
		DOM_Element topLevel = document.getDocumentElement();
		TopTree(topLevel);
	}
	else
	{
		userlog("errorCount :%d", errorCount);
		userlog("error constain: %s", strerror(errno));
	}
	delete parser;
	//delete memBufIS;
	return 0;
}


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
	/* XMLPlatformUtils::Initialize(); */
	parseXMLBuffer(&rqst->data);
	tpreturn(TPSUCCESS, 0L, (char *)rqst->data, rqst->len, 0L);
}

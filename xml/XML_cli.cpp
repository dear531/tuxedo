#include <stdio.h>
#include <atmi.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define XML_LEN 2048
#define filename	"cli.xml"

using namespace std;

int
#if defined(__STDC__) || defined(__cplusplus)
main(int argc, char *argv[])
#else
main(argc, argv)
int argc;
char *argv[];
#endif
{
	FILE *fp = NULL;
	char *xml_buff = NULL;
	char *send_buff = NULL;
	int n = 0;
	long recv_len = 0;
	/* tpinit */
	if (-1 == tpinit((TPINIT *)NULL))
	{
		fprintf(stderr, "tpinit error :%s\n", tpstrerror(tperrno));
		goto failure;
	}
	if (NULL == (xml_buff = (char *)malloc(sizeof(char) * XML_LEN)))
	{
		fprintf(stderr, "malloc error :%s\n", strerror(errno));
		goto failure;
	}
	if (NULL == (fp = fopen(filename, "r")))
	{
		fprintf(stderr, "fopen error :%s\n", strerror(errno));
		goto failure;
	}
#if 0
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
#endif
	if (0 > (n = fread((void *)xml_buff, sizeof(char), XML_LEN, fp)))
	{
		fprintf(stderr, "fread error :%s\n", strerror(errno));
		goto failure;
	}
	/* tpalloc */
	if (NULL == (send_buff = tpalloc((char *)"XML", NULL, n + 1)))
	{
		fprintf(stderr, "tpalloc error :%s\n", tpstrerror(tperrno));
		goto failure;
	}
	memcpy(send_buff, xml_buff, n);
	fprintf(stdout, "send_buff :%s\n", send_buff);
	if (-1 == tpcall("XML", send_buff, n, &send_buff, &recv_len, 0))
	{
		fprintf(stderr, "tpcall error :%s\n", tpstrerror(tperrno));
		goto failure;
	}
	/* tpcall */
failure:
	if (NULL != xml_buff)
		free(xml_buff);
	if (NULL != fp)
		fclose(fp);
	if (NULL != send_buff)
		tpfree(send_buff);
	/* tpterm */
	tpterm();
}

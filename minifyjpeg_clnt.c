/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "minifyjpeg.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

FileTransfer *
getfile_1(FileTransfer arg1,  CLIENT *clnt)
{
	static FileTransfer clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));

	enum clnt_stat CallValue = clnt_call (clnt, GetFile,
			(xdrproc_t) xdr_FileTransfer, (caddr_t) &arg1,
			(xdrproc_t) xdr_FileTransfer, (caddr_t) &clnt_res,
			TIMEOUT);

	if (CallValue == RPC_TIMEDOUT)
		exit(124);

	if (CallValue != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

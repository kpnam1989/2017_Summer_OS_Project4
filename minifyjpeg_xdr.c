/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "minifyjpeg.h"

bool_t
xdr_FileTransfer (XDR *xdrs, FileTransfer *objp)
{
	register int32_t *buf;

	 if (!xdr_bytes (xdrs, (char **)&objp->fileHandler.fileHandler_val, (u_int *) &objp->fileHandler.fileHandler_len, 600000))
		 return FALSE;
	return TRUE;
}

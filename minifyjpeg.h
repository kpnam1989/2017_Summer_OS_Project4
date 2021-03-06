/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _MINIFYJPEG_H_RPCGEN
#define _MINIFYJPEG_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct FileTransfer {
	struct {
		u_int fileHandler_len;
		char *fileHandler_val;
	} fileHandler;
};
typedef struct FileTransfer FileTransfer;

#define MINIFYJPEG_PROG 0x31234568
#define MINIFYJPEG_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define GetFile 1
extern  FileTransfer * getfile_1(FileTransfer , CLIENT *);
extern  FileTransfer * getfile_1_svc(FileTransfer , struct svc_req *);
extern int minifyjpeg_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define GetFile 1
extern  FileTransfer * getfile_1();
extern  FileTransfer * getfile_1_svc();
extern int minifyjpeg_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_FileTransfer (XDR *, FileTransfer*);

#else /* K&R C */
extern bool_t xdr_FileTransfer ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_MINIFYJPEG_H_RPCGEN */

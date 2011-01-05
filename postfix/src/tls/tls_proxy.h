#ifndef _TLS_PROXY_H_INCLUDED_
#define _TLS_PROXY_H_INCLUDED_

/*++
/* NAME
/*	tls_proxy_clnt 3h
/* SUMMARY
/*	postscreen TLS proxy support
/* SYNOPSIS
/*	#include <tls_proxy_clnt.h>
/* DESCRIPTION
/* .nf

 /*
  * Utility library.
  */
#include <vstream.h>
#include <attr.h>

 /*
  * TLS library.
  */
#include <tls.h>

 /*
  * External interface.
  */
#define TLSPROXY_SERVICE		"tlsproxy"

#define TLS_PROXY_FLAG_ROLE_SERVER	(1<<0)	/* request server role */
#define TLS_PROXY_FLAG_ROLE_CLIENT	(1<<1)	/* request client role */
#define TLS_PROXY_FLAG_SEND_CONTEXT	(1<<2)	/* send TLS context */

#ifdef USE_TLS

extern VSTREAM *tls_proxy_open(int, VSTREAM *, const char *,
			               const char *, int);
extern TLS_SESS_STATE *tls_proxy_state_receive(VSTREAM *);
extern void tls_proxy_state_free(TLS_SESS_STATE *);
extern int tls_proxy_print_state(ATTR_SCAN_MASTER_FN, VSTREAM *, int, void *);
extern int tls_proxy_scan_state(ATTR_SCAN_MASTER_FN, VSTREAM *, int, void *);

#endif

/* LICENSE
/* .ad
/* .fi
/*	The Secure Mailer license must be distributed with this software.
/* AUTHOR(S)
/*	Wietse Venema
/*	IBM T.J. Watson Research
/*	P.O. Box 704
/*	Yorktown Heights, NY 10598, USA
/*--*/

#endif

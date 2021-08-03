/**
 * Summary: library of generic URI related routines
 * Description: library of generic URI related routines
 *              Implements RFC 2396
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */
#ifdef __checkedc
#pragma CHECKED_SCOPE push
#pragma CHECKED_SCOPE off
#endif

#include_next <uri.h>

#ifdef __checkedc
#pragma CHECKED_SCOPE pop
#endif

#ifdef __checkedc
#ifndef __XML_URI_CHECKED_H__
#define __XML_URI_CHECKED_H__

#pragma CHECKED_SCOPE push
#pragma CHECKED_SCOPE on

#include <xmlversion.h>
#include <tree.h>


/**
 * xmlURI:
 *
 * A parsed URI reference. This is a struct containing the various fields
 * as described in RFC 2396 but separated for further processing.
 *
 * Note: query is a deprecated field which is incorrectly unescaped.
 * query_raw takes precedence over query if the former is set.
 * See: http://mail.gnome.org/archives/xml/2007-April/thread.html#00127
 */
typedef struct _xmlURI xmlURI;
typedef xmlURI *xmlURIPtr;
struct _xmlURI {
    char *scheme : itype(_Nt_array_ptr<char>);	/* the URI scheme */
    char *opaque : itype(_Nt_array_ptr<char>);	/* opaque part */
    char *authority : itype(_Nt_array_ptr<char>);	/* the authority part */
    char *server : itype(_Nt_array_ptr<char>);	/* the server part */
    char *user : itype(_Nt_array_ptr<char>);		/* the user part */
    int port;		/* the port number */
    char *path : itype(_Nt_array_ptr<char>);		/* the path string */
    char *query : itype(_Nt_array_ptr<char>);	/* the query string (deprecated - use with caution) */
    char *fragment : itype(_Nt_array_ptr<char>);	/* the fragment identifier */
    int  cleanup;	/* parsing potentially unclean URI */
    char *query_raw : itype(_Nt_array_ptr<char>);	/* the query string (as it appears in the URI) */
};

/*
 * This function is in tree.h:
 * xmlChar *	xmlNodeGetBase	(xmlDocPtr doc,
 *                               xmlNodePtr cur);
 */
XMLPUBFUN xmlURIPtr XMLCALL
		xmlCreateURI		(void);
XMLPUBFUN xmlChar * XMLCALL
		xmlBuildURI		(const xmlChar *URI : itype(_Nt_array_ptr<const xmlChar>),
					 const xmlChar *base : itype(_Nt_array_ptr<const xmlChar>)) : itype(_Nt_array_ptr<xmlChar>);
XMLPUBFUN xmlChar * XMLCALL
		xmlBuildRelativeURI	(const xmlChar *URI : itype(_Nt_array_ptr<const xmlChar>),
					 const xmlChar *base : itype(_Nt_array_ptr<const xmlCHar>)) : itype(_Nt_array_ptr<xmlChar>);
XMLPUBFUN xmlURIPtr XMLCALL
		xmlParseURI		(const char *str : itype(_Nt_array_ptr<const char>));
XMLPUBFUN xmlURIPtr XMLCALL
		xmlParseURIRaw		(const char *str : itype(_Nt_array_ptr<const char>),
					 int raw);
XMLPUBFUN int XMLCALL
		xmlParseURIReference	(xmlURIPtr uri,
					 const char *str : itype(_Nt_array_ptr<const char>));
XMLPUBFUN xmlChar * XMLCALL
		xmlSaveUri		(xmlURIPtr uri : itype(_Ptr<xmlURI>) : itype(_Nt_array_ptr<xmlChar>);
XMLPUBFUN void XMLCALL
		xmlPrintURI		(FILE *stream : itype(_Ptr<FILE>),
					 xmlURIPtr uri : itype(_Ptr<xmlURI>));
XMLPUBFUN xmlChar * XMLCALL
		xmlURIEscapeStr         (const xmlChar *str : itype(_Nt_array_ptr<const xmlChar>),
					 const xmlChar *list : itype(_Nt_array_ptr<const xmlChar>)) : itype(_Nt_array_ptr<xmlChar>);
XMLPUBFUN char * XMLCALL
		xmlURIUnescapeString	(const char *str : itype(_Nt_array_ptr<const char>),
					 int len,
					 char *target : itype(_Nt_array_ptr<char>)) : itype(_Nt_array_ptr<char>);
XMLPUBFUN int XMLCALL
		xmlNormalizeURIPath	(char *path : itype(_Nt_array_ptr<char>));
XMLPUBFUN xmlChar * XMLCALL
		xmlURIEscape		(const xmlChar *str : itype(_Nt_array_ptr<const xmlChar>)) : itype(_Nt_array_ptr<xmlChar>);
XMLPUBFUN void XMLCALL
		xmlFreeURI		(xmlURIPtr uri : itype(_Ptr<xmlURI>));
XMLPUBFUN xmlChar* XMLCALL
		xmlCanonicPath		(const xmlChar *path : itype(_Nt_array_ptr<const xmlChar>)) : itype(_Nt_array_ptr<xmlChar>);
XMLPUBFUN xmlChar* XMLCALL
		xmlPathToURI		(const xmlChar *path : itype(_Nt_array_ptr<const xmlChar>)) : itype(_Nt_array_ptr<xmlChar>);

#pragma CHECKED_SCOPE pop

#endif /* __XML_URI_H__ */
#endif /* checkedc */

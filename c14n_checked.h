/*
 * Summary: Provide Canonical XML and Exclusive XML Canonicalization
 * Description: the c14n modules provides a
 *
 * "Canonical XML" implementation
 * http://www.w3.org/TR/xml-c14n
 *
 * and an
 *
 * "Exclusive XML Canonicalization" implementation
 * http://www.w3.org/TR/xml-exc-c14n

 * Copy: See Copyright for the status of this software.
 *
 * Author: Aleksey Sanin <aleksey@aleksey.com>
 */
#ifdef __checkedc
#pragma CHECKED_SCOPE push
#pragma CHECKED_SCOPE off
#endif

#include_next <c14n.h>

#ifdef __checkedc
#pragma CHECKED_SCOPE pop
#endif

#ifdef __checkedc
#ifndef __XML_C14N__CHECKED_H__
#define __XML_C14N_CHECKED_H__
#ifdef LIBXML_C14N_ENABLED
#ifdef LIBXML_OUTPUT_ENABLED

#include <xmlversion.h>
#include <tree.h>
#include <xpath.h>

/*
 * XML Canonicalization
 * http://www.w3.org/TR/xml-c14n
 *
 * Exclusive XML Canonicalization
 * http://www.w3.org/TR/xml-exc-c14n
 *
 * Canonical form of an XML document could be created if and only if
 *  a) default attributes (if any) are added to all nodes
 *  b) all character and parsed entity references are resolved
 * In order to achieve this in libxml2 the document MUST be loaded with
 * following global settings:
 *
 *    xmlLoadExtDtdDefaultValue = XML_DETECT_IDS | XML_COMPLETE_ATTRS;
 *    xmlSubstituteEntitiesDefault(1);
 *
 * or corresponding parser context setting:
 *    xmlParserCtxtPtr ctxt;
 *
 *    ...
 *    ctxt->loadsubset = XML_DETECT_IDS | XML_COMPLETE_ATTRS;
 *    ctxt->replaceEntities = 1;
 *    ...
 */

/*
 * xmlC14NMode:
 *
 * Predefined values for C14N modes
 *
 */
#pragma CHECKED_SCOPE push
#pragma CHECKED_SCOPE on

typedef enum {
    XML_C14N_1_0            = 0,    /* Original C14N 1.0 spec */
    XML_C14N_EXCLUSIVE_1_0  = 1,    /* Exclusive C14N 1.0 spec */
    XML_C14N_1_1            = 2     /* C14N 1.1 spec */
} xmlC14NMode;

XMLPUBFUN int XMLCALL
		xmlC14NDocSaveTo	(xmlDocPtr doc,
					 xmlNodeSetPtr nodes,
					 int mode, /* a xmlC14NMode */
					 xmlChar **inclusive_ns_prefixes : itype(_Array_ptr<_Ptr<xmlChar>>),
					 int with_comments,
					 xmlOutputBufferPtr buf);

XMLPUBFUN int XMLCALL
		xmlC14NDocDumpMemory	(xmlDocPtr doc,
					 xmlNodeSetPtr nodes,
					 int mode, /* a xmlC14NMode */
					 xmlChar **inclusive_ns_prefixes : itype(_Array_ptr<_Ptr<xmlChar>>),
					 int with_comments,
					 xmlChar **doc_txt_ptr : itype(_Array_ptr<_Ptr<xmlChar>>));

XMLPUBFUN int XMLCALL
		xmlC14NDocSave		(xmlDocPtr doc,
					 xmlNodeSetPtr nodes,
					 int mode, /* a xmlC14NMode */
					 xmlChar **inclusive_ns_prefixes : itype(_Array_ptr<_Ptr<xmlChar>>),
					 int with_comments,
					 const char* filenamei : itype(_Ptr<const char>),
					 int compression);


/**
 * This is the core C14N function
 */
/**
 * xmlC14NIsVisibleCallback:
 * @user_data: user data
 * @node: the current node
 * @parent: the parent node
 *
 * Signature for a C14N callback on visible nodes
 *
 * Returns 1 if the node should be included
 */
typedef int (*xmlC14NIsVisibleCallback)	(void* user_data,
					 xmlNodePtr node,
					 xmlNodePtr parent);

XMLPUBFUN int XMLCALL
		xmlC14NExecute		(xmlDocPtr doc,
					 xmlC14NIsVisibleCallback is_visible_callback,
					 _Itype_for_any(T) void* user_data : itype(_Ptr<T>),
					 int mode, /* a xmlC14NMode */
					 xmlChar **inclusive_ns_prefixes : itype(_Array_ptr<_Ptr<xmlChar>>),
					 int with_comments,
					 xmlOutputBufferPtr buf);

#pragma CHECKED_SCOPE pop

#endif /* LIBXML_OUTPUT_ENABLED */
#endif /* LIBXML_C14N_ENABLED */
#endif /* __XML_C14N_H__ */
#endif /* checkedc */

#if HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include "markover.h"

/* Simple constructor to set up the object. */
static mko_doc *new_doc(int flags) {
    mko_doc *ret = calloc(sizeof(mko_doc), 1);
    if ( ret ) {
        ret->flags = flags;
        return ret;
    }
    return 0;
}

/* Simple destructor to free up the object. */
void mko_destroy( mko_doc *doc) {
    free(doc);
}

/* Does the work of parsing the document and returning the new object. */
mko_doc *mko_parse( FILE *read_from, int flags ) {
    printf("parse the read_from file here\n");
    mko_doc *ret = new_doc(flags);
    return ret;
}

/* Standard shortcut function. */
void markover( FILE *read_from, FILE *write_to, int flags ) {
    mko_to_html(mko_parse(read_from, flags), write_to );
}

/* Method to output HTML. */
void mko_to_html( mko_doc *doc, FILE *write_to ) {
    fprintf( write_to, "Send HTML to write_to here\n");
}

/* Method to output man format. */
void mko_to_man( mko_doc *doc, FILE *write_to ) {
    fprintf( write_to, "Send man to write_to here\n");
}


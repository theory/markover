#if HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include "markover.h"

void mko_parse( mko_doc *doc, FILE *read_from, int flags ) {
    printf("parse the read_from file here\n");
}

void markover( mko_doc *doc, FILE *write_to, int flags ) {
    mko_to_html(doc, write_to, flags);
}

void mko_to_html( mko_doc *doc, FILE *write_to, int flags ) {
    fprintf( write_to, "Send HTML to write_to here\n");
}

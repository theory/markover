#define MKO_HTML 1
#define MKO_MAN  2
#define MKO_PDF  4

typedef struct mko_doc {
    int flags;
} mko_doc;

void mko_destroy( mko_doc *doc);

mko_doc *mko_parse( FILE *read_from, int flags );

void mko_to_html( mko_doc *doc, FILE *write_to );
void mko_to_man(  mko_doc *doc, FILE *write_to );

/* Common case. */
void markover( FILE *read_from, FILE *write_to, int flags );


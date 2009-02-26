typedef struct mko_doc {
    int whatever;
} mko_doc;

void mko_parse(   mko_doc *doc, FILE *read_from, int flags );
void markover(    mko_doc *doc, FILE *write_to,  int flags );
void mko_to_html( mko_doc *doc, FILE *write_to,  int flags );

/* void mko_to_man(    mko_doc *doc, FILE *write_to, int flags ); */

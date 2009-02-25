typedef struct mko_params {
    char  *read_from;
    char  *write_to;
    int   verbose;
} mko_params;

void markover( mko_params *params );

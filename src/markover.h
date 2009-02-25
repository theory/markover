typedef struct mo_params {
    char  *read_from;
    char  *write_to;
    int   verbose;
} mo_params;

void markover( mo_params *params );

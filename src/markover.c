#if HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include "markover.h"

void markover( mko_params *params ) {
    if (params->verbose)
        printf("  and we got it: %d\n", params->verbose);
    if (params->read_from)
        printf("  and read from: %s\n", params->read_from);
    if (params->write_to)
        printf("  and read from: %s\n", params->write_to);
}

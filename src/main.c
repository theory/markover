#if HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "markover.h"

static void get_markover_options(int argc, char *argv[], mo_params *params);
static void show_version(void);
static void show_usage(void);

main(int argc, char *argv[]) {
    mo_params params;
    get_markover_options(argc, argv, &params);
    if (params.verbose)
        printf("  and we got it: %d\n", params.verbose);
    if (params.read_from)
        printf("  and read from: %s\n", params.read_from);
    if (params.write_to)
        printf("  and read from: %s\n", params.write_to);
    exit(EXIT_SUCCESS);
}

static void get_markover_options(int argc, char *argv[], mo_params *params) {
    int c;

    params->verbose   = 0;

    static struct option long_options[] = {
        { "version",   no_argument,       0, 'v' },
        { "help",      no_argument,       0, 'h' },
        { "verbose",   no_argument,       0, 'V' },
        { "read-from", required_argument, 0, 'r' },
        { "write-to",  required_argument, 0, 'w' },
        { 0, 0, 0, 0}
    };

    while (1) {
        /* getopt_long stores the option index here. */
        int option_index = 0;

        c = getopt_long (argc, argv, "Vhvr:w:", long_options, &option_index);
     
        /* Detect the end of the options. */
        if (c == -1)
            break;
     
        switch (c) {
        case 'v':
            show_version();
            exit(EXIT_SUCCESS);

        case 'h':
            show_usage();
            exit(EXIT_SUCCESS);

        case 'V':
            params->verbose += 1;
            break;

        case 'r':
            params->read_from = optarg;
            break;
     
        case 'w':
            params->write_to = optarg;
            break;

        case '?':
            puts("Try \"" PACKAGE " --help\" for more information");
            exit(EXIT_FAILURE);
            break;

        default:
            abort ();
        }
    }
     
    /* Print any remaining command line arguments (not options). */
    if (optind < argc && !params->read_from) {
        params->read_from = argv[optind];
    }
}

/* show_version
 *
 * This output format is intended to match GNU standards.
 */
static void show_version(void) {
    puts(PACKAGE " " VERSION);
}

/*
 * usage
 *
 * print out command line arguments
 */
static void show_usage(void) {
    puts("This is " PACKAGE " " VERSION ", a parser and formatter for the Markover markup language.\n");
	puts("Usage:");
    puts("  " PACKAGE " [OPTIONS]... [FILENAME]\n");
	puts("General options:");
    puts("  -r --read-from  FILENAME  Markdown file from which to read.");
    puts("  -w --write-to   FILENAME  File to which to write output.");
    puts("  -V --verbose              Incremental verbose mode.");
    puts("  -h --help                 Output this usage statement and exit.");
    puts("  -v --version              Output version information and exit.");
    puts("");
    puts("Report bugs to <bugs@markover.info>.");
}

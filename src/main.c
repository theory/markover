#if HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "markover.h"

static void get_markover_options(int argc, char *argv[]);
static void show_version(void);
static void show_usage(void);

main(int argc, char *argv[]) {
    int     c;
    int     flags;
    mko_doc doc;
    FILE    *read_from = 0;
    FILE    *write_to  = 0;

    static struct option long_options[] = {
        { "version",   no_argument,       0, 'v' },
        { "help",      no_argument,       0, 'h' },
/*      { "verbose",   no_argument,       0, 'V' }, */
        { "read-from", required_argument, 0, 'r' },
        { "write-to",  required_argument, 0, 'w' },
        { 0, 0, 0, 0}
    };

    while (1) {
        /* getopt_long stores the option index here. */
        int option_index = 0;

        c = getopt_long (argc, argv, "hvr:w:", long_options, &option_index);
     
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

/*         case 'V': */
/*             params->verbose += 1; */
/*             break; */

        case 'r':
            if ( read_from ) {
                fprintf(stderr, "You can specify --read-from only once!\n");
                exit(1);
            }
            read_from = fopen(optarg, "r");
            if ( !read_from ) {
                perror(optarg);
                exit(1);
            }
            break;
     
        case 'w':
            if ( write_to ) {
                fprintf(stderr, "You can specify --write-to only once!\n");
                exit(1);
            }
            write_to = fopen(optarg, "w");
            if ( ! write_to) {
                perror(optarg);
                exit(1);
            }
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
    if (optind < argc && !read_from) {
        read_from = fopen(argv[optind], "r");
        if ( ! read_from ) {
            perror(argv[optind]);
            exit(1);
        }
    } else {
        read_from = stdin;
    }

    if (!write_to) write_to = stdout;

    mko_parse( &doc, read_from,  flags );
    markover(  &doc, write_to, flags );
    exit(EXIT_SUCCESS);
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
/*     puts("  -v --version              Output version information and exit."); */
    puts("");
    puts("Report bugs to <bugs@markover.info>.");
}

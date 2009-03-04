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

#define mko_open( fh, fn, mode ) \
    fh = fopen(fn, mode); \
    if ( !fh ) { \
        perror(optarg);\
        exit(1); \
    }

main(int argc, char *argv[]) {
    int     c;
    int     flags;
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
            mko_open(read_from, optarg, "r")
            break;
     
        case 'w':
            if ( write_to ) {
                fprintf(stderr, "You can specify --write-to only once!\n");
                exit(1);
            }
            mko_open(write_to, optarg, "w");
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
        mko_open(read_from, argv[optind], "r");
    } else {
        read_from = stdin;
    }

    if (!write_to) write_to = stdout;

    markover(  read_from, write_to, flags );
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
/*     puts("  -V --verbose              Incremental verbose mode."); */
    puts("  -h --help                 Output this usage statement and exit.");
    puts("  -v --version              Output version information and exit.");
    puts("");
    puts("Report bugs to <bugs@markover.info>.");
}

/* 
 * Features to add from discount?:
 * -b --url-base
 * -d --debug
 *    --no-pants
 *    --no-image
 *    --no-links
 *    --no-html
 *    --expand-quotes (" => &quot;)
 *    --no-header
 *    --tabstop 4
 *    --with-toc
 *    --compat (strict Markdown.pl compatibility)
 *    --no-spans (pseudo-protocols)?
 *    --relax-em (relaxed emphasis)?
 * -t --text
 */

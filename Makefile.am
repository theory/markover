#EXTRA_DIST = configure
#SUBDIRS = lib src doc
bin_PROGRAMS = markover
markover_SOURCES = src/markover.c

noinst_PROGRAMS = lemon
lemon_SOURCES = lib/lemon.c

doc/.html: markover
	markdown doc/markover.txt > doc/markover.html

#########
# Configure lemon.
#
noinst_PROGRAMS = lemon
lemon_SOURCES = lib/lemon.c

#########
# Configure the markover library.
#
lib_LTLIBRARIES = src/libmarkover.la
src_libmarkover_la_SOURCES = src/markover.c

#########
# Configure the markover app.
#
bin_PROGRAMS = src/markover
src_markover_SOURCES = src/main.c
src_markover_LDADD = src/libmarkover.la

#########
# Configure the tests.
#
check_PROGRAMS = test/base
test_base_SOURCES = test/tap.c test/base.c
test_base_LDADD = src/libmarkover.la

#########
# Setup the tests.
#
TESTS = test/base
.PHONY: test
test:
	$(MAKE) $(AM_MAKEFLAGS) $(check_PROGRAMS)
	prove -e '' $(TESTS)

doc/*.html: markover
	markdown doc/markover.txt > doc/markover.html

#########
# Let me really clean out the directory.
#
REPOCLEANFILES = Makefile.in aclocal.m4 config.* configure depcomp install-sh markover-* missing ltmain.sh test/.libs src/.libs
repoclean: maintainer-clean
	rm -rf $(REPOCLEANFILES)

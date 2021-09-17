
AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\"

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = v0

v0_SOURCES = v0.cc 
v0_LDADD = $(CUNIT_LIBS) $(OCTETOS_CORE_LIBS) $(top_builddir)/src/liboctetos-image.la
v0_CPPFLAGS = $(CUNIT_CFLGAS) $(OCTETOS_CORE_CFLGAS) -I$(top_srcdir)/src


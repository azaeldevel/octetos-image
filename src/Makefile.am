
AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\"

AM_CFLAGS =\
	 -Wall\
	 -g


lib_LTLIBRARIES = liboctetos-image.la

liboctetos_image_la_SOURCES = BMP.cc

liboctetos_image_la_LIBADD =  $(OCTETOS_CORE_LIBS) 

liboctetos_image_la_LDFLAGS =  $(OCTETOS_CORE_CFLGAS)


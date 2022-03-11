
AC_INIT(octetos-image, 0.1.0-alpha, azael.devel@gmail.com)

AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE

AM_SILENT_RULES([yes])

AC_PROG_CXX

LT_INIT

PKG_CHECK_MODULES(CUNIT,cunit)

PKG_CHECK_MODULES(OCTETOS_CORE,octetos-core)

AM_CONDITIONAL(WITH_TESTS, test x"$with_tests" = "xyes")
AC_ARG_WITH([tests], AS_HELP_STRING([--with-tests], [Compilando con soporte para Tests]))
if test "x$with_tests" = "xyes"; then 
	PKG_CHECK_MODULES(CUNIT,cunit)
fi

AC_OUTPUT([
Makefile
src/Makefile
tests/Makefile
])

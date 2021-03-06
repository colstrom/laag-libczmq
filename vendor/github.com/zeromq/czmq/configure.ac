################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################

#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
AC_PREREQ(2.61)
#
AC_INIT([czmq],[4.1.0],[zeromq-dev@lists.zeromq.org])

AC_CONFIG_AUX_DIR(config)
AC_CONFIG_MACRO_DIR(config)
AC_CONFIG_HEADERS([src/platform.h])
AM_INIT_AUTOMAKE([subdir-objects tar-ustar dist-zip foreign])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

# This defines PACKAGE_VERSION_... in src/platform.h
PV_MAJOR=`echo $PACKAGE_VERSION | cut -d . -f 1`
PV_MINOR=`echo $PACKAGE_VERSION | cut -d . -f 2`
PV_PATCH=`echo $PACKAGE_VERSION | cut -d . -f 3`
AC_DEFINE_UNQUOTED([PACKAGE_VERSION_MAJOR],[$PV_MAJOR],
    [CZMQ major version])
AC_DEFINE_UNQUOTED([PACKAGE_VERSION_MINOR],[$PV_MINOR],
    [CZMQ minor version])
AC_DEFINE_UNQUOTED([PACKAGE_VERSION_PATCH],[$PV_PATCH],
    [CZMQ patchlevel])
# This lets us use PACKAGE_VERSION in Makefiles
AC_SUBST(PACKAGE_VERSION)

#
# Libtool -version-info (ABI version)
#
# Currently 5:0:1 ("stable"). Don't change this unless you
# know exactly what you're doing and have read and understand
# http://www.gnu.org/software/libtool/manual/html_node/Updating-version-info.html
#
# libczmq -version-info
LTVER="5:0:1"
AC_SUBST(LTVER)

# building in a subdirectory?
AM_CONDITIONAL([USING_VPATH], [test "x${srcdir}" != "x."])

# Capture c flags
CZMQ_ORIG_CFLAGS="${CFLAGS:-none}"

# Checks for programs
AC_PROG_CC
AC_PROG_CC_C99
AM_PROG_CC_C_O
AC_LIBTOOL_WIN32_DLL
AC_PROG_LIBTOOL
AC_PROG_SED
AC_PROG_AWK
PKG_PROG_PKG_CONFIG

# Check endianess of the system
AC_C_BIGENDIAN

# Optional project-local hook (acinclude.m4, add AC_DEFUN([AX_PROJECT_LOCAL_HOOK], [whatever]) )
AX_PROJECT_LOCAL_HOOK

# Code coverage
AC_MSG_CHECKING([whether to enable GCov])
AC_ARG_WITH(gcov, [AS_HELP_STRING([--with-gcov=yes/no],
                  [With GCC Code Coverage reporting])],
                  [CZMQ_GCOV="$withval"])

if test "x${CZMQ_GCOV}" == "xyes"; then
    CFLAGS="-O0 -g -fprofile-arcs -ftest-coverage"

    if test "x${CZMQ_ORIG_CFLAGS}" != "xnone"; then
        CFLAGS="${CFLAGS} ${CZMQ_ORIG_CFLAGS}"
    fi
    AM_CONDITIONAL(WITH_GCOV, true)
    AC_MSG_RESULT([yes])
else
    AM_CONDITIONAL(WITH_GCOV, false)
    AC_MSG_RESULT([no])
fi

# Memory mis-use detection
AC_MSG_CHECKING([whether to enable ASan])
AC_ARG_ENABLE(address-sanitizer, [AS_HELP_STRING([--enable-address-sanitizer=yes/no],
                  [Build with GCC Address Sanitizer instrumentation])],
                  [CZMQ_ASAN="$enableval"])

if test "x${CZMQ_ASAN}" == "xyes"; then
    CFLAGS="${CFLAGS} -fsanitize=address"
    CXXFLAGS="${CXXFLAGS} -fsanitize=address"

    AM_CONDITIONAL(ENABLE_ASAN, true)
    AC_MSG_RESULT([yes])
else
    AM_CONDITIONAL(ENABLE_ASAN, false)
    AC_MSG_RESULT([no])
fi

# Set pkgconfigdir
AC_ARG_WITH([pkgconfigdir], AS_HELP_STRING([--with-pkgconfigdir=PATH],
    [Path to the pkgconfig directory [[LIBDIR/pkgconfig]]]),
    [pkgconfigdir="$withval"], [pkgconfigdir='${libdir}/pkgconfig'])
AC_SUBST([pkgconfigdir])

# Use the provided pkgconfigdir not only to write our pkg-config data,
# but also as an additional location to look for other packages metadata.
AS_IF([test -n "${pkgconfigdir}" -a -d "${pkgconfigdir}"],
    [AS_IF([test -z "${PKG_CONFIG_PATH}"],
        [PKG_CONFIG_PATH="${pkgconfigdir}"],
        [PKG_CONFIG_PATH="${pkgconfigdir}:${PKG_CONFIG_PATH}"])
     export PKG_CONFIG_PATH
    ])

# Will be used to add flags to pkg-config useful when apps want to statically link
PKGCFG_LIBS_PRIVATE=""

# Archive user supplied flags
PREVIOUS_CFLAGS="${CFLAGS}"
PREVIOUS_LIBS="${LIBS}"


was_libzmq_check_lib_detected=no

search_libzmq="yes"

AC_ARG_WITH([libzmq],
    [
        AS_HELP_STRING([--with-libzmq],
        [yes or no. Optionally specify libzmq prefix (directory where its include/ and lib/ are located), but that is only used if pkgconfig metadata is not found first])
    ],
    [
        search_libzmq="yes"
    ],
    [])
AS_CASE([x"${with_libzmq}"],
    [xyes], [search_libzmq="yes"],
    [xno],  [search_libzmq="no"])

dnl We do not abort right now, because the maintainer/developer may have
dnl something particular in mind, e.g. to build just parts of a project.
AS_IF([test x"${search_libzmq}" = xno],
    [AC_MSG_WARN([Required dependency on libzmq was explicitly disabled during configuration by '--with-libzmq=no'; subsequent full build of czmq may fail])])

AS_IF([test x"${search_libzmq}" = xyes], [
    # Archive previously detected and supplied flags
    PRE_SEARCH_CFLAGS="${CFLAGS}"
    PRE_SEARCH_LIBS="${LIBS}"

    found_pkgconfig=""
    found_linkname=""
    PKG_CHECK_MODULES([libzmq], [libzmq >= 0.0.0],
    [
        PKGCFG_LIBS_PRIVATE="$PKGCFG_LIBS_PRIVATE $libzmq_LIBS"
        was_libzmq_check_lib_detected=pkgcfg
        found_pkgconfig="libzmq"
    ],
    [
        AC_MSG_NOTICE([Package libzmq not found; falling back to defined compilability tests])

        libzmq_synthetic_cflags=""
        libzmq_synthetic_libs="-lzmq"

        if test -n "${with_libzmq}" && test x"${with_libzmq}" != xyes && test x"${with_libzmq}" != xno; then
            if test -r "${with_libzmq}/include/zmq.h"; then
                libzmq_synthetic_cflags="-I${with_libzmq}/include"
                libzmq_synthetic_libs="-L${with_libzmq}/lib -lzmq"
            else
            AC_MSG_ERROR([Header file ${with_libzmq}/include/zmq.h was not found. Please check libzmq prefix])
            fi
        else
            AC_CHECK_HEADER([zmq.h], [],
            AC_MSG_ERROR([Header file zmq.h was not found in default search paths])
                )
        fi

        AC_CHECK_LIB([zmq], [zmq_init],
            [
                was_libzmq_check_lib_detected=yes
                PKGCFG_LIBS_PRIVATE="$PKGCFG_LIBS_PRIVATE -lzmq"
                found_linkname="zmq"
            ],
            [AC_MSG_ERROR([cannot link with -lzmq, install libzmq])])
    ])

dnl END of PKG_CHECK_MODULES and/or direct tests for libzmq
    AS_CASE(["x${was_libzmq_check_lib_detected}"],
        [xpkgcfg], [
                AC_SUBST([pkgconfig_name_libzmq],[${found_pkgconfig}])
                CFLAGS="${libzmq_CFLAGS} ${CFLAGS}"
                LIBS="${libzmq_LIBS} ${LIBS}"
            ],
        [xyes], [
                AC_SUBST([pkgconfig_name_libzmq],[${found_linkname}])
                CFLAGS="${libzmq_synthetic_cflags} ${CFLAGS}"
                LDFLAGS="${libzmq_synthetic_libs} ${LDFLAGS}"
                LIBS="${libzmq_synthetic_libs} ${LIBS}"

                AC_SUBST([libzmq_CFLAGS],[${libzmq_synthetic_cflags}])
                AC_SUBST([libzmq_LIBS],[${libzmq_synthetic_libs}])
            ],
        [xno], [
                AC_SUBST([pkgconfig_name_libzmq],[libzmq])
            AC_MSG_ERROR([Cannot find pkg-config metadata for libzmq 0.0.0 or higher])
    ])
])
dnl END of enabled attempts to search for libzmq


was_uuid_check_lib_detected=no

search_uuid="no"

AC_ARG_WITH([uuid],
    [
        AS_HELP_STRING([--with-uuid],
        [yes or no. Optionally specify uuid prefix (directory where its include/ and lib/ are located), but that is only used if pkgconfig metadata is not found first])
    ],
    [
        search_uuid="yes"
    ],
    [])
AS_CASE([x"${with_uuid}"],
    [xyes], [search_uuid="yes"],
    [xno],  [search_uuid="no"])


AS_IF([test x"${search_uuid}" = xyes], [
    # Archive previously detected and supplied flags
    PRE_SEARCH_CFLAGS="${CFLAGS}"
    PRE_SEARCH_LIBS="${LIBS}"

    found_pkgconfig=""
    found_linkname=""
    PKG_CHECK_MODULES([uuid], [uuid >= 0.0.0],
    [
        AC_DEFINE(HAVE_UUID, 1, [The optional uuid library is to be used])
        PKGCFG_LIBS_PRIVATE="$PKGCFG_LIBS_PRIVATE $uuid_LIBS"
        was_uuid_check_lib_detected=pkgcfg
        found_pkgconfig="uuid"
    ],
    [
        AC_MSG_NOTICE([Package uuid not found; falling back to defined compilability tests])

        uuid_synthetic_cflags=""
        uuid_synthetic_libs="-luuid"

        if test -n "${with_uuid}" && test x"${with_uuid}" != xyes && test x"${with_uuid}" != xno; then
            if test -r "${with_uuid}/include/uuid/uuid.h"; then
                uuid_synthetic_cflags="-I${with_uuid}/include"
                uuid_synthetic_libs="-L${with_uuid}/lib -luuid"
            else
            AC_MSG_WARN([Header file ${with_uuid}/include/uuid/uuid.h was not found. Please check uuid prefix])
            fi
        else
            AC_CHECK_HEADER([uuid/uuid.h], [],
            AC_MSG_WARN([Header file uuid/uuid.h was not found in default search paths])
                )
        fi

        AC_CHECK_LIB([uuid], [uuid_generate],
            [
                was_uuid_check_lib_detected=yes
                PKGCFG_LIBS_PRIVATE="$PKGCFG_LIBS_PRIVATE -luuid"
                found_linkname="uuid"
                AC_DEFINE(HAVE_UUID, 1, [The optional uuid library is to be used (as -luuid)])
            ],
            [])
    ])

dnl END of PKG_CHECK_MODULES and/or direct tests for uuid
    AS_CASE(["x${was_uuid_check_lib_detected}"],
        [xpkgcfg], [
                AC_SUBST([pkgconfig_name_uuid],[${found_pkgconfig}])
                CFLAGS="${uuid_CFLAGS} ${CFLAGS}"
                LIBS="${uuid_LIBS} ${LIBS}"
            ],
        [xyes], [
                AC_SUBST([pkgconfig_name_uuid],[${found_linkname}])
                CFLAGS="${uuid_synthetic_cflags} ${CFLAGS}"
                LDFLAGS="${uuid_synthetic_libs} ${LDFLAGS}"
                LIBS="${uuid_synthetic_libs} ${LIBS}"

                AC_SUBST([uuid_CFLAGS],[${uuid_synthetic_cflags}])
                AC_SUBST([uuid_LIBS],[${uuid_synthetic_libs}])
            ],
        [xno], [
                AC_SUBST([pkgconfig_name_uuid],[uuid])
            AC_MSG_WARN([Cannot find pkg-config metadata for uuid 0.0.0 or higher])
    ])
])
dnl END of enabled attempts to search for uuid


was_systemd_check_lib_detected=no

search_libsystemd="no"

AC_ARG_WITH([libsystemd],
    [
        AS_HELP_STRING([--with-libsystemd],
        [yes or no. Optionally specify libsystemd prefix (directory where its include/ and lib/ are located), but that is only used if pkgconfig metadata is not found first])
    ],
    [
        search_libsystemd="yes"
    ],
    [])
AS_CASE([x"${with_libsystemd}"],
    [xyes], [search_libsystemd="yes"],
    [xno],  [search_libsystemd="no"])


AS_IF([test x"${search_libsystemd}" = xyes], [
    # Archive previously detected and supplied flags
    PRE_SEARCH_CFLAGS="${CFLAGS}"
    PRE_SEARCH_LIBS="${LIBS}"

    found_pkgconfig=""
    found_linkname=""
    PKG_CHECK_MODULES([systemd], [libsystemd >= 200.0.0],
    [
        AC_DEFINE(HAVE_LIBSYSTEMD, 1, [The optional libsystemd library is to be used])
        PKGCFG_LIBS_PRIVATE="$PKGCFG_LIBS_PRIVATE $systemd_LIBS"
        was_systemd_check_lib_detected=pkgcfg
        found_pkgconfig="libsystemd"
    ],
    [
        AC_MSG_NOTICE([Package libsystemd not found with needed constraints; falling back to defined compilability tests])

        systemd_synthetic_cflags=""
        systemd_synthetic_libs="-lsystemd"

        if test -n "${with_libsystemd}" && test x"${with_libsystemd}" != xyes && test x"${with_libsystemd}" != xno; then
            if test -r "${with_libsystemd}/include/systemd/sd-daemon.h"; then
                systemd_synthetic_cflags="-I${with_libsystemd}/include"
                systemd_synthetic_libs="-L${with_libsystemd}/lib -lsystemd"
            else
            AC_MSG_WARN([Header file ${with_libsystemd}/include/systemd/sd-daemon.h was not found. Please check libsystemd prefix])
            fi
        else
            AC_CHECK_HEADER([systemd/sd-daemon.h], [],
            AC_MSG_WARN([Header file systemd/sd-daemon.h was not found in default search paths])
                )
        fi

        AC_CHECK_LIB([libsystemd], [sd_listen_fds],
            [
                was_systemd_check_lib_detected=yes
                PKGCFG_LIBS_PRIVATE="$PKGCFG_LIBS_PRIVATE -lsystemd"
                found_linkname="systemd"
                AC_DEFINE(HAVE_LIBSYSTEMD, 1, [The optional libsystemd library is to be used (as -lsystemd)])
            ],
            [])
    ])

dnl END of PKG_CHECK_MODULES and/or direct tests for libsystemd
    AS_CASE(["x${was_systemd_check_lib_detected}"],
        [xpkgcfg], [
                AC_SUBST([pkgconfig_name_libsystemd],[${found_pkgconfig}])
                CFLAGS="${systemd_CFLAGS} ${CFLAGS}"
                LIBS="${systemd_LIBS} ${LIBS}"
            ],
        [xyes], [
                AC_SUBST([pkgconfig_name_libsystemd],[${found_linkname}])
                CFLAGS="${systemd_synthetic_cflags} ${CFLAGS}"
                LDFLAGS="${systemd_synthetic_libs} ${LDFLAGS}"
                LIBS="${systemd_synthetic_libs} ${LIBS}"

                AC_SUBST([systemd_CFLAGS],[${systemd_synthetic_cflags}])
                AC_SUBST([systemd_LIBS],[${systemd_synthetic_libs}])
            ],
        [xno], [
                AC_SUBST([pkgconfig_name_libsystemd],[libsystemd])
            AC_MSG_WARN([Cannot find pkg-config metadata for libsystemd 200.0.0 or higher])
    ])
])
dnl END of enabled attempts to search for libsystemd


was_lz4_check_lib_detected=no

search_liblz4="no"

AC_ARG_WITH([liblz4],
    [
        AS_HELP_STRING([--with-liblz4],
        [yes or no. Optionally specify liblz4 prefix (directory where its include/ and lib/ are located), but that is only used if pkgconfig metadata is not found first])
    ],
    [
        search_liblz4="yes"
    ],
    [])
AS_CASE([x"${with_liblz4}"],
    [xyes], [search_liblz4="yes"],
    [xno],  [search_liblz4="no"])


AS_IF([test x"${search_liblz4}" = xyes], [
    # Archive previously detected and supplied flags
    PRE_SEARCH_CFLAGS="${CFLAGS}"
    PRE_SEARCH_LIBS="${LIBS}"

    found_pkgconfig=""
    found_linkname=""
    PKG_CHECK_MODULES([lz4], [liblz4 >= 0.0.0],
    [
        AC_DEFINE(HAVE_LIBLZ4, 1, [The optional liblz4 library is to be used])
        PKGCFG_LIBS_PRIVATE="$PKGCFG_LIBS_PRIVATE $lz4_LIBS"
        was_lz4_check_lib_detected=pkgcfg
        found_pkgconfig="liblz4"
    ],
    [
        AC_MSG_NOTICE([Package liblz4 not found; falling back to defined compilability tests])

        lz4_synthetic_cflags=""
        lz4_synthetic_libs="-llz4"

        if test -n "${with_liblz4}" && test x"${with_liblz4}" != xyes && test x"${with_liblz4}" != xno; then
            if test -r "${with_liblz4}/include/lz4.h"; then
                lz4_synthetic_cflags="-I${with_liblz4}/include"
                lz4_synthetic_libs="-L${with_liblz4}/lib -llz4"
            else
            AC_MSG_WARN([Header file ${with_liblz4}/include/lz4.h was not found. Please check liblz4 prefix])
            fi
        else
            AC_CHECK_HEADER([lz4.h], [],
            AC_MSG_WARN([Header file lz4.h was not found in default search paths])
                )
        fi

        AC_CHECK_LIB([lz4], [LZ4_decompress_safe],
            [
                was_lz4_check_lib_detected=yes
                PKGCFG_LIBS_PRIVATE="$PKGCFG_LIBS_PRIVATE -llz4"
                found_linkname="lz4"
                AC_DEFINE(HAVE_LIBLZ4, 1, [The optional liblz4 library is to be used (as -llz4)])
            ],
            [])
    ])

dnl END of PKG_CHECK_MODULES and/or direct tests for liblz4
    AS_CASE(["x${was_lz4_check_lib_detected}"],
        [xpkgcfg], [
                AC_SUBST([pkgconfig_name_liblz4],[${found_pkgconfig}])
                CFLAGS="${lz4_CFLAGS} ${CFLAGS}"
                LIBS="${lz4_LIBS} ${LIBS}"
            ],
        [xyes], [
                AC_SUBST([pkgconfig_name_liblz4],[${found_linkname}])
                CFLAGS="${lz4_synthetic_cflags} ${CFLAGS}"
                LDFLAGS="${lz4_synthetic_libs} ${LDFLAGS}"
                LIBS="${lz4_synthetic_libs} ${LIBS}"

                AC_SUBST([lz4_CFLAGS],[${lz4_synthetic_cflags}])
                AC_SUBST([lz4_LIBS],[${lz4_synthetic_libs}])
            ],
        [xno], [
                AC_SUBST([pkgconfig_name_liblz4],[liblz4])
            AC_MSG_WARN([Cannot find pkg-config metadata for liblz4 0.0.0 or higher])
    ])
])
dnl END of enabled attempts to search for liblz4


CFLAGS="${PREVIOUS_CFLAGS}"
LIBS="${PREVIOUS_LIBS}"

AC_SUBST(pkg_config_libs_private, $PKGCFG_LIBS_PRIVATE)

# Platform specific checks
czmq_on_mingw32="no"
czmq_on_cygwin="no"
czmq_on_android="no"
czmq_on_linux="no"
czmq_on_gnu="no"

# Host specific checks
AC_CANONICAL_HOST

# Man pages are built/installed if asciidoc and xmlto are present
#   --with-docs=no overrides this
AC_ARG_WITH([docs],
    AS_HELP_STRING([--with-docs],
        [Build and install man pages [default=yes]]),
    [with_docs=$withval])

if test "x$with_docs" = "xno"; then
    czmq_build_doc="no"
    czmq_install_man="no"
else
    # Determine whether or not documentation should be built and installed.
    czmq_build_doc="yes"
    czmq_install_man="yes"

    # Check for asciidoc and xmlto and don't build the docs if these are not installed.
    AC_CHECK_PROG(czmq_have_asciidoc, asciidoc, yes, no)
    AC_CHECK_PROG(czmq_have_xmlto, xmlto, yes, no)
    if test "x$czmq_have_asciidoc" = "xno" -o "x$czmq_have_xmlto" = "xno"; then
        if test "x$with_docs" = "xyes" ; then
            AC_MSG_ERROR([Build with docs was explicitly requested, but tools are not available])
        fi
        czmq_build_doc="no"
        # Tarballs built with 'make dist' ship with prebuilt documentation.
        if ! test -f doc/czmq.7; then
            czmq_install_man="no"
            AC_MSG_WARN([You are building an unreleased version of CZMQ and asciidoc or xmlto are not installed.])
            AC_MSG_WARN([Documentation will not be built and manual pages will not be installed.])
        fi
    fi
fi
AC_MSG_CHECKING([whether to build documentation])
AC_MSG_RESULT([$czmq_build_doc])
AC_MSG_CHECKING([whether to install manpages])
AC_MSG_RESULT([$czmq_install_man])

# Set some default features required by libczmq code.
CPPFLAGS="-DCZMQ_INTERNAL_BUILD -D_REENTRANT -D_THREAD_SAFE $CPPFLAGS"

# OS-specific tests
case "${host_os}" in
    *linux*)
        # Define on Linux to enable all library features
        CPPFLAGS="-D_GNU_SOURCE -DLINUX $CPPFLAGS"
        AC_DEFINE(CZMQ_HAVE_LINUX, 1, [Have Linux OS])
        czmq_on_linux="yes"

        case "${host_os}" in
            *android*)
                AC_DEFINE(CZMQ_HAVE_ANDROID, 1, [Have Android OS])
                czmq_on_android="yes"
            ;;
        esac
        ;;
    *solaris*)
        # Define on Solaris to enable all library features
        CPPFLAGS="-D_PTHREADS $CPPFLAGS"
        # Allow definitions of common OS-provided functions that are not in old standards
        CPPFLAGS="-D__EXTENSIONS__ $CPPFLAGS"
        AC_DEFINE(CZMQ_HAVE_SOLARIS, 1, [Have Solaris OS])
        CFLAGS="${CFLAGS} -lsocket -lssp"
        ;;
    *freebsd*)
        # Define on FreeBSD to enable all library features
        CPPFLAGS="-D__BSD_VISIBLE $CPPFLAGS"
        AC_DEFINE(CZMQ_HAVE_FREEBSD, 1, [Have FreeBSD OS])
        ;;
    *darwin*)
        # Define on Darwin to enable all library features
        CPPFLAGS="-D_DARWIN_C_SOURCE $CPPFLAGS"
        AC_DEFINE(CZMQ_HAVE_OSX, 1, [Have DarwinOSX OS])
        ;;
    *netbsd*)
        # Define on NetBSD to enable all library features
        CPPFLAGS="-D_NETBSD_SOURCE $CPPFLAGS"
        AC_DEFINE(CZMQ_HAVE_NETBSD, 1, [Have NetBSD OS])
        ;;
    *openbsd*)
        # Define on OpenBSD to enable all library features
        CPPFLAGS="-D_BSD_SOURCE $CPPFLAGS"
        AC_DEFINE(CZMQ_HAVE_OPENBSD, 1, [Have OpenBSD OS])
        ;;
    *nto-qnx*)
        AC_DEFINE(CZMQ_HAVE_QNXNTO, 1, [Have QNX Neutrino OS])
        ;;
    *aix*)
        AC_DEFINE(CZMQ_HAVE_AIX, 1, [Have AIX OS])
        ;;
    *hpux*)
        # Define on HP-UX to enable all library features
        CPPFLAGS="-D_POSIX_C_SOURCE=200112L"
        AC_DEFINE(CZMQ_HAVE_HPUX, 1, [Have HPUX OS])
        ;;
    *mingw32*)
        # Disable format error due to incomplete ANSI C
        CFLAGS="-Wno-error=format -Wno-unused-function -Wno-unused-variable -D_XOPEN_SOURCE $CFLAGS"
        CPPFLAGS="-Wno-error=format -Wno-unused-function -Wno-unused-variable -D_XOPEN_SOURCE $CPPFLAGS"
        AC_DEFINE(CZMQ_HAVE_WINDOWS, 1, [Have Windows OS])
        AC_DEFINE(CZMQ_HAVE_MINGW32, 1, [Have MinGW32])
        AC_CHECK_HEADERS(windows.h)
        czmq_on_mingw32="yes"
        czmq_install_man="no"
        ;;
    *mingw64*)
        # Define on MINGW64 to enable all libeary features
        # Disable format error due to incomplete ANSI C
        CFLAGS="-Wno-error=format -Wno-unused-function -Wno-unused-variable -D_XOPEN_SOURCE $CFLAGS"
        CPPFLAGS="-Wno-error=format -Wno-unused-function -Wno-unused-variable -D_XOPEN_SOURCE $CPPFLAGS"
        AC_DEFINE(CZMQ_HAVE_WINDOWS, 1, [Have Windows OS])
        AC_DEFINE(CZMQ_HAVE_MINGW32, 1, [Have MinGW32])
        AC_CHECK_HEADERS(windows.h)
        czmq_on_mingw32="yes"
        czmq_install_man="no"
        ;;
    *cygwin*)
        # Define on Cygwin to enable all library features
        CPPFLAGS="-D_GNU_SOURCE $CPPFLAGS"
        AC_DEFINE(CZMQ_HAVE_CYGWIN, 1, [Have Cygwin])
        czmq_on_cygwin="yes"
        ;;
    gnu*)
        # Define on GNU/Hurd to enable all library features
        if test "x$GXX" = "xyes"; then
            CPPFLAGS="-D_GNU_SOURCE $CPPFLAGS"
        fi
        AC_DEFINE(CZMQ_HAVE_GNU, 1, [Have GNU/Hurd OS])
        czmq_on_gnu="yes"
        ;;
    *)
        AC_MSG_ERROR([unsupported system: ${host_os}])
        ;;
esac

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS(errno.h arpa/inet.h netinet/tcp.h netinet/in.h stddef.h \
                 stdlib.h string.h sys/socket.h sys/time.h unistd.h \
                 limits.h ifaddrs.h)
AC_CHECK_HEADERS([net/if.h net/if_media.h linux/wireless.h], [], [],
[
#ifdef HAVE_SYS_SOCKET_H
# include <sys/socket.h>
#endif
#include <stdint.h>
])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_HEADER_TIME
AC_TYPE_UINT32_T
AC_C_VOLATILE
AC_C_BIGENDIAN

# These options are GNU compiler specific.
if test "x$GCC" = "xyes"; then
    CPPFLAGS="-pedantic -Werror -Wall -Wc++-compat ${CPPFLAGS}"
fi

AM_CONDITIONAL(ENABLE_SHARED, test "x$enable_shared" = "xyes")
AM_CONDITIONAL(ON_MINGW, test "x$czmq_on_mingw32" = "xyes")
AM_CONDITIONAL(ON_CYGWIN, test "x$czmq_on_cygwin" = "xyes")
AM_CONDITIONAL(ON_ANDROID, test "x$czmq_on_android" = "xyes")
AM_CONDITIONAL(ON_LINUX, test "x$czmq_on_linux" = "xyes")
AM_CONDITIONAL(ON_GNU, test "x$czmq_on_gnu" = "xyes")
AM_CONDITIONAL(INSTALL_MAN, test "x$czmq_install_man" = "xyes")
AM_CONDITIONAL(BUILD_DOC, test "x$czmq_build_doc" = "xyes")

AC_ARG_ENABLE([dist_cmakefiles],
    AS_HELP_STRING([--enable-dist_cmakefiles],
        [Distribute CMakeLists.txt and related files [default depends: on if present and not cross compiling]]),
    [enable_dist_cmakefiles=$enableval],
    [AC_MSG_CHECKING([for presence of CMake recipes])
if test "x$cross_compiling" = "xyes"; then
     enable_dist_cmakefiles=no
else
     AC_CHECK_FILE($srcdir/CMakeLists.txt, [enable_dist_cmakefiles=yes], [enable_dist_cmakefiles=no])
fi
     AC_MSG_RESULT([$enable_dist_cmakefiles])])
AM_CONDITIONAL(ENABLE_DIST_CMAKEFILES, test "x$enable_dist_cmakefiles" = "xyes")

# Check for zmakecert intent
AC_ARG_ENABLE([zmakecert],
    AS_HELP_STRING([--enable-zmakecert],
        [Compile and install 'zmakecert' [default=yes]]),
    [enable_zmakecert=$enableval],
    [enable_zmakecert=yes])

AM_CONDITIONAL([ENABLE_ZMAKECERT], [test x$enable_zmakecert != xno])
AM_COND_IF([ENABLE_ZMAKECERT], [AC_MSG_NOTICE([ENABLE_ZMAKECERT defined])])

# Check for zsp intent
AC_ARG_ENABLE([zsp],
    AS_HELP_STRING([--enable-zsp],
        [Compile 'zsp' in src [default=yes]]),
    [enable_zsp=$enableval],
    [enable_zsp=yes])

AM_CONDITIONAL([ENABLE_ZSP], [test x$enable_zsp != xno])
AM_COND_IF([ENABLE_ZSP], [AC_MSG_NOTICE([ENABLE_ZSP defined])])

# Check for test_randof intent
AC_ARG_ENABLE([test_randof],
    AS_HELP_STRING([--enable-test_randof],
        [Compile 'test_randof' in src [default=yes]]),
    [enable_test_randof=$enableval],
    [enable_test_randof=yes])

AM_CONDITIONAL([ENABLE_TEST_RANDOF], [test x$enable_test_randof != xno])
AM_COND_IF([ENABLE_TEST_RANDOF], [AC_MSG_NOTICE([ENABLE_TEST_RANDOF defined])])

# Check for czmq_selftest intent
AC_ARG_ENABLE([czmq_selftest],
    AS_HELP_STRING([--enable-czmq_selftest],
        [Compile 'czmq_selftest' in src [default=yes]]),
    [enable_czmq_selftest=$enableval],
    [enable_czmq_selftest=yes])

AM_CONDITIONAL([ENABLE_CZMQ_SELFTEST], [test x$enable_czmq_selftest != xno])
AM_COND_IF([ENABLE_CZMQ_SELFTEST], [AC_MSG_NOTICE([ENABLE_CZMQ_SELFTEST defined])])

# Checks for library functions.
AC_TYPE_SIGNAL
AC_CHECK_FUNCS(perror gettimeofday memset getifaddrs)


# enable specific system integration features
if test "x$cross_compiling" = "xyes"; then
    #   Enable draft by default when cross-compiling
    defaultval=yes
else
    # enable draft API by default if we're in a git repository
    # else disable it by default; then allow --enable-drafts=yes/no override
    AC_CHECK_FILE($srcdir/.git, [defaultval=yes],
        [AC_MSG_CHECKING([running under a git repository workspace])
         AS_IF([git rev-parse --show-toplevel 2>/dev/null],
            [defaultval=yes],
            [defaultval=no])
         AC_MSG_RESULT($defaultval)
        ])
fi

AC_ARG_ENABLE([drafts],
    AS_HELP_STRING([--enable-drafts],
        [Build and install draft classes and methods [default=yes]]),
    [enable_drafts=$enableval],
    [enable_drafts=$defaultval])

AM_CONDITIONAL([ENABLE_DRAFTS], [test x$enable_drafts != xno])

if test "x$enable_drafts" = "xyes"; then
    AC_MSG_NOTICE([Building stable and legacy API + draft API])
    AC_DEFINE(CZMQ_BUILD_DRAFT_API, 1, [Provide draft classes and methods])
    AC_SUBST(pkg_config_defines, "-DCZMQ_BUILD_DRAFT_API=1")
else
    AC_MSG_NOTICE([Building stable and legacy API (no draft API)])
    AC_SUBST(pkg_config_defines, "")
fi

AC_ARG_ENABLE([Werror],
    AS_HELP_STRING([--enable-Werror],
        [Add -Wall -Werror to GCC/GXX arguments [default=no; default=auto if nothing specified]]),
    [AS_IF([test -n "$enableval"], [enable_Werror=$enableval], [enable_Werror=auto])],
    [enable_Werror=no])

AS_IF([test "x$enable_Werror" = "xyes" || test "x$enable_Werror" = "xauto"],
    [AS_IF([test -n "$CC"],[AS_IF([$CC --version 2>&1 | grep 'Free Software Foundation' > /dev/null],
        [AC_MSG_NOTICE([Enabling pedantic errors for GNU C])
         CFLAGS="$CFLAGS -Wall -Werror"],
        [AC_MSG_NOTICE([Not enabling pedantic errors: compiler not supported by this recipe (not GNU C)])
         AS_IF([test "x$enable_Werror" = "xyes"], [AC_MSG_ERROR([--enable-Werror=yes was requested and can not be satisfied for C: $CC])])
        ])])
     AS_IF([test -n "$CXX"],[AS_IF([$CXX --version 2>&1 | grep 'Free Software Foundation' > /dev/null],
        [AC_MSG_NOTICE([Enabling pedantic errors for GNU C++])
         CXXFLAGS="$CXXFLAGS -Wall -Werror"],
        [AC_MSG_NOTICE([Not enabling pedantic errors: compiler not supported by this recipe (not GNU C++)])
         AS_IF([test "x$enable_Werror" = "xyes"], [AC_MSG_ERROR([--enable-Werror=yes was requested and can not be satisfied for C++: $CXX])])
        ])])
     AS_IF([test -n "$CPP"],[AS_IF([$CPP --version 2>&1 | grep 'Free Software Foundation' > /dev/null],
        [AC_MSG_NOTICE([Enabling pedantic errors for GNU CPP preprocessor])
         CPPFLAGS="$CPPFLAGS -Wall -Werror"],
        [AC_MSG_NOTICE([Not enabling pedantic errors: preprocessor not supported by this recipe (not GNU CPP)])
         AS_IF([test "x$enable_Werror" = "xyes"], [AC_MSG_ERROR([--enable-Werror=yes was requested and can not be satisfied for CPP: $CPP])])
        ])])
])

# Specify output files
AC_CONFIG_FILES([Makefile
                 doc/Makefile
                 src/libczmq.pc
                 ])


AC_OUTPUT

# Print configure summary and list make options
AC_DEFUN([AX_SUMMARIZE_ENV],
[
BUILD_USER=${USER}
BUILD_ARCH=${host}
BUILD_HOST=${ac_hostname}
BUILD_DATE=$(date +'%F %H:%M')

AC_DEFINE_UNQUOTED([BUILD_USER],     "${BUILD_USER}",     [The fine user who built the package])
AC_DEFINE_UNQUOTED([BUILD_ARCH],     "${BUILD_ARCH}",     [Architecture of the build host])
AC_DEFINE_UNQUOTED([BUILD_HOST],     "${BUILD_HOST}",     [Build host name])
AC_DEFINE_UNQUOTED([BUILD_DATE],     "${BUILD_DATE}",     [Build date])

AC_SUBST(BUILD_USER)
AC_SUBST(BUILD_ARCH)
AC_SUBST(BUILD_HOST)
AC_SUBST(BUILD_DATE)
AC_SUBST(BUILD_VERSION)
])

AC_DEFUN([AX_SUMMARIZE_CONFIG],
[
echo
echo '##########################################################################'
echo '#                                SUMMARY                                 #'
echo '##########################################################################'
echo
echo Package version............... : $PACKAGE-$VERSION
echo
echo C compiler.................... : $CC
echo C compiler flags.............. : $CFLAGS
echo C++ compiler.................. : $CXX
echo C++ compiler flags............ : $CXXFLAGS
echo Configure date................ : $BUILD_DATE
echo Build architecture............ : $BUILD_ARCH
echo Build docs.................... : $czmq_build_doc
echo Build host.................... : $BUILD_HOST
echo Build user.................... : $USER
echo Draft API..................... : $enable_drafts
echo Install dir................... : $prefix
echo Install man pages............. : $czmq_install_man

echo
echo Help:
echo Use the Draft API \(default = yes\):
echo --enable-drafts=\(yes\|no\)
echo
echo Build the docs and install the man pages \(default = yes\):
echo --with-docs=\(yes\|no\)       *requires asciidoc and xmlto

echo
echo '##########################################################################'

echo
echo Configure complete! Now proceed with:
echo "    - 'make'               compile the project"
echo "    - 'make check'         run the project's selftest"
echo "    - 'make install'       install the project to $prefix"
echo
echo Further options are:
echo "    - 'make callcheck'     run the project's selftest with valgrind to"
echo "                           check for performance leaks"
echo "    - 'make check-verbose' run the project's selftest in verbose mode"
echo "    - 'make code'          generate code from models in src directory"
echo "                           (requires zproject and zproto)"
echo "    - 'make debug'         run the project's selftest under gdb"
echo "    - 'make memcheck'      run the project's selftest with valgrind to"
echo "                           check for memory leaks"
echo "    - 'make coverage'      generate project's selftest coverage report"
echo "                           expects --with-gcov option for configure"
echo
])

AX_SUMMARIZE_ENV
AX_SUMMARIZE_CONFIG
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################

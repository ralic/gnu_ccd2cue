dnl
dnl configure.ac -- configuration script;
dnl
dnl Copyright (C) 2013, 2014, 2015 Bruno Félix Rezende Ribeiro <oitofelix@gnu.org>
dnl
dnl This program is free software: you can redistribute it and/or modify
dnl it under the terms of the GNU General Public License as published by
dnl the Free Software Foundation, either version 3 of the License, or
dnl (at your option) any later version.
dnl
dnl This program is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl GNU General Public License for more details.
dnl
dnl You should have received a copy of the GNU General Public License
dnl along with this program.  If not, see <http://www.gnu.org/licenses/>.
dnl





##################
# Initialization #
##################

# Release definitions;
AC_INIT([GNU ccd2cue], [0.5],
[bug-ccd2cue@gnu.org], [ccd2cue],
[https://www.gnu.org/software/ccd2cue])
AC_SUBST([PACKAGE_MAILING_LIST], [ccd2cue@gnu.org])
AC_DEFINE_UNQUOTED([PACKAGE_MAILING_LIST], ["$PACKAGE_MAILING_LIST"],
  [Help and support mailing list])
AC_DEFINE(PACKAGE_TRANSLATION_BUGREPORT,
["http://translationproject.org/team/"], [Translation bugs reporting address])
AC_DEFINE(PACKAGE_COPYRIGHT_HOLDER, ["Bruno Fe'lix Rezende Ribeiro"],
[Copyright holder's name])


# GNU Autoconf settings;
AC_CONFIG_AUX_DIR([build-aux])
AC_PREREQ(2.60)
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR([src/ccd2cue.c])
AC_SUBST([CONFIG_STATUS_DEPENDENCIES], ['$(top_srcdir)/doc/Doxyfile.in'])

# GNUlib initialization;
dnl gl_EARLY
dnl gl_INIT

# GNU Automake settings;
AM_INIT_AUTOMAKE([-Wall -Wno-portability -Wno-override foreign])
AM_SILENT_RULES([yes])
AM_EXTRA_RECURSIVE_TARGETS([homepage install-man])
AM_GNU_GETTEXT_VERSION([0.18.1])
AM_GNU_GETTEXT([external])

# Decide whether you are configuring from VCS.
AS_IF([[test -d "$srcdir"/.git]], [[VCS=y]], [[VCS=n]])
AC_SUBST([VCS])





################################
# Programs Search and Checking #
################################

# Check for `mkdir'.
AC_PROG_MKDIR_P

# Check for `ln'.
AC_PROG_LN_S

# Check for `grep'.
AC_PROG_GREP

# Check for `sed'.
AC_PROG_SED

# Check for `cc'.
AC_PROG_CC



##########
### Check for programs needed to build documentation.
######

AC_MSG_NOTICE([checking programs needed in order to build documentation])

# Check for GNU Texinfo program `makeinfo'.

### Define GNU Texinfo minimal version.
m4_define([TEXINFO_MINVER], 5.1)

### Declare `MAKEINFO' as a precious variable.
AC_ARG_VAR([MAKEINFO], [Texinfo `makeinfo' program])

### Check for `makeinfo'.
AC_PATH_PROG([MAKEINFO], [makeinfo])

# Check for GNU Texinfo existence.  If not building from a VCS
# checkout, GNU Texinfo is not required.
AS_IF([[test x$MAKEINFO = x && test x$VCS = xy]],
  AC_MSG_ERROR(
[[GNU Texinfo not found.  It is required at least version ]]TEXINFO_MINVER.
[[You can find it at https://gnu.org/software/texinfo/.]]))

# If GNU Texinfo was not found and you are not building from a VCS
# checkout, warn the user about what the lack of that optional
# dependence means.
AS_IF([[test x$MAKEINFO = x]],
  AC_MSG_WARN(
[[GNU Texinfo not found.  It is required at least version ]]TEXINFO_MINVER.
[[You can find it at https://gnu.org/software/texinfo/.]]
[[It will not be possible to rebuild the Info documentation
nor generate any other documentation format.]]))

### If `makeinfo' was found, test whether its version is at least
### TEXINFO_MINVER.
AS_IF([[test x$MAKEINFO != x]],
  # Put `makeinfo' version in variable `texinfo_version'.
  [[texinfo_version=`$MAKEINFO --version |
      $SED -n 's/^makeinfo.* \(@<:@@<:@:digit:@:>@.@:>@*\)$/\1/p'`]]

  # If `makeinfo' version is less than TEXINFO_VER, print an error
  # message and abort when building from VCS checkout or warn the user
  # otherwise.
  AS_VERSION_COMPARE([[$texinfo_version]], TEXINFO_MINVER,
    [AS_IF([test x$VCS = xy ],
      AC_MSG_ERROR(
[[GNU Texinfo is too old.  It is required at least version ]]TEXINFO_MINVER.
[[You can find it at https://gnu.org/software/texinfo/.]]),
      AC_MSG_WARN(
[[GNU Texinfo is too old.  It is required at least version ]]TEXINFO_MINVER.
[[You can find it at https://gnu.org/software/texinfo/.]]
[[It will not be possible to rebuild the Info documentation
nor generate any other documentation format.]]))]))

AM_MISSING_PROG([MAKEINFO], [makeinfo])


### Declare `HELP2MAN' as a precious variable.
AC_ARG_VAR([HELP2MAN], ['help2man' program])

### Check for `help2man'.
AC_PATH_PROG([HELP2MAN], [help2man])

# Check for GNU help2man existence.  If not building from a VCS
# checkout, it is not required.
AS_IF([[test x$HELP2MAN = x && test x$VCS = xy]],
  AC_MSG_ERROR(
[[GNU help2man not found.  You can get it at https://gnu.org/software/help2man/.]]))

# Check for GNU help2man existence.  It should only be used if not
# cross-compiling.
AS_IF([[test $cross_compiling = no]],
  [AM_MISSING_PROG([HELP2MAN], [help2man])], HELP2MAN=:)


# Check for Doxygen existence and configure it;
DX_DOT_FEATURE(ON)
DX_PDF_FEATURE(OFF)
DX_PS_FEATURE(OFF)
DX_INIT_DOXYGEN([ccd2cue], ['$(top_builddir)/doc/Doxyfile'],
  ['$(top_builddir)/doc/doxygen'])


# rsync is needed to fetch PO files from 'translationproject.org'.
AM_MISSING_PROG([RSYNC], [rsync])





####################
# Meta-information #
####################

AC_MSG_NOTICE([[Checking meta-information]])

AC_MSG_CHECKING([available translations])
AC_SUBST([LINGUAS], $(echo $(ls $srcdir/po/*.po | $GREP -v quot |
  $SED 's,^.*po/\(.*\)\.po$,\1,')))
AC_MSG_RESULT([$LINGUAS])

AS_IF([test x$VCS = xy],

  AC_MSG_CHECKING([release date])
  AC_SUBST([RELEASE_DATE], $(LINGUA=C LANG=C date '+%B %d, %Y'))
  AC_MSG_RESULT([$RELEASE_DATE])

  AC_MSG_CHECKING([Autoconf version])
  AC_SUBST([AUTOCONF_VERSION], m4_defn([AC_AUTOCONF_VERSION]))
  AC_MSG_RESULT([$AUTOCONF_VERSION])

  AC_MSG_CHECKING([Automake version])
  AC_SUBST([AUTOMAKE_VERSION], `automake --version |
    $SED -n 's/^automake.* \(@<:@@<:@:digit:@:>@.@:>@*\)$/\1/p'`)
  AC_MSG_RESULT([$AUTOMAKE_VERSION])

  AC_MSG_CHECKING([Texinfo version])
  AC_SUBST([TEXINFO_VERSION], `$MAKEINFO --version |
    $SED -n 's/^makeinfo.* \(@<:@@<:@:digit:@:>@.@:>@*\)$/\1/p'`)
  AC_MSG_RESULT([$TEXINFO_VERSION]))





################
# Output Files #
################

# Output files;
AC_CONFIG_FILES(
[Makefile
po/Makefile.in
po/LINGUAS
src/Makefile
doc/Makefile
doc/Doxyfile
doc/man/Makefile
doc/release/release.texi])

AC_OUTPUT





###########################
# Help about Make targets #
###########################

AS_ECHO("")
AS_BOX([[GNU Make Targets Table]])
AS_ECHO("")
AS_ECHO("")

AS_ECHO(["\
Build:

 all            Compile entire program.

 info, html, pdf, ps, dvi
                Build documentation in the respective format.

 doxygen-doc    Build source-code documentation.
 check          Run test suite.

 tags, ctags
                Build respective tags table file.


Installation:

 install-exec     Install architecture-dependent files.
 install-data     Install architecture-independent files.
 install          Same as \`install-exec' followed by \`install-data'.
 install-strip    Same as \`install' but strip executables.

 install-{info,html,pdf,ps,dvi}
                  Install documentation in the respective format.

 install-man      Install man pages.
 installdirs      Create the installation directory tree.
 installcheck     Perform installation tests.
 uninstall        Delete installed files.


Cleaning:

 mostlyclean         Delete files that \`make' built and usually
                      one would like to rebuild.
 clean               Same as \`mostlyclean' but delete also
                      any file \`make' built but was ignored by
                      \`mostlyclean'.
 distclean           Same as \`clean' but delete also files
                      generated by the configuration script.
 maintainer-clean    Same as \`distclean' but delete also
                      files maintainers built.


Distribution:

 distdir      Create distribution directory.
 dist         Same as \`distdir' but package the distribution
               directory into a tarball.
 distcheck    Same as \`dist' but also check generated
               tarball for correctness.


Maintenance:

 These can only be made from VCS checkouts.

 homepage     Generate package's homepage.
 distgnu      Same as \`distcheck' but also sign and upload the
               resulting tarball to the GNU ftp site.
 announcegnu  Send release announcement to 'info-gnu@gnu.org',
               '$PACKAGE_MAILING_LIST' and
               'coordinator@translationproject.org'
 fetchpo      Fetch the latest PO translation files from the
               Translation Project.
"])

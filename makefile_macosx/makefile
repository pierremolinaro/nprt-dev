#---------------------------------------------------------------*
#                                                               *
# MAKEFILE for building NPRT command line tools                 *
#  For MacOS X, compiled on MacOS X                             *
#                                                               *
#---------------------------------------------------------------*

#--- Release and debug versions of markg
EXECUTABLE := nprt
EXECUTABLE_DEBUG := nprt_debug

#--- Install directory (for "install" goal)
INSTALL_DIR := /usr/bin

#---------------------------------------------------------------*

#--- Linker libraries
LINKER_OPTIONS :=

#---------------------------------------------------------------*

RELEASE_OPTIONS := -DDO_NOT_GENERATE_CHECKINGS

#---------------------------------------------------------------*

include ../common_files_for_make/common_sources_makefile.mke

#---------------------------------------------------------------*
#                                                               *
#     Include gcc tools for MAC OS X                            *
#                                                               *
#---------------------------------------------------------------*

include $(LIB_PM_PATH)/included_makefiles/macosx_gcc_tools.mke

#---------------------------------------------------------------*
#                                                               *
#     Include makefile that performs actual work                *
#                                                               *
#---------------------------------------------------------------*

include $(LIB_PM_PATH)/included_makefiles/generic_makefile.mke

#---------------------------------------------------------------*

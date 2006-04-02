#---------------------------------------------------------------*
#                                                               *
# MAKEFILE for building NPRT command line tools for Unix        *
#                                                               *
#---------------------------------------------------------------*

#--- Release and debug versions of NPRT
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
#     Include gcc tools for Unix                                *
#                                                               *
#---------------------------------------------------------------*

include $(LIB_PM_PATH)/included_makefiles/unix_gcc_tools.mke

#---------------------------------------------------------------*
#                                                               *
#     Include makefile that performs actual work                *
#                                                               *
#---------------------------------------------------------------*

include $(LIB_PM_PATH)/included_makefiles/generic_makefile.mke

#---------------------------------------------------------------*

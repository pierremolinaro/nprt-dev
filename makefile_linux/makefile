#---------------------------------------------------------------*
#                                                               *
# MAKEFILE for building NPRT command line tools                 *
#  For Linux, compiled on Linux                                 *
#                                                               *
#---------------------------------------------------------------*

#--- Release and debug versions of NPRT
EXECUTABLE := nprt
EXECUTABLE_DEBUG := nprt_debug

#--- Install directory (for "install" goal)
INSTALL_DIR := /usr/bin

#---------------------------------------------------------------*

#--- Linker libraries
LINKER_OPTIONS := -lstdc++ -lm

#---------------------------------------------------------------*

RELEASE_OPTIONS := -DDO_NOT_GENERATE_MEMORY_CHECK_CODE

#---------------------------------------------------------------*

include ../common_files_for_make/common_sources_makefile.mke

#---------------------------------------------------------------*
#                                                               *
#     Include gcc tools for Linux                               *
#                                                               *
#---------------------------------------------------------------*

include $(LIB_PM_PATH)/included_makefiles/linux_gcc_tools.mke

#---------------------------------------------------------------*
#                                                               *
#     Include makefile that performs actual work                *
#                                                               *
#---------------------------------------------------------------*

include $(LIB_PM_PATH)/included_makefiles/generic_makefile.mke

#---------------------------------------------------------------*

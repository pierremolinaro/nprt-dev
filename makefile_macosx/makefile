#---------------------------------------------------------------*
#                                                               *
# MAKEFILE for building NPRT command line tools                 *
#  For MacOS X, compiled on MacOS X                             *
#                                                               *
#---------------------------------------------------------------*

#--- Release and debug versions of markg
EXECUTABLE := nprt
EXECUTABLE_DEBUG := nprt_debug

#---------------------------------------------------------------*
#                                                               *
#     Object files directory                                    *
#                                                               *
#---------------------------------------------------------------*

OBJECTS_DIR := objects
DEBUG_OBJECTS_DIR := debug_objects

#--- Install directory (for "install" goal)
INSTALL_DIR := /usr/bin

#---------------------------------------------------------------*

#--- Linker Options for this platform
PLATFORM_LINKER_OPTIONS :=

#---------------------------------------------------------------*

include ../galgas_sources/GALGAS_OUTPUT/file_list.mke

#---------------------------------------------------------------*
#                                                               *
#     Include gcc tools for MAC OS X                            *
#                                                               *
#---------------------------------------------------------------*

include $(LIB_PM_PATH)/included_makefiles/macosx_gcc_tools_32.mke

#---------------------------------------------------------------*
#                                                               *
#     Include makefile that performs actual work                *
#                                                               *
#---------------------------------------------------------------*

include $(LIB_PM_PATH)/included_makefiles/generic_makefile.mke

#---------------------------------------------------------------*

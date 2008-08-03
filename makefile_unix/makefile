#---------------------------------------------------------------*
#                                                               *
# MAKEFILE for building NPRT command line tools for Unix        *
#                                                               *
#---------------------------------------------------------------*

#--- Release and debug versions of NPRT
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
#     Include gcc tools for Unix                                *
#                                                               *
#---------------------------------------------------------------*

include $(LIB_PM_PATH)/included_makefiles/unix_gcc_tools_32.mke

#---------------------------------------------------------------*
#                                                               *
#     Include makefile that performs actual work                *
#                                                               *
#---------------------------------------------------------------*

include $(LIB_PM_PATH)/included_makefiles/generic_makefile.mke

#---------------------------------------------------------------*

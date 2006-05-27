#---------------------------------------------------------------*
#                                                               *
# MAKEFILE for building NPRT command line tool                  *
#   For Win32, compiled on Mac OS X                             *
#                                                               *
#---------------------------------------------------------------*

#--- Release and debug versions of markg
EXECUTABLE := nprt.exe
EXECUTABLE_DEBUG := nprt_debug.exe

#---------------------------------------------------------------*

#--- Linker Options for this platform
PLATFORM_LINKER_OPTIONS := -lcomdlg32

#---------------------------------------------------------------*

include ../common_files_for_make/common_sources_makefile.mke

#---------------------------------------------------------------*
#                                                               *
#     Include MinGW gcc tools definitions for MAC OS X          *
#                                                               *
#---------------------------------------------------------------*

include $(LIB_PM_PATH)/included_makefiles/mingw_on_macosx_gcc_tools.mke

#---------------------------------------------------------------*
#                                                               *
#     Include makefile that performs actual work                *
#                                                               *
#---------------------------------------------------------------*

include $(LIB_PM_PATH)/included_makefiles/generic_makefile.mke

#---------------------------------------------------------------*

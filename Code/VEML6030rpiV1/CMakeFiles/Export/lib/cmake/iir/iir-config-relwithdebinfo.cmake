#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "iir::iir" for configuration "RelWithDebInfo"
set_property(TARGET iir::iir APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(iir::iir PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libiir.so.1.7.3"
  IMPORTED_SONAME_RELWITHDEBINFO "libiir.so.1"
  )

list(APPEND _IMPORT_CHECK_TARGETS iir::iir )
list(APPEND _IMPORT_CHECK_FILES_FOR_iir::iir "${_IMPORT_PREFIX}/lib/libiir.so.1.7.3" )

# Import target "iir::iir_static" for configuration "RelWithDebInfo"
set_property(TARGET iir::iir_static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(iir::iir_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libiir_static.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS iir::iir_static )
list(APPEND _IMPORT_CHECK_FILES_FOR_iir::iir_static "${_IMPORT_PREFIX}/lib/libiir_static.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

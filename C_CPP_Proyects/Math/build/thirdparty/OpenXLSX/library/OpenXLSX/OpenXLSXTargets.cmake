# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.5)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6...3.17)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget OpenXLSX::OpenXLSX-static OpenXLSX::OpenXLSX-shared)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  unset(_targetsDefined)
  unset(_targetsNotDefined)
  unset(_expectedTargets)
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Create imported target OpenXLSX::OpenXLSX-static
add_library(OpenXLSX::OpenXLSX-static STATIC IMPORTED)

set_target_properties(OpenXLSX::OpenXLSX-static PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/home/tonix/Documents/ATHENAS/C_CPP_Proyects/Math/thirdparty/OpenXLSX/library;/home/tonix/Documents/ATHENAS/C_CPP_Proyects/Math/thirdparty/OpenXLSX/library/headers;/home/tonix/Documents/ATHENAS/C_CPP_Proyects/Math/build/thirdparty/OpenXLSX/library"
  INTERFACE_LINK_LIBRARIES "\$<LINK_ONLY:Zippy>;\$<LINK_ONLY:PugiXML>;\$<LINK_ONLY:NoWide>"
)

# Create imported target OpenXLSX::OpenXLSX-shared
add_library(OpenXLSX::OpenXLSX-shared SHARED IMPORTED)

set_target_properties(OpenXLSX::OpenXLSX-shared PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/home/tonix/Documents/ATHENAS/C_CPP_Proyects/Math/thirdparty/OpenXLSX/library;/home/tonix/Documents/ATHENAS/C_CPP_Proyects/Math/thirdparty/OpenXLSX/library/headers;/home/tonix/Documents/ATHENAS/C_CPP_Proyects/Math/build/thirdparty/OpenXLSX/library"
)

# Import target "OpenXLSX::OpenXLSX-static" for configuration ""
set_property(TARGET OpenXLSX::OpenXLSX-static APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(OpenXLSX::OpenXLSX-static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "/home/tonix/Documents/ATHENAS/C_CPP_Proyects/Math/build/output/libOpenXLSX-static.a"
  )

# Import target "OpenXLSX::OpenXLSX-shared" for configuration ""
set_property(TARGET OpenXLSX::OpenXLSX-shared APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(OpenXLSX::OpenXLSX-shared PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "/home/tonix/Documents/ATHENAS/C_CPP_Proyects/Math/build/output/libOpenXLSX-shared.so"
  IMPORTED_SONAME_NOCONFIG "libOpenXLSX-shared.so"
  )

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)

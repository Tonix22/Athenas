
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/src)
add_executable(Lagrange lagrange.cpp)
target_link_libraries(Lagrange PRIVATE OpenXLSX-static ${CMAKE_SOURCE_DIR}/thirdparty/koolplot/libkoolplot.a)
target_compile_definitions(Lagrange PRIVATE OPENXLSX_STATIC_DEFINE)
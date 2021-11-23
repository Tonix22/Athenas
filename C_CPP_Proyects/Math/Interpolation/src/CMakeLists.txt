
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/src)
#graphics
find_package(Python3 COMPONENTS Development NumPy)

add_executable(Lagrange lagrange.cpp)

target_include_directories(Lagrange PRIVATE ${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS})
target_link_libraries(Lagrange PRIVATE OpenXLSX-static 
${CMAKE_SOURCE_DIR}/thirdparty/koolplot/libkoolplot.a 
Python3::Python Python3::NumPy)

target_compile_definitions(Lagrange PRIVATE OPENXLSX_STATIC_DEFINE)

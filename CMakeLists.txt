cmake_minimum_required(VERSION 3.15)
project(LC)

set(CMAKE_CXX_STANDARD 11)

# 添加一个自定义函数，用于获取目录下的所有源文件
function(add_sources curdir)
    file(GLOB sources ${curdir}/*.cpp)
    foreach(source ${sources})
        get_filename_component(target ${source} NAME_WE)
        add_executable(${target} ${source})
    endforeach()
endfunction()

# 添加每个题目的源文件到项目中
add_sources(${CMAKE_CURRENT_SOURCE_DIR})

# 添加 clean 功能
add_custom_target(clean-all
        COMMAND ${CMAKE_BUILD_TOOL} clean
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Cleaning all binaries"
)


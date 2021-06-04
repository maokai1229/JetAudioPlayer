cmake_minimum_required(VERSION 3.10.2)

project("jetaudioplayer")

# 导入头文件的目录文件夹
include_directories(include)
# 设置系统环境变量
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI}")
message(-------------)
message(${CMAKE_SOURCE_DIR})
aux_source_directory(. SOURCE)
#file(GLOB ALLC "src/main/cpp/*.cpp")
add_library(
             native-lib
             SHARED
             ${SOURCE}
#             ${ALLC}
             )


find_library(
              log-lib
              log )



target_link_libraries(
        native-lib
        avcodec
        avdevice
        avfilter
        avformat
        avutil
        swresample
        swscale
        ${log-lib}
        OpenSLES
        android )
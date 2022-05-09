cmake_minimum_required (VERSION 3.7)

project (Magick4J)

add_compile_definitions(_USING_TRACE_MODE_)

aux_source_directory(. DIR_SRCS)

find_package(ImageMagick COMPONENTS MagickCore)

find_package(JNI)

add_library(Magick4J SHARED ${DIR_SRCS})

if(ImageMagick_FOUND)
    message(NOTICE "** Found ${ImageMagick_INCLUDE_DIRS}")
    # include_directories(${ImageMagick_INCLUDE_DIRS})
    target_include_directories(Magick4J PRIVATE ${ImageMagick_INCLUDE_DIRS})
    target_link_libraries(Magick4J ${ImageMagick_LIBRARIES})
else(ImageMagick_FOUND)
    message(FATAL_ERROR "ImageMagick library not found")
endif(ImageMagick_FOUND)

if(JNI_FOUND)
    message(NOTICE "** Found ${JNI_INCLUDE_DIRS}")
    target_include_directories(Magick4J PRIVATE ${JNI_INCLUDE_DIRS})
    # target_link_libraries(Magick4J ${JNI_LIBRARIES})
else(JNI_FOUND)
    message(FATAL_ERROR "JNI library not found")
endif(JNI_FOUND)
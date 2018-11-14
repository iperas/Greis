CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

# Common settings

CMAKE_POLICY(SET CMP0003 NEW)
CMAKE_POLICY(SET CMP0054 NEW)

# Get all propreties that cmake supports
execute_process(COMMAND cmake --help-property-list OUTPUT_VARIABLE CMAKE_PROPERTY_LIST)

# Convert command output into a CMake list
STRING(REGEX REPLACE ";" "\\\\;" CMAKE_PROPERTY_LIST "${CMAKE_PROPERTY_LIST}")
STRING(REGEX REPLACE "\n" ";" CMAKE_PROPERTY_LIST "${CMAKE_PROPERTY_LIST}")

function(print_properties)
    message ("CMAKE_PROPERTY_LIST = ${CMAKE_PROPERTY_LIST}")
endfunction(print_properties)

function(print_target_properties tgt)
    if(NOT TARGET ${tgt})
      message("There is no target named '${tgt}'")
      return()
    endif()

    foreach (prop ${CMAKE_PROPERTY_LIST})
        string(REPLACE "<CONFIG>" "${CMAKE_BUILD_TYPE}" prop ${prop})
        # message ("Checking ${prop}")
        get_property(propval TARGET ${tgt} PROPERTY ${prop} SET)
        if (propval)
            get_target_property(propval ${tgt} ${prop})
            message ("${tgt} ${prop} = ${propval}")
        endif()
    endforeach(prop)
endfunction(print_target_properties)


MACRO(add_custom_action_copy targets)
	foreach(File ${targets})
	  add_custom_command(TARGET ${PROJECT} PRE_BUILD
	                     COMMAND ${CMAKE_COMMAND} -E
	                         copy $<TARGET_PROPERTY:${PROJECT},SOURCE_DIR>/${File} $<TARGET_FILE_DIR:${PROJECT}>)
	endforeach()
ENDMACRO()

MACRO(add_test_ex target)
    ADD_TEST(NAME ${target} COMMAND $<TARGET_FILE:${target}> --gtest_output=xml:
${CMAKE_BINARY_DIR}/build/test-reports/${target}.xml)
ENDMACRO()

# Project settings

SET(PROJECT greis)
PROJECT(${PROJECT} CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/bin)

# Add some multithreaded build support
MARK_AS_ADVANCED(MULTITHREADED_BUILD)
set(MULTITHREADED_BUILD 12 CACHE STRING "How many threads are used to build the project")
if(MULTITHREADED_BUILD)
    if(CMAKE_COMPILER_IS_GNUCXX)
        message(STATUS ${CMAKE_BUILD_TOOL})
        set(CMAKE_MAKE_PROGRAM "${CMAKE_MAKE_PROGRAM} -j${MULTITHREADED_BUILD}")
        message(STATUS "Added arguments to CMAKE_BUILD_TOOL: ${CMAKE_MAKE_PROGRAM}")
    elseif(MSVC)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
        message(STATUS "Added parallel build arguments to CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
    endif()
endif()

# Libraries

## Qt

# (Make sure that CMAKE_PREFIX_PATH env var is set)
FIND_PACKAGE(Qt5Core)
FIND_PACKAGE(Qt5Sql)

# Common

include(ExternalProject)

# Greis

SET(CMAKE_AUTOMOC ON)


FILE(GLOB_RECURSE HEADERS "${PROJECT}/*.h")
FILE(GLOB ROOT_HEADERS "${PROJECT}/*.h")
FILE(GLOB COMMON_HEADERS "common/*.h")
FILE(GLOB EXTRAS_HEADERS "extras/*.h")
FILE(GLOB STDMESSAGE_HEADERS "${PROJECT}/StdMessage/*.h")
FILE(GLOB CUSTOMTYPE_HEADERS "${PROJECT}/CustomType/*.h")

FILE(GLOB_RECURSE SOURCES "src/*.cpp")
FILE(GLOB EXTRAS_SOURCES "extras/*.cpp")
FILE(GLOB ROOT_SOURCES "src/*.cpp")
FILE(GLOB STDMESSAGE_SOURCES "src/StdMessage/*.cpp")
FILE(GLOB CUSTOMTYPE_SOURCES "src/CustomType/*.cpp")

# source grouping

source_group ("Header Files" FILES ${ROOT_HEADERS})
source_group ("Header Files\\StdMessage" FILES ${STDMESSAGE_HEADERS})
source_group ("Header Files\\CustomType" FILES ${CUSTOMTYPE_HEADERS})

source_group ("Source Files" FILES ${ROOT_SOURCES})
source_group ("Source Files\\StdMessage" FILES ${STDMESSAGE_SOURCES})
source_group ("Source Files\\CustomType" FILES ${CUSTOMTYPE_SOURCES})

# includes

foreach(DEPENDENCY ${DEPENDS_ON_PROJECTS})
        include_directories("../${DEPENDENCY}")
endforeach()

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/common")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT}")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT}/StdMessage")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT}/CustomType")

# linking

add_library(${PROJECT} STATIC ${HEADERS} ${EXTRAS_HEADERS} ${COMMON_HEADERS} ${SOURCES} ${EXTRAS_SOURCES} ${MOC_SOURCES})
set_property(TARGET ${PROJECT} PROPERTY CXX_STANDARD 14)
SET_TARGET_PROPERTIES(${PROJECT} PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(
    ${PROJECT}
    ${DEPENDS_ON_PROJECTS}
    Qt5::Core
        Qt5::Sql)


install ( TARGETS ${PROJECT} EXPORT ${PROJECT} ARCHIVE DESTINATION ${CMAKE_BINARY_DIR}/build/lib)
export ( TARGETS ${PROJECT} FILE ${CMAKE_BINARY_DIR}/${PROJECT}-config.cmake )
export ( PACKAGE ${PROJECT} )
add_subdirectory(test)
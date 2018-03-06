CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
CMAKE_POLICY(SET CMP0054 NEW)
CMAKE_POLICY(SET CMP0060 NEW)
# variables declaration

SET(PROJECT greis.Tests)

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

FILE(GLOB_RECURSE HEADERS "include/*.h")

FILE(GLOB_RECURSE SOURCES "src/*.cpp")

FILE(GLOB_RECURSE MOC_SOURCES "*_automoc.cpp")

SET(CONFIG_FILES "config.test.ini")

SET(TEXT_TEMPLATES "include/tests.h")

# check 64 bit
#if(CMAKE_SIZEOF_VOID_P EQUALS 4)
#    set(HAVE_64_BIT 0)
#else()
#    set(HAVE_64_BIT 1)
#endif()

if (MSVC)
	# Now we support only x86 build with this. Be aware that x64 configuration will fail with a strange error 'Driver not found'
	SET (DEPLOY_FILES ${DEPLOY_FILES} "C:/MySQL/MySQLConnectorC6.1/lib/libmysql.dll")
endif()

# source grouping

source_group ("Header Files" FILES ${HEADERS})
source_group ("Source Files" FILES ${SOURCES})
source_group ("Generated Files" FILES ${MOC_SOURCES})

# project definition

PROJECT(${PROJECT} CXX)

# includes

include_directories("${Common_source_dir}/common")
include_directories("${Common_source_dir}/greis")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT}")

# linking

add_executable(${PROJECT} ${HEADERS} ${SOURCES} ${MOC_SOURCES} ${CONFIG_FILES} ${TEXT_TEMPLATES})
set_property(TARGET ${PROJECT} PROPERTY CXX_STANDARD 14)
SET_TARGET_PROPERTIES(${PROJECT} PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(
    ${PROJECT}
    ${Boost_LIBRARIES}
    greis
    Qt5::Core
    Qt5::Sql
    debug ${GTEST_DEBUG_LIBS}
    optimized ${GTEST_RELEASE_LIBS}
    ${Pthread})

# dependencies

add_dependencies(${PROJECT} googletest ${DEPENDS_ON_PROJECTS})
# add_custom_target(copy)

add_custom_action_copy(${CONFIG_FILES})
if (DEPLOY_FILES)
    add_custom_action_copy(${DEPLOY_FILES})
endif()
if (MSVC)
	add_custom_action_t4(${TEXT_TEMPLATES})
endif()

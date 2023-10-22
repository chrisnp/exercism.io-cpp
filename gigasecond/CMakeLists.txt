# Get the exercise name from the current directory
get_filename_component(exercise ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Basic CMake project
cmake_minimum_required(VERSION 3.5.1)

# Name the project after the exercise
project(${exercise} CXX)

# Locate Boost date_time library -- linux
set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "/c/msys64/mingw64/include")
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "/c/msys64/mingw64/lib")
set(BOOST_INCLUDE_DIR ${Boost_INCLUDE_DIR} "/c/msys64/mingw64/include")
set(BOOST_LIBRARYDIR ${Boost_LIBRARYDIR} "/c/msys64/mingw64/lib")
# Locate Boost date_time library -- win
# set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "/mingw64/include")
# set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "/mingw64/lib")
# set(BOOST_INCLUDE_DIR ${Boost_INCLUDE_DIR} "/mingw64/include")
# set(BOOST_LIBRARYDIR ${Boost_LIBRARYDIR} "/mingw64/lib")

# cmake_policy(SET CMP0074 NEW)

set ( PROJECT_LINK_LIBS libboost_date_time.a )
# link_directories( /c/msys64/mingw64/lib )
# include_directories( /c/msys64/mingw64/include)
# for win64 uncomment (comment out above)
link_directories( /mingw64/lib )
include_directories( /mingw64/include)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.59 COMPONENTS date_time REQUIRED )

# IF (Boost_FOUND)
#     INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
#     ADD_DEFINITIONS( "-DHAS_BOOST" )
# ENDIF()

# Get a source filename from the exercise name by replacing -'s with _'s
string(REPLACE "-" "_" file ${exercise})

# Implementation could be only a header
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file}.cpp)
    set(exercise_cpp ${file}.cpp)
else()
    set(exercise_cpp "")
endif()

# Use the common Catch library?
if(EXERCISM_COMMON_CATCH)
    # For Exercism track development only
    add_executable(${exercise} ${file}_test.cpp ${exercise_cpp} ${file}.h $<TARGET_OBJECTS:catchlib>)
else()
    # Build executable from sources and headers
    add_executable(${exercise} ${file}_test.cpp ${exercise_cpp} ${file}.h test/tests-main.cpp )
endif()

set_target_properties(${exercise} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED OFF
    CXX_EXTENSIONS OFF
)

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(GNU|Clang)")
    set_target_properties(${exercise} PROPERTIES
        COMPILE_FLAGS "-Wall -Wextra -Wpedantic -Werror"
    )
endif()

# We need boost libraries
target_link_libraries(${exercise}
    # PRIVATE
    # Boost::date_time
    ${PROJECT_LINK_LIBS}
)

# Configure to run all the tests?
if(${EXERCISM_RUN_ALL_TESTS})
    target_compile_definitions(${exercise} PRIVATE EXERCISM_RUN_ALL_TESTS)
endif()

# Tell MSVC not to warn us about unchecked iterators in debug builds
if(${MSVC})
    set_target_properties(${exercise} PROPERTIES
        COMPILE_DEFINITIONS_DEBUG _SCL_SECURE_NO_WARNINGS)
endif()

# Run the tests on every build
add_custom_target(test_${exercise} ALL DEPENDS ${exercise} COMMAND ${exercise})

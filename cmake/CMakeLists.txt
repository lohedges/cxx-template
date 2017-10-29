CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
IF(COMMAND cmake_policy)
    CMAKE_POLICY(SET CMP0003 NEW)
ENDIF(COMMAND cmake_policy)

# Check for build type argument.
IF(DEFINED CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "Choose the type of
build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug
Release RelWithDebInfo MinSizeRel." FORCE)
ELSE()
    SET(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build,
options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release
RelWithDebInfo MinSizeRel." FORCE)
ENDIF()

# Get Git commit and branch information.
EXECUTE_PROCESS(
    COMMAND
    git describe --abbrev=4 --dirty --always --tags
    OUTPUT_VARIABLE GIT_COMMIT
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
EXECUTE_PROCESS(
    COMMAND
    git rev-parse --abbrev-ref HEAD
    OUTPUT_VARIABLE
    GIT_BRANCH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

PROJECT(SHAPES)

# Set library path.
SET(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib CACHE INTERNAL "Single output directory for libraries.")

# Set the compiler flags.
IF("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    SET(CMAKE_CXX_FLAGS "-O0 -g -Wall")
ELSEIF("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    SET(CMAKE_CXX_FLAGS "-O3 -DNDEBUG")
ENDIF()

ADD_DEFINITIONS(-DCOMMIT="${GIT_COMMIT}")
ADD_DEFINITIONS(-DBRANCH="${GIT_BRANCH}")

# Output some useful info.
SITE_NAME(COMPUTER_NAME)
MESSAGE(STATUS "Computer name: " \"${COMPUTER_NAME}\")
MESSAGE(STATUS "Build type: " \"${CMAKE_BUILD_TYPE}\")
MESSAGE(STATUS "Compiler flags: " \"${CMAKE_CXX_FLAGS}\")

# Search for Doxygen, add dox subdirectory if found.
# CMakeLists.txt in dox directory adds documentation dependencies and doc make target.
FIND_PACKAGE(Doxygen)
IF(DOXYGEN_FOUND)
    OPTION(ENABLE_DOXYGEN "Enables building of documentation with doxygen" 1)
    IF(ENABLE_DOXYGEN)
        ADD_SUBDIRECTORY(dox)
    ENDIF(ENABLE_DOXYGEN)
ENDIF(DOXYGEN_FOUND)

# Make shapes.h library header file.
FILE(GLOB HEADER_FILES "${CMAKE_SOURCE_DIR}/src/*.h")
STRING(REPLACE "${CMAKE_SOURCE_DIR}/src/shapes.h;" "" HEADER_FILES "${HEADER_FILES}")
STRING(REPLACE "${CMAKE_SOURCE_DIR}/src/" "" HEADER_FILES "${HEADER_FILES}")
FILE(WRITE ${CMAKE_SOURCE_DIR}/src/shapes.h "#ifndef _SHAPES_H\n#define _SHAPES_H\n\n")
FOREACH(_FILENAME ${HEADER_FILES})
    FILE(APPEND ${CMAKE_SOURCE_DIR}/src/shapes.h "#include \"${_FILENAME}\"\n")
ENDFOREACH(_FILENAME ${HEADER_FILES})
FILE(APPEND ${CMAKE_SOURCE_DIR}/src/shapes.h "\n#endif\n")

# Update include directories.
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/src)
AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/src SHAPES_SRC)

# Create shapes library.
ADD_LIBRARY(shapes
    ${SHAPES_SRC}
)

# Install.
FILE(GLOB _FILES "${CMAKE_SOURCE_DIR}/src/*.h")
INSTALL(FILES ${_FILES} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/shapes)
INSTALL(TARGETS shapes
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)

# Uninstall target
CONFIGURE_FILE(
    "${CMAKE_CURRENT_SOURCE_DIR}/uninstall.cmake.in"
    "${CMAKE_CURRENT_SOURCE_DIR}/uninstall.cmake"
    IMMEDIATE @ONLY)

ADD_CUSTOM_TARGET(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_SOURCE_DIR}/uninstall.cmake)

# Set the test code path.
FILE(GLOB TESTS RELATIVE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/tests/*.cpp)

# Build tests.
FOREACH(TEST ${TESTS})
    STRING(REPLACE ".cpp" "" NAME ${TEST})
    STRING(REPLACE "tests/" "" NAME ${NAME})
    MESSAGE(STATUS "Found test: " ${NAME})
    ADD_EXECUTABLE(${NAME} ${TEST})
    TARGET_LINK_LIBRARIES(${NAME} shapes)
	SET_TARGET_PROPERTIES(${NAME}
		PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests"
	)
ENDFOREACH(TEST ${TESTS})

# Set the demo code path.
FILE(GLOB DEMOS RELATIVE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/demos/*.cpp)

# Build demos.
FOREACH(DEMO ${DEMOS})
    STRING(REPLACE ".cpp" "" NAME ${DEMO})
    STRING(REPLACE "demos/" "" NAME ${NAME})
    MESSAGE(STATUS "Found demo: " ${NAME})
    ADD_EXECUTABLE(${NAME} ${DEMO})
    TARGET_LINK_LIBRARIES(${NAME} shapes)
    INSTALL(TARGETS ${NAME}
        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/share/shapes-demo
    )
	SET_TARGET_PROPERTIES(${NAME}
		PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/demos"
	)
ENDFOREACH(DEMO ${DEMOS})

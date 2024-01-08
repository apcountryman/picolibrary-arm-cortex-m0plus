# picolibrary-arm-cortex-m0plus
#
# Copyright 2023-2024, Andrew Countryman <apcountryman@gmail.com> and the
# picolibrary-arm-cortex-m0plus contributors
#
# Licensed under the Apache License, Version 2.0 (the "License"); you may not use this
# file except in compliance with the License. You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software distributed under
# the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied. See the License for the specific language governing
# permissions and limitations under the License.

# Description: picolibrary-arm-cortex-m0plus core CMake rules.

cmake_minimum_required( VERSION 3.16.3 )
project(
    picolibrary-arm-cortex-m0plus
    LANGUAGES CXX
)

# general project configuration
set(
    PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_INCLUDE_DIR
    "" CACHE STRING
    "picolibrary-arm-cortex-m0plus: implementation include directory"
)

if( "${PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_INCLUDE_DIR}" STREQUAL "" )
    message( FATAL_ERROR "PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_INCLUDE_DIR must be configured" )
endif( "${PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_INCLUDE_DIR}" STREQUAL "" )

# load additional CMake modules
list(
    APPEND CMAKE_MODULE_PATH
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/apcountryman-cmake-utilities"
)

# configure compilation and linking
if( "${PROJECT_SOURCE_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}" )
    set( CMAKE_CXX_STANDARD 17 )
    set( CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE )
    add_compile_options(
        -mcpu=cortex-m0plus
        -mthumb
        -Werror -Wall -Wextra
        -Wcast-align=strict
        -Wcast-qual
        -Wduplicated-cond
        -Wextra-semi
        -Wfloat-equal
        -Wimplicit-fallthrough=5
        -Wlogical-op
        -Wmissing-field-initializers
        -Wmissing-include-dirs
        -Wold-style-cast
        -Wplacement-new=2
        -Wpointer-arith
        -Wshadow
        -Wunsafe-loop-optimizations
        -fno-exceptions
        -fno-threadsafe-statics
        -ffile-prefix-map=${CMAKE_CURRENT_SOURCE_DIR}/=
        -ffile-prefix-map=${CMAKE_CURRENT_SOURCE_DIR}/picolibrary/=
    )
endif( "${PROJECT_SOURCE_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}" )

# configure picolibrary
option(
    PICOLIBRARY_ARM_CORTEX_M0PLUS_USE_PARENT_PROJECT_PICOLIBRARY
    "picolibrary-arm-cortex-m0plus: use parent project's picolibrary"
    ON
)

if( NOT ${PICOLIBRARY_ARM_CORTEX_M0PLUS_USE_PARENT_PROJECT_PICOLIBRARY} )
    set( PICOLIBRARY_HIL_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include" CACHE INTERNAL "" )

    set( PICOLIBRARY_ENABLE_AUTOMATED_TESTING OFF CACHE INTERNAL "" )
endif( NOT ${PICOLIBRARY_ARM_CORTEX_M0PLUS_USE_PARENT_PROJECT_PICOLIBRARY} )

if( NOT "${PICOLIBRARY_HIL_INCLUDE_DIR}" STREQUAL "${PROJECT_SOURCE_DIR}/include" )
    message( FATAL_ERROR "PICOLIBRARY_HIL_INCLUDE_DIR must be ${PROJECT_SOURCE_DIR}/include" )
endif( NOT "${PICOLIBRARY_HIL_INCLUDE_DIR}" STREQUAL "${PROJECT_SOURCE_DIR}/include" )

if( ${PICOLIBRARY_ENABLE_AUTOMATED_TESTING} )
    message( FATAL_ERROR "PICOLIBRARY_ENABLE_AUTOMATED_TESTING must be OFF" )
endif( ${PICOLIBRARY_ENABLE_AUTOMATED_TESTING} )

if( NOT ${PICOLIBRARY_ARM_CORTEX_M0PLUS_USE_PARENT_PROJECT_PICOLIBRARY} )
    add_subdirectory( picolibrary )
endif( NOT ${PICOLIBRARY_ARM_CORTEX_M0PLUS_USE_PARENT_PROJECT_PICOLIBRARY} )

# capture project version information
include( git-utilities )
execute_git_command(
    PICOLIBRARY_ARM_CORTEX_M0PLUS_VERSION
    COMMAND describe --match=none --always --dirty --broken
)

# library
add_subdirectory( source )

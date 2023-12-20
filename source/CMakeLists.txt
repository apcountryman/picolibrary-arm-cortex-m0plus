# picolibrary-arm-cortex-m0plus
#
# Copyright 2023, Andrew Countryman <apcountryman@gmail.com> and the
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

# Description: picolibrary-arm-cortex-m0plus CMake rules.

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/picolibrary/arm/cortex/m0plus/version.cc.in"
    "${CMAKE_CURRENT_BINARY_DIR}/picolibrary/arm/cortex/m0plus/version.cc"
    @ONLY
)

set(
    PICOLIBRARY_ARM_CORTEX_M0PLUS_SOURCE_FILES
    "picolibrary/arm/cortex/m0plus.cc"
    "picolibrary/arm/cortex/m0plus/configuration.cc"
    "picolibrary/arm/cortex/m0plus/peripheral.cc"
    "picolibrary/arm/cortex/m0plus/peripheral/nvic.cc"
)
set(
    PICOLIBRARY_ARM_CORTEX_M0PLUS_LINK_LIBRARIES
    "picolibrary"
)

add_library(
    picolibrary-arm-cortex-m0plus
    ${PICOLIBRARY_ARM_CORTEX_M0PLUS_SOURCE_FILES}
)
target_include_directories(
    picolibrary-arm-cortex-m0plus
    PUBLIC "${PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_INCLUDE_DIR}"
    PUBLIC "${PROJECT_SOURCE_DIR}/include"
)
target_link_libraries(
    picolibrary-arm-cortex-m0plus
    ${PICOLIBRARY_ARM_CORTEX_M0PLUS_LINK_LIBRARIES}
)

add_library(
    picolibrary-arm-cortex-m0plus-version
    "${CMAKE_CURRENT_BINARY_DIR}/picolibrary/arm/cortex/m0plus/version.cc"
)
target_include_directories(
    picolibrary-arm-cortex-m0plus-version
    PUBLIC "${PROJECT_SOURCE_DIR}/include"
)
target_link_libraries(
    picolibrary-arm-cortex-m0plus-version
    picolibrary
)

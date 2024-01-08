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

# Description: picolibrary-arm-cortex-m0plus release configuration.

# build configuration
set( CMAKE_BUILD_TYPE                                         "MinSizeRel"                        CACHE INTERNAL "" )
set( CMAKE_EXPORT_COMPILE_COMMANDS                            ON                                  CACHE INTERNAL "" )
set( PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/include" CACHE INTERNAL "" )

# picolibrary configuration
set( PICOLIBRARY_ARM_CORTEX_M0PLUS_USE_PARENT_PROJECT_PICOLIBRARY OFF CACHE INTERNAL "" )
set( PICOLIBRARY_ENABLE_INTERACTIVE_TESTING                       OFF CACHE INTERNAL "" )
set( PICOLIBRARY_SUPPRESS_ASSERTION_FAILURE_LOCATION_INFORMATION  OFF CACHE INTERNAL "" )
set( PICOLIBRARY_SUPPRESS_HUMAN_READABLE_ERROR_INFORMATION        OFF CACHE INTERNAL "" )
set( PICOLIBRARY_SUPPRESS_HUMAN_READABLE_EVENT_INFORMATION        OFF CACHE INTERNAL "" )

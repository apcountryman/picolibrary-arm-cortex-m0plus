/**
 * picolibrary-arm-cortex-m0plus
 *
 * Copyright 2023, Andrew Countryman <apcountryman@gmail.com> and the
 * picolibrary-arm-cortex-m0plus contributors
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not use this
 * file except in compliance with the License. You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software distributed under
 * the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

/**
 * \file
 * \brief picolibrary::Arm::Cortex::M0PLUS configuration interface.
 */

#ifndef PICOLIBRARY_ARM_CORTEX_M0PLUS_CONFIGURATION_H
#define PICOLIBRARY_ARM_CORTEX_M0PLUS_CONFIGURATION_H

#include "picolibrary/arm/cortex/m0plus/implementation/configuration.h"

#ifndef PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_MPU
#error "PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_MPU not configured"
#endif // PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_MPU

#ifndef PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SCB_VTOR
#error "PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SCB_VTOR not configured"
#endif // PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SCB_VTOR

#ifndef PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SYSTICK
#error "PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SYSTICK not configured"
#endif // PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SYSTICK

namespace picolibrary::Arm::Cortex::M0PLUS {
} // namespace picolibrary::Arm::Cortex::M0PLUS

#endif // PICOLIBRARY_ARM_CORTEX_M0PLUS_CONFIGURATION_H

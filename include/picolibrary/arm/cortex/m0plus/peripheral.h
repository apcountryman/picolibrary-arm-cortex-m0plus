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
 * \brief picolibrary::Arm::Cortex::M0PLUS::Peripheral interface.
 */

#ifndef PICOLIBRARY_ARM_CORTEX_M0PLUS_PERIPHERAL_H
#define PICOLIBRARY_ARM_CORTEX_M0PLUS_PERIPHERAL_H

#include "picolibrary/arm/cortex/m0plus/peripheral/nvic.h"
#include "picolibrary/peripheral.h"

/**
 * \brief Arm Cortex-M0+ peripheral facilities.
 */
namespace picolibrary::Arm::Cortex::M0PLUS::Peripheral {

/**
 * \brief NVIC0.
 */
using NVIC0 = ::picolibrary::Peripheral::Instance<NVIC, 0xE000E100>;

} // namespace picolibrary::Arm::Cortex::M0PLUS::Peripheral

#endif // PICOLIBRARY_ARM_CORTEX_M0PLUS_PERIPHERAL_H

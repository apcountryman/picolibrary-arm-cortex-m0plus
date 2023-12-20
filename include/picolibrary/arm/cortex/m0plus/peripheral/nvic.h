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
 * \brief picolibrary::Arm::Cortex::M0PLUS::Peripheral::NVIC interface.
 */

#ifndef PICOLIBRARY_ARM_CORTEX_M0PLUS_PERIPHERAL_NVIC_H
#define PICOLIBRARY_ARM_CORTEX_M0PLUS_PERIPHERAL_NVIC_H

#include <cstdint>

#include "picolibrary/register.h"

namespace picolibrary::Arm::Cortex::M0PLUS::Peripheral {

/**
 * \brief Arm Cortex-M0+ Nested Vectored Interrupt Controller (NVIC) peripheral.
 */
class NVIC {
  public:
    /**
     * \brief Interrupt Set-Enable Register (ISER) register.
     */
    Register<std::uint32_t> iser;

    /**
     * \brief Reserved registers (offset 0x004-0x07F).
     */
    Reserved_Register<std::uint32_t> reserved_0x004_0x07F[ ( ( 0x07F - 0x004 ) + 1 ) / 4 ];

    /**
     * \brief Interrupt Clear-Enable Register (ICER) register.
     */
    Register<std::uint32_t> icer;

    /**
     * \brief Reserved registers (offset 0x084-0x0FF).
     */
    Reserved_Register<std::uint32_t> reserved_0x084_0x0FF[ ( ( 0x0FF - 0x084 ) + 1 ) / 4 ];

    /**
     * \brief Interrupt Set-Pending Register (ISPR) register.
     */
    Register<std::uint32_t> ispr;

    /**
     * \brief Reserved registers (offset 0x104-0x17F).
     */
    Reserved_Register<std::uint32_t> reserved_0x104_0x17F[ ( ( 0x17F - 0x104 ) + 1 ) / 4 ];

    /**
     * \brief Interrupt Clear-Pending Register (ICPR) register.
     */
    Register<std::uint32_t> icpr;

    /**
     * \brief Reserved registers (offset 0x184-0x1FF).
     */
    Reserved_Register<std::uint32_t> reserved_0x184_0x1FF[ ( ( 0x1FF - 0x184 ) + 1 ) / 4 ];

    /**
     * \brief Reserved registers (offset 0x200-0x2FF).
     */
    Reserved_Register<std::uint32_t> reserved_0x200_0x2FF[ ( ( 0x2FF - 0x200 ) + 1 ) / 4 ];

    /**
     * \brief Interrupt Priority Register (IPR) registers.
     */
    Register<std::uint32_t> ipr[ ( 7 - 0 ) + 1 ];

    /**
     * \brief Reserved registers (offset 0x320-0x3EF).
     */
    Reserved_Register<std::uint32_t> reserved_0x320_0x3EF[ ( ( 0x3EF - 0x320 ) + 1 ) / 4 ];

    NVIC() = delete;

    NVIC( NVIC && ) = delete;

    NVIC( NVIC const & ) = delete;

    ~NVIC() = delete;

    auto operator=( NVIC && ) = delete;

    auto operator=( NVIC const & ) = delete;
};

} // namespace picolibrary::Arm::Cortex::M0PLUS::Peripheral

#endif // PICOLIBRARY_ARM_CORTEX_M0PLUS_PERIPHERAL_NVIC_H

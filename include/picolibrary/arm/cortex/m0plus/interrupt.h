/**
 * picolibrary-arm-cortex-m0plus
 *
 * Copyright 2023-2024, Andrew Countryman <apcountryman@gmail.com> and the
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
 * \brief picolibrary::Arm::Cortex::M0PLUS::Interrupt interface.
 */

#ifndef PICOLIBRARY_ARM_CORTEX_M0PLUS_INTERRUPT_H
#define PICOLIBRARY_ARM_CORTEX_M0PLUS_INTERRUPT_H

#include "picolibrary/arm/cortex/m0plus/configuration.h"

/**
 * \brief Arm Cortex-M0+ interrupt facilities.
 */
namespace picolibrary::Arm::Cortex::M0PLUS::Interrupt {

/**
 * \brief Interrupt handler.
 */
using Handler = void ( * )();

#define PICOLIBRARY_ARM_CORTEX_M0PLUS_INTERRUPT_VECTOR_TABLE_ALIGNMENT alignas( 256 )

/**
 * \brief Interrupt vector table.
 */
struct PICOLIBRARY_ARM_CORTEX_M0PLUS_INTERRUPT_VECTOR_TABLE_ALIGNMENT Vector_Table {
    /**
     * \brief Initial stack pointer value.
     */
    void * stack;

    /**
     * \brief Reset handler.
     */
    Handler reset_handler;

    /**
     * \brief Non-Maskable Interrupt (NMI) handler.
     */
    Handler nonmaskable_interrupt_handler;

    /**
     * \brief Hard fault handler.
     */
    Handler hard_fault_handler;

    /**
     * \brief Reserved (IRQ -12).
     */
    Handler reserved_n12;

    /**
     * \brief Reserved (IRQ -11).
     */
    Handler reserved_n11;

    /**
     * \brief Reserved (IRQ -10).
     */
    Handler reserved_n10;

    /**
     * \brief Reserved (IRQ -9).
     */
    Handler reserved_n9;

    /**
     * \brief Reserved (IRQ -8).
     */
    Handler reserved_n8;

    /**
     * \brief Reserved (IRQ -7).
     */
    Handler reserved_n7;

    /**
     * \brief Reserved (IRQ -6).
     */
    Handler reserved_n6;

    /**
     * \brief Supervisor Call (SVCALL) handler.
     */
    Handler supervisor_call_handler;

    /**
     * \brief Reserved (IRQ -4).
     */
    Handler reserved_n4;

    /**
     * \brief Reserved (IRQ -3).
     */
    Handler reserved_n3;

    /**
     * \brief Context Switch (PENDSV) handler.
     */
    Handler context_switch_handler;

#if PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SYSTICK
    /**
     * \brief System Tick (SYSTICK) handler.
     */
    Handler system_tick_handler;
#else  // PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SYSTICK
    /**
     * \brief Reserved (IRQ -1).
     */
    Handler reserved_n1;
#endif // PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SYSTICK

#include "picolibrary/arm/cortex/m0plus/implementation/interrupt/vectors.h"
};

} // namespace picolibrary::Arm::Cortex::M0PLUS::Interrupt

#endif // PICOLIBRARY_ARM_CORTEX_M0PLUS_INTERRUPT_H

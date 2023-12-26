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
 * \brief picolibrary::Arm::Cortex::M0PLUS::Peripheral::SCB interface.
 */

#ifndef PICOLIBRARY_ARM_CORTEX_M0PLUS_PERIPHERAL_SCB_H
#define PICOLIBRARY_ARM_CORTEX_M0PLUS_PERIPHERAL_SCB_H

#include <cstdint>

#include "picolibrary/arm/cortex/m0plus/configuration.h"
#include "picolibrary/bit_manipulation.h"
#include "picolibrary/register.h"

namespace picolibrary::Arm::Cortex::M0PLUS::Peripheral {

/**
 * \brief Arm Cortex-M0+ System Control Block (SCB) peripheral.
 */
class SCB {
  public:
    /**
     * \brief CPUID (CPUID) register.
     *
     * This register has the following fields:
     * - Minor Revision Number (REVISION)
     * - Processor Part Number (PARTNO)
     * - Processor Architecture (ARCHITECTURE)
     * - Major Revision Number (VARIANT)
     * - Implementer Code (IMPLEMENTER)
     */
    class CPUID : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto REVISION     = std::uint_fast8_t{ 4 };  ///< REVISION.
            static constexpr auto PARTNO       = std::uint_fast8_t{ 12 }; ///< PARTNO.
            static constexpr auto ARCHITECTURE = std::uint_fast8_t{ 4 }; ///< ARCHITECTURE.
            static constexpr auto VARIANT      = std::uint_fast8_t{ 4 }; ///< VARIANT.
            static constexpr auto IMPLEMENTER  = std::uint_fast8_t{ 8 }; ///< IMPLEMENTER.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto REVISION = std::uint_fast8_t{}; ///< REVISION.
            static constexpr auto PARTNO = std::uint_fast8_t{ REVISION + Size::REVISION }; ///< PARTNO.
            static constexpr auto ARCHITECTURE = std::uint_fast8_t{ PARTNO + Size::PARTNO }; ///< ARCHITECTURE.
            static constexpr auto VARIANT = std::uint_fast8_t{ ARCHITECTURE + Size::ARCHITECTURE }; ///< VARIANT.
            static constexpr auto IMPLEMENTER = std::uint_fast8_t{ VARIANT + Size::VARIANT }; ///< IMPLEMENTER.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto REVISION = mask<std::uint32_t>( Size::REVISION, Bit::REVISION ); ///< REVISION.
            static constexpr auto PARTNO = mask<std::uint32_t>( Size::PARTNO, Bit::PARTNO ); ///< PARTNO.
            static constexpr auto ARCHITECTURE = mask<std::uint32_t>( Size::ARCHITECTURE, Bit::ARCHITECTURE ); ///< ARCHITECTURE.
            static constexpr auto VARIANT = mask<std::uint32_t>( Size::VARIANT, Bit::VARIANT ); ///< VARIANT.
            static constexpr auto IMPLEMENTER = mask<std::uint32_t>( Size::IMPLEMENTER, Bit::IMPLEMENTER ); ///< IMPLEMENTER.
        };

        CPUID() = delete;

        CPUID( CPUID && ) = delete;

        CPUID( CPUID const & ) = delete;

        ~CPUID() = delete;

        auto operator=( CPUID && ) = delete;

        auto operator=( CPUID const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief Interrupt Control and State (ICSR) register.
     *
     * This register has the following fields:
     * - Highest Priority Pending Interrupt Number (VECTPENDING)
     * - SYSTICK Clear-Pending Bit (PENDSTCLR) (only if
     *   PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SYSTICK is true)
     * - SYSTICK Set-Pending Bit (PENDSTSET) (only if
     *   PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SYSTICK is true)
     * - PENDSV Clear-Pending Bit (PENDSVCLR)
     * - PENDSV Set-Pending Bit (PENDSVSET)
     * - NMI Set-Pending Bit (NMIPENDSET)
     */
    class ICSR : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto RESERVED0   = std::uint_fast8_t{ 12 }; ///< RESERVED0.
            static constexpr auto VECTPENDING = std::uint_fast8_t{ 6 };  ///< VECTPENDING.
#if PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SYSTICK
            static constexpr auto RESERVED18 = std::uint_fast8_t{ 7 }; ///< RESERVED18.
            static constexpr auto PENDSTCLR  = std::uint_fast8_t{ 1 }; ///< PENDSTCLR.
            static constexpr auto PENDSTSET  = std::uint_fast8_t{ 1 }; ///< PENDSTSET.
#else  // PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SYSTICK
            static constexpr auto RESERVED18 = std::uint_fast8_t{ 9 }; ///< RESERVED18.
#endif // PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SYSTICK
            static constexpr auto PENDSVCLR  = std::uint_fast8_t{ 1 }; ///< PENDSVCLR.
            static constexpr auto PENDSVSET  = std::uint_fast8_t{ 1 }; ///< PENDSVSET.
            static constexpr auto RESERVED29 = std::uint_fast8_t{ 2 }; ///< RESERVED29.
            static constexpr auto NMIPENDSET = std::uint_fast8_t{ 1 }; ///< NMIPENDSET.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto RESERVED0 = std::uint_fast8_t{}; ///< RESERVED0.
            static constexpr auto VECTPENDING = std::uint_fast8_t{ RESERVED0 + Size::RESERVED0 }; ///< VECTPENDING.
            static constexpr auto RESERVED18 = std::uint_fast8_t{ VECTPENDING + Size::VECTPENDING }; ///< RESERVED18.
#if PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SYSTICK
            static constexpr auto PENDSTCLR = std::uint_fast8_t{ RESERVED18 + Size::RESERVED18 }; ///< PENDSTCLR.
            static constexpr auto PENDSTSET = std::uint_fast8_t{ PENDSTCLR + Size::PENDSTCLR }; ///< PENDSTSET.
            static constexpr auto PENDSVCLR = std::uint_fast8_t{ PENDSTSET + Size::PENDSTSET }; ///< PENDSVCLR.
#else  // PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SYSTICK
            static constexpr auto PENDSVCLR = std::uint_fast8_t{ RESERVED18 + Size::RESERVED18 }; ///< PENDSVCLR.
#endif // PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SYSTICK
            static constexpr auto PENDSVSET = std::uint_fast8_t{ PENDSVCLR + Size::PENDSVCLR }; ///< PENDSVSET.
            static constexpr auto RESERVED29 = std::uint_fast8_t{ PENDSVSET + Size::PENDSVSET }; ///< RESERVED29.
            static constexpr auto NMIPENDSET = std::uint_fast8_t{ RESERVED29 + Size::RESERVED29 }; ///< NMIPENDSET.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto RESERVED0 = mask<std::uint32_t>( Size::RESERVED0, Bit::RESERVED0 ); ///< RESERVED0.
            static constexpr auto VECTPENDING = mask<std::uint32_t>( Size::VECTPENDING, Bit::VECTPENDING ); ///< VECTPENDING.
            static constexpr auto RESERVED18 = mask<std::uint32_t>( Size::RESERVED18, Bit::RESERVED18 ); ///< RESERVED18.
#if PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SYSTICK
            static constexpr auto PENDSTCLR = mask<std::uint32_t>( Size::PENDSTCLR, Bit::PENDSTCLR ); ///< PENDSTCLR.
            static constexpr auto PENDSTSET = mask<std::uint32_t>( Size::PENDSTSET, Bit::PENDSTSET ); ///< PENDSTSET.
#endif // PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SYSTICK
            static constexpr auto PENDSVCLR = mask<std::uint32_t>( Size::PENDSVCLR, Bit::PENDSVCLR ); ///< PENDSVCLR.
            static constexpr auto PENDSVSET = mask<std::uint32_t>( Size::PENDSVSET, Bit::PENDSVSET ); ///< PENDSVSET.
            static constexpr auto RESERVED29 = mask<std::uint32_t>( Size::RESERVED29, Bit::RESERVED29 ); ///< RESERVED29.
            static constexpr auto NMIPENDSET = mask<std::uint32_t>( Size::NMIPENDSET, Bit::NMIPENDSET ); ///< NMIPENDSET.
        };

        ICSR() = delete;

        ICSR( ICSR && ) = delete;

        ICSR( ICSR const & ) = delete;

        ~ICSR() = delete;

        auto operator=( ICSR && ) = delete;

        auto operator=( ICSR const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

#if PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SCB_VTOR
    /**
     * \brief Vector Table Offset Register (VTOR) register.
     *
     * This register has the following fields:
     * - Vector Table Base Offset (TBLOFF)
     */
    class VTOR : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto RESERVD0 = std::uint_fast8_t{ 7 };  ///< RESERVD0.
            static constexpr auto TBLOFF   = std::uint_fast8_t{ 25 }; ///< TBLOFF.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto RESERVD0 = std::uint_fast8_t{}; ///< RESERVD0.
            static constexpr auto TBLOFF = std::uint_fast8_t{ RESERVD0 + Size::RESERVD0 }; ///< TBLOFF.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto RESERVD0 = mask<std::uint32_t>( Size::RESERVD0, Bit::RESERVD0 ); ///< RESERVD0.
            static constexpr auto TBLOFF = mask<std::uint32_t>( Size::TBLOFF, Bit::TBLOFF ); ///< TBLOFF.
        };

        VTOR() = delete;

        VTOR( VTOR && ) = delete;

        VTOR( VTOR const & ) = delete;

        ~VTOR() = delete;

        auto operator=( VTOR && ) = delete;

        auto operator=( VTOR const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };
#endif // PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SCB_VTOR

    /**
     * \brief Application Interrupt and Reset Control Register (AIRCR) register.
     *
     * This register has the following fields:
     * - Interrupt Clear-Active Bit (VECTCLRACTIVE)
     * - System Reset Request (SYSRESETREQ)
     * - Implementation Endianness (ENDIANESS)
     * - Register Key (VECTKEY)
     */
    class AIRCR : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto RESERVED0     = std::uint_fast8_t{ 1 }; ///< RESERVED0.
            static constexpr auto VECTCLRACTIVE = std::uint_fast8_t{ 1 }; ///< VECTCLRACTIVE.
            static constexpr auto SYSRESETREQ = std::uint_fast8_t{ 1 };  ///< SYSRESETREQ.
            static constexpr auto RESERVED3   = std::uint_fast8_t{ 12 }; ///< RESERVED3.
            static constexpr auto ENDIANESS   = std::uint_fast8_t{ 1 };  ///< ENDIANESS.
            static constexpr auto VECTKEY     = std::uint_fast8_t{ 16 }; ///< VECTKEY.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto RESERVED0 = std::uint_fast8_t{}; ///< RESERVED0.
            static constexpr auto VECTCLRACTIVE = std::uint_fast8_t{ RESERVED0 + Size::RESERVED0 }; ///< VECTCLRACTIVE.
            static constexpr auto SYSRESETREQ = std::uint_fast8_t{ VECTCLRACTIVE + Size::VECTCLRACTIVE }; ///< SYSRESETREQ.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ SYSRESETREQ + Size::SYSRESETREQ }; ///< RESERVED3.
            static constexpr auto ENDIANESS = std::uint_fast8_t{ RESERVED3 + Size::RESERVED3 }; ///< ENDIANESS.
            static constexpr auto VECTKEY = std::uint_fast8_t{ ENDIANESS + Size::ENDIANESS }; ///< VECTKEY.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto RESERVED0 = mask<std::uint32_t>( Size::RESERVED0, Bit::RESERVED0 ); ///< RESERVED0.
            static constexpr auto VECTCLRACTIVE = mask<std::uint32_t>(
                Size::VECTCLRACTIVE,
                Bit::VECTCLRACTIVE ); ///< VECTCLRACTIVE.
            static constexpr auto SYSRESETREQ = mask<std::uint32_t>( Size::SYSRESETREQ, Bit::SYSRESETREQ ); ///< SYSRESETREQ.
            static constexpr auto RESERVED3 = mask<std::uint32_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
            static constexpr auto ENDIANESS = mask<std::uint32_t>( Size::ENDIANESS, Bit::ENDIANESS ); ///< ENDIANESS.
            static constexpr auto VECTKEY = mask<std::uint32_t>( Size::VECTKEY, Bit::VECTKEY ); ///< VECTKEY.
        };

        AIRCR() = delete;

        AIRCR( AIRCR && ) = delete;

        AIRCR( AIRCR const & ) = delete;

        ~AIRCR() = delete;

        auto operator=( AIRCR && ) = delete;

        auto operator=( AIRCR const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief System Control Register (SCR) register.
     *
     * This register has the following fields:
     * - Sleep-On-Exit (SLEEPONEXIT)
     * - Deep Sleep (SLEEPDEEP)
     * - Send Event on Pending (SEVONPEND)
     */
    class SCR : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto RESERVED0   = std::uint_fast8_t{ 1 };  ///< RESERVED0.
            static constexpr auto SLEEPONEXIT = std::uint_fast8_t{ 1 };  ///< SLEEPONEXIT.
            static constexpr auto SLEEPDEEP   = std::uint_fast8_t{ 1 };  ///< SLEEPDEEP.
            static constexpr auto RESERVED3   = std::uint_fast8_t{ 1 };  ///< RESERVED3.
            static constexpr auto SEVONPEND   = std::uint_fast8_t{ 1 };  ///< SEVONPEND.
            static constexpr auto RESERVED5   = std::uint_fast8_t{ 27 }; ///< RESERVED5.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto RESERVED0 = std::uint_fast8_t{}; ///< RESERVED0.
            static constexpr auto SLEEPONEXIT = std::uint_fast8_t{ RESERVED0 + Size::RESERVED0 }; ///< SLEEPONEXIT.
            static constexpr auto SLEEPDEEP = std::uint_fast8_t{ SLEEPONEXIT + Size::SLEEPONEXIT }; ///< SLEEPDEEP.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ SLEEPDEEP + Size::SLEEPDEEP }; ///< RESERVED3.
            static constexpr auto SEVONPEND = std::uint_fast8_t{ RESERVED3 + Size::RESERVED3 }; ///< SEVONPEND.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ SEVONPEND + Size::SEVONPEND }; ///< RESERVED5.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto RESERVED0 = mask<std::uint32_t>( Size::RESERVED0, Bit::RESERVED0 ); ///< RESERVED0.
            static constexpr auto SLEEPONEXIT = mask<std::uint32_t>( Size::SLEEPONEXIT, Bit::SLEEPONEXIT ); ///< SLEEPONEXIT.
            static constexpr auto SLEEPDEEP = mask<std::uint32_t>( Size::SLEEPDEEP, Bit::SLEEPDEEP ); ///< SLEEPDEEP.
            static constexpr auto RESERVED3 = mask<std::uint32_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
            static constexpr auto SEVONPEND = mask<std::uint32_t>( Size::SEVONPEND, Bit::SEVONPEND ); ///< SEVONPEND.
            static constexpr auto RESERVED5 = mask<std::uint32_t>( Size::RESERVED5, Bit::RESERVED5 ); ///< RESERVED5.
        };

        SCR() = delete;

        SCR( SCR && ) = delete;

        SCR( SCR const & ) = delete;

        ~SCR() = delete;

        auto operator=( SCR && ) = delete;

        auto operator=( SCR const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief Configuration and Control Register (CCR) register.
     *
     * This register has the following fields:
     * - Unaligned Accesses Generate Hard Fault (UNALIGN_TRP)
     * - 8-Byte Stack Alignment on Interrupt Entry (STKALIGN)
     */
    class CCR : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto RESERVED0   = std::uint_fast8_t{ 3 };  ///< RESERVED0.
            static constexpr auto UNALIGN_TRP = std::uint_fast8_t{ 1 };  ///< UNALIGN_TRP.
            static constexpr auto RESERVED4   = std::uint_fast8_t{ 5 };  ///< RESERVED4.
            static constexpr auto STKALIGN    = std::uint_fast8_t{ 1 };  ///< STKALIGN.
            static constexpr auto RESERVED10  = std::uint_fast8_t{ 22 }; ///< RESERVED10.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto RESERVED0 = std::uint_fast8_t{}; ///< RESERVED0.
            static constexpr auto UNALIGN_TRP = std::uint_fast8_t{ RESERVED0 + Size::RESERVED0 }; ///< UNALIGN_TRP.
            static constexpr auto RESERVED4 = std::uint_fast8_t{ UNALIGN_TRP + Size::UNALIGN_TRP }; ///< RESERVED4.
            static constexpr auto STKALIGN = std::uint_fast8_t{ RESERVED4 + Size::RESERVED4 }; ///< STKALIGN.
            static constexpr auto RESERVED10 = std::uint_fast8_t{ STKALIGN + Size::STKALIGN }; ///< RESERVED10.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto RESERVED0 = mask<std::uint32_t>( Size::RESERVED0, Bit::RESERVED0 ); ///< RESERVED0.
            static constexpr auto UNALIGN_TRP = mask<std::uint32_t>( Size::UNALIGN_TRP, Bit::UNALIGN_TRP ); ///< UNALIGN_TRP.
            static constexpr auto RESERVED4 = mask<std::uint32_t>( Size::RESERVED4, Bit::RESERVED4 ); ///< RESERVED4.
            static constexpr auto STKALIGN = mask<std::uint32_t>( Size::STKALIGN, Bit::STKALIGN ); ///< STKALIGN.
            static constexpr auto RESERVED10 = mask<std::uint32_t>( Size::RESERVED10, Bit::RESERVED10 ); ///< RESERVED10.
        };

        CCR() = delete;

        CCR( CCR && ) = delete;

        CCR( CCR const & ) = delete;

        ~CCR() = delete;

        auto operator=( CCR && ) = delete;

        auto operator=( CCR const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief CPUID.
     */
    CPUID const cpuid;

    /**
     * \brief ICSR.
     */
    ICSR icsr;

#if PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SCB_VTOR
    /**
     * \brief VTOR.
     */
    VTOR vtor;
#else  // PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SCB_VTOR
    /**
     * \brief Reserved registers (offset 0x08-0x0B).
     */
    Reserved_Register<std::uint32_t> reserved_0x08_0x0B[ ( ( 0x0B - 0x08 ) + 1 ) / 4 ];
#endif // PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SCB_VTOR

    /**
     * \brief AIRCR.
     */
    AIRCR aircr;

    /**
     * \brief SCR.
     */
    SCR scr;

    /**
     * \brief CCR.
     */
    CCR const ccr;

    /**
     * \brief Reserved registers (offset 0x18-0x1B).
     */
    Reserved_Register<std::uint32_t> reserved_0x18_0x1B[ ( ( 0x1B - 0x18 ) + 1 ) / 4 ];

    /**
     * \brief System Handler Priority Register (SHPR) registers.
     */
    Register<std::uint32_t> shpr[ ( 3 - 2 ) + 1 ];

    SCB() = delete;

    SCB( SCB && ) = delete;

    SCB( SCB const & ) = delete;

    ~SCB() = delete;

    auto operator=( SCB && ) = delete;

    auto operator=( SCB const & ) = delete;
};

} // namespace picolibrary::Arm::Cortex::M0PLUS::Peripheral

#endif // PICOLIBRARY_ARM_CORTEX_M0PLUS_PERIPHERAL_SCB_H

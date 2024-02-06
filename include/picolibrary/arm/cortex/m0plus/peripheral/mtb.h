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
 * \brief picolibrary::Arm::Cortex::M0PLUS::Peripheral::MTB interface.
 */

#ifndef PICOLIBRARY_ARM_CORTEX_M0PLUS_PERIPHERAL_MTB_H
#define PICOLIBRARY_ARM_CORTEX_M0PLUS_PERIPHERAL_MTB_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/register.h"

namespace picolibrary::Arm::Cortex::M0PLUS::Peripheral {

/**
 * \brief Arm Cortex-M0+ Micro Trace Buffer (MTB) peripheral.
 */
class MTB {
  public:
    /**
     * \brief Position (POSITION) register.
     *
     * This register has the following fields:
     * - Pointer Wrap (WRAP)
     * - Trace Packet Location Pointer (POINTER)
     */
    class POSITION : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto RESERVED0 = std::uint_fast8_t{ 2 };  ///< RESERVED0.
            static constexpr auto WRAP      = std::uint_fast8_t{ 1 };  ///< WRAP.
            static constexpr auto POINTER   = std::uint_fast8_t{ 29 }; ///< POINTER.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto RESERVED0 = std::uint_fast8_t{}; ///< RESERVED0.
            static constexpr auto WRAP = std::uint_fast8_t{ RESERVED0 + Size::RESERVED0 }; ///< WRAP.
            static constexpr auto POINTER = std::uint_fast8_t{ WRAP + Size::WRAP }; ///< POINTER.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto RESERVED0 = mask<std::uint32_t>( Size::RESERVED0, Bit::RESERVED0 ); ///< RESERVED0.
            static constexpr auto WRAP = mask<std::uint32_t>( Size::WRAP, Bit::WRAP ); ///< WRAP.
            static constexpr auto POINTER = mask<std::uint32_t>( Size::POINTER, Bit::POINTER ); ///< POINTER.
        };

        POSITION() = delete;

        POSITION( POSITION && ) = delete;

        POSITION( POSITION const & ) = delete;

        ~POSITION() = delete;

        auto operator=( POSITION && ) = delete;

        auto operator=( POSITION const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief Master (MASTER) register.
     *
     * This register has the following fields:
     * - Mask (MASK)
     * - Trace Start Input Enable (TSTARTEN)
     * - Trace Stop Input Enable (TSTOPEN)
     * - Special Function Register Write Privilege (SFRWPRIV)
     * - SRAM Privilege (RAMPRIV)
     * - Halt Request (HALTREQ)
     * - Main Trace Enable (EN)
     */
    class MASTER : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto MASK       = std::uint_fast8_t{ 5 };  ///< MASK.
            static constexpr auto TSTARTEN   = std::uint_fast8_t{ 1 };  ///< TSTARTEN.
            static constexpr auto TSTOPEN    = std::uint_fast8_t{ 1 };  ///< TSTOPEN.
            static constexpr auto SFRWPRIV   = std::uint_fast8_t{ 1 };  ///< SFRWPRIV.
            static constexpr auto RAMPRIV    = std::uint_fast8_t{ 1 };  ///< RAMPRIV.
            static constexpr auto HALTREQ    = std::uint_fast8_t{ 1 };  ///< HALTREQ.
            static constexpr auto RESERVED10 = std::uint_fast8_t{ 21 }; ///< RESERVED10.
            static constexpr auto EN         = std::uint_fast8_t{ 1 };  ///< EN.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto MASK = std::uint_fast8_t{}; ///< MASK.
            static constexpr auto TSTARTEN = std::uint_fast8_t{ MASK + Size::MASK }; ///< TSTARTEN.
            static constexpr auto TSTOPEN = std::uint_fast8_t{ TSTARTEN + Size::TSTARTEN }; ///< TSTOPEN.
            static constexpr auto SFRWPRIV = std::uint_fast8_t{ TSTOPEN + Size::TSTOPEN }; ///< SFRWPRIV.
            static constexpr auto RAMPRIV = std::uint_fast8_t{ SFRWPRIV + Size::SFRWPRIV }; ///< RAMPRIV.
            static constexpr auto HALTREQ = std::uint_fast8_t{ RAMPRIV + Size::RAMPRIV }; ///< HALTREQ.
            static constexpr auto RESERVED10 = std::uint_fast8_t{ HALTREQ + Size::HALTREQ }; ///< RESERVED10.
            static constexpr auto EN = std::uint_fast8_t{ RESERVED10 + Size::RESERVED10 }; ///< EN.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto MASK = mask<std::uint32_t>( Size::MASK, Bit::MASK ); ///< MASK.
            static constexpr auto TSTARTEN = mask<std::uint32_t>( Size::TSTARTEN, Bit::TSTARTEN ); ///< TSTARTEN.
            static constexpr auto TSTOPEN = mask<std::uint32_t>( Size::TSTOPEN, Bit::TSTOPEN ); ///< TSTOPEN.
            static constexpr auto SFRWPRIV = mask<std::uint32_t>( Size::SFRWPRIV, Bit::SFRWPRIV ); ///< SFRWPRIV.
            static constexpr auto RAMPRIV = mask<std::uint32_t>( Size::RAMPRIV, Bit::RAMPRIV ); ///< RAMPRIV.
            static constexpr auto HALTREQ = mask<std::uint32_t>( Size::HALTREQ, Bit::HALTREQ ); ///< HALTREQ.
            static constexpr auto RESERVED10 = mask<std::uint32_t>( Size::RESERVED10, Bit::RESERVED10 ); ///< RESERVED10.
            static constexpr auto EN = mask<std::uint32_t>( Size::EN, Bit::EN ); ///< EN.
        };

        MASTER() = delete;

        MASTER( MASTER && ) = delete;

        MASTER( MASTER const & ) = delete;

        ~MASTER() = delete;

        auto operator=( MASTER && ) = delete;

        auto operator=( MASTER const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief Flow (FLOW) register.
     *
     * This register has the following fields:
     * - Autostop (AUTOSTOP)
     * - Autohalt (AUTOHALT)
     * - Watermark Value (WATERMARK)
     */
    class FLOW : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto AUTOSTOP  = std::uint_fast8_t{ 1 };  ///< AUTOSTOP.
            static constexpr auto AUTOHALT  = std::uint_fast8_t{ 1 };  ///< AUTOHALT.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ 1 };  ///< RESERVED2.
            static constexpr auto WATERMARK = std::uint_fast8_t{ 29 }; ///< WATERMARK.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto AUTOSTOP = std::uint_fast8_t{}; ///< AUTOSTOP.
            static constexpr auto AUTOHALT = std::uint_fast8_t{ AUTOSTOP + Size::AUTOSTOP }; ///< AUTOHALT.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ AUTOHALT + Size::AUTOHALT }; ///< RESERVED2.
            static constexpr auto WATERMARK = std::uint_fast8_t{ RESERVED2 + Size::RESERVED2 }; ///< WATERMARK.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto AUTOSTOP = mask<std::uint32_t>( Size::AUTOSTOP, Bit::AUTOSTOP ); ///< AUTOSTOP.
            static constexpr auto AUTOHALT = mask<std::uint32_t>( Size::AUTOHALT, Bit::AUTOHALT ); ///< AUTOHALT.
            static constexpr auto RESERVED2 = mask<std::uint32_t>( Size::RESERVED2, Bit::RESERVED2 ); ///< RESERVED2.
            static constexpr auto WATERMARK = mask<std::uint32_t>( Size::WATERMARK, Bit::WATERMARK ); ///< WATERMARK.
        };

        FLOW() = delete;

        FLOW( FLOW && ) = delete;

        FLOW( FLOW const & ) = delete;

        ~FLOW() = delete;

        auto operator=( FLOW && ) = delete;

        auto operator=( FLOW const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief Integration Mode Control (ITCTRL) register.
     *
     * This register has the following fields:
     * - Integration Mode Enable (IME)
     */
    class ITCTRL : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto IME       = std::uint_fast8_t{ 1 };  ///< IME.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 31 }; ///< RESERVED1.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto IME = std::uint_fast8_t{}; ///< IME.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ IME + Size::IME }; ///< RESERVED1.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto IME = mask<std::uint32_t>( Size::IME, Bit::IME ); ///< IME.
            static constexpr auto RESERVED1 = mask<std::uint32_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
        };

        ITCTRL() = delete;

        ITCTRL( ITCTRL && ) = delete;

        ITCTRL( ITCTRL const & ) = delete;

        ~ITCTRL() = delete;

        auto operator=( ITCTRL && ) = delete;

        auto operator=( ITCTRL const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief Software Lock Status (LSR) register.
     *
     * This register has the following fields:
     * - Software Lock Implemented (SLI)
     * - Software Lock Status (SLK)
     * - NTT (NTT)
     */
    class LSR : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto SLI       = std::uint_fast8_t{ 1 };  ///< SLI.
            static constexpr auto SLK       = std::uint_fast8_t{ 1 };  ///< SLK.
            static constexpr auto NTT       = std::uint_fast8_t{ 1 };  ///< NTT.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 29 }; ///< RESERVED3.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto SLI = std::uint_fast8_t{};                  ///< SLI.
            static constexpr auto SLK = std::uint_fast8_t{ SLI + Size::SLI }; ///< SLK.
            static constexpr auto NTT = std::uint_fast8_t{ SLK + Size::SLK }; ///< NTT.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ NTT + Size::NTT }; ///< RESERVED3.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto SLI = mask<std::uint32_t>( Size::SLI, Bit::SLI ); ///< SLI.
            static constexpr auto SLK = mask<std::uint32_t>( Size::SLK, Bit::SLK ); ///< SLK.
            static constexpr auto NTT = mask<std::uint32_t>( Size::NTT, Bit::NTT ); ///< NTT.
            static constexpr auto RESERVED3 = mask<std::uint32_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
        };

        LSR() = delete;

        LSR( LSR && ) = delete;

        LSR( LSR const & ) = delete;

        ~LSR() = delete;

        auto operator=( LSR && ) = delete;

        auto operator=( LSR const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief Authentication Status (AUTHSTATUS) register.
     *
     * This register has the following fields:
     * - Non-Secure Invasive Debug (NSID)
     * - Non-Secure Noninvasive Debug (NSNID)
     * - Secure Invasive Debug (SID)
     * - Secure Noninvasive Debug (SNID)
     * - Hypervisor Invasive Debug (HID)
     * - Hypervisor Noninvasive Debug (HNID)
     */
    class AUTHSTATUS : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto NSID       = std::uint_fast8_t{ 2 };  ///< NSID.
            static constexpr auto NSNID      = std::uint_fast8_t{ 2 };  ///< NSNID.
            static constexpr auto SID        = std::uint_fast8_t{ 2 };  ///< SID.
            static constexpr auto SNID       = std::uint_fast8_t{ 2 };  ///< SNID.
            static constexpr auto HID        = std::uint_fast8_t{ 2 };  ///< HID.
            static constexpr auto HNID       = std::uint_fast8_t{ 2 };  ///< HNID.
            static constexpr auto RESERVED12 = std::uint_fast8_t{ 20 }; ///< RESERVED12.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto NSID = std::uint_fast8_t{}; ///< NSID.
            static constexpr auto NSNID = std::uint_fast8_t{ NSID + Size::NSID }; ///< NSNID.
            static constexpr auto SID = std::uint_fast8_t{ NSNID + Size::NSNID }; ///< SID.
            static constexpr auto SNID = std::uint_fast8_t{ SID + Size::SID }; ///< SNID.
            static constexpr auto HID  = std::uint_fast8_t{ SNID + Size::SNID }; ///< HID.
            static constexpr auto HNID = std::uint_fast8_t{ HID + Size::HID }; ///< HNID.
            static constexpr auto RESERVED12 = std::uint_fast8_t{ HNID + Size::HNID }; ///< RESERVED12.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto NSID = mask<std::uint32_t>( Size::NSID, Bit::NSID ); ///< NSID.
            static constexpr auto NSNID = mask<std::uint32_t>( Size::NSNID, Bit::NSNID ); ///< NSNID.
            static constexpr auto SID = mask<std::uint32_t>( Size::SID, Bit::SID ); ///< SID.
            static constexpr auto SNID = mask<std::uint32_t>( Size::SNID, Bit::SNID ); ///< SNID.
            static constexpr auto HID = mask<std::uint32_t>( Size::HID, Bit::HID ); ///< HID.
            static constexpr auto HNID = mask<std::uint32_t>( Size::HNID, Bit::HNID ); ///< HNID.
            static constexpr auto RESERVED12 = mask<std::uint32_t>( Size::RESERVED12, Bit::RESERVED12 ); ///< RESERVED12.
        };

        AUTHSTATUS() = delete;

        AUTHSTATUS( AUTHSTATUS && ) = delete;

        AUTHSTATUS( AUTHSTATUS const & ) = delete;

        ~AUTHSTATUS() = delete;

        auto operator=( AUTHSTATUS && ) = delete;

        auto operator=( AUTHSTATUS const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief Device Architecture (DEVARCH) register.
     *
     * This register has the following fields:
     * - Architecture ID (ARCHID)
     * - Architecture Revision (REVISION)
     * - DEVARCH Present (PRESENT)
     * - Architect (ARCHITECT)
     */
    class DEVARCH : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto ARCHID    = std::uint_fast8_t{ 16 }; ///< ARCHID.
            static constexpr auto REVISION  = std::uint_fast8_t{ 4 };  ///< REVISION.
            static constexpr auto PRESENT   = std::uint_fast8_t{ 1 };  ///< PRESENT.
            static constexpr auto ARCHITECT = std::uint_fast8_t{ 11 }; ///< ARCHITECT.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto ARCHID = std::uint_fast8_t{}; ///< ARCHID.
            static constexpr auto REVISION = std::uint_fast8_t{ ARCHID + Size::ARCHID }; ///< REVISION.
            static constexpr auto PRESENT = std::uint_fast8_t{ REVISION + Size::REVISION }; ///< PRESENT.
            static constexpr auto ARCHITECT = std::uint_fast8_t{ PRESENT + Size::PRESENT }; ///< ARCHITECT.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto ARCHID = mask<std::uint32_t>( Size::ARCHID, Bit::ARCHID ); ///< ARCHID.
            static constexpr auto REVISION = mask<std::uint32_t>( Size::REVISION, Bit::REVISION ); ///< REVISION.
            static constexpr auto PRESENT = mask<std::uint32_t>( Size::PRESENT, Bit::PRESENT ); ///< PRESENT.
            static constexpr auto ARCHITECT = mask<std::uint32_t>( Size::ARCHITECT, Bit::ARCHITECT ); ///< ARCHITECT.
        };

        DEVARCH() = delete;

        DEVARCH( DEVARCH && ) = delete;

        DEVARCH( DEVARCH const & ) = delete;

        ~DEVARCH() = delete;

        auto operator=( DEVARCH && ) = delete;

        auto operator=( DEVARCH const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief Device Type Identifier (DEVTYPE) register.
     *
     * This register has the following fields:
     * - Major Type (MAJOR)
     * - Sub Type (SUB)
     */
    class DEVTYPE : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto MAJOR     = std::uint_fast8_t{ 4 };  ///< MAJOR.
            static constexpr auto SUB       = std::uint_fast8_t{ 4 };  ///< SUB.
            static constexpr auto RESERVED8 = std::uint_fast8_t{ 24 }; ///< RESERVED8.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto MAJOR = std::uint_fast8_t{}; ///< MAJOR.
            static constexpr auto SUB = std::uint_fast8_t{ MAJOR + Size::MAJOR }; ///< SUB.
            static constexpr auto RESERVED8 = std::uint_fast8_t{ SUB + Size::SUB }; ///< RESERVED8.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto MAJOR = mask<std::uint32_t>( Size::MAJOR, Bit::MAJOR ); ///< MAJOR.
            static constexpr auto SUB = mask<std::uint32_t>( Size::SUB, Bit::SUB ); ///< SUB.
            static constexpr auto RESERVED8 = mask<std::uint32_t>( Size::RESERVED8, Bit::RESERVED8 ); ///< RESERVED8.
        };

        DEVTYPE() = delete;

        DEVTYPE( DEVTYPE && ) = delete;

        DEVTYPE( DEVTYPE const & ) = delete;

        ~DEVTYPE() = delete;

        auto operator=( DEVTYPE && ) = delete;

        auto operator=( DEVTYPE const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief Peripheral Identification Register 4 (PIDR4) register.
     *
     * This register has the following fields:
     * - JEP106 Continuation Code (DES_2)
     * - Component Memory Size (SIZE)
     */
    class PIDR4 : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto DES_2     = std::uint_fast8_t{ 1 }; ///< DES_2.
            static constexpr auto SIZE      = std::uint_fast8_t{ 1 }; ///< SIZE.
            static constexpr auto RESERVED8 = std::uint_fast8_t{ 1 }; ///< RESERVED8.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto DES_2 = std::uint_fast8_t{}; ///< DES_2.
            static constexpr auto SIZE = std::uint_fast8_t{ DES_2 + Size::DES_2 }; ///< SIZE.
            static constexpr auto RESERVED8 = std::uint_fast8_t{ SIZE + Size::SIZE }; ///< RESERVED8.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto DES_2 = mask<std::uint32_t>( Size::DES_2, Bit::DES_2 ); ///< DES_2.
            static constexpr auto SIZE = mask<std::uint32_t>( Size::SIZE, Bit::SIZE ); ///< SIZE.
            static constexpr auto RESERVED8 = mask<std::uint32_t>( Size::RESERVED8, Bit::RESERVED8 ); ///< RESERVED8.
        };

        PIDR4() = delete;

        PIDR4( PIDR4 && ) = delete;

        PIDR4( PIDR4 const & ) = delete;

        ~PIDR4() = delete;

        auto operator=( PIDR4 && ) = delete;

        auto operator=( PIDR4 const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief Peripheral Identification Register 0 (PIDR0) register.
     *
     * This register has the following fields:
     * - Part Number bits [7:0] (PART_0)
     */
    class PIDR0 : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto PART_0    = std::uint_fast8_t{ 8 };  ///< PART_0.
            static constexpr auto RESERVED8 = std::uint_fast8_t{ 24 }; ///< RESERVED8.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto PART_0 = std::uint_fast8_t{}; ///< PART_0.
            static constexpr auto RESERVED8 = std::uint_fast8_t{ PART_0 + Size::PART_0 }; ///< RESERVED8.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto PART_0 = mask<std::uint32_t>( Size::PART_0, Bit::PART_0 ); ///< PART_0.
            static constexpr auto RESERVED8 = mask<std::uint32_t>( Size::RESERVED8, Bit::RESERVED8 ); ///< RESERVED8.
        };

        PIDR0() = delete;

        PIDR0( PIDR0 && ) = delete;

        PIDR0( PIDR0 const & ) = delete;

        ~PIDR0() = delete;

        auto operator=( PIDR0 && ) = delete;

        auto operator=( PIDR0 const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief Peripheral Identification Register 1 (PIDR1) register.
     *
     * This register has the following fields:
     * - Part Number bits [11:8] (PART_1)
     * - JEP106 Identification Code bits [3:0] (DES_0)
     */
    class PIDR1 : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto PART_1    = std::uint_fast8_t{ 4 };  ///< PART_1.
            static constexpr auto DES_0     = std::uint_fast8_t{ 4 };  ///< DES_0.
            static constexpr auto RESERVED8 = std::uint_fast8_t{ 24 }; ///< RESERVED8.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto PART_1 = std::uint_fast8_t{}; ///< PART_1.
            static constexpr auto DES_0 = std::uint_fast8_t{ PART_1 + Size::PART_1 }; ///< DES_0.
            static constexpr auto RESERVED8 = std::uint_fast8_t{ DES_0 + Size::DES_0 }; ///< RESERVED8.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto PART_1 = mask<std::uint32_t>( Size::PART_1, Bit::PART_1 ); ///< PART_1.
            static constexpr auto DES_0 = mask<std::uint32_t>( Size::DES_0, Bit::DES_0 ); ///< DES_0.
            static constexpr auto RESERVED8 = mask<std::uint32_t>( Size::RESERVED8, Bit::RESERVED8 ); ///< RESERVED8.
        };

        PIDR1() = delete;

        PIDR1( PIDR1 && ) = delete;

        PIDR1( PIDR1 const & ) = delete;

        ~PIDR1() = delete;

        auto operator=( PIDR1 && ) = delete;

        auto operator=( PIDR1 const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief Peripheral Identification Register 2 (PIDR2) register.
     *
     * This register has the following fields:
     * - JEP106 Identification Code bits [6:4] (DES_1)
     * - JEDEC Assigned (JEDEC)
     * - Revision (REVISION)
     */
    class PIDR2 : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto DES_1     = std::uint_fast8_t{ 3 };  ///< DES_1.
            static constexpr auto JEDEC     = std::uint_fast8_t{ 1 };  ///< JEDEC.
            static constexpr auto REVISION  = std::uint_fast8_t{ 4 };  ///< REVISION.
            static constexpr auto RESERVED8 = std::uint_fast8_t{ 24 }; ///< RESERVED8.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto DES_1 = std::uint_fast8_t{}; ///< DES_1.
            static constexpr auto JEDEC = std::uint_fast8_t{ DES_1 + Size::DES_1 }; ///< JEDEC.
            static constexpr auto REVISION = std::uint_fast8_t{ JEDEC + Size::JEDEC }; ///< REVISION.
            static constexpr auto RESERVED8 = std::uint_fast8_t{ REVISION + Size::REVISION }; ///< RESERVED8.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto DES_1 = mask<std::uint32_t>( Size::DES_1, Bit::DES_1 ); ///< DES_1.
            static constexpr auto JEDEC = mask<std::uint32_t>( Size::JEDEC, Bit::JEDEC ); ///< JEDEC.
            static constexpr auto REVISION = mask<std::uint32_t>( Size::REVISION, Bit::REVISION ); ///< REVISION.
            static constexpr auto RESERVED8 = mask<std::uint32_t>( Size::RESERVED8, Bit::RESERVED8 ); ///< RESERVED8.
        };

        PIDR2() = delete;

        PIDR2( PIDR2 && ) = delete;

        PIDR2( PIDR2 const & ) = delete;

        ~PIDR2() = delete;

        auto operator=( PIDR2 && ) = delete;

        auto operator=( PIDR2 const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief Peripheral Identification Register 3 (PIDR3) register.
     *
     * This register has the following fields:
     * - Customer Modified (CMOD)
     * - Errata (REVAND)
     */
    class PIDR3 : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto CMOD      = std::uint_fast8_t{ 4 };  ///< CMOD.
            static constexpr auto REVAND    = std::uint_fast8_t{ 4 };  ///< REVAND.
            static constexpr auto RESERVED0 = std::uint_fast8_t{ 24 }; ///< RESERVED0.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto CMOD = std::uint_fast8_t{}; ///< CMOD.
            static constexpr auto REVAND = std::uint_fast8_t{ CMOD + Size::CMOD }; ///< REVAND.
            static constexpr auto RESERVED0 = std::uint_fast8_t{ REVAND + Size::REVAND }; ///< RESERVED0.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto CMOD = mask<std::uint32_t>( Size::CMOD, Bit::CMOD ); ///< CMOD.
            static constexpr auto REVAND = mask<std::uint32_t>( Size::REVAND, Bit::REVAND ); ///< REVAND.
            static constexpr auto RESERVED0 = mask<std::uint32_t>( Size::RESERVED0, Bit::RESERVED0 ); ///< RESERVED0.
        };

        PIDR3() = delete;

        PIDR3( PIDR3 && ) = delete;

        PIDR3( PIDR3 const & ) = delete;

        ~PIDR3() = delete;

        auto operator=( PIDR3 && ) = delete;

        auto operator=( PIDR3 const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief Component Identification Register 0 (CIDR0) register.
     *
     * This register has the following fields:
     * - Preamble Segment 0 (PRMBL_0)
     */
    class CIDR0 : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto PRMBL_0   = std::uint_fast8_t{ 8 };  ///< PRMBL_0.
            static constexpr auto RESERVED8 = std::uint_fast8_t{ 24 }; ///< RESERVED8.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto PRMBL_0 = std::uint_fast8_t{}; ///< PRMBL_0.
            static constexpr auto RESERVED8 = std::uint_fast8_t{ PRMBL_0 + Size::PRMBL_0 }; ///< RESERVED8.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto PRMBL_0 = mask<std::uint32_t>( Size::PRMBL_0, Bit::PRMBL_0 ); ///< PRMBL_0.
            static constexpr auto RESERVED8 = mask<std::uint32_t>( Size::RESERVED8, Bit::RESERVED8 ); ///< RESERVED8.
        };

        CIDR0() = delete;

        CIDR0( CIDR0 && ) = delete;

        CIDR0( CIDR0 const & ) = delete;

        ~CIDR0() = delete;

        auto operator=( CIDR0 && ) = delete;

        auto operator=( CIDR0 const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief Component Identification Register 1 (CIDR1) register.
     *
     * This register has the following fields:
     * - Preamble Segment 1 (PRMBL_1)
     * - Component Class (CLASS)
     */
    class CIDR1 : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto PRMBL_1   = std::uint_fast8_t{ 4 };  ///< PRMBL_1.
            static constexpr auto CLASS     = std::uint_fast8_t{ 4 };  ///< CLASS.
            static constexpr auto RESERVED8 = std::uint_fast8_t{ 24 }; ///< RESERVED8.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto PRMBL_1 = std::uint_fast8_t{}; ///< PRMBL_1.
            static constexpr auto CLASS = std::uint_fast8_t{ PRMBL_1 + Size::PRMBL_1 }; ///< CLASS.
            static constexpr auto RESERVED8 = std::uint_fast8_t{ CLASS + Size::CLASS }; ///< RESERVED8.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto PRMBL_1 = mask<std::uint32_t>( Size::PRMBL_1, Bit::PRMBL_1 ); ///< PRMBL_1.
            static constexpr auto CLASS = mask<std::uint32_t>( Size::CLASS, Bit::CLASS ); ///< CLASS.
            static constexpr auto RESERVED8 = mask<std::uint32_t>( Size::RESERVED8, Bit::RESERVED8 ); ///< RESERVED8.
        };

        CIDR1() = delete;

        CIDR1( CIDR1 && ) = delete;

        CIDR1( CIDR1 const & ) = delete;

        ~CIDR1() = delete;

        auto operator=( CIDR1 && ) = delete;

        auto operator=( CIDR1 const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief Component Identification Register 2 (CIDR2) register.
     *
     * This register has the following fields:
     * - Preamble Segment 2 (PRMBL_2)
     */
    class CIDR2 : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto PRMBL_2   = std::uint_fast8_t{ 8 };  ///< PRMBL_2.
            static constexpr auto RESERVED8 = std::uint_fast8_t{ 24 }; ///< RESERVED8.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto PRMBL_2 = std::uint_fast8_t{}; ///< PRMBL_2.
            static constexpr auto RESERVED8 = std::uint_fast8_t{ PRMBL_2 + Size::PRMBL_2 }; ///< RESERVED8.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto PRMBL_2 = mask<std::uint32_t>( Size::PRMBL_2, Bit::PRMBL_2 ); ///< PRMBL_2.
            static constexpr auto RESERVED8 = mask<std::uint32_t>( Size::RESERVED8, Bit::RESERVED8 ); ///< RESERVED8.
        };

        CIDR2() = delete;

        CIDR2( CIDR2 && ) = delete;

        CIDR2( CIDR2 const & ) = delete;

        ~CIDR2() = delete;

        auto operator=( CIDR2 && ) = delete;

        auto operator=( CIDR2 const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief Component Identification Register 3 (CIDR3) register.
     *
     * This register has the following fields:
     * - Preamble Segment 3 (PRMBL_3)
     */
    class CIDR3 : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto PRMBL_3   = std::uint_fast8_t{ 8 };  ///< PRMBL_3.
            static constexpr auto RESERVED8 = std::uint_fast8_t{ 24 }; ///< RESERVED8.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto PRMBL_3 = std::uint_fast8_t{}; ///< PRMBL_3.
            static constexpr auto RESERVED8 = std::uint_fast8_t{ PRMBL_3 + Size::PRMBL_3 }; ///< RESERVED8.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto PRMBL_3 = mask<std::uint32_t>( Size::PRMBL_3, Bit::PRMBL_3 ); ///< PRMBL_3.
            static constexpr auto RESERVED8 = mask<std::uint32_t>( Size::RESERVED8, Bit::RESERVED8 ); ///< RESERVED8.
        };

        CIDR3() = delete;

        CIDR3( CIDR3 && ) = delete;

        CIDR3( CIDR3 const & ) = delete;

        ~CIDR3() = delete;

        auto operator=( CIDR3 && ) = delete;

        auto operator=( CIDR3 const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief POSITION.
     */
    POSITION position;

    /**
     * \brief MASTER.
     */
    MASTER master;

    /**
     * \brief FLOW.
     */
    FLOW flow;

    /**
     * \brief Base (BASE) register.
     */
    Register<std::uint32_t> const base;

    /**
     * \brief Reserved registers (offset 0x010-0xEFC).
     */
    Reserved_Register<std::uint32_t> reserved_0x010_0xEFC[ ( ( 0xEFC - 0x010 ) + 4 ) / 4 ];

    /**
     * \brief ITCTRL.
     */
    ITCTRL itctrl;

    /**
     * \brief Reserved registers (offset 0xF04-0xF9C).
     */
    Reserved_Register<std::uint32_t> reserved_0xF04_0xF9C[ ( ( 0xF9C - 0xF04 ) + 4 ) / 4 ];

    /**
     * \brief Claim Tag Set (CLAIMSET) register.
     */
    Register<std::uint32_t> claimset;

    /**
     * \brief Claim Tag Clear (CLAIMCLR) register.
     */
    Register<std::uint32_t> claimclr;

    /**
     * \brief Device Affinity (DEVAFF) registers.
     */
    Register<std::uint32_t> const devaff[ ( ( 0xFAC - 0xFA8 ) + 4 ) / 4 ];

    /**
     * \brief Software Lock Access (LAR) register.
     */
    Register<std::uint32_t> lar;

    /**
     * \brief LSR.
     */
    LSR const lsr;

    /**
     * \brief AUTHSTATUS.
     */
    AUTHSTATUS const autostatus;

    /**
     * \brief DEVARCH.
     */
    DEVARCH const devarch;

    /**
     * \brief Device Configuration Register 2 (DEVID2) register.
     */
    Register<std::uint32_t> const devid2;

    /**
     * \brief Device Configuration Register 1 (DEVID1) register.
     */
    Register<std::uint32_t> const devid1;

    /**
     * \brief Device Configuration Register (DEVID) register.
     */
    Register<std::uint32_t> const devid;

    /**
     * \brief DEVTYPE.
     */
    DEVTYPE const devtype;

    /**
     * \brief PIDR4.
     */
    PIDR4 const pidr4;

    /**
     * \brief Peripheral Identification Register 5 (PIDR5) register.
     */
    Register<std::uint32_t> const pidr5;

    /**
     * \brief Peripheral Identification Register 6 (PIDR6) register.
     */
    Register<std::uint32_t> const pidr6;

    /**
     * \brief Peripheral Identification Register 7 (PIDR7) register.
     */
    Register<std::uint32_t> const pidr7;

    /**
     * \brief PIDR0.
     */
    PIDR0 const pidr0;

    /**
     * \brief PIDR1.
     */
    PIDR1 const pidr1;

    /**
     * \brief PIDR2.
     */
    PIDR2 const pidr2;

    /**
     * \brief PIDR3.
     */
    PIDR3 const pidr3;

    /**
     * \brief CIDR0.
     */
    CIDR0 const cidr0;

    /**
     * \brief CIDR1.
     */
    CIDR1 const cidr1;

    /**
     * \brief CIDR2.
     */
    CIDR2 const cidr2;

    /**
     * \brief CIDR3.
     */
    CIDR3 const cidr3;

    MTB() = delete;

    MTB( MTB && ) = delete;

    MTB( MTB const & ) = delete;

    ~MTB() = delete;

    auto operator=( MTB && ) = delete;

    auto operator=( MTB const & ) = delete;
};

} // namespace picolibrary::Arm::Cortex::M0PLUS::Peripheral

#endif // PICOLIBRARY_ARM_CORTEX_M0PLUS_PERIPHERAL_MTB_H

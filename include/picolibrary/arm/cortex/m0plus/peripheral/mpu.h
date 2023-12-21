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
 * \brief picolibrary::Arm::Cortex::M0PLUS::Peripheral::MPU interface.
 */

#ifndef PICOLIBRARY_ARM_CORTEX_M0PLUS_PERIPHERAL_MPU_H
#define PICOLIBRARY_ARM_CORTEX_M0PLUS_PERIPHERAL_MPU_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/register.h"

namespace picolibrary::Arm::Cortex::M0PLUS::Peripheral {

/**
 * \brief Arm Cortex-M0+ Memory Protection Unit (MPU) peripheral.
 */
class MPU {
  public:
    /**
     * \brief Type Register (TYPE) register.
     *
     * This register has the following fields:
     * - SEPARATE (SEPARATE)
     * - DREGION (DREGION)
     * - IREGION (IREGION)
     */
    class TYPE : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto SEPARATE   = std::uint_fast8_t{ 1 }; ///< SEPARATE.
            static constexpr auto RESERVED1  = std::uint_fast8_t{ 7 }; ///< RESERVED1.
            static constexpr auto DREGION    = std::uint_fast8_t{ 8 }; ///< DREGION.
            static constexpr auto IREGION    = std::uint_fast8_t{ 8 }; ///< IREGION.
            static constexpr auto RESERVED24 = std::uint_fast8_t{ 8 }; ///< RESERVED24.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto SEPARATE = std::uint_fast8_t{}; ///< SEPARATE.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ SEPARATE + Size::SEPARATE }; ///< RESERVED1.
            static constexpr auto DREGION = std::uint_fast8_t{ RESERVED1 + Size::RESERVED1 }; ///< DREGION.
            static constexpr auto IREGION = std::uint_fast8_t{ DREGION + Size::DREGION }; ///< IREGION.
            static constexpr auto RESERVED24 = std::uint_fast8_t{ IREGION + Size::IREGION }; ///< RESERVED24.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto SEPARATE = mask<std::uint32_t>( Size::SEPARATE, Bit::SEPARATE ); ///< SEPARATE.
            static constexpr auto RESERVED1 = mask<std::uint32_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
            static constexpr auto DREGION = mask<std::uint32_t>( Size::DREGION, Bit::DREGION ); ///< DREGION.
            static constexpr auto IREGION = mask<std::uint32_t>( Size::IREGION, Bit::IREGION ); ///< IREGION.
            static constexpr auto RESERVED24 = mask<std::uint32_t>( Size::RESERVED24, Bit::RESERVED24 ); ///< RESERVED24.
        };

        TYPE() = delete;

        TYPE( TYPE && ) = delete;

        TYPE( TYPE const & ) = delete;

        ~TYPE() = delete;

        auto operator=( TYPE && ) = delete;

        auto operator=( TYPE const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief Control Register (CTRL) register.
     *
     * This register has the following fields:
     * - ENABLE (ENABLE)
     * - HFNMIENA (HFNMIENA)
     * - PRIVDEFENA (PRIVDEFENA)
     */
    class CTRL : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto ENABLE     = std::uint_fast8_t{ 1 };  ///< ENABLE.
            static constexpr auto HFNMIENA   = std::uint_fast8_t{ 1 };  ///< HFNMIENA.
            static constexpr auto PRIVDEFENA = std::uint_fast8_t{ 1 };  ///< PRIVDEFENA.
            static constexpr auto RESERVED3  = std::uint_fast8_t{ 29 }; ///< RESERVED3.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto ENABLE = std::uint_fast8_t{}; ///< ENABLE.
            static constexpr auto HFNMIENA = std::uint_fast8_t{ ENABLE + Size::ENABLE }; ///< HFNMIENA.
            static constexpr auto PRIVDEFENA = std::uint_fast8_t{ HFNMIENA + Size::HFNMIENA }; ///< PRIVDEFENA.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ PRIVDEFENA + Size::PRIVDEFENA }; ///< RESERVED3.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto ENABLE = mask<std::uint32_t>( Size::ENABLE, Bit::ENABLE ); ///< ENABLE.
            static constexpr auto HFNMIENA = mask<std::uint32_t>( Size::HFNMIENA, Bit::HFNMIENA ); ///< HFNMIENA.
            static constexpr auto PRIVDEFENA = mask<std::uint32_t>( Size::PRIVDEFENA, Bit::PRIVDEFENA ); ///< PRIVDEFENA.
            static constexpr auto RESERVED3 = mask<std::uint32_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
        };

        CTRL() = delete;

        CTRL( CTRL && ) = delete;

        CTRL( CTRL const & ) = delete;

        ~CTRL() = delete;

        auto operator=( CTRL && ) = delete;

        auto operator=( CTRL const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief Region Number Register (RNR) register.
     *
     * This register has the following fields:
     * - REGION (REGION)
     */
    class RNR : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto REGION    = std::uint_fast8_t{ 8 };  ///< REGION.
            static constexpr auto RESERVED8 = std::uint_fast8_t{ 24 }; ///< RESERVED8.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto REGION = std::uint_fast8_t{}; ///< REGION.
            static constexpr auto RESERVED8 = std::uint_fast8_t{ REGION + Size::REGION }; ///< RESERVED8.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto REGION = mask<std::uint32_t>( Size::REGION, Bit::REGION ); ///< REGION.
            static constexpr auto RESERVED8 = mask<std::uint32_t>( Size::RESERVED8, Bit::RESERVED8 ); ///< RESERVED8.
        };

        RNR() = delete;

        RNR( RNR && ) = delete;

        RNR( RNR const & ) = delete;

        ~RNR() = delete;

        auto operator=( RNR && ) = delete;

        auto operator=( RNR const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief Region Base Address Register (RBAR) register.
     *
     * This register has the following fields:
     * - REGION (REGION)
     * - VALID (VALID)
     * - ADDR (ADDR)
     */
    class RBAR : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto REGION    = std::uint_fast8_t{ 4 };  ///< REGION.
            static constexpr auto VALID     = std::uint_fast8_t{ 1 };  ///< VALID.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ 3 };  ///< RESERVED5.
            static constexpr auto ADDR      = std::uint_fast8_t{ 24 }; ///< ADDR.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto REGION = std::uint_fast8_t{}; ///< REGION.
            static constexpr auto VALID = std::uint_fast8_t{ REGION + Size::REGION }; ///< VALID.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ VALID + Size::VALID }; ///< RESERVED5.
            static constexpr auto ADDR = std::uint_fast8_t{ RESERVED5 + Size::RESERVED5 }; ///< ADDR.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto REGION = mask<std::uint32_t>( Size::REGION, Bit::REGION ); ///< REGION.
            static constexpr auto VALID = mask<std::uint32_t>( Size::VALID, Bit::VALID ); ///< VALID.
            static constexpr auto RESERVED5 = mask<std::uint32_t>( Size::RESERVED5, Bit::RESERVED5 ); ///< RESERVED5.
            static constexpr auto ADDR = mask<std::uint32_t>( Size::ADDR, Bit::ADDR ); ///< ADDR.
        };

        RBAR() = delete;

        RBAR( RBAR && ) = delete;

        RBAR( RBAR const & ) = delete;

        ~RBAR() = delete;

        auto operator=( RBAR && ) = delete;

        auto operator=( RBAR const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief Region Attribute and Size Register (RASR) register.
     *
     * This register has the following fields:
     * - ENABLE (ENABLE)
     * - SIZE (SIZE)
     * - SRD (SRD)
     * - B (B)
     * - C (C)
     * - S (S)
     * - AP (AP)
     * - XN (XN)
     */
    class RASR : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto ENABLE     = std::uint_fast8_t{ 1 }; ///< ENABLE.
            static constexpr auto SIZE       = std::uint_fast8_t{ 5 }; ///< SIZE.
            static constexpr auto RESERVED6  = std::uint_fast8_t{ 2 }; ///< RESERVED6.
            static constexpr auto SRD        = std::uint_fast8_t{ 8 }; ///< SRD.
            static constexpr auto B          = std::uint_fast8_t{ 1 }; ///< B.
            static constexpr auto C          = std::uint_fast8_t{ 1 }; ///< C.
            static constexpr auto S          = std::uint_fast8_t{ 1 }; ///< S.
            static constexpr auto RESERVED19 = std::uint_fast8_t{ 5 }; ///< RESERVED19.
            static constexpr auto AP         = std::uint_fast8_t{ 3 }; ///< AP.
            static constexpr auto RESERVED27 = std::uint_fast8_t{ 1 }; ///< RESERVED27.
            static constexpr auto XN         = std::uint_fast8_t{ 1 }; ///< XN.
            static constexpr auto RESERVED29 = std::uint_fast8_t{ 3 }; ///< RESERVED29.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto ENABLE = std::uint_fast8_t{}; ///< ENABLE.
            static constexpr auto SIZE = std::uint_fast8_t{ ENABLE + Size::ENABLE }; ///< SIZE.
            static constexpr auto RESERVED6 = std::uint_fast8_t{ SIZE + Size::SIZE }; ///< RESERVED6.
            static constexpr auto SRD = std::uint_fast8_t{ RESERVED6 + Size::RESERVED6 }; ///< SRD.
            static constexpr auto B = std::uint_fast8_t{ SRD + Size::SRD }; ///< B.
            static constexpr auto C = std::uint_fast8_t{ B + Size::B };     ///< C.
            static constexpr auto S = std::uint_fast8_t{ C + Size::C };     ///< S.
            static constexpr auto RESERVED19 = std::uint_fast8_t{ S + Size::S }; ///< RESERVED19.
            static constexpr auto AP = std::uint_fast8_t{ RESERVED19 + Size::RESERVED19 }; ///< AP.
            static constexpr auto RESERVED27 = std::uint_fast8_t{ AP + Size::AP }; ///< RESERVED27.
            static constexpr auto XN = std::uint_fast8_t{ RESERVED27 + Size::RESERVED27 }; ///< XN.
            static constexpr auto RESERVED29 = std::uint_fast8_t{ XN + Size::XN }; ///< RESERVED29.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto ENABLE = mask<std::uint32_t>( Size::ENABLE, Bit::ENABLE ); ///< ENABLE.
            static constexpr auto SIZE = mask<std::uint32_t>( Size::SIZE, Bit::SIZE ); ///< SIZE.
            static constexpr auto RESERVED6 = mask<std::uint32_t>( Size::RESERVED6, Bit::RESERVED6 ); ///< RESERVED6.
            static constexpr auto SRD = mask<std::uint32_t>( Size::SRD, Bit::SRD ); ///< SRD.
            static constexpr auto B = mask<std::uint32_t>( Size::B, Bit::B ); ///< B.
            static constexpr auto C = mask<std::uint32_t>( Size::C, Bit::C ); ///< C.
            static constexpr auto S = mask<std::uint32_t>( Size::S, Bit::S ); ///< S.
            static constexpr auto RESERVED19 = mask<std::uint32_t>( Size::RESERVED19, Bit::RESERVED19 ); ///< RESERVED19.
            static constexpr auto AP = mask<std::uint32_t>( Size::AP, Bit::AP ); ///< AP.
            static constexpr auto RESERVED27 = mask<std::uint32_t>( Size::RESERVED27, Bit::RESERVED27 ); ///< RESERVED27.
            static constexpr auto XN = mask<std::uint32_t>( Size::XN, Bit::XN ); ///< XN.
            static constexpr auto RESERVED29 = mask<std::uint32_t>( Size::RESERVED29, Bit::RESERVED29 ); ///< RESERVED29.
        };

        RASR() = delete;

        RASR( RASR && ) = delete;

        RASR( RASR const & ) = delete;

        ~RASR() = delete;

        auto operator=( RASR && ) = delete;

        auto operator=( RASR const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief TYPE.
     */
    TYPE const type;

    /**
     * \brief CTRL.
     */
    CTRL ctrl;

    /**
     * \brief RNR.
     */
    RNR rnr;

    /**
     * \brief RBAR.
     */
    RBAR rbar;

    /**
     * \brief RASR.
     */
    RASR rasr;

    MPU() = delete;

    MPU( MPU && ) = delete;

    MPU( MPU const & ) = delete;

    ~MPU() = delete;

    auto operator=( MPU && ) = delete;

    auto operator=( MPU const & ) = delete;
};

} // namespace picolibrary::Arm::Cortex::M0PLUS::Peripheral

#endif // PICOLIBRARY_ARM_CORTEX_M0PLUS_PERIPHERAL_MPU_H

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
 * \brief picolibrary::Arm::Cortex::M0PLUS::Peripheral::SYSTICK interface.
 */

#ifndef PICOLIBRARY_ARM_CORTEX_M0PLUS_PERIPHERAL_SYSTICK_H
#define PICOLIBRARY_ARM_CORTEX_M0PLUS_PERIPHERAL_SYSTICK_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/register.h"

namespace picolibrary::Arm::Cortex::M0PLUS::Peripheral {

/**
 * \brief Arm Cortex-M0+ System Timer (SYSTICK) peripheral.
 */
class SYSTICK {
  public:
    /**
     * \brief Control and Status Register (CSR) register.
     *
     * This register has the following fields:
     * - Enable Counter (ENABLE)
     * - Enable SYSTICK Interrupt Request (TICKINT)
     * - Timer Clock Source (CLKSOURCE)
     * - Timer Counted to 0 (COUNTFLAG)
     */
    class CSR : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto ENABLE     = std::uint_fast8_t{ 1 };  ///< ENABLE.
            static constexpr auto TICKINT    = std::uint_fast8_t{ 1 };  ///< TICKINT.
            static constexpr auto CLKSOURCE  = std::uint_fast8_t{ 1 };  ///< CLKSOURCE.
            static constexpr auto RESERVED3  = std::uint_fast8_t{ 13 }; ///< RESERVED3.
            static constexpr auto COUNTFLAG  = std::uint_fast8_t{ 1 };  ///< COUNTFLAG.
            static constexpr auto RESERVED17 = std::uint_fast8_t{ 15 }; ///< RESERVED17.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto ENABLE = std::uint_fast8_t{}; ///< ENABLE.
            static constexpr auto TICKINT = std::uint_fast8_t{ ENABLE + Size::ENABLE }; ///< TICKINT.
            static constexpr auto CLKSOURCE = std::uint_fast8_t{ TICKINT + Size::TICKINT }; ///< CLKSOURCE.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ CLKSOURCE + Size::CLKSOURCE }; ///< RESERVED3.
            static constexpr auto COUNTFLAG = std::uint_fast8_t{ RESERVED3 + Size::RESERVED3 }; ///< COUNTFLAG.
            static constexpr auto RESERVED17 = std::uint_fast8_t{ COUNTFLAG + Size::COUNTFLAG }; ///< RESERVED17.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto ENABLE = mask<std::uint32_t>( Size::ENABLE, Bit::ENABLE ); ///< ENABLE.
            static constexpr auto TICKINT = mask<std::uint32_t>( Size::TICKINT, Bit::TICKINT ); ///< TICKINT.
            static constexpr auto CLKSOURCE = mask<std::uint32_t>( Size::CLKSOURCE, Bit::CLKSOURCE ); ///< CLKSOURCE.
            static constexpr auto RESERVED3 = mask<std::uint32_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
            static constexpr auto COUNTFLAG = mask<std::uint32_t>( Size::COUNTFLAG, Bit::COUNTFLAG ); ///< COUNTFLAG.
            static constexpr auto RESERVED17 = mask<std::uint32_t>( Size::RESERVED17, Bit::RESERVED17 ); ///< RESERVED17.
        };

        CSR() = delete;

        CSR( CSR && ) = delete;

        CSR( CSR const & ) = delete;

        ~CSR() = delete;

        auto operator=( CSR && ) = delete;

        auto operator=( CSR const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief Reload Value Register (RVR) register.
     *
     * This register has the following fields:
     * - Reload Value (RELOAD)
     */
    class RVR : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto RELOAD     = std::uint_fast8_t{ 24 }; ///< RELOAD.
            static constexpr auto RESERVED24 = std::uint_fast8_t{ 8 };  ///< RESERVED24.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto RELOAD = std::uint_fast8_t{}; ///< RELOAD.
            static constexpr auto RESERVED24 = std::uint_fast8_t{ RELOAD + Size::RELOAD }; ///< RESERVED24.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto RELOAD = mask<std::uint32_t>( Size::RELOAD, Bit::RELOAD ); ///< RELOAD.
            static constexpr auto RESERVED24 = mask<std::uint32_t>( Size::RESERVED24, Bit::RESERVED24 ); ///< RESERVED24.
        };

        RVR() = delete;

        RVR( RVR && ) = delete;

        RVR( RVR const & ) = delete;

        ~RVR() = delete;

        auto operator=( RVR && ) = delete;

        auto operator=( RVR const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief Current Value Register (CVR) register.
     *
     * This register has the following fields:
     * - Current Value (CURRENT)
     */
    class CVR : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto CURRENT    = std::uint_fast8_t{ 24 }; ///< CURRENT.
            static constexpr auto RESERVED24 = std::uint_fast8_t{ 8 };  ///< RESERVED24.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto CURRENT = std::uint_fast8_t{}; ///< CURRENT.
            static constexpr auto RESERVED24 = std::uint_fast8_t{ CURRENT + Size::CURRENT }; ///< RESERVED24.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto CURRENT = mask<std::uint32_t>( Size::CURRENT, Bit::CURRENT ); ///< CURRENT.
            static constexpr auto RESERVED24 = mask<std::uint32_t>( Size::RESERVED24, Bit::RESERVED24 ); ///< RESERVED24.
        };

        CVR() = delete;

        CVR( CVR && ) = delete;

        CVR( CVR const & ) = delete;

        ~CVR() = delete;

        auto operator=( CVR && ) = delete;

        auto operator=( CVR const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief Calibration Value Register (CALIB) register.
     *
     * This register has the following fields:
     * - Counter 10 ms Interval Reload Value (TENMS)
     * - TENMS Rounded (SKEW)
     * - No Separate Reference Clock Provided (NOREF)
     */
    class CALIB : public Register<std::uint32_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto TENMS      = std::uint_fast8_t{ 24 }; ///< TENMS.
            static constexpr auto RESERVED24 = std::uint_fast8_t{ 6 };  ///< RESERVED24.
            static constexpr auto SKEW       = std::uint_fast8_t{ 1 };  ///< SKEW.
            static constexpr auto NOREF      = std::uint_fast8_t{ 1 };  ///< NOREF.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto TENMS = std::uint_fast8_t{}; ///< TENMS.
            static constexpr auto RESERVED24 = std::uint_fast8_t{ TENMS + Size::TENMS }; ///< RESERVED24.
            static constexpr auto SKEW = std::uint_fast8_t{ RESERVED24 + Size::RESERVED24 }; ///< SKEW.
            static constexpr auto NOREF = std::uint_fast8_t{ SKEW + Size::SKEW }; ///< NOREF.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto TENMS = mask<std::uint32_t>( Size::TENMS, Bit::TENMS ); ///< TENMS.
            static constexpr auto RESERVED24 = mask<std::uint32_t>( Size::RESERVED24, Bit::RESERVED24 ); ///< RESERVED24.
            static constexpr auto SKEW = mask<std::uint32_t>( Size::SKEW, Bit::SKEW ); ///< SKEW.
            static constexpr auto NOREF = mask<std::uint32_t>( Size::NOREF, Bit::NOREF ); ///< NOREF.
        };

        CALIB() = delete;

        CALIB( CALIB && ) = delete;

        CALIB( CALIB const & ) = delete;

        ~CALIB() = delete;

        auto operator=( CALIB && ) = delete;

        auto operator=( CALIB const & ) = delete;

        using Register<std::uint32_t>::operator=;
    };

    /**
     * \brief CSR.
     */
    CSR csr;

    /**
     * \brief RVR.
     */
    RVR rvr;

    /**
     * \brief CVR.
     */
    CVR cvr;

    /**
     * \brief CALIB.
     */
    CALIB const calib;

    SYSTICK() = delete;

    SYSTICK( SYSTICK && ) = delete;

    SYSTICK( SYSTICK const & ) = delete;

    ~SYSTICK() = delete;

    auto operator=( SYSTICK && ) = delete;

    auto operator=( SYSTICK const & ) = delete;
};

} // namespace picolibrary::Arm::Cortex::M0PLUS::Peripheral

#endif // PICOLIBRARY_ARM_CORTEX_M0PLUS_PERIPHERAL_SYSTICK_H

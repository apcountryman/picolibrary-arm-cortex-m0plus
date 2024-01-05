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
 * \brief picolibrary::Arm::Cortex::M0PLUS::Delayer interface.
 */

#ifndef PICOLIBRARY_ARM_CORTEX_M0PLUS_DELAYER_H
#define PICOLIBRARY_ARM_CORTEX_M0PLUS_DELAYER_H

#include <cstdint>

#include "picolibrary/arm/cortex/m0plus/peripheral/systick.h"
#include "picolibrary/utility.h"

namespace picolibrary::Arm::Cortex::M0PLUS {

/**
 * \brief Blocking delayer.
 */
class Delayer {
  public:
    /**
     * \brief SYSTICK clock source.
     */
    enum class Clock_Source : std::uint32_t {
        EXTERNAL_REFERENCE_CLOCK = 0 << Peripheral::SYSTICK::CSR::Bit::CLKSOURCE, ///< External reference clock.
        PROCESSOR_CLOCK = 1 << Peripheral::SYSTICK::CSR::Bit::CLKSOURCE, ///< Processor clock.
    };

    /**
     * \brief Constructor.
     */
    constexpr Delayer() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] systick The SYSTICK peripheral instance to use to create blocking
     *            delays.
     * \param[in] clock_source The SYSTICK peripheral clock source to use.
     * \param[in] reload_value The SYSTICK peripheral counter reload value to use to
     *            create blocking delays of the desired duration.
     * \param[in] ticks The number of SYSTICK peripheral counter reloads required to
     *            create blocking delays of the desired duration.
     *
     * \attention The delayer will use the processor clock if the external reference clock
     *            is requested but is not available.
     */
    constexpr Delayer( Peripheral::SYSTICK & systick, Clock_Source clock_source, std::uint32_t reload_value, std::uint32_t ticks ) noexcept
        :
        m_systick{ &systick },
        m_ticks{ ticks }
    {
        m_systick->rvr = reload_value;
        m_systick->cvr = 0;
        m_systick->csr = to_underlying( clock_source ) | Peripheral::SYSTICK::CSR::Mask::ENABLE;
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Delayer( Delayer && source ) noexcept :
        m_systick{ source.m_systick },
        m_ticks{ source.m_ticks }
    {
        source.m_systick = nullptr;
    }

    Delayer( Delayer const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Delayer() noexcept
    {
        disable();
    }

    /**
     * \brief Assignment operator.
     *
     * \param[in] expression The expression to be assigned.
     *
     * \return The assigned to object.
     */
    constexpr auto operator=( Delayer && expression ) noexcept -> Delayer &
    {
        if ( &expression != this ) {
            disable();

            m_systick = expression.m_systick;
            m_ticks   = expression.m_ticks;

            expression.m_systick = nullptr;
        } // if

        return *this;
    }

    auto operator=( Delayer const & ) = delete;

    /**
     * \brief Delay.
     */
    void operator()() const noexcept
    {
        m_systick->cvr = 0;

        for ( auto ticks = std::uint32_t{}; ticks < m_ticks; ++ticks ) {
            while ( not( m_systick->csr & Peripheral::SYSTICK::CSR::Mask::COUNTFLAG ) ) {} // while
        } // for
    }

  private:
    /**
     * \brief The SYSTICK peripheral instance used to create blocking delays.
     */
    Peripheral::SYSTICK * m_systick{};

    /**
     * \brief The number of SYSTICK peripheral counter reloads required to create blocking
     *        delays of the desired duration.
     */
    std::uint32_t m_ticks{};

    /**
     * \brief Disable the counter.
     */
    constexpr void disable() noexcept
    {
        if ( m_systick ) {
            m_systick->rvr = 0;
            m_systick->csr = 0;
        } // if
    }
};

} // namespace picolibrary::Arm::Cortex::M0PLUS

#endif // PICOLIBRARY_ARM_CORTEX_M0PLUS_DELAYER_H

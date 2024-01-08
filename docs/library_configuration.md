# Library Configuration

## Table of Contents
1. [Overview](#overview)
1. [General Configuration](#general-configuration)
1. [Interrupt Vector Table Configuration](#interrupt-vector-table-configuration)

## Overview
picolibrary-arm-cortex-m0plus is configured for use with a specific Arm Cortex-M0+
microcontroller implementation via injected header files.
The `PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_INCLUDE_DIR` project configuration
option defines the search path for these header files.

## General Configuration
General library configuration is performed by an implementation's
`picolibrary/arm/cortex/m0plus/implementation/configuration.h` header file.
General library configuration consists of the following macros:
- `PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_MPU`: implementation MPU peripheral
  configuration
- `PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SCB_VTOR`: implementation SCB
  peripheral VTOR register configuration
- `PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SYSTICK`: implementation SYSTICK
  peripheral configuration

These macros should be accessed via the
[`include/picolibrary/arm/cortex/m0plus/configuration.h`](https://github.com/apcountryman/picolibrary-arm-cortex-m0plus/blob/main/include/picolibrary/arm/cortex/m0plus/configuration.h)
header file.

`picolibrary/arm/cortex/m0plus/implementation/configuration.h` would be defined as follows
for the Microchip SAM D21/DA1 family of Arm Cortex-M0+ microcontrollers:
```c++
#ifndef PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_CONFIGURATION_H
#define PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_CONFIGURATION_H

#define PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_MPU 0

#define PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SCB_VTOR 1

#define PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SYSTICK 1

#endif // PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_CONFIGURATION_H
```

## Interrupt Vector Table Configuration
Interrupt vector table configuration is performed by an implementation's
`picolibrary/arm/cortex/m0plus/implementation/interrupt/vectors.h` header file.
This header file is used to inject implementation interrupt handler entries into
`::picolibrary::Arm::Cortex::M0PLUS::Interrupt::Vector_Table`.

`picolibrary/arm/cortex/m0plus/implementation/interrupt/vectors.h` would be defined as
follows for the Microchip SAM D21/DA1 family of Arm Cortex-M0+ microcontrollers:
```c++
Handler pm0_handler;

Handler sysctrl0_handler;

Handler wdt0_handler;

Handler rtc0_handler;

Handler eic0_handler;

Handler nvmctrl0_handler;

Handler dmac0_handler;

Handler usb0_handler;

Handler evsys0_handler;

Handler sercom0_handler;

Handler sercom1_handler;

Handler sercom2_handler;

Handler sercom3_handler;

Handler sercom4_handler;

Handler sercom5_handler;

Handler tcc0_handler;

Handler tcc1_handler;

Handler tcc2_handler;

Handler tc3_handler;

Handler tc4_handler;

Handler tc5_handler;

Handler tc6_handler;

Handler tc7_handler;

Handler adc0_handler;

Handler ac0_handler;

Handler dac0_handler;

Handler ptc0_handler;

Handler i2s0_handler;

Handler ac1_handler;

Handler tcc3_handler;
```

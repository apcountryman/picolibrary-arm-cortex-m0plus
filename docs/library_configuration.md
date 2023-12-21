# Library Configuration

## Table of Contents
1. [Overview](#overview)
1. [General Configuration](#general-configuration)

## Overview
picolibrary-arm-cortex-m0plus is configured for use with a specific Arm Cortex-M0+
microcontroller implementation via injected header files.
The `PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_INCLUDE_DIR` project configuration
option defines the search path for these header files.

## General Configuration
General library configuration is performed by an implementation's
`picolibrary/arm/cortex/m0plus/implementation/configuration.h` header file.
General library configuration consists of the following macros:
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

#define PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SYSTICK 1

#endif // PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_CONFIGURATION_H
```

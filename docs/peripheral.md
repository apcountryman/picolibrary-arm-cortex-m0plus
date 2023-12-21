# Peripheral Facilities

## Table of Contents
1. [Peripherals](#peripherals)
    1. [NVIC](#nvic)
    1. [SYSTICK](#systick)
1. [Peripheral Instances](#peripheral-instances)

## Peripherals
The layout of each Arm Cortex-M0+ peripheral's registers is defined by the class named
after the peripheral.
Peripheral registers are accessed via the member variables named after the registers.
Peripheral register information is defined in member classes named after the registers.
Peripheral register field constants are defined in the following member structures:
- `Size`: field sizes
- `Bit`: field bit positions
- `Mask`: field bit masks

### NVIC
The `::picolibrary::Arm::Cortex::M0PLUS::Peripheral::NVIC` class defines the layout of the
Arm Cortex-M0+ NVIC peripheral.
The `::picolibrary::Arm::Cortex::M0PLUS::Peripheral::NVIC` class is defined in the
[`include/picolibrary/arm/cortex/m0plus/peripheral/nvic.h`](https://github.com/apcountryman/picolibrary-arm-cortex-m0plus/blob/main/include/picolibrary/arm/cortex/m0plus/peripheral/nvic.h)/[`source/picolibrary/arm/cortex/m0plus/peripheral/nvic.cc`](https://github.com/apcountryman/picolibrary-arm-cortex-m0plus/blob/main/source/picolibrary/arm/cortex/m0plus/peripheral/nvic.cc)
header/source file pair.

### SYSTICK
The `::picolibrary::Arm::Cortex::M0PLUS::Peripheral::SYSTICK` class defines the layout of
the Arm Cortex-M0+ SYSTICK peripheral and information about its registers.
The `::picolibrary::Arm::Cortex::M0PLUS::Peripheral::SYSTICK` class is defined in the
[`include/picolibrary/arm/cortex/m0plus/peripheral/systick.h`](https://github.com/apcountryman/picolibrary-arm-cortex-m0plus/blob/main/include/picolibrary/arm/cortex/m0plus/peripheral/systick.h)/[`source/picolibrary/arm/cortex/m0plus/peripheral/systick.cc`](https://github.com/apcountryman/picolibrary-arm-cortex-m0plus/blob/main/source/picolibrary/arm/cortex/m0plus/peripheral/systick.cc)
header/source file pair.

## Peripheral Instances
Arm Cortex-M0+ peripheral instances are defined in the
[`include/picolibrary/arm/cortex/m0plus/peripheral.h`](https://github.com/apcountryman/picolibrary-arm-cortex-m0plus/blob/main/include/picolibrary/arm/cortex/m0plus/peripheral.h)/[`source/picolibrary/arm/cortex/m0plus/peripheral.cc`](https://github.com/apcountryman/picolibrary-arm-cortex-m0plus/blob/main/source/picolibrary/arm/cortex/m0plus/peripheral.cc)
header/source file pair.
Peripheral instance names are based on the names used in the "Cortex-M0+ Peripherals"
chapter of the "Cortex-M0+ Devices Generic User Guide" with the following change: a `0` is
added to the end of the name of peripherals that only have a single instance to
differentiate the peripheral name and the instance name.
The following peripheral instances are defined (listed alphabetically):
- `::picolibrary::Arm::Cortex::M0PLUS::Peripheral::NVIC0`
- `::picolibrary::Arm::Cortex::M0PLUS::Peripheral::SYSTICK0` (only available if
  `PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SYSTICK` is true

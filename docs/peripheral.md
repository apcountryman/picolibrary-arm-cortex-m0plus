# Peripheral Facilities

## Table of Contents
1. [Peripherals](#peripherals)
    1. [MPU](#mpu)
    1. [MTB](#mtb)
    1. [NVIC](#nvic)
    1. [SCB](#scb)
    1. [SYSTICK](#systick)
1. [Peripheral Instances](#peripheral-instances)

## Peripherals
The layout of each Arm Cortex-M0+ peripheral's registers is defined by the class named
after the peripheral (e.g. the layout of the SYSTICK peripheral's registers is defined by
the `::picolibrary::Arm::Cortex::M0PLUS::Peripheral::SYSTICK` class).
Peripheral registers are accessed via the member variables named after the registers (e.g.
the SYSTICK peripheral's CSR register is accessed via the
`::picolibrary::Arm::Cortex::M0PLUS::Peripheral::SYSTICK::csr` member variable).
Peripheral register information is defined in member classes named after the registers
(e.g. SYSTICK peripheral CSR register information is defined in the
`::picolibrary::Arm::Cortex::M0PLUS::Peripheral::SYSTICK::CSR` member class).
Peripheral register field constants are defined in the following member structures:
- `Size`: field sizes (e.g. the size of the ENABLE field of the SYSTICK peripheral's CSR
  register is defined by the
  `::picolibrary::Arm::Cortex::M0PLUS::Peripheral::SYSTICK::CSR::Size::ENABLE` constant)
- `Bit`: field bit positions (e.g. the position of the ENABLE field of the SYSTICK
  peripheral's CSR register is defined by the
  `::picolibrary::Arm::Cortex::M0PLUS::Peripheral::SYSTICK::CSR::Bit::ENABLE` constant)
- `Mask`: field bit masks (e.g. the mask for the ENABLE field of the SYSTICK peripheral's
  CSR register is defined by the
  `::picolibrary::Arm::Cortex::M0PLUS::Peripheral::SYSTICK::CSR::Mask::ENABLE` constant)

### MPU
The `::picolibrary::Arm::Cortex::M0PLUS::Peripheral::MPU` class defines the layout of the
Arm Cortex-M0+ MPU peripheral and information about its registers.
The `::picolibrary::Arm::Cortex::M0PLUS::Peripheral::MPU` class is defined in the
[`include/picolibrary/arm/cortex/m0plus/peripheral/mpu.h`](https://github.com/apcountryman/picolibrary-arm-cortex-m0plus/blob/main/include/picolibrary/arm/cortex/m0plus/peripheral/mpu.h)/[`source/picolibrary/arm/cortex/m0plus/peripheral/mpu.cc`](https://github.com/apcountryman/picolibrary-arm-cortex-m0plus/blob/main/source/picolibrary/arm/cortex/m0plus/peripheral/mpu.cc)
header/source file pair.

### MTB
The `::picolibrary::Arm::Cortex::M0PLUS::Peripheral::MTB` class defines the layout of the
Arm Cortex-M0+ MTB peripheral and information about its registers.
The `::picolibrary::Arm::Cortex::M0PLUS::Peripheral::MTB` class is defined in the
[`include/picolibrary/arm/cortex/m0plus/peripheral/mtb.h`](https://github.com/apcountryman/picolibrary-arm-cortex-m0plus/blob/main/include/picolibrary/arm/cortex/m0plus/peripheral/mtb.h)/[`source/picolibrary/arm/cortex/m0plus/peripheral/mtb.cc`](https://github.com/apcountryman/picolibrary-arm-cortex-m0plus/blob/main/source/picolibrary/arm/cortex/m0plus/peripheral/mtb.cc)
header/source file pair.

### NVIC
The `::picolibrary::Arm::Cortex::M0PLUS::Peripheral::NVIC` class defines the layout of the
Arm Cortex-M0+ NVIC peripheral.
The `::picolibrary::Arm::Cortex::M0PLUS::Peripheral::NVIC` class is defined in the
[`include/picolibrary/arm/cortex/m0plus/peripheral/nvic.h`](https://github.com/apcountryman/picolibrary-arm-cortex-m0plus/blob/main/include/picolibrary/arm/cortex/m0plus/peripheral/nvic.h)/[`source/picolibrary/arm/cortex/m0plus/peripheral/nvic.cc`](https://github.com/apcountryman/picolibrary-arm-cortex-m0plus/blob/main/source/picolibrary/arm/cortex/m0plus/peripheral/nvic.cc)
header/source file pair.

### SCB
The `::picolibrary::Arm::Cortex::M0PLUS::Peripheral::SCB` class defines the layout of the
Arm Cortex-M0+ SCB peripheral and information about its registers.
The `::picolibrary::Arm::Cortex::M0PLUS::Peripheral::SCB` class is defined in the
[`include/picolibrary/arm/cortex/m0plus/peripheral/scb.h`](https://github.com/apcountryman/picolibrary-arm-cortex-m0plus/blob/main/include/picolibrary/arm/cortex/m0plus/peripheral/scb.h)/[`source/picolibrary/arm/cortex/m0plus/peripheral/scb.cc`](https://github.com/apcountryman/picolibrary-arm-cortex-m0plus/blob/main/source/picolibrary/arm/cortex/m0plus/peripheral/scb.cc)
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
- `::picolibrary::Arm::Cortex::M0PLUS::Peripheral::MPU0` (only available if
  `PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_MPU` is true)
- `::picolibrary::Arm::Cortex::M0PLUS::Peripheral::NVIC0`
- `::picolibrary::Arm::Cortex::M0PLUS::Peripheral::SCB0`
- `::picolibrary::Arm::Cortex::M0PLUS::Peripheral::SYSTICK0` (only available if
  `PICOLIBRARY_ARM_CORTEX_M0PLUS_IMPLEMENTATION_HAS_SYSTICK` is true)

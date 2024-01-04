# Interrupt Facilities
Arm Cortex-M0+ interrupt facilities are defined in the
[`include/picolibrary/arm/cortex/m0plus/interrupt.h`](https://github.com/apcountryman/picolibrary-arm-cortex-m0plus/blob/main/include/picolibrary/arm/cortex/m0plus/interrupt.h)/[`source/picolibrary/arm/cortex/m0plus/interrupt.cc`](https://github.com/apcountryman/picolibrary-arm-cortex-m0plus/blob/main/source/picolibrary/arm/cortex/m0plus/interrupt.cc)
header/source file pair.

## Table of Contents
- [Handler](#handler)
- [Vector Table](#vector-table)

## Handler
The `::picolibrary::Arm::Cortex::M0PLUS::Interrupt::Handler` type alias defines the
signature of interrupt handlers.

## Vector Table
The `::picolibrary::Arm::Cortex::M0PLUS::Interrupt::Vector_Table` structure defines the
layout of the interrupt vector table.
picolibrary-arm-cortex-m0plus does not instantiate a default interrupt vector table.

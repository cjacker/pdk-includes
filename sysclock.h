#ifndef __PDK_SYSCLOCK_H__
#define __PDK_SYSCLOCK_H__

#if !defined(__PDK_DEVICE_H__)
	#error "You must #include "pdk/device.h" instead of "pdk/sysclock.h" by itself."
#endif

// System Clock definitions
#define SYSCLOCK_IHRC_16MHZ                 CLKMD_IHRC
#define SYSCLOCK_IHRC_8MHZ                  CLKMD_IHRC_DIV2
#define SYSCLOCK_IHRC_4MHZ                  CLKMD_IHRC_DIV4
#define SYSCLOCK_IHRC_2MHZ                  CLKMD_IHRC_DIV8
#define SYSCLOCK_IHRC_1MHZ                  CLKMD_IHRC_DIV16
#define SYSCLOCK_IHRC_500KHZ                CLKMD_IHRC_DIV32
#define SYSCLOCK_IHRC_250KHZ                CLKMD_IHRC_DIV64

#define SYSCLOCK_ILRC                       CLKMD_ILRC
#define SYSCLOCK_ILRC_DIV4                  CLKMD_ILRC_DIV4
#define SYSCLOCK_ILRC_DIV16                 CLKMD_ILRC_DIV16

#define SYSCLOCK_EOSC                       CLKMD_EOSC
#define SYSCLOCK_EOSC_DIV2                  CLKMD_EOSC_DIV2
#define SYSCLOCK_EOSC_DIV4                  CLKMD_EOSC_DIV4
#define SYSCLOCK_EOSC_DIV8                  CLKMD_EOSC_DIV8

// System Clock macros
#define PDK_SET_SYSCLOCK(f)                 CLKMD = (uint8_t)(CLKMD_ENABLE_ILRC | CLKMD_ENABLE_IHRC | f)

#define PDK_DISABLE_IHRC()                  CLKMD &= ~CLKMD_ENABLE_IHRC
#define PDK_DISABLE_ILRC()                  CLKMD &= ~CLKMD_ENABLE_ILRC
#define PDK_DISABLE_INTERNAL_RCS()          CLKMD &= ~(CLKMD_ENABLE_IHRC | CLKMD_ENABLE_ILRC)

#define PDK_USE_16MHZ_IHRC_SYSCLOCK()       PDK_SET_SYSCLOCK(SYSCLOCK_IHRC_16MHZ)
#define PDK_USE_8MHZ_IHRC_SYSCLOCK()        PDK_SET_SYSCLOCK(SYSCLOCK_IHRC_8MHZ)
#define PDK_USE_4MHZ_IHRC_SYSCLOCK()        PDK_SET_SYSCLOCK(SYSCLOCK_IHRC_4MHZ)
#define PDK_USE_2MHZ_IHRC_SYSCLOCK()        PDK_SET_SYSCLOCK(SYSCLOCK_IHRC_2MHZ)
#define PDK_USE_1MHZ_IHRC_SYSCLOCK()        PDK_SET_SYSCLOCK(SYSCLOCK_IHRC_1MHZ)
#define PDK_USE_500KHZ_IHRC_SYSCLOCK()      PDK_SET_SYSCLOCK(SYSCLOCK_IHRC_500KHZ)
#define PDK_USE_250KHZ_IHRC_SYSCLOCK()      PDK_SET_SYSCLOCK(SYSCLOCK_IHRC_250KHZ)

#define PDK_USE_ILRC_SYSCLOCK()             PDK_SET_SYSCLOCK(SYSCLOCK_ILRC)
#define PDK_USE_ILRC_DIV4_SYSCLOCK()        PDK_SET_SYSCLOCK(SYSCLOCK_ILRC_DIV4)
#define PDK_USE_ILRC_DIV16_SYSCLOCK()       PDK_SET_SYSCLOCK(SYSCLOCK_ILRC_DIV16)

// NOTES:
// - EOSC must be enabled first
// - IHRC and ILRC need to stay running until EOSC is stable
#define PDK_USE_EOSC_SYSCLOCK()             PDK_SET_SYSCLOCK(SYSCLOCK_EOSC)
#define PDK_USE_EOSC_DIV2_SYSCLOCK()        PDK_SET_SYSCLOCK(SYSCLOCK_EOSC_DIV2)
#define PDK_USE_EOSC_DIV4_SYSCLOCK()        PDK_SET_SYSCLOCK(SYSCLOCK_EOSC_DIV4)
#define PDK_USE_EOSC_DIV8_SYSCLOCK()        PDK_SET_SYSCLOCK(SYSCLOCK_EOSC_DIV8)

#endif //__PDK_SYSCLOCK_H__

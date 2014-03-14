/*  Copyright (c) 2009 by Alex Leone <acleone ~AT~ gmail.com>

    This file is part of the Arduino TLC5940 Library.

    The Arduino TLC5940 Library is free software: you can redistribute it
    and/or modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    The Arduino TLC5940 Library is distributed in the hope that it will be
    useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with The Arduino TLC5940 Library.  If not, see
    <http://www.gnu.org/licenses/>. */
#include <avr/io.h>
#include <Arduino.h>

#ifndef TLCMUX_CONFIG_H
#define TLCMUX_CONFIG_H


#ifndef TLC_ATMEGA_XX8_H
#define TLC_ATMEGA_XX8_H

/** SIN (TLC pin 26) */
#define SIN_PIN        11

/** SCLK (TLC pin 25) */
#define SCLK_PIN       13


/** SCK (Arduino digital pin 13) -> SCLK (TLC pin 25) */
#define TLC_SCK_PIN      13

/** OC1A (Arduino digital pin 9) -> XLAT (TLC pin 24) */
#define XLAT_PIN     9

/** OC1B (Arduino digital pin 10) -> BLANK (TLC pin 23) */
#define BLANK_PIN    10

/** OC2B (Arduino digital pin 3) -> GSCLK (TLC pin 18) */
#define GSCLK_PIN    3

#define rowLatchPin A1
#define rowDataPin A2
#endif

#include <stdint.h>

#define TLC_BITBANG        0

#ifndef NUM_TLCS
#define NUM_TLCS    1
#endif

/** Number of rows Multiplexed. */
#ifndef NUM_ROWS
#define NUM_ROWS    1
#endif

#if NUM_TLCS <= 16
#define TLC_CHANNEL_TYPE    uint8_t
#define TLC_CHANNEL_TYPE_STR  '1'
#else
#define TLC_CHANNEL_TYPE    uint16_t
#define TLC_CHANNEL_TYPE_STR  '2'
#endif

/** Determines how long each PWM period should be, in clocks.
    \f$\displaystyle f_{PWM} = \frac{f_{osc}}{2 * TLC\_PWM\_PERIOD} Hz \f$
    \f$\displaystyle TLC\_PWM\_PERIOD = \frac{f_{osc}}{2 * f_{PWM}} \f$
    This is related to TLC_GSCLK_PERIOD:
    \f$\displaystyle TLC\_PWM\_PERIOD =
       \frac{(TLC\_GSCLK\_PERIOD + 1) * 4096}{2} \f$
    \note The default of 8192 means the PWM frequency is 976.5625Hz */
#ifndef TLC_PWM_PERIOD
#define TLC_PWM_PERIOD    8192
#endif

/** Determines how long each period GSCLK is.
    This is related to TLC_PWM_PERIOD:
    \f$\displaystyle TLC\_GSCLK\_PERIOD =
       \frac{2 * TLC\_PWM\_PERIOD}{4096} - 1 \f$
    \note Default is 3 */
#ifndef TLC_GSCLK_PERIOD
#define TLC_GSCLK_PERIOD    3
#endif


/* Various Macros */

/** Arranges 2 grayscale values (0 - 4095) in the packed array format (3 bytes).
    This is for array initializers only: the output is three comma seperated
    8-bit values. */
#define GS_DUO(a, b)    ((a) >> 4), ((a) << 4) | ((b) >> 8), (b)



#endif


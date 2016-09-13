/*
             LUFA Library
     Copyright (C) Dean Camera, 2016.

  dean [at] fourwalledcubicle [dot] com
           www.lufa-lib.org
*/

/*
  Copyright 2016  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaims all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

/** \file
 *  \brief Board specific LED driver header for the Arduino Yun board.
 *  \copydetails Group_LEDs_YUN
 *
 *  \note This file should not be included directly. It is automatically included as needed by the LEDs driver
 *        dispatch header located in LUFA/Drivers/Board/LEDs.h.
 */

/** \ingroup Group_LEDs
 *  \defgroup Group_LEDs_YUN YUN
 *  \brief Board specific LED driver header for the Arduino Yun board.
 *
 *  Board specific LED driver header for the Arduino Yun board (http://arduino.cc/en/Main/arduinoBoardYun).
 *
 *  <table>
 *    <tr><th>Name</th><th>Color</th><th>Info</th><th>Active Level</th><th>Port Pin</th></tr>
 *    <tr><td>LEDS_LED1</td><td>Yellow</td><td>RX</td><td>Low</td><td>PORTB.0</td></tr>
 *    <tr><td>LEDS_LED2</td><td>Yellow</td><td>TX</td><td>Low</td><td>PORTD.5</td></tr>
 *    <tr><td>LEDS_LED3</td><td>Red</td><td>General Indicator</td><td>High</td><td>PORTC.7</td></tr>
 *  </table>
 *
 *  @{
 */

#ifndef __LEDS_CUSTOM_H__
#define __LEDS_CUSTOM_H__

	/* Includes: */
		#include "LUFA/Common/Common.h"

	/* Enable C linkage for C++ Compilers: */
		#if defined(__cplusplus)
			extern "C" {
		#endif

	/* Preprocessor Checks: */
		#if !defined(__INCLUDE_FROM_LEDS_H)
			#error Do not include this file directly. Include LUFA/Drivers/Board/LEDS.h instead.
		#endif

	/* Private Interface - For use in library only: */
	#if !defined(__DOXYGEN__)
		/* Macros: */ //pb0 pd5
			#define LEDS_PORTD_INT       (LEDS_TX)
			#define LEDS_PORTD_FRONT     (LEDS_PORT1|LEDS_PORT2)
			#define LEDS_PORTB_INT	     (LED_iRX)
			#define RX_DELTA	     4
	#endif

	/* Public Interface - May be used in end-application: */
		/* Macros: */
			/** private LED mask for the first LED on the board. */
			#define LED_iRX        (1 << 0)
			/** public **/
			#define LEDS_RX	       (1 << 4)

			/** LED mask for the second LED on the board. */
			#define LEDS_TX        (1 << 5)

			/** LED mask for the first LED on the board. */
			#define LEDS_PORT1        (1 << 0)

			/** LED mask for the second LED on the board. */
			#define LEDS_PORT2        (1 << 7)

			/** LED mask for all the LEDs on the board. */
			#define LEDS_ALL_LEDS    (LED_iRX >> RX_DELTA | LEDS_TX | LEDS_PORT1 | LEDS_PORT2 )

			/** LED mask for none of the board LEDs. */
			#define LEDS_NO_LEDS     0

		/* Inline Functions: */
		#if !defined(__DOXYGEN__)
			static inline void LEDs_Init(void)
			{
				DDRB  |=  LEDS_PORTB_INT;
				PORTB |=  LEDS_PORTB_INT;
				DDRD  |=  (LEDS_PORTD_INT|LEDS_PORTD_FRONT);
				PORTD |=  (LEDS_PORTD_INT|LEDS_PORTD_FRONT);
			}

			static inline void LEDs_Disable(void)
			{
				DDRB  &= ~LEDS_PORTB_INT;
				PORTB &= ~LEDS_PORTB_INT;
				DDRD  &= ~(LEDS_PORTD_INT|LEDS_PORTD_FRONT);
				PORTD &= ~(LEDS_PORTD_INT|LEDS_PORTD_FRONT);
			}

			static inline void LEDs_TurnOnLEDs(const uint8_t LEDMask)
			{
				PORTD |= ((LEDMask & LEDS_PORTD_FRONT));
				PORTD &= ~((LEDMask & LEDS_PORTD_INT));
				PORTB &= ~((LEDMask >> RX_DELTA) & LEDS_PORTB_INT);
			}

			static inline void LEDs_TurnOffLEDs(const uint8_t LEDMask)
			{
				PORTD &=  ~(LEDMask & LEDS_PORTD_FRONT);
				PORTD |=  (LEDMask & LEDS_PORTD_INT);
				PORTB |=  ((LEDMask >> RX_DELTA) & LEDS_PORTB_INT);

			}

			static inline void LEDs_SetAllLEDs(const uint8_t LEDMask)
			{/** untested **/
				PORTB = ((PORTB |  LEDS_PORTB_INT) & ~(LEDMask & LEDS_PORTB_INT));
				PORTD = ((PORTD |  LEDS_PORTD_INT) & ~(LEDMask & LEDS_PORTD_INT));
				PORTD = ((PORTD & ~LEDS_PORTD_FRONT) |  (LEDMask & LEDS_PORTD_FRONT));
			}

			static inline void LEDs_ChangeLEDs(const uint8_t LEDMask,
			                                   const uint8_t ActiveMask)
			{/** incomplete **/
				PORTB = ((PORTB |  (LEDMask & LEDS_PORTB_INT)) & ~(ActiveMask & LEDS_PORTB_INT));
				PORTD = ((PORTD |  (LEDMask & LEDS_PORTD_INT)) & ~(ActiveMask & LEDS_PORTD_INT));
				//PORTC = ((PORTC & ~(LEDMask & LEDS_PORTC_LEDS)) |  (ActiveMask & LEDS_PORTC_LEDS));
			}

			static inline void LEDs_ToggleLEDs(const uint8_t LEDMask)
			{/** incomplete **/
				PINB  = (LEDMask & LEDS_PORTB_INT);
				PIND  = (LEDMask & LEDS_PORTD_INT);
				//PINC  = (LEDMask & LEDS_PORTC_LEDS);
			}

			static inline uint8_t LEDs_GetLEDs(void) ATTR_WARN_UNUSED_RESULT;
			static inline uint8_t LEDs_GetLEDs(void)
			{/** incomplete **/
				return ((~PORTB & LEDS_PORTB_INT) | (~PORTD & LEDS_PORTD_INT));
			}
		#endif

	/* Disable C linkage for C++ Compilers: */
		#if defined(__cplusplus)
			}
		#endif

#endif

/** @} */


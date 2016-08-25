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
 *  \brief Board specific Buttons driver header for the Atmel USBKEY.
 *  \copydetails Group_Buttons_USBKEY
 *
 *  \note This file should not be included directly. It is automatically included as needed by the Buttons driver
 *        dispatch header located in LUFA/Drivers/Board/Buttons.h.
 */

/** \ingroup Group_Buttons
 *  \defgroup Group_Buttons_USBKEY USBKEY
 *  \brief Board specific Buttons driver header for the Atmel USBKEY.
 *
 *  Board specific Buttons driver header for the Atmel USBKEY.
 *
 *  <table>
 *    <tr><th>Name</th><th>Info</th><th>Active Level</th><th>Port Pin</th></tr>
 *    <tr><td>BUTTONS_BUTTON1</td><td>HWB Button</td><td>Low</td><td>PORTE.2</td></tr>
 *  </table>
 *
 *  @{
 */

#ifndef __BUTTONS_LEONARDO_H__
#define __BUTTONS_LEONARDO_H__

	/* Includes: */
		#include "LUFA/Common/Common.h"

	/* Enable C linkage for C++ Compilers: */
		#if defined(__cplusplus)
			extern "C" {
		#endif

	/* Preprocessor Checks: */
		#if !defined(__INCLUDE_FROM_BUTTONS_H)
			#error Do not include this file directly. Include LUFA/Drivers/Board/Buttons.h instead.
		#endif

	/* Private Interface - For use in library only: */
	#if !defined(__DOXYGEN__)
		/* Macros: */
			#define BUTTONS_CMASK                  (1 << 6)
			#define BUTTONS_FMASK_PORT1            ((1 << 4) | (1 << 5))

			#define BUTTONS_EMASK                  (1 << 6)
			#define BUTTONS_FMASK_PORT2            ((1 << 6) | (1 << 7))
	#endif

	/* Public Interface - May be used in end-application: */
		/* Macros: */
			/** Button mask for the first button on the board. */
			#define BUTTONS_LEFT_PORT1	(1 << 6) //pc6
			#define BUTTONS_RIGHT_PORT1	(1 << 5) //pf5 
			#define BUTTONS_MIDDLE_PORT1	(1 << 4) //pf4

			#define BUTTONS_LEFT_PORT2	(1 << 6) //pe6
			#define BUTTONS_RIGHT_PORT2	(1 << 7) //pf7 
			#define BUTTONS_MIDDLE_PORT2	(1 << 6) //pf6

		/* Inline Functions: */
		#if !defined(__DOXYGEN__)
			static inline void Buttons_Init_Port1(void)
			{
				DDRC  &= ~BUTTONS_CMASK;
				DDRF  &= ~BUTTONS_FMASK_PORT1;

				PORTC |=  BUTTONS_CMASK;
				PORTF |=  BUTTONS_FMASK_PORT1;
			}

			static inline void Buttons_Init_Port2(void)
			{
				DDRE  &= ~BUTTONS_EMASK;
				DDRF  &= ~BUTTONS_FMASK_PORT2;

				PORTE |=  BUTTONS_EMASK;
				PORTF |=  BUTTONS_FMASK_PORT2;
			}

			static inline void Buttons_Disable_Port1(void)
			{
				DDRC  &= ~BUTTONS_CMASK;
				DDRF  &= ~BUTTONS_FMASK_PORT1;

				PORTC &= ~BUTTONS_CMASK;
				PORTF &= ~BUTTONS_FMASK_PORT1;
			}

			static inline void Buttons_Disable_Port2(void)
			{
				DDRE  &= ~BUTTONS_EMASK;
				DDRF  &= ~BUTTONS_FMASK_PORT2;

				PORTE &= ~BUTTONS_EMASK;
				PORTF &= ~BUTTONS_FMASK_PORT2;
			}

			static inline uint8_t Buttons_GetStatus_Port1(void) ATTR_WARN_UNUSED_RESULT;
			static inline uint8_t Buttons_GetStatus_Port1(void)
			{
				//return ((PINE & BUTTONS_CMASK) ^ BUTTONS_CMASK);
				return (((uint8_t)~PINC & BUTTONS_CMASK) | ((uint8_t)~PINF & BUTTONS_FMASK_PORT1));
			}

			static inline uint8_t Buttons_GetStatus_Port2(void) ATTR_WARN_UNUSED_RESULT;
			static inline uint8_t Buttons_GetStatus_Port2(void)
			{
				//return ((PINE & BUTTONS_CMASK) ^ BUTTONS_CMASK);
				return (((uint8_t)~PINE & BUTTONS_EMASK) | ((uint8_t)~PINF & BUTTONS_FMASK_PORT2));
			}
		#endif

	/* Disable C linkage for C++ Compilers: */
		#if defined(__cplusplus)
			}
		#endif

#endif

/** @} */


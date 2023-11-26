/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  $Id: wiring.h 249 2007-02-03 16:52:51Z mellis $

  Changelog
  -----------
  11/25/11  - ryan@ryanmsutton.com - Add pins for Sanguino 644P and 1284P
  07/15/12  - ryan@ryanmsutton.com - Updated for arduino0101
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

/*
#define NOT_A_PIN 0
#define NOT_A_PORT 0
#define NOT_ON_TIMER 0
#define TIMER0A 1
#define TIMER0B 2
#define TIMER1A 3
#define TIMER1B 4
#define TIMER2  5
#define TIMER2A 6
#define TIMER2B 7

#define TIMER3A 8
#define TIMER3B 9
#define TIMER3C 10
#define TIMER4A 11
#define TIMER4B 12
#define TIMER4C 13
#define TIMER5A 14
#define TIMER5B 15
#define TIMER5C 16
*/

const static uint8_t SS   = 20;
const static uint8_t MOSI = 21;
const static uint8_t MISO = 22;
const static uint8_t SCK  = 23;

static const uint8_t SDA = 9;
static const uint8_t SCL = 8;

static const uint8_t A0 = 24;
static const uint8_t A1 = 25;
static const uint8_t A2 = 26;
static const uint8_t A3 = 27;
static const uint8_t A4 = 28;
static const uint8_t A5 = 29;
static const uint8_t A6 = 30;
static const uint8_t A7 = 31;

// On the ATmega1280, the addresses of some of the port registers are
// greater than 255, so we can't store them in uint8_t's.
// extern const uint16_t PROGMEM port_to_mode_PGM[];
// extern const uint16_t PROGMEM port_to_input_PGM[];
// extern const uint16_t PROGMEM port_to_output_PGM[];

// extern const uint8_t PROGMEM digital_pin_to_port_PGM[];
// extern const uint8_t PROGMEM digital_pin_to_bit_PGM[];
// extern const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[];
// extern const uint8_t PROGMEM digital_pin_to_timer_PGM[];

// ATMEL ATMEGA644P / IPST-SE
//
//                   +---\/---+
//  INT0 (D 16) PB0  1|        |40  PA0 (AI 0 / D31)
//  INT1 (D 17) PB1  2|        |39  PA1 (AI 1 / D30)
//  INT2 (D 18) PB2  3|        |38  PA2 (AI 2 / D29)
//   PWM (D 19) PB3  4|        |37  PA3 (AI 3 / D28)
//   PWM (D 20) PB4  5|        |36  PA4 (AI 4 / D27)
//  MOSI (D 21) PB5  6|        |35  PA5 (AI 5 / D26)
//  MISO (D 22) PB6  7|        |34  PA6 (AI 6 / D25)
//   SCK (D 23) PB7  8|        |33  PA7 (AI 7 / D24)
//             RST  9|        |32  AREF
//             VCC 10|        |31  GND 
//             GND 11|        |30  AVCC
//           XTAL2 12|        |29  PC7 (D 15)
//           XTAL1 13|        |28  PC6 (D 14)
//  RX0 (D 0)  PD0 14|        |27  PC5 (D 13) TDI
//  TX0 (D 1)  PD1 15|        |26  PC4 (D 12) TDO
//  RX1 (D 2) PD2 16|        |25  PC3 (D 12) TMS
//  TX1 (D 3) PD3 17|        |24  PC2 (D 10) TCK
//  PWM (D 4) PD4 18|        |23  PC1 (D 9) SDA
//  PWM (D 5) PD5 19|        |22  PC0 (D 8) SCL
//  PWM (D 6) PD6 20|        |21  PD7 (D 7) PWM
//                   +--------+
//
#define NUM_DIGITAL_PINS            32
#define NUM_ANALOG_INPUTS           8
#define analogInputToDigitalPin(p)  ((p < NUM_ANALOG_INPUTS) ? (p) + 24 : -1)

#define digitalPinHasPWM(p)         ((p) == 4 || (p) == 5 || (p) == 6 || (p) == 7 || (p) == 19 || (p) == 20 )

#define PA 1
#define PB 2
#define PC 3
#define PD 4

#ifdef ARDUINO_MAIN
// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] =
{
        NOT_A_PORT,
        (uint16_t) &DDRA,
        (uint16_t) &DDRB,
        (uint16_t) &DDRC,
        (uint16_t) &DDRD,
};

const uint16_t PROGMEM port_to_output_PGM[] =
{
        NOT_A_PORT,
        (uint16_t) &PORTA,
        (uint16_t) &PORTB,
        (uint16_t) &PORTC,
        (uint16_t) &PORTD,
};
const uint16_t PROGMEM port_to_input_PGM[] =
{
        NOT_A_PORT,
        (uint16_t) &PINA,
        (uint16_t) &PINB,
        (uint16_t) &PINC,
        (uint16_t) &PIND,
};
const uint8_t PROGMEM digital_pin_to_port_PGM[] =
{
        PD, /* 0 */
        PD,
        PD,
        PD,
        PD,
        PD,
        PD,
        PD,
        PC, /* 8 */
        PC,
        PC,
        PC,
        PC,
        PC,
        PC,
        PC,
        PB, /* 16 */
        PB,
        PB,
        PB,
        PB,
        PB,
        PB,
        PB,
        PA, /* 24 */
        PA,
        PA,
        PA,
        PA,
        PA,
        PA,
        PA  /* 31 */
};
const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] =
{
        _BV(0), /* 0, port D */
        _BV(1),
        _BV(2),
        _BV(3),
        _BV(4),
        _BV(5),
        _BV(6),
        _BV(7),
        _BV(0), /* 8, port C */
        _BV(1),
        _BV(2),
        _BV(3),
        _BV(4),
        _BV(5),
        _BV(6),
        _BV(7),
        _BV(0), /* 16, port B */
        _BV(1),
        _BV(2),
        _BV(3),
        _BV(4),
        _BV(5),
        _BV(6),
        _BV(7),
        _BV(0), /* 24, port A */
        _BV(1),
        _BV(2),
        _BV(3),
        _BV(4),
        _BV(5),
        _BV(6),
        _BV(7)
};
const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
{
        NOT_ON_TIMER,   /* 0  - PD0 */
        NOT_ON_TIMER,   /* 1  - PD1 */
        NOT_ON_TIMER,   /* 2 - PD2 */
        NOT_ON_TIMER,   /* 3 - PD3 */
        TIMER1B,        /* 4 - PD4 */
        TIMER1A,        /* 5 - PD5 */
        TIMER2B,        /* 6 - PD6 */
        TIMER2A,        /* 7 - PD7 */
        NOT_ON_TIMER,   /* 8 - PC0 */
        NOT_ON_TIMER,   /* 9 - PC1 */
        NOT_ON_TIMER,   /* 10 - PC2 */
        NOT_ON_TIMER,   /* 11 - PC3 */
        NOT_ON_TIMER,   /* 12 - PC4 */
        NOT_ON_TIMER,   /* 13 - PC5 */
        NOT_ON_TIMER,   /* 14 - PC6 */
        NOT_ON_TIMER,   /* 15 - PC7 */
        NOT_ON_TIMER,   /* 16  - PB0 */
        NOT_ON_TIMER,   /* 17  - PB1 */
        NOT_ON_TIMER,   /* 18  - PB2 */
        TIMER0A,        /* 19  - PB3 */
        TIMER0B,        /* 20  - PB4 */
        NOT_ON_TIMER,   /* 21  - PB5 */
        NOT_ON_TIMER,   /* 22  - PB6 */
        NOT_ON_TIMER,   /* 23  - PB7 */

        NOT_ON_TIMER,   /* 24 - PA0 */
        NOT_ON_TIMER,   /* 25 - PA1 */
        NOT_ON_TIMER,   /* 26 - PA2 */
        NOT_ON_TIMER,   /* 27 - PA3 */
        NOT_ON_TIMER,   /* 28 - PA4 */
        NOT_ON_TIMER,   /* 29 - PA5 */
        NOT_ON_TIMER,   /* 30 - PA6 */
        NOT_ON_TIMER   /* 31 - PA7 */
};
#endif
#endif

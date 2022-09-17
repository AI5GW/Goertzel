/*
 * Goertzel.cpp - Goertzel algorithm library for Arduino
 *
 * Copyright (C) 2022 Sebastian Westerhold (AI5GW) <sebastian@baltic-lab.com>
 * Web (EN): https://baltic-lab.com
 * Web (DE): https://baltic-labor.de/
 * YouTube (EN): https://www.youtube.com/c/BalticLab
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <Goertzel.h>
#include "Arduino.h"

#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__) || defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega16U4__)
#include <avr/pgmspace.h>
#endif

#ifndef SAMPLE_RATE
#if F_CPU == 16000000L
#define SAMPLE_RATE 8800
#else
#define SAMPLE_RATE 4400
#endif
#endif

#ifndef ADC_MIDPOINT
#define ADC_MIDPOINT 512
#endif

float COEF;

/* Public Class Members */
Goertzel::Goertzel(float FREQ, int SAMP_RATE) {
  COEF = 2.0 * cos((2.0 * PI * FREQ) / SAMP_RATE);
}

float Goertzel::Mag(int SAMPLES[], int DEPTH) {
  float Q1 = 0;
  float Q2 = 0;
  for (int n = 0; n < DEPTH; n++) {
    float Q0 = COEF * Q1 - Q2 + (float)(SAMPLES[n] - ADC_MIDPOINT);
    Q2 = Q1;
    Q1 = Q0;
  }
  return sqrt(Q1 * Q1 + Q2 * Q2 - COEF * Q1 * Q2);
}

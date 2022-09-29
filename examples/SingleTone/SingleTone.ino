/*
 *  SingleTone.ino - Goertzel library example
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

// Define the ADC midpoint (512 is the default)
#define ADC_MIDPOINT 512

// Define the sample rate (8800 S/s is the default for 16 MHz Boards)
#define SAMPLE_RATE 8800

// include the Goertzel library
#include <Goertzel.h>

// Array buffer for ADC samples
int Samples[100];

// Variable for resulting magnitude
float Mag;

// Instantiate class for 440 Hz tone detection
Goertzel TONE(440.0);

void setup() {
  Serial.begin(9600);
}

void loop() {

  // Get 100 ADC samples from A1 and store them in the buffer
  for (int n = 0; n < 100; n++) {
    Samples[n] = analogRead(A1);
  }

  // get the magnitude of the 440 Hz tone
  // The second parameter is the amount of samples passed to the class function
  Mag = TONE.Mag(Samples, 100);

  // print result to serial
  Serial.println(Mag);
}

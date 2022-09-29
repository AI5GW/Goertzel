/*
 *  FSK_DEMOD.ino - Goertzel library FSK demodulation example
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

// Array for the ADC samples
int Samples[50];

// Variables for the tone magnitudes
float TONE_ONE_MAG, TONE_TWO_MAG;

//FSK output variable
bool FSK;

// 550 Hz and 670 Hz
Goertzel ONE(500.0, 8800);
Goertzel TWO(670.0, 8800);

void setup() {
  Serial.begin(9600);
}

void loop() {

  // Get 50 samples from A1
  for (int n = 0; n < 50; n++) {
    Samples[n] = analogRead(A1);
  }

  // Determine the amount of Samples
  int DEPTH = sizeof(Samples) / sizeof(Samples[0]);

  // Get the magnitude for both tones
  TONE_ONE_MAG = ONE.Mag(Samples, DEPTH);
  TONE_TWO_MAG = TWO.Mag(Samples, DEPTH);

  // If the magnitudeof Tone 2 (670 Hz) is larger than the magnitude of tone 1 (500 Hz), output a logic 1
  if (TONE_TWO_MAG > TONE_ONE_MAG > 0) {
    FSK = 1;
  } else {
    FSK = 0;
  }

  // For simplicity, print results via Serial
  Serial.println(FSK);
}

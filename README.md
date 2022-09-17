Goertzel library for Arduino
==========================
The Goertzel algorithm is a fast and resource-efficient way of evaluating just a small portion of a discrete Fourier transform (DFT). This is particularly useful if only the magnitude of a few single frequencies is of interest. Compared to a DFT, this method is rather quick and efficient. This library provides an easy way to take advantage of the Goertzel algorithm for tone decoding. The library can be used to detect the presence of a single tone, or it can be used to detect multiple tones. The latter can be useful for DTMF decoding, FSK demodulation and various other applications. 

Library Installation
---------------------
The best way to install the library is via the Arduino Library Manager, which is available if you are using Arduino IDE version 1.6.2 or greater. To install it this way, simply go to the menu Sketch > Include Library > Manage Libraries..., and then in the search box at the upper-right, type "Goertzel". Click on the entry in the list below, then click on the provided "Install" button. By installing the library this way, you will always have notifications of future library updates, and can easily switch between library versions.

If you need to or would like to install the library the old-fashioned was, you can download a copy of the library in a ZIP file. Download a ZIP file of the library from the GitHub repository by using the "Download ZIP" button at the right of the main repository page. Extract the ZIP file, then rename the unzipped folder as "Goertzel". Finally, open the Arduino IDE, select menu Sketch > Import Library... > Add Library..., and select the renamed folder that you just downloaded. Restart the IDE and you should have access to the new library.

Hardware Requirements
-------------------------------
This library has been written for the Arduino platform and has been successfully tested on the Arduino Uno, Arduino Nano and Arduino Mega 2560 Rev 3.

Available Functions and Constants
-------

Two example sketches are included in the examples folder of the library. SingleTone.ino shows how to detect the magnitude of one single tone from an array of ADC samples. FSK_DEMOD.ino shows how to demodulate an FSK signal by comparing the magnitude of two frequencies. 
    
After instantiating the Goertzel class, the Mag() function will be available to determine the magnitude of the frequency specified during instantiation. The function requires two parameters: The sample array is the first parameter, the amount of samples passed the second. 
    
Links & Contact
---------------------
If you have any questions or comments, feel free to contact me through the email address provided in the project files. Additionally, feel free to check out my blogs and YouTube channel for additional information, examples and feedback:


[Blog (EN): https://baltic-lab.com](https://baltic-lab.com)

[Blog (DE): https://baltic-labor.de/](https://baltic-labor.de/)

[YouTube (EN): https://www.youtube.com/c/BalticLab](https://www.youtube.com/c/BalticLab)

Arduino Lint Status
-------------------
[![arduino-lint Actions Status](https://github.com/AI5GW/CCIR476/workflows/arduino-lint/badge.svg)](https://github.com/AI5GW/Goertzel/actions)

Changelog
---------
    
* v1.0.0

    * Initial release
    
License
-------
Goertzel is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

Goertzel is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with Goertzel. If not, see <http://www.gnu.org/licenses/>.

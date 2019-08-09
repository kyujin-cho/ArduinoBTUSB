/*
 * Copyright (c) 2019 Kyujin Cho
 * Email: thy2134@gmail.com
 * Website: blog.r3mark.xyz
 *
 * This file is part of ArduinoBTUSB.
 *
 * ArduinoBTUSB is free software: you can redistribute it and/or modify
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
 
#include <KeyboardController.h>

#include "Bluetooth.h"

#define KEYBOARD_CLOCK 4
#define KEYBOARD_DATA 5

#define _DEBUG 0

#if _DEBUG
#define HARDWARE_SERIAL_RATE 38400
#else
#define HARDWARE_SERIAL_RATE 115200
#endif

USBKeyboard keyboard(KEYBOARD_CLOCK, KEYBOARD_DATA);

#if _DEBUG
#define BLUETOOTH_DEBUG_BAUD 9600
Bluetooth bluetooth(BLUETOOTH_DEBUG_BAUD);
#else
Bluetooth bluetooth(HARDWARE_SERIAL_RATE);
#endif

USBHost usb;
KeyboardController keyboard(usb);

vector<int> pressedKeys;

void keyPressed() {
	pressedKeys.push_back(keyboard.getOemKey());
	bluetooth.sendKeyboardState(keyboard.getModifiers(), pressedKeys);
}

void keyReleased() {
	pressedKeys.pop_back();
	bluetooth.sendKeyboardState(keyboard.getModifiers(), pressedKeys);
}


void setup() {
#if _DEBUG
	Serial.begin(HARDWARE_SERIAL_RATE);
	Serial.println("Setup started");
#endif

#if _DEBUG
  Serial.println("Initializing keyboard...");
#endif

	delay(250);

	Serial.println("Setup complete");
}

void loop() {
	usb.Task();
}

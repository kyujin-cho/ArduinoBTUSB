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
 
#ifndef  BLUETOOTH_H
#define BLUETOOTH_H

#include <Arduino.h>

class Bluetooth
{
public:
	Bluetooth(uint32_t baudRate);
	~Bluetooth();

	void sendKeyboardState(uint8_t modifiers, uint8_t * keysPressed);
	void sendConsumerReport(uint16_t consumerKeys);
	void getKeyboardLEDState();

private:
	Stream * _serialStream;
};

#endif // ! BLUETOOTH_H

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

#include "Bluetooth.h"

Bluetooth::Bluetooth(uint32_t baudRate)
{
	_serialStream = &Serial1;
	((HardwareSerial*)_serialStream)->begin(baudRate);
}

Bluetooth::~Bluetooth() {}

void Bluetooth::sendKeyboardState(uint8_t modifiers, vector<int> keysPressed)
{
	_serialStream->write((uint8_t)0xFD);
	_serialStream->write((uint8_t)0x09);
	_serialStream->write((uint8_t)0x01);
	_serialStream->write(modifiers);
	_serialStream->write((uint8_t)0x00);
	for (uint8_t i = 0; i < keysPressed.size(); ++i)
	{
		_serialStream->write(keysPressed[i]);
	}
}

void Bluetooth::sendConsumerReport(uint16_t consumerKeys)
{
	_serialStream->write((uint8_t)0xFD);
	_serialStream->write((uint8_t)0x00);
	_serialStream->write((uint8_t)0x02);
	_serialStream->write((uint8_t)((consumerKeys >> 8) & 0xFF));
	_serialStream->write((uint8_t)(consumerKeys & 0xFF));
	_serialStream->write((uint8_t)0x00);
	_serialStream->write((uint8_t)0x00);
	_serialStream->write((uint8_t)0x00);
	_serialStream->write((uint8_t)0x00);
}

void Bluetooth::getKeyboardLEDState()
{
	_serialStream->write((uint8_t)0xFF);
	_serialStream->write((uint8_t)0x02);

	//TODO
	//what to read from BT device?
}

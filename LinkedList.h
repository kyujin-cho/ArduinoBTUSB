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
 
#include <Arduino.h>

class LinkedList {
    public:
        LinkedList();

        void put(int data);
        int get(int index);
        void remove(int data);
        void removeAt(int index);
    
    private:
        Node *start;
};

class Node {
    public: 
        Node(int _data);
        
        int data;
        Node *prev;
        Node *next;
};
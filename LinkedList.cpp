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
 
#include "LinkedList.h"

LinkedList::LinkedList() { }

void LinkedList::put(int data) {
    Node *node = start;
    if (!node) {
        start = Node(data);
        return;
    }
    while (node->next) {
        node = node->next;
    }
    node->next = Node(data);
    node->next->prev = node;
}
int LinkedList::get(int index) {
    Node *node = start;
    if (!node) return NULL;
    int traveled = 0;
    while (node->next && traveled < index) {
        node = node->next;
        traveled++;
    }
    if (traveled != index) return NULL;
    return node->data;
}
void LinkedList::remove(int data) {
    Node *node = start;
    if (!node) return NULL;
    while (node->next && node->data != data) {
        node = node->next;
    }
    if (node->data != data) return;
    node->prev->next = NULL;
    node->next->prev = NULL;
}
void LinkedList::removeAt(int index) {
    Node *node = start;
    if (!node) return NULL;
    int traveled = 0;
    while (node->next && traveled < index) {
        node = node->next;
        traveled++;
    }
    if (traveled != index) return NULL;
    node->prev->next = NULL;
    node->next->prev = NULL;
}

Node::Node(int _data) {
    data = _data;
}
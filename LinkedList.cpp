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
#include "Node.h"
#include <iostream> 
template <class T>
LinkedList<T>::LinkedList() {
    length = 0;
    head = nullptr;
    tail = nullptr;
    curr = nullptr;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> & list) {
    length = 0;
    head = nullptr;
    tail = nullptr;
    curr = nullptr;

    ListNode<T> * temp = list.head;

    while(temp != nullptr)
    {
        Append(temp->element);
        temp = temp->next;
    }
}

template <class T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList<T> & list)
{
    Clear();

    ListNode<T> * temp = list.head;

    while(temp != nullptr)
    {
        Append(temp->element);
        temp = temp->next;
    }

    return *this;
}

template <class T>
LinkedList<T>::~LinkedList() {
    Clear();
}

template<class T>
T& LinkedList<T>::getCurrent()
{
  return curr->element;
}

template<class T>
T& LinkedList<T>::First() const
{
  return head->element;
}

template<class T>
T& LinkedList<T>::Last() const
{
  return tail->element;
}

template<class T>
int LinkedList<T>::getLength()
{
  return length;
}

template <class T>
void LinkedList<T>::Append(T element)
{
    ListNode<T> * node = new ListNode<T>(element, tail, nullptr);

    if(length == 0)
        curr = tail = head = node;
    else {
        tail->next = node;
        tail = node;
    }

    length++;

}

template <class T>
void LinkedList<T>::DeleteLast()
{
    if(length == 0)
      return;
    curr = tail;
    DeleteCurrent();
}

template <class T>
void LinkedList<T>::DeleteFirst()
{
    if(length == 0)
      return;
    curr = head;
    DeleteCurrent();
}

template <class T>
bool LinkedList<T>::next()
{
    if(length == 0)
        return false;

    if(curr->next == nullptr)
        return false;

    curr = curr->next;
    return true;
}

template <class T>
bool LinkedList<T>::moveTo(int index) {
    if (index > length) return false;
    for (int i = 0; i < index; i++) next();
    return true;
}

template <class T>
bool LinkedList<T>::moveToStart()
{
    curr = head;
    return length != 0;
}

template<class T>
bool LinkedList<T>::prev()
{
    if(length == 0)
        return false;

    if(curr->prev != nullptr)
        return false;

    curr = curr->prev;
    return true;
}

template <class T>
void LinkedList<T>::Delete(T & elem)
{
    if(Search(elem))
        DeleteCurrent();
}

template <class T>
void LinkedList<T>::DeleteCurrent()
{
    if(length == 0)
        return;
    length--;
    ListNode<T> * temp = curr;

    if(temp->prev != nullptr)
        temp->prev->next = temp->next;
    if(temp->next != nullptr)
        temp->next->prev = temp->prev;

    if(length == 0)
        head = curr = tail = nullptr;
    else if(curr == head)
        curr = head = head->next;
    else if(curr == tail)
        curr = tail = tail->prev;
    else
        curr = curr->prev;

     delete temp;
}

template <class T>
bool LinkedList<T>::Search(T elem)
{
    if(length == 0)
        return false;
    if(moveToStart())
        do {
            if(curr->element == elem)
                return true;
        } while (next());
    return false;
}

template <class T>
void LinkedList<T>::PutFirstToLast()
{
  if(length < 2)
    return;
  ListNode<T>* temp = head->next;
  head->next->prev = nullptr;
  head->next = nullptr;
  head->prev = tail;
  tail->next = head;
  tail = head;
  head = temp;
}

template <class T>
void LinkedList<T>::Update(T elem)
{
    if(Search(elem))
        curr->element = elem;
}

template <class T>
void LinkedList<T>::Clear()
{
    if(length == 0)
        return;
    ListNode<T> * temp = head;

    while(temp != nullptr)
    {
        head = head->next;
        delete temp;
        temp = head;
    }

    head = curr = tail = nullptr;

}

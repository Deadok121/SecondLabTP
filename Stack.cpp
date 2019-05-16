//
// Created by Roman Oborin on 2019-04-22.
//

#include <limits>
#include <cstdlib>
#include "iostream"
#include "Stack.h"

using namespace std;

Stack::Stack(int count) {
    for (int i = 0; i < count; i++) {
        push(rand());
    }
}

Stack::~Stack() {
    StackElement *last = getLastElement();
    for (int i = 0; i < getSize(); ++i) {
        free(last);
        last = last->getPrevious();
    }
    free(last);
    setLastElement(NULL);
}

Stack::Stack(const Stack &stack) {
    StackElement *last = stack.getLastElement();
    for (int i = 0; i < stack.getSize(); ++i) {
        push(last->getData());
        last = last->getPrevious();
    }
}

StackElement *Stack::getLastElement() const {
    return lastElement;
}

void Stack::setLastElement(StackElement *lastElement) {
    Stack::lastElement = lastElement;
}

bool Stack::operator==(const Stack &c2) const {
    auto *first = new Stack(*this);
    auto *second = new Stack(c2);
    if (first->getSize() != second->getSize()) {
        return false;
    }


    for (int i = 0; i < second->getSize(); ++i) {
        if (first->pop() != second->pop()) {
            return false;
        }
    }

    return true;
}

bool Stack::operator!=(const Stack &c2) const {
    bool res = operator==(c2);
    return !res;
}

void Stack::display() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }

    StackElement *last = getLastElement();
    cout << last->getData() << " ";
    for (int i = 0; i < getSize() - 1; ++i) {
        last = last->getPrevious();
        cout << last->getData() << " ";
    }
    cout << endl;
}

int Stack::pop() const {
    if (isEmpty()) {
        return INT_MIN;
    }

    StackElement *temp = getLastElement();
    int popped = temp->getData();
    delete temp;
    decrementLenght();
    return popped;
}

int Stack::peek() {
    if (isEmpty())
        return INT_MIN;
    return getLastElement()->getData();
}

void Stack::push(int data) {
    auto stackNode = new StackElement(data);
    stackNode->setPrevious(getLastElement());
    setLastElement(stackNode);
    incrementLenght();
}

bool Stack::operator>(const Stack &c2) const {
    return getSize() > c2.getSize();
}

bool Stack::operator<(const Stack &c2) const {
    return getSize() > c2.getSize();
}

bool Stack::operator>=(const Stack &c2) const {
    return *this > c2 || *this == c2;
}

bool Stack::operator<=(const Stack &c2) const {
    return *this < c2 || *this == c2;
}

Stack Stack::operator()(int lenght) {
    Stack *stack = new Stack();
    StackElement *last = getLastElement();
    while (lenght > 0) {
        for (int j = lenght; j > 1; j--) {
            last = last->getPrevious();
        }
        stack->push(last->getData());
        last = getLastElement();
        lenght--;
    }
    return *stack;
}

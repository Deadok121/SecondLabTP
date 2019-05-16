//
// Created by Roman Oborin on 2019-04-22.
//

#ifndef SECONDLABTP_STACK_H
#define SECONDLABTP_STACK_H

#include "StackElement.h"

class Stack {
private:
    int lenght = 0;

    StackElement *lastElement = NULL;
public:
    explicit Stack(int countElems);

    Stack() = default;

    ~Stack();

    Stack(const Stack &stack);

    bool operator==(const Stack &c2) const;

    bool operator!=(const Stack &c2) const;

    bool operator>(const Stack &c2) const;

    bool operator<(const Stack &c2) const;

    bool operator<=(const Stack &c2) const;

    bool operator>=(const Stack &c2) const;

    Stack operator() (int i);

    StackElement *getLastElement() const;

    void display();

    int getSize() const {
        return lenght;
    }

    void setLastElement(StackElement *lastElement);

    void incrementLenght() {
        lenght++;
    }

    void decrementLenght() const {
        const_cast<int &>(lenght) = lenght - 1;
    }

    int isEmpty() const {
        return getSize() == 0;
    }

    void push(int data);

    int pop() const;

    int peek();

};

#endif //SECONDLABTP_STACK_H

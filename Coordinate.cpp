//
// Created by Roman Oborin on 2019-04-05.
//

#include <iostream>
#include "Сoordinate.h"

//префиксная форма, дружественная функция
Coordinate &operator++(Coordinate &coordinate) {
    Coordinate &old = coordinate;
    coordinate.x += coordinate.x;
    coordinate.y += coordinate.y;
    coordinate.z += coordinate.z;
    return old;
}

//постфиксный инкремент
const Coordinate Coordinate::operator++(int) {
    x += 1.5;
    y += 1.5;
    z += 1.5;
    return *this;
}


//постфикс
const Coordinate Coordinate::operator--(int) {
    x -= 5.9;
    y -= 5.9;
    z -= 5.9;
    return Coordinate();
}


//Префикс
Coordinate &Coordinate::operator--() {
    Coordinate *old = this;
    float xc = x;
    float xy = y;
    float xz = z;
    x = xc - xy - xz;
    y = xc - xy - xz;
    z = xc - xy - xz;
    return *old;
}

void Coordinate::display() {
    std::cout << std::endl;
    std::cout << "x:" << x << " y:" << y << " z:" << z;
}








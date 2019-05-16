//
// Created by Roman Oborin on 2019-04-05.
//

#ifndef SECONDLABTP_СOORDINATE_H
#define SECONDLABTP_СOORDINATE_H

class Coordinate {
private:
    float x = 0, y = 0, z = 0;
public:
    Coordinate() = default;

    ~Coordinate() = default;

    Coordinate(const Coordinate &coordinate) = default;

    //префиксная форма, дружественная функция инкремент
    friend Coordinate &operator++(Coordinate &coordinate);

    //постфиксный инкремент non member func
    const Coordinate operator++(int);

    //постфиксный декремент
    const Coordinate operator--(int);

    //инфиксный декремент
    Coordinate &operator--();

    void display();

};

#endif SECONDLABTP_СOORDINATE_H

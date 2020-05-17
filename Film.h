//
// Created by Expert on 5/13/2020.
//

#ifndef PROIECT3_FILM_H
#define PROIECT3_FILM_H

#include <iostream>

class Film {
    std::string nume, tip;
    int durata;
public:
    explicit Film(std::string nume = "", std::string tip = "", int durata = 0);

    Film(const Film &film);

    ~Film() = default;

    Film &operator=(const Film &x);

    friend std::istream &operator>>(std::istream &input, Film &film);

    friend std::ostream &operator<<(std::ostream &output, Film &film);

    std::string getNume() const {return nume;}
};


#endif //PROIECT3_FILM_H

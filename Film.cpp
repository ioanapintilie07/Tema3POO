//
// Created by Expert on 5/13/2020.
//

#include "Film.h"

Film::Film(std::string nume, std::string tip, int durata) : nume {nume}, tip {tip}, durata {durata} {};

Film::Film(const Film &film) {
    nume = film.nume;
    tip = film.tip;
    durata = film.durata;
}

Film &Film::operator=(const Film &x){
    if (this == &x)
        return *this;
    nume = x.nume;
    tip = x.tip;
    durata = x.durata;
    return *this;
}

std::istream &operator>>(std::istream &input, Film &film) {
    input >> film.nume >> film.tip >> film.durata;
    return input;
}

std::ostream &operator<<(std::ostream &output, Film &film){
    output << film.nume << " " << film.tip << " " << film.durata;
    return output;

}
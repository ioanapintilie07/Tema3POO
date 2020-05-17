//
// Created by Expert on 5/13/2020.
//

#include "Personal.h"

Personal::Personal(std::string cnp, std::string nume, std::string numeFilm) : cnp{cnp}, nume{nume},
                                                                              numeFilm{numeFilm} {};

Personal::Personal(const Personal &personal) {
    cnp = personal.cnp;
    nume = personal.nume;
    numeFilm = personal.numeFilm;
}

Personal &Personal::operator=(const Personal &personal) {
    if (this == &personal)
        return *this;
    cnp = personal.cnp;
    nume = personal.nume;
    numeFilm = personal.numeFilm;
    return *this;
}


std::istream &operator>>(std::istream &input, Personal &personal) {
    input >> personal.cnp >> personal.nume >> personal.numeFilm;
    return input;
}

void Personal::afisare() const {
    std::cout << cnp << ", " << nume << ", " << numeFilm;
}
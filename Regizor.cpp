//
// Created by Expert on 5/13/2020.
//

#include "Regizor.h"

Regizor::Regizor(std::string cnp, std::string nume, std::string numeFilm, int sumaFixa) : Personal{cnp, nume, numeFilm}, sumaFixa {sumaFixa} {}

Regizor::Regizor(const Regizor &regizor) : Personal{regizor} {
    sumaFixa = regizor.sumaFixa;
}

Regizor &Regizor::operator=(const Regizor &regizor) {
    if(this == &regizor)
        return *this;
    *this = regizor;
    this->sumaFixa = regizor.sumaFixa;
    return *this;
}

std::istream &operator>>(std::istream &input, Regizor &regizor) {
    Personal *p = &regizor;
    input >> *p;
    input >> regizor.sumaFixa;
    return input;

}

void Regizor::afisare() const {
    std::cout << cnp << ", " << nume << ", " << numeFilm << ", " << sumaFixa;
}

int Regizor::getSumaFixa() const {
    return sumaFixa;
}
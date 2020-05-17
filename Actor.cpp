//
// Created by Expert on 5/14/2020.
//

#include "Actor.h"

Actor::Actor(std::string cnp, std::string nume, std::string numeFilm, bool principal) : Personal{cnp, nume, numeFilm}, principal {principal} {}

Actor::Actor(const Actor &actor) : Personal{actor} {
    principal = actor.principal;
}

Actor &Actor::operator=(const Actor &actor) {
    if(this == &actor)
        return *this;
    *this = actor;
    this->principal = actor.principal;
    return *this;
}

std::istream &operator>>(std::istream &input, Actor &actor) {
    Personal *p = &actor;
    input >> *p;
    input >> actor.principal;
    return input;

}

void Actor::afisare() const {
    std::cout << cnp << ", " << nume << ", " << numeFilm << ", " << principal;
}


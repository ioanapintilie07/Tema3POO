//
// Created by Expert on 5/14/2020.
//

#ifndef PROIECT3_ACTOR_H
#define PROIECT3_ACTOR_H

#include "Personal.h"

class Actor : public Personal {
    bool principal;
public:
    explicit Actor(std::string cnp = " ", std::string nume = " ", std::string numeFilm = " ", bool principal = false);

    Actor(const Actor &actor);

    ~Actor() {principal = 0; };

    Actor &operator=(const Actor &actor);

    friend std::istream &operator>>(std::istream &input, Actor &actor);

    void afisare() const override;

    bool getRol() const { return principal; };
};


#endif //PROIECT3_ACTOR_H

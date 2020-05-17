//
// Created by Expert on 5/13/2020.
//

#ifndef PROIECT3_REGIZOR_H
#define PROIECT3_REGIZOR_H

#include "Personal.h"

class Regizor : public Personal {
    int sumaFixa;
public:
    explicit Regizor(std::string cnp = " ", std::string nume = " ", std::string numeFilm = " ", int sumaFixa = 0);

    Regizor(const Regizor &regizor);

    ~Regizor() {sumaFixa = 0; };

    Regizor &operator=(const Regizor &regizor);

    friend std::istream &operator>>(std::istream &input, Regizor &regizor);

    void afisare() const override ;

    int getSumaFixa() const;
};


#endif //PROIECT3_REGIZOR_H

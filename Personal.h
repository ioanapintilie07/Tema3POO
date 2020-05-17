//
// Created by Expert on 5/13/2020.
//

#ifndef PROIECT3_PERSONAL_H
#define PROIECT3_PERSONAL_H

#include <iostream>

class Personal {
protected:
    std::string cnp;
    std::string nume;
    std::string numeFilm;
public:
    explicit Personal(std::string cnp = " ", std::string nume = " ", std::string numeFilm = " ");

    Personal(const Personal &personal);

    virtual ~Personal() {
        cnp = "";
        nume = "";
        numeFilm = "";
    };

    Personal &operator=(const Personal &personal);

    friend std::istream &operator>>(std::istream &input, Personal &personal);

    virtual void afisare() const;

    std::string getNume() const {return nume;};

    std::string getNumeFilm() const {return numeFilm;};
};


#endif //PROIECT3_PERSONAL_H

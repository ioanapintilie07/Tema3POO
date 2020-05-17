#include <iostream>
#include <fstream>
#include "Film.h"
#include "Personal.h"
#include "Regizor.h"
#include "Actor.h"
#include <typeinfo>
#include <set>
#include <tuple>

using namespace std;

template<class T>
class FirmaDistributie {
    static int numarPersoane, numarActori;
    static set<tuple<T *, Film *, int>> structura;
    const int bonusPrincipal = 10, bonus = 0;
public:
    FirmaDistributie() = default;

    FirmaDistributie(FirmaDistributie &firma) = default;

    ~FirmaDistributie() = default;

    void adauga(T *obiect, Film *film);

    static void afisare();

    static bool conversieRol(T *obiect);
};

template<class T>
int FirmaDistributie<T>::numarPersoane = 0;

template<class T>
int FirmaDistributie<T>::numarActori = 0;

template<class T>
set<tuple<T *, Film *, int>> FirmaDistributie<T>::structura;

template<class T>
bool FirmaDistributie<T>::conversieRol(T *obiect) {
    Actor *a;
    Regizor *r;
    if (typeid(obiect) == typeid(r))
        return false;
    else if (typeid(obiect) == typeid(a)) {
        a = dynamic_cast<Actor *> (obiect);
        return a->getRol();
    }
    return false;
}

template<class T>
void FirmaDistributie<T>::adauga(T *obiect, Film *film) {
    FirmaDistributie::numarPersoane++;
    Actor *actor;
    tuple<T *, Film *, int> tuplu;
    if (typeid(obiect) == typeid(actor)) {
        FirmaDistributie::numarActori++;
        if (FirmaDistributie<T>::conversieRol(obiect))
            tuplu = make_tuple(obiect, film, bonusPrincipal);
        else
            tuplu = make_tuple(obiect, film, bonus);
    }
    else
        tuplu = make_tuple(obiect, film, bonus);
    structura.insert(tuplu);
}

template<class T>
void FirmaDistributie<T>::afisare() {
    cout << "Personal total: " << numarPersoane << "\nActori in total: " << numarActori << "\n";
    T *ob = new T;
    Film *f = new Film;
    int b;
    for (auto element : structura) {
        tie(ob, f, b) = element;
        std::cout << "Nume: " << ob->getNume() << ". Filmul: " << f->getNume() << ". Bonus: " << b << "\n";
    }
    delete ob;
    delete f;
}

template<>
class FirmaDistributie<Actor> {
    static int numarPersoane, numarActori, numarRoluriPrincipale;
    static set<tuple<Actor *, Film *, int>> structura;
    const int bonusPrincipal = 10, bonus = 0;
public:
    FirmaDistributie() = default;

    FirmaDistributie(FirmaDistributie &firma) = default;

    ~FirmaDistributie() = default;

    void adauga(Actor *obiect, Film *film);

    static void afisare();
};

int FirmaDistributie<Actor>::numarRoluriPrincipale = 0;

int FirmaDistributie<Actor>::numarPersoane = 0;

int FirmaDistributie<Actor>::numarActori = 0;

set<tuple<Actor *, Film *, int>> FirmaDistributie<Actor>::structura;

void FirmaDistributie<Actor>::adauga(Actor *obiect, Film *film) {
    FirmaDistributie::numarPersoane++;
    FirmaDistributie::numarActori++;
    tuple<Actor *, Film *, int> tuplu;
    if (obiect->getRol()) {
        FirmaDistributie::numarRoluriPrincipale++;
        tuplu = make_tuple(obiect, film, bonusPrincipal);
    } else
        tuplu = make_tuple(obiect, film, bonus);
    structura.insert(tuplu);
}

void FirmaDistributie<Actor>::afisare() {
    cout << "Personal total: " << numarPersoane << "\nActori in total: " << numarActori << "\nRoluri principale: "
         << numarRoluriPrincipale << "\n";
    auto *ob = new Actor;
    Film *f = new Film;
    int b;
    for (auto element : structura) {
        tie(ob, f, b) = element;
        std::cout << "Nume: " << ob->getNume() << ". Filmul: " << f->getNume() << ". Bonus: " << b << "\n";
    }
    delete ob;
    delete f;
}

int cautaFilm(Film *filme, int nrFilme, const string &nume) {
    int i;
    for (i = 0; i < nrFilme; ++i)
        if (filme[i].getNume() == nume)
            return i;
    return -1;
}

int main() {
    ifstream fin("intrare.in");
    FirmaDistributie<Personal> firma;
    FirmaDistributie<Regizor> firmaRegizor;
    FirmaDistributie<Actor> firmaActor;
    int nrFilme, nrPersonal, nrRegizori, nrActori, i;
    fin >> nrFilme >> nrPersonal >> nrRegizori >> nrActori;
    Personal *persoane;
    Film *filme;
    Actor *actori;
    Regizor *regizori;
    filme = new Film[nrFilme];
    persoane = new Personal[nrPersonal];
    actori = new Actor[nrActori];
    regizori = new Regizor[nrRegizori];
    for (i = 0; i < nrFilme; ++i) {
        fin >> filme[i];
        cout << filme[i] << "\n";
    }
    for (i = 0; i < nrPersonal; ++i) {
        fin >> persoane[i];
        persoane[i].afisare();
        cout << "\n";
        int cauta = cautaFilm(filme, nrFilme, persoane[i].getNumeFilm());
        if (cauta != -1) {
            Personal *p = &persoane[i];
            Film *f = &filme[cauta];
            firma.adauga(p, f);
        }

    }
    FirmaDistributie<Personal>::afisare();

    for (i = 0; i < nrRegizori; ++i) {
        fin >> regizori[i];
        regizori[i].afisare();
        cout << "\n";
        int cauta = cautaFilm(filme, nrFilme, regizori[i].getNumeFilm());
        if (cauta != -1) {
            Regizor *r = &regizori[i];
            Film *f = &filme[cauta];
            firmaRegizor.adauga(r, f);
        }
    }
    FirmaDistributie<Regizor>::afisare();

    for(i = 0; i < nrActori; ++i) {
        fin >> actori[i];
        actori[i].afisare();
        cout << "\n";
        int cauta = cautaFilm(filme, nrFilme, actori[i].getNumeFilm());
        if(cauta != -1) {
            Actor *a = &actori[i];
            Film *f = &filme[cauta];
            firmaActor.adauga(a, f);
        }
    }
    FirmaDistributie<Actor>::afisare();

    delete filme;
    delete regizori;
    delete persoane;
    delete actori;
    fin.close();
    return 0;
}
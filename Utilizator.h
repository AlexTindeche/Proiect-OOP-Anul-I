#ifndef PORIECT_OOP_ANUL_I_UTILIZATOR_H
#define PORIECT_OOP_ANUL_I_UTILIZATOR_H

#include <iostream>
#include <string.h>
#include <vector>
#include <windows.h>

#include "Masina.h"

using namespace std;

class Utilizator
{
    char* categorie_permis;
    char* nume, * prenume;
    char* cnp;
    vector <Masina> masini_rezervate;

public:
    Utilizator(char* nume = "", char* prenume = "", char* categorie_permis = "", char* cnp = "0000000000000");
    friend istream& operator >> (istream &, Utilizator &);
    friend ostream& operator << (ostream &, const Utilizator &);
    char* getNume() {return nume;};
    char* getPrenume() {return prenume;};
    void rezervare(Masina);
    void remove(Masina);
    ~Utilizator();
};


#endif //PORIECT_OOP_ANUL_I_UTILIZATOR_H

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
    vector<Masina> masini_rezervate;

public:
    Utilizator (char* nume = "", char* prenume = "", char* categorie_permis = "", char* cnp = "0000000000000");

    Utilizator (const Utilizator&);

    friend istream& operator>> (istream&, Utilizator&);

    friend ostream& operator<< (ostream&, const Utilizator&);

    Utilizator& operator= (const Utilizator& u);

    char* getNume ()
    { return nume; };

    char* getPrenume ()
    { return prenume; };

    char* getCNP ()
    { return cnp; };

    void rezervare (Masina&);

    void remove (Masina);

    void eliberare_masini ();

    void elibereaza (Masina&);

    ~Utilizator ();

    void modifica_depozit (Masina m, string s);
};


#endif //PORIECT_OOP_ANUL_I_UTILIZATOR_H

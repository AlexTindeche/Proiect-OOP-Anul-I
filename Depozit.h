#ifndef PORIECT_OOP_ANUL_I_DEPOZIT_H
#define PORIECT_OOP_ANUL_I_DEPOZIT_H

#include <iostream>
#include <string.h>
#include <vector>

#include "Masina.h"

using namespace std;

class Depozit
{
    string locatie;
    int nr_masini;
    vector<Masina> masini;
public:
    Depozit (string s = "", int n = 0);

    ~Depozit ();

    Depozit (const Depozit&);

    friend istream& operator>> (istream&, Depozit&);

    friend ostream& operator<< (ostream&, const Depozit&);

    string getLocatie ()
    { return locatie; };

    void pushMasina (Masina& m)
    { masini.push_back(m); }

    void incrementNr_masini ()
    { nr_masini++; }

    void decrementNr_masini ()
    { nr_masini--; }

    void remove (Masina m);

    void rezerva (Masina m);

    void elibereaza (Masina m);
};
//TODO: de fiecare data cand se adauga masina sa se actualizeze nr masini

#endif //PORIECT_OOP_ANUL_I_DEPOZIT_H

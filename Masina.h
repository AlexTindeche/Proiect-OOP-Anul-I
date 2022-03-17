#ifndef PORIECT_OOP_ANUL_I_MASINA_H
#define PORIECT_OOP_ANUL_I_MASINA_H

#include <iostream>
#include <string.h>
#include <vector>


using namespace std;

class Masina
{
    string marca;
    string depozit;
    string model;
    int nr_loc;
    string transmisie;
    bool aer_conditionat;
    int consum;
    string categorie;
    bool rezervat;
public:
    Masina (string m = "", string d = "", string mar = "", int n = 0, string t = "", bool a = false, int c = 0,
            string cat = "");

    Masina (const Masina& m);

    string getModel ()
    { return model; };

    string getDepozit ()
    { return depozit; };

    string getMarca ()
    { return marca; };

    int getNr_loc ()
    { return nr_loc; };

    string getTransmisie ()
    { return transmisie; };

    bool getAer_conditionat ()
    { return aer_conditionat; };

    int getConsum ()
    { return consum; };

    string getCategorie ()
    { return categorie; };

    bool este_rezervata ()
    { return rezervat; };

    void citire ();

    void rezerva ();

    void elibereaza ();

    void modifica_depozit (string s);

    friend istream& operator>> (istream&, Masina&);

    friend ostream& operator<< (ostream&, const Masina&);

    friend bool operator== (Masina&, Masina&);
};


#endif //PORIECT_OOP_ANUL_I_MASINA_H

#include "Depozit.h"

Depozit::Depozit (string s, int n)
{
    locatie = s;
    nr_masini = n;
}

Depozit::~Depozit ()
{}

Depozit::Depozit (const Depozit& d)
{
    this->locatie = d.locatie;
    this->nr_masini = d.nr_masini;
    for (int i = 0; i < d.masini.size(); i++)
        this->masini.push_back(d.masini[i]);
}

istream& operator>> (istream& in, Depozit& d)
{
    string s;
    cout << "Locatia la care se afla depozitul: ";
    getline(in, s);
    d.locatie = s;
    return in;
}

ostream& operator<< (ostream& out, const Depozit& d)
{
    cout << "Locatia depozitului: " << d.locatie << "\nNr. de masini: " << d.nr_masini << '\n';
    cout << "\n\n\nMasinile aflate in acest depozit: \n";
    for (int i = 0; i < d.masini.size(); i++)
        cout << d.masini[i] << "\n";
}

void Depozit::remove (Masina m)
{
    for (int i = 0; i < masini.size(); i++)
        if (m == masini[i])
        {
            masini.erase(masini.begin() + i);
            nr_masini--;
        }
}

void Depozit::rezerva (Masina m)
{
    for (int i = 0; i < masini.size(); i++)
        if (masini[i] == m)
            masini[i].rezerva();
}

void Depozit::elibereaza (Masina m)
{
    for (int i = 0; i < masini.size(); i++)
        if (masini[i] == m)
            masini[i].elibereaza();
}
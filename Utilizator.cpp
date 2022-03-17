#include "Utilizator.h"

Utilizator::Utilizator (char* nume, char* prenume, char* categorie_permis, char* cnp)
{
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
    this->prenume = new char[strlen(prenume) + 1];
    strcpy(this->prenume, prenume);
    this->categorie_permis = new char[strlen(categorie_permis) + 1];
    strcpy(this->categorie_permis, categorie_permis);
    this->cnp = new char[strlen(cnp) + 1];
    strcpy(this->cnp, cnp);
}

Utilizator::Utilizator (const Utilizator& u)
{
    this->nume = new char[strlen(u.nume) + 1];
    strcpy(this->nume, u.nume);
    this->prenume = new char[strlen(u.prenume) + 1];
    strcpy(this->prenume, u.prenume);
    this->cnp = new char[strlen(u.cnp) + 1];
    strcpy(this->cnp, u.cnp);
    this->categorie_permis = new char[strlen(u.categorie_permis) + 1];
    strcpy(this->categorie_permis, u.categorie_permis);
    for (int i = 0; i < u.masini_rezervate.size(); i++)
        this->masini_rezervate.push_back(u.masini_rezervate[i]);
}

Utilizator& Utilizator::operator= (const Utilizator & u)
{
    if (this != &u)
    {
        this->nume = new char[strlen(u.nume) + 1];
        strcpy(this->nume, u.nume);
        this->prenume = new char[strlen(u.prenume) + 1];
        strcpy(this->prenume, u.prenume);
        this->cnp = new char[strlen(u.cnp) + 1];
        strcpy(this->cnp, u.cnp);
        this->categorie_permis = new char[strlen(u.categorie_permis) + 1];
        strcpy(this->categorie_permis, u.categorie_permis);
    }
    return *this;
}

Utilizator::~Utilizator ()
{ delete[] categorie_permis, delete[] nume, delete[] prenume, delete[] cnp; }

istream& operator>> (istream& in, Utilizator& ui)
{
    char s[256];
    cout << "Numele utilizatorului: ";
    in.getline(s, 256);
    strcpy(ui.nume, s);
    cout << "Prenumele utilizatorului: ";
    in.getline(s, 256);
    strcpy(ui.prenume, s);
    cout << "Categoria permisului: ";
    in.getline(s, 256);
    strcpy(ui.categorie_permis, s);
    cout << "Cnp (13 caractere): ";
    in.getline(s, 256);
    while (strlen(s) != 13)
    {
        cout << "Cnp-ul nu a fost introdus corect\nMai introduceti CNP-ul inca odata: ";
        in.getline(s, 256);
    }
    strcpy(ui.cnp, s);
    return in;
}

ostream& operator<< (ostream& out, const Utilizator& ui)
{
    out << "Nume: " << ui.nume << "\nPrenume: " << ui.prenume << "\nCNP: " << ui.cnp << "\nCategorie permis: "
        << ui.categorie_permis << '\n';
    if (ui.masini_rezervate.size() == 0)
        out << "Utilizitarul nu are nicio masina rezervata";
    else
    {
        cout << "Masini rezervate: \n";
        for (int i = 0; i < ui.masini_rezervate.size(); i++)
            out << ui.masini_rezervate[i] << "\n\n";
    }

    return out;
}

void Utilizator::rezervare (Masina& m)
{
    m.rezerva();
    masini_rezervate.push_back(m);
}

void Utilizator::elibereaza (Masina& m)
{
    for(int i = 0; i < masini_rezervate.size();i++)
        if(masini_rezervate[i] == m)
            masini_rezervate[i].elibereaza();
    m.elibereaza();
}

void Utilizator::remove (Masina m)
{
    for (int i = 0; i < masini_rezervate.size(); i++)
        if (m == masini_rezervate[i])
            masini_rezervate.erase(masini_rezervate.begin() + i);
}

void Utilizator::eliberare_masini()
{
    for(int i = 0; i < masini_rezervate.size(); i++)
        masini_rezervate[i].elibereaza();
}

void Utilizator::modifica_depozit (Masina m, string s)
{
    for(int i = 0; i < masini_rezervate.size(); i++)
        if(masini_rezervate[i] == m)
            masini_rezervate[i].modifica_depozit(s);
}
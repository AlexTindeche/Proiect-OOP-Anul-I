#include "Utilizator.h"

Utilizator::Utilizator(char* nume, char* prenume, char* categorie_permis, char* cnp)
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
Utilizator::~Utilizator(){cout << "Destructor", Sleep(2000), delete [] categorie_permis, delete [] nume, delete [] prenume, delete [] cnp;}

istream& operator >> (istream& in, Utilizator& ui)
{
    char s[256];
    cout << "Numele utilizatorului: ";
    in.getline(s, 256);
    ui.nume = new char[strlen(s) + 1];
    strcpy(ui.nume, s);
    cout << "Prenumele utilizatorului: ";
    in.getline(s, 256);
    ui.prenume = new char[strlen(s) + 1];
    strcpy(ui.prenume, s);
    cout << "Categoria permisului: ";
    in.getline(s, 256);
    ui.categorie_permis = new char[strlen(s) + 1];
    strcpy(ui.categorie_permis, s);
    cout << "Cnp (13 caractere): ";
    in.getline(s, 256);
    while(strlen(s) != 13)
    {
        cout << "Cnp-ul nu a fost introdus corect\nMai introduceti CNP-ul inca odata: ";
        in.getline(s, 256);
    }
    ui.cnp = new char[14];
    strcpy(ui.cnp, s);
    return in;
}

ostream& operator << (ostream & out, const Utilizator& ui)
{
    out << "Nume: " << ui.nume <<  "\nPrenume: " << ui.prenume <<  "\nCNP: " << ui.cnp << "\nCategorie permis: " << ui.categorie_permis << '\n';
    return out;
}

void Utilizator::rezervare(Masina m){masini_rezervate.push_back(m);}
void Utilizator::remove (Masina m)
{
    for(int i = 0; i < masini_rezervate.size(); i++)
        if(m == masini_rezervate[i])
            masini_rezervate.erase(masini_rezervate.begin() + i);
}

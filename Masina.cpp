#include "Masina.h"
#include "common.h"

Masina::Masina (string m, string d, string mar, int n, string t, bool a, int c, string cat)
{
    marca = m;
    depozit = d;
    model = mar;
    nr_loc = n;
    transmisie = t;
    aer_conditionat = a;
    consum = c;
    categorie = cat;
    rezervat = false;
}

Masina::Masina (const Masina& m)
{
    this->marca = m.marca;
    this->depozit = m.depozit;
    this->model = m.model;
    this->nr_loc = m.nr_loc;
    this->transmisie = m.transmisie;
    this->aer_conditionat = m.aer_conditionat;
    this->consum = m.consum;
    this->categorie = m.categorie;
    this->rezervat = m.rezervat;
}

istream& operator>> (istream& in, Masina& masina)
{
    string s;
    int ok = 0;
    while (ok == 0)
    {
        cout << "Depozitul in care se afla: ";
        getline(in, s);
        for (int i = 0; i < dep.size(); i++)
            if (s == dep[i].getLocatie())
                ok = 1;
        if (ok == 0)
        { cout << "Depozitul nu exista, instroduceti din nou datele.\n"; }
    }
    masina.depozit = s;
    cout << "Marca: ";
    getline(in, s);
    masina.marca = s;
    cout << "Model: ";
    getline(in, s);
    masina.model = s;
    cout << "Categorie: ";
    getline(in, s);
    masina.categorie = s;
    cout << "Nr locuri: ";
    in >> masina.nr_loc;
    cout << "Transmisie: ";
    in >> masina.transmisie;
    cout << "Are sau nu aer conditionat: (d/n) ";
    string input;
    in >> input;
    if (input == "d")
        masina.aer_conditionat = true;
    else
        masina.aer_conditionat = false;
    cout << "Consum (l/100km): ";
    in >> masina.consum;
    in.get();
    return in;
}

ostream& operator<< (ostream& out, const Masina& m)
{
    out << "Depozit: " << m.depozit;
    out << "\nMarca: " << m.marca << "\nModel: " << m.model << "\nCategorie: " << m.categorie << "\nNr locuri: "
        << m.nr_loc
        << "\nTransmisie: " << m.transmisie << "\nConsum: " << m.consum << "l/100km" << "\nAer conditionat: ";
    if (m.aer_conditionat)
        out << "Da\n";
    else
        out << "Nu\n";
    if (m.rezervat)
        out << "Rezervat\n";
    else
        out << "Liber\n";
    return out;
}

bool operator== (Masina& m1, Masina& m2)
{
    if (m1.getMarca() != m2.getMarca())
        return false;
    if (m1.getModel() != m2.getModel())
        return false;
    if (m1.getDepozit() != m2.getDepozit())
        return false;
    if (m1.getNr_loc() != m2.getNr_loc())
        return false;
    if (m1.getTransmisie() != m2.getTransmisie())
        return false;
    if (m1.getAer_conditionat() != m2.getAer_conditionat())
        return false;
    if (m1.getConsum() != m2.getConsum())
        return false;
    return true;
}

void Masina::rezerva ()
{
    if (!rezervat)
        rezervat = true;
    else
        cout << "\nMasina este deja rezervata!";
}

void Masina::elibereaza ()
{
    if (rezervat)
        rezervat = false;
    else
        cout << "\nMasina este deja libera!";
}

void Masina::modifica_depozit (string s)
{
    depozit = s;
}


// in caz de nu merge supraincarcarea operatorului de citire
void Masina::citire ()
{
    string s;
    cout << "Depozitul in care se afla: ";
    getline(cin, s);
    depozit = s;
    cout << "Marca: ";
    getline(cin, s);
    marca = s;
    cout << "Model: ";
    getline(cin, s);
    model = s;
    cout << "Nr locuri: ";
    cin >> nr_loc;
    cout << "Transmisie: ";
    cin >> transmisie;
    cout << "Are sau nu aer conditionat: (d/n) ";
    string input;
    cin >> input;
    if (input == "d")
        aer_conditionat = true;
    else
        aer_conditionat = false;
    cout << "Consum (l/100km): ";
    cin >> consum;
    cin.get();
}



#include "Masina.h"


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

istream& operator>> (istream& in, Masina& m)
{
    string s;
    cout << "Depozitul in care se afla: ";
    getline(in, s);
    m.depozit = s;
    cout << "Marca: ";
    getline(in, s);
    m.marca = s;
    cout << "Model: ";
    getline(in, s);
    m.model = s;
    cout << "Categorie: ";
    getline(in, s);
    m.categorie = s;
    cout << "Nr locuri: ";
    in >> m.nr_loc;
    cout << "Transmisie: ";
    in >> m.transmisie;
    cout << "Are sau nu aer conditionat: (d/n) ";
    string input;
    in >> input;
    if(input == "d")
        m.aer_conditionat = true;
    else
        m.aer_conditionat = false;
    cout << "Consum (l/100km): ";
    in >> m.consum;
    in.get();
}

ostream& operator<< (ostream& out, const Masina& m)
{
    out << "Depozit: " << m.depozit;
    out << "\nMarca: " << m.marca << "\nModel: " << m.model << "\nCategorie: " << m.categorie << "\nNr locuri: " << m.nr_loc
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

bool operator == (Masina &m1, Masina &m2)
{
    if(m1.getMarca() != m2.getMarca())
        return false;
    if(m1.getModel() != m2.getModel())
        return false;
    if(m1.getDepozit() != m2.getDepozit())
        return false;
    if(m1.getNr_loc() != m2.getNr_loc())
        return false;
    if(m1.getTransmisie() != m2.getTransmisie())
        return false;
    if(m1.getAer_conditionat() != m2.getAer_conditionat())
        return false;
    if(m1.getConsum() != m2.getConsum())
        return false;
    return true;
}

void Masina::modifica_rezervare ()
{
    cout << "Masina selectata";
    if(rezervat)
    {
        cout << " este rezervata, doriti sa i se modifice statusul la a fi libera? (d/n) ";
        string input;
        cin >> input;
        if(input == "d")
            rezervat = false;
        cout << "Gata";
    }
    else
    {
        cout << " nu este rezervata, doriti sa i se modifice statusul la a fi rezervata? (d/n) ";
        string input;
        cin >> input;
        if(input == "d")
            rezervat = true;
        cout << "Gata";
    }
}

//void Masina::modifica_depozit()
//{
//    cout
//            << "1. Sterge ultimul depozit\n"
//            << "2. Adauga depozit\n"
//            << "3. Elimina toate depozitele inregistrate\n"
//            << "4. Elimina un anumit depozit\n"
//            << "Alege optiunea introducand numarul corespunzator optiunii: ";
//    int input;
//    cin >> input;
//    cin.get();
//    cout << '\n';
//    switch(input)
//    {
//        case 1:
//            depozit.pop_back();
//            break;
//        case 2:
//        {
//            string s;
//            cout << "Numele depozitului: ";
//            getline(cin, s);
//            for(int i = 0; i < depozit.size(); i++)
//            {
//                if (depozit[i] == s)
//                {
//                    cout << "Depozitul a fost adaugat deja!";
//                    break;
//                }
//            }
//            depozit.push_back(s);
//            break;
//        }
//        case 3:
//            depozit.clear();
//            break;
//        case 4:
//        {
//            string s;
//            cout << "Numele depozitului: ";
//            getline(cin, s);
//            int ok = 0;
//            for(int i = 0; i < depozit.size(); i++)
//            {
//                if (depozit[i] == s)
//                {
//                    depozit.erase(depozit.begin() + i);
//                    ok = 1;
//                }
//            }
//            if(ok == 0)
//                cout << "Masina nu se afla in depozitul cerut!";
//            break;
//        }
//    }
//}















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
    if(input == "d")
        aer_conditionat = true;
    else
        aer_conditionat = false;
    cout << "Consum (l/100km): ";
    cin >> consum;
    cin.get();
}



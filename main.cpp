#include <iostream>
#include <string.h>
#include <windows.h>

#include "Masina.h"
#include "Utilizator.h"
#include "Depozit.h"
#include "common.h"

using namespace std;

//Declararea vectorilor de obiecte
vector<Masina> m;
vector<Utilizator> usr;
vector<Depozit> dep;

int meniu ()
{
    system("cls");
    cout
            << "1. Adauga masina\n"
            << "2. Afiseaza lista de masini\n"
            << "3. Modifica un depozit la o masina\n"
            << "4. Modifica statusul rezervarii unei masini\n"
            << "5. Sterge masini din lista\n"
            << "6. Adauga utilizator\n"
            << "7. Afiseaza lista de utilizatori\n"
            << "8. Sterge utilizator\n"
            << "9. Afiseaza depozitele (impreuna cu masinile de acolo)\n"
            << "10. Adauga depozit.\n"
            << "11. Cauta o masina dupa model\n"
            << "12. Intrerupe aplicatia\n";
    int input;
    cout << "Optiune: ";
    cin >> input;
    cin.get();
    if (input > 12)
        return 0;
    return input;
}


int main ()
{

    int optiune = meniu();
    while (optiune != 12)
    {

        if (optiune == 0)
            cout << "Optiunea nu e valabila", Sleep(2000), optiune = meniu();

        switch (optiune)
        {
            case 1:
            {
                if (dep.size() == 0)
                {
                    cout << "Nu exista niciun depozit in baza de date!";
                    Sleep(2000);
                    break;
                }
                system("cls");
                Masina x;
                cin >> x;
                int ok = 1;
                for (int i = 0; i < m.size(); i++)
                    if (m[i] == x)
                        ok = 0;
                if (ok == 0)
                {
                    cout << "Nu pot fi duplicate!";
                    Sleep(2000);
                } else
                {
                    m.push_back(x);
                    for (int i = 0; i < dep.size(); i++)
                        if (m[m.size() - 1].getDepozit() == dep[i].getLocatie())
                        {
                            dep[i].pushMasina(m.back());
                            dep[i].incrementNr_masini();
                        }
                }
                break;
            }
            case 2:
            {
                system("cls");
                if (m.size() != 0)
                {
                    cout << "Lista de masini:\n";
                    for (int i = 0; i < m.size(); i++)
                        cout << m[i] << "\n\n\n";
                    string input;
                    cout << "Doriti sa reveniti la meniul principal? (d/n) ";
                    getline(cin, input);
                    if (input == "n")
                        return 0;
                } else
                    cout << "Nu exista masini in lista\n", Sleep(2000);
                break;
            }
            case 3:
            {
                system("cls");
                if (m.size() == 0)
                {
                    cout << "Nu exista nicio masina in baza de date!";
                    Sleep(2000);
                    break;
                }
                if (dep.size() == 0)
                {
                    cout << "Nu exista niciun depozit in baza de date!";
                    Sleep(2000);
                    break;
                }
                cout << "Lista de masini:\n";
                for (int i = 0; i < m.size(); i++)
                    cout << "Id masina: #" << i << '\n' << m[i] << "\n\n\n";
                int input_id;
                cout << "Introduceti id-ul masinii la care vreti sa modificati lista depozitelor: ";
                cin >> input_id;
                cin.get();
                if (input_id < m.size())
                {
                    string s;
                    int ok = 0;
                    cout << "Noul depozit: ";
                    getline(cin, s);
                    for (int i = 0; i < dep.size(); i++)
                        if (s == dep[i].getLocatie())
                            ok = 1;
                    if(ok == 0 || s == m[input_id].getDepozit())
                        cout << "Depozitul nu exista!", Sleep(2000);
                    else
                    {
                        for (int i = 0; i < dep.size(); i++)
                            dep[i].remove(m[input_id]);
                        for (int i = 0; i < usr.size(); i++)
                            usr[i].modifica_depozit(m[input_id], s);
                        m[input_id].modifica_depozit(s);
                        for (int i = 0; i < dep.size(); i++)
                            if (m[m.size() - 1].getDepozit() == dep[i].getLocatie())
                            {
                                dep[i].pushMasina(m.back());
                                dep[i].incrementNr_masini();
                            }
                    }
                } else
                    system("cls"), cout << "Masina nu exista!", Sleep(2000);
                break;
            }
            case 4:
            {
                system("cls");
                if (dep.size() == 0)
                {
                    cout << "Nu exista masini in lista\n";
                    Sleep(2000);
                    break;
                }
                cout << "1. Rezerva masina\n"
                     << "2. Elibereaza o masina\n";
                cout << "Alege optiunea: ";
                int input;
                cin >> input;
                cin.get();
                switch (input)
                {
                    case 1:
                    {
                        if (m.size() != 0)
                        {
                            cout << "Lista de masini:\n";
                            for (int i = 0; i < m.size(); i++)
                                cout << "Id masina: #" << i << '\n' << m[i] << "\n\n\n";
                            int input_id;
                            cout << "Introduceti id-ul masinii pe care vreti sa o rezervati: ";
                            cin >> input_id;
                            cin.get();
                            if (m[input_id].este_rezervata())
                            {
                                cout << "Masina este deja rezervata!";
                                Sleep(2000);
                                break;
                            }
                            cout << "Care este userul pentru care se rezerva masina?\n";
                            char nume[256];
                            char prenume[256];
                            char cnp[14];
                            char categorie_permis[256];
                            cout << "Nume: ";
                            cin.getline(nume, 256);
                            cout << "Prenume: ";
                            cin.getline(prenume, 256);
                            cout << "CNP: ";
                            cin.getline(cnp, 14);
                            while (strlen(cnp) != 13)
                            {
                                cout << "CNP-ul nu a fost introdus corect, mai introduceti inca odata: ";
                                cin.getline(cnp, 14);
                            }
                            cout << "Categoria permisului: ";
                            cin.getline(categorie_permis, 256);
                            int ok = 0;
                            for (int i = 0; i < usr.size(); i++)
                                if (strcmp(usr[i].getNume(), nume) == 0 and
                                    strcmp(usr[i].getPrenume(), prenume) == 0 and strcmp(usr[i].getCNP(), cnp) == 0)
                                    usr[i].rezervare(m[input_id]), ok = 1;
                            if (ok == 1)
                            {
                                for (int i = 0; i < dep.size(); i++)
                                    dep[i].rezerva(m[input_id]);
                                cout << "\nGata!", Sleep(2000);
                            } else
                            {
                                cout << "Utilizatorul nu exista!\n";
                                cout << "Doriti sa adaugati acest utilizator? (d/n)";
                                string input;
                                getline(cin, input);
                                if (input == "n")
                                    break;
                                Utilizator u(nume, prenume, categorie_permis, cnp);
                                usr.push_back(u);
                                usr[usr.size() - 1].rezervare(m[input_id]);
                                cout << "Gata";
                                Sleep(2000);
                            }

                        } else
                            cout << "Nu sunt masini in lista!", Sleep(2000);
                        break;
                    }
                    case 2:
                    {
                        if (m.size() != 0)
                        {
                            cout << "Lista de masini:\n";
                            for (int i = 0; i < m.size(); i++)
                                cout << "Id masina: #" << i << '\n' << m[i] << "\n\n\n";
                            int input_id;
                            cout << "Introduceti id-ul masinii pe care vreti sa o eliberati: ";
                            cin >> input_id;
                            cin.get();
                            if (!m[input_id].este_rezervata())
                            {
                                cout << "Masina este deja libera!";
                                Sleep(2000);
                                break;
                            }
                            cout << "Care este userul pentru care se rezerva masina?\n";
                            char nume[256];
                            char prenume[256];
                            char cnp[14];
                            char categorie_permis[256];
                            cout << "Nume: ";
                            cin.getline(nume, 256);
                            cout << "Prenume: ";
                            cin.getline(prenume, 256);
                            cout << "CNP: ";
                            cin.getline(cnp, 14);
                            while (strlen(cnp) != 13)
                            {
                                cout << "CNP-ul nu a fost introdus corect, mai introduceti inca odata: ";
                                cin.getline(cnp, 14);
                            }
                            cout << "Categoria permisului: ";
                            cin.getline(categorie_permis, 256);
                            int ok = 0;
                            for (int i = 0; i < usr.size(); i++)
                                if (strcmp(usr[i].getNume(), nume) == 0 and
                                    strcmp(usr[i].getPrenume(), prenume) == 0 and strcmp(usr[i].getCNP(), cnp) == 0)
                                    usr[i].elibereaza(m[input_id]), ok = 1, usr[i].remove(m[input_id]);

                            if (ok == 1)
                            {
                                for (int i = 0; i < dep.size(); i++)
                                    dep[i].elibereaza(m[input_id]);
                                cout << "\nGata!", Sleep(2000);
                            } else
                            {
                                cout << "Utilizatorul nu exista!\n";
                            }

                        } else
                            cout << "Nu sunt masini in lista!", Sleep(2000);
                    }
                }

                break;
            }
            case 5:
            {
                if (m.size() == 0)
                {
                    system("cls");
                    cout << "Nu sunt masini in lista!\n";
                    Sleep(2000);
                    break;
                } else
                {
                    system("cls");
                    cout << "Lista de masini:\n";
                    for (int i = 0; i < m.size(); i++)
                        cout << "Id masina: #" << i << '\n' << m[i] << "\n\n\n";
                    cout
                            << "1. Scoate ultima masina\n"
                            << "2. Sterge intreaga lista\n"
                            << "3. Sterge o anumita masina din lista\n";
                    int in;
                    cin >> in;
                    cin.get();
                    switch (in)
                    {
                        case 1:
                            for (int i = 0; i < usr.size(); i++)
                                usr[i].remove(m.back());
                            for (int i = 0; i < dep.size(); i++)
                                dep[i].decrementNr_masini(), dep[i].remove(m.back());
                            m.pop_back();
                            break;
                        case 2:
                            for (int i = 0; i < usr.size(); i++)
                                for (int j = 0; j < m.size(); j++)
                                    usr[i].remove(m[j]);
                            for (int i = 0; i < dep.size(); i++)
                                for (int j = 0; j < m.size(); j++)
                                    dep[i].decrementNr_masini(), dep[i].remove(m[j]);
                            m.clear();
                            break;
                        case 3:
                        {
                            cout << "Id-ul masinii de sters: \n";
                            int id;
                            cin >> id;
                            cin.get();
                            if (id < m.size())
                            {
                                m.erase(m.begin() + id);
                                for (int i = 0; i < usr.size(); i++)
                                    usr[i].remove(m[id]);
                                for (int i = 0; i < dep.size(); i++)
                                    dep[i].decrementNr_masini(), dep[i].remove(m[id]);
                            } else
                                cout << "Masina nu exista! \n";
                            cout << "Inapoi la meniul principal? (d/n) ";
                            string in;
                            getline(cin, in);
                            if (in == "n")
                                return 0;
                            break;
                        }
                    }
                }
                break;
            }
            case 6:
            {
                system("cls");
                Utilizator u;
                cin >> u;
                usr.push_back(u);
                break;
            }
            case 7:
            {
                system("cls");
                cout << "Lista de utilizatori:\n";
                if (usr.size() == 0)
                    cout << "Nu exista niciun user in lista!", Sleep(2000);
                else
                {
                    for (int i = 0; i < usr.size(); i++)
                        cout << usr[i] << "\n\n\n";
                    string input;
                    cout << "Doriti sa reveniti la meniul principal? (d/n) ";
                    getline(cin, input);
                    if (input == "n")
                        return 0;
                }
                break;
            }
            case 8:
            {
                system("cls");
                if (usr.size() == 0)
                {
                    cout << "Nu exista utilizatori in lista\n";
                    Sleep(2000);
                    break;
                }
                cout << "Lista de utilizatori:\n";
                for (int i = 0; i < usr.size(); i++)
                    cout << "Id utilizator: #" << i << '\n' << usr[i] << "\n\n\n";
                cout << "Id-ul utilizatorului de sters: \n";
                int id;
                cin >> id;
                cin.get();
                if (id < usr.size())
                {
                    usr[id].eliberare_masini();
                    usr.erase(usr.begin() + id);
                } else
                    cout << "Userul nu exista! \n";
                cout << "Inapoi la meniul principal? (d/n) ";
                string in;
                getline(cin, in);
                if (in == "n")
                    return 0;
                break;
            }
            case 9:
            {
                system("cls");
                if (m.size() == 0)
                {
                    cout << "Nu exista nicio masina in baza de date!";
                    Sleep(2000);
                    break;
                }
                if (dep.size() == 0)
                {
                    cout << "Nu exista niciun depozit!";
                    Sleep(2000);
                    break;
                }
                for (int i = 0; i < dep.size(); i++)
                    cout << dep[i];
                string input;
                cout << "Doriti sa reveniti la meniul principal? (d/n) ";
                getline(cin, input);
                if (input == "n")
                    return 0;
                break;
            }
            case 10:
            {
                system("cls");
                Depozit d;
                cin >> d;
                dep.push_back(d);
                break;
            }
        }
        system("cls");
        optiune = meniu();
    }
    return 0;
}


//TODO: cauta masina
//TODO: pune in loc de un vector, ceva alocat dinamic:
/* TODO:
template <class T>
void Array<T>::add(T value)
{
    T * tmp = new T[mCount + 1];

    for (int i = 0; i < mCount; i++)
    {
        tmp[i] = mData[i];
    }

    mCount++;

    delete[] mData;
    mData = tmp;

    mData[mCount - 1] = value;
}
 */
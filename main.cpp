#include <iostream>
#include <string.h>
#include <windows.h>

#include "Masina.h"
#include "Utilizator.h"

using namespace std;

int meniu ()
{
    system("cls");
    cout
            << "1. Adauga masina\n"
            << "2. Afiseaza lista de masini\n"
            << "3. Modifica un depozit la o masina\n"
            << "4. Rezerva o masina\n"
            << "5. Sterge masini din lista\n"
            << "6. Adauga utilizator\n"
            << "7. Afiseaza lista de utilizatori\n"
            << "12. Intrerupe aplicatia\n";
    int input;
    cout << "Optiune: ";
    cin >> input;
    cin.get();
    if(input > 12)
        return 0;
    return input;
}

int main ()
{
    vector<Masina> m;
    vector<Utilizator> usr;
    int optiune = meniu();
    while (optiune != 12)
    {
        if(optiune == 0)
            cout << "Optiunea nu e valabila", Sleep(2000), optiune = meniu();

            switch (optiune)
            {
                case 1:
                {
                    system("cls");
                    Masina x;
                    cin >> x;
                    m.push_back(x);
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
                    }
                    else
                        cout << "Nu exista masini in lista\n", Sleep(2000);
                    break;
                }
                case 3:
                {
//                    system("cls");
//                    cout << "Lista de masini:\n";
//                    for (int i = 0; i < m.size(); i++)
//                        cout << "Id masina: #" << i << '\n' << m[i] << "\n\n\n";
//                    int input_id;
//                    cout << "Introduceti id-ul masinii la care vreti sa modificati lista depozitelor: ";
//                    cin >> input_id;
//                    cin.get();
//                    if(input_id < m.size())
//                        m[input_id].modifica_depozit(), system("cls"), cout << "Gata!", cout << m[input_id];
//                    else
//                        system("cls"), cout << "Masina nu exista!", Sleep(2000);
                    break;
                }
                case 4:
                {
                    system("cls");
                    if(m.size() != 0)
                    {
                        cout << "Lista de masini:\n";
                        for (int i = 0; i < m.size(); i++)
                            cout << "Id masina: #" << i << '\n' << m[i] << "\n\n\n";
                        int input_id;
                        cout << "Introduceti id-ul masinii pe care vreti sa o rezervati: ";
                        cin >> input_id;
                        cin.get();
                        cout << "Pe ce nume sa fie rezervata masina?\n";
                        cout << "Nume: ";
                        char nume[256];
                        char prenume[256];
                        cin.getline(nume, 256);
                        cout << "Prenume: ";
                        cin.getline(prenume, 256);
                        int ok = 0;
                        for (int i = 0; i < usr.size(); i++)
                            if (strcmp(usr[i].getNume(), nume) == 0 and strcmp(usr[i].getPrenume(), prenume) == 0)
                                usr[i].rezervare(m[input_id]), ok = 1;
                        if (ok == 1)
                            m[input_id].modifica_rezervare(), system("cls"), cout << "Gata!", cout << m[input_id];
                        else
                            cout << "Utilizatorul nu exista!", Sleep(2000);
                    }
                    else
                        cout << "Nu sunt masini in lista!", Sleep(2000);
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
                                m.pop_back();
                                break;
                            case 2:
                                for (int i = 0; i < usr.size(); i++)
                                    for (int j = 0; j < m.size(); j++)
                                        usr[i].remove(m[j]);
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
                    if(usr.size() == 0)
                        cout << "Nu exista niciun user in lista!", Sleep(2000);
                    else
                    {
                        for(int i = 0; i < usr.size(); i++)
                            cout << usr[i] << '\n\n\n';
                        string input;
                        cout << "Doriti sa reveniti la meniul principal? (d/n) ";
                        getline(cin, input);
                        if (input == "n")
                            return 0;
                    }
                    break;
                }
            }
        system("cls");
        optiune = meniu();
    }
    return 0;
}

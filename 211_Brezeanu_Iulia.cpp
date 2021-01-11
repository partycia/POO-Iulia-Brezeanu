/* Brezeanu Iulia
211
GNU GCC
Eduard Szmenteanca*/
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
//cod asemanator cu cel din proiectul de la laborator

class Vaccin
{
    char* producator;
    float pret;
    float temperatura;
    string substante;

public:
    Vaccin()
    {
        this -> producator = new char[strlen("Necunoscut")+1];
        strcpy(this -> producator, "Necunoscut");
        this -> pret  = 0;
        this -> temperatura = 0;
        substante = "null";
    }

    Vaccin(char* nume, float pret, float temperatura, string  substante)
    {
        this -> producator = new char[strlen(nume)+1];
        strcpy(producator, nume);
        this -> pret = pret;
        this -> temperatura = temperatura;
        substante = substante;
    }

    char* getProducator()
    {
        return this -> producator;
    }

    float getPret()
    {
        return this -> pret;
    }

        float getTemperatura()
    {
        return this -> temperatura;
    }
    string getSubstante()
    {
        return this -> substante;
    }

    friend istream &operator>>(istream &in, Vaccin &v)
    {
        char aux[100];
        cout << "Introdu nume producator: ";
        if(v.producator != NULL)
            delete[] v.producator;

        in.get(aux, 100);
        in.get();

        v.producator = new char[strlen(aux)+1];
        strcpy(v.producator, aux);
        cout << "\nIntrodu pret: ";
        in >> v.pret;
        cout << "\n Introdu temperatura: ";
        in >> v.temperatura;
        cout << "\nIntrodu lista substante: ";
        in >> v.substante;

        return in;
    }

    friend ostream &operator<<(ostream &out, const Vaccin &v)
    {
        out <<"Producatorul vaccinului este " << v.producator;
        if (v.pret > 0)
        {
            out<<"acesta are pretul de " << v.pret<< " lei si temperatura de "<<v.temperatura<<" grade.";
        }
        out <<"Acesta este alacatuit din urmatoarele substante: ";
        out << v.substante;

        return out;
    }

    ~Vaccin()
    {

    }
};

class AntiGripal: public Vaccin
{
    string tulpina;
    bool recomandari;

public:

    AntiGripal(): Vaccin()
    {
        tulpina ="necunoscuta";
        recomandari = false;
    }

    AntiGripal(char* nume, float pret, float temp, string lista, string tulpina, bool recomand): Vaccin(nume,pret,temp,lista)
    {
        this -> tulpina = tulpina;
        recomandari = recomand;
    }

    void administrare()
    {
        cout << "se administrează la adulți o doză de 0.5 ml, iar la copii și adolescenți o doză de 0.3 ml, repetându-se din 2 în 2 ani";
    }

    friend istream &operator>>(istream &in, AntiGripal &v)
    {
        in >> (Vaccin&) v;

        cout << " Introdu tulpina: ";
        in >> v.tulpina;
        cout << " Respecta normele?: ";
        in >> v.recomandari;

        return in;
    }

    friend ostream &operator<<(ostream &out, const AntiGripal &v)
    {
        out << (Vaccin&) v;

        out << " Vaccinul ucide tulpina " << v.tulpina << " si ";
        if(v.recomandari == true)
            out << "respecta nurmele.\n";
        else
            out << "nu respecta normele.\n";

        return out;
    }

    ~AntiGripal()
    {

    }
};

class VaccinAntihepatic: public Vaccin
{
    char* tipHepatita;
    string tipVaccinare;

public:

    VaccinAntihepatic(): Vaccin()
    {
        tipHepatita ="n";
        tipVaccinare = "necunoscut";
    }

    VaccinAntihepatic(char* nume, float pret, float temp, string lista, char tip, char* tipHepatita): Vaccin(nume,pret,temp,lista)
    {
        tipHepatita = tipHepatita;
        tipVaccinare = tip;
    }

    void administrare()
    {
        cout << "Antihepatită A și B, la copii cu vârstă mai mică de 1 an se adminstrează 2 injectări la un interval de o lună, a treia injectare după 6 luni de la prima administrare, la adulți conform schemei de imunizare recomandată de medic; cel Antihepatită C doar la recomandarea medicului.";
    }

    friend istream &operator>>(istream &in, VaccinAntihepatic &v)
    {
        in >> (Vaccin&) v;

        cout << "\nIntrodu tipul: ";
        in >> v.tipHepatita;
        cout << "\nIntrodu mod vaccinare: ";
        in >> v.tipVaccinare;

        return in;
    }

    friend ostream &operator<<(ostream &out, const VaccinAntihepatic &v)
    {
        out << (Vaccin&) v;

        out << " Acesta ucide tulpina " << v.tipHepatita << " si modul de vaccinare este "<<v.tipVaccinare;

        return out;
    }

    ~VaccinAntihepatic()
    {

    }
};

class VaccinAntiSarsCov2: public Vaccin
{

};


int main()
{
    cout << "Hello world!" << endl;
    AntiGripal a;
    VaccinAntihepatic b;
    VaccinAntiSarsCov2 c;
    cin>>a>>b>>c;
    cout<<a<<b<<c;
    Vaccin* list[3];
    list[0]=new AntiGripal();
    list[1]=new VaccinAntihepatic ();
    list[2]=new VaccinAntiSarsCov2();
    for(int i=0; i<3; i++)
        list[i]-> administrare();
    Comanda com1("20-12-2020", "SpitalX", "AntiSarsCov2",20);
    ListaComenzi lista;
    lista=lista+com1;
    cout<<lista[0];
    return 0;
}

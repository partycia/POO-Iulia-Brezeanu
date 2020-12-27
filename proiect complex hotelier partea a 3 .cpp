#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>

using namespace std;

class ComplexHotelier
{
    const int idComplex;
    char* numeComplex;
    int nrHoteluri;
    int nrNote;
    float* note;
    bool recomandat;

public:

    static void bunVenit()
    {
        cout << "Bine ati venit la noi\n";
    }

    ComplexHotelier():idComplex(0)
    {
        this -> numeComplex = new char[strlen("Necunoscut")+1];
        strcpy(this -> numeComplex, "Necunoscut");

        this -> nrHoteluri = 0;
        this -> nrNote = 0;

        this -> note = new float[0];
        recomandat = false;
    }

    ComplexHotelier(int id):idComplex(id)
    {
        this -> numeComplex = new char[strlen("Necunoscut")+1];
        strcpy(this -> numeComplex, "Necunoscut");

        this -> nrHoteluri = 0;
        this -> nrNote = 0;

        this -> note = new float[0];
        recomandat = false;
    }

    ComplexHotelier(int id, char* nume, int nrHoteluri, int nrNote, float* note, bool recomandat):idComplex(id)
    {
        this -> numeComplex = new char[strlen(nume)+1];
        strcpy(numeComplex, nume);

        this -> nrHoteluri = nrHoteluri;
        this -> nrNote = nrNote;
        this -> recomandat = recomandat;

        this -> note = new float[nrNote];
        for(int i = 0; i < nrNote; i++)
            this -> note[i] = note[i];
    }

    ComplexHotelier(const ComplexHotelier &c):idComplex(c.idComplex)
    {
        this -> numeComplex = new char[strlen(c.numeComplex)+1];
        strcpy(this -> numeComplex, c.numeComplex);

        this -> nrHoteluri = c.nrHoteluri;
        this -> nrNote = c.nrNote;
        this -> recomandat = c.recomandat;

        this -> note = new float[c.nrNote];
        for(int i = 0; i < c.nrNote; i++)
            this -> note[i] = c.note[i];
    }

    int getIdComplex()
    {
        return (int)this -> idComplex;
    }

    char* getNumeComplex()
    {
        return this -> numeComplex;
    }

    int getNrHoteluri()
    {
        return this -> nrHoteluri;
    }

    int getNrNote()
    {
        return this -> nrNote;
    }

    float* getNote()
    {
        return this -> note;
    }

    bool getRecomandat()
    {
        return this -> recomandat;
    }

    void setNumeComplex(char* a)
    {
        if(this -> numeComplex != NULL)
            delete[] this -> numeComplex;

        this -> numeComplex = new char[strlen(a)+1];
        strcpy(this -> numeComplex, a);
    }

    void setNrHoteluri(int a)
    {
        this -> nrHoteluri = a;
    }

    void setRecomandat(bool a)
    {
        this -> recomandat = a;
    }

    void setNote(int a, float* b)
    {
        if(this -> note != NULL)
            delete[] note;

        this -> nrNote = a;
        this -> note = new float[this -> nrNote];

        for(int i = 0; i < a; i++)
            this -> note[i] = b[i];
    }

    friend ostream &operator<< (ostream &out, const ComplexHotelier c)
    {
        out << "Complexul hotelier " << c.numeComplex;

        if(c.nrNote>0)
        {
            out << " are " << c.nrNote << " note:";
            for(int i = 0; i  < c.nrNote; i++)
                out << " " << c.note[i];
            out << " si ";

            if(c.recomandat == true)
                out << " este recomandat. ";
            else
                out << " nu este recomandat.";
        }

        else
            out << " nu are note, deci nici recomandare. ";

        if(c.nrHoteluri > 0)
            out << " In plus detine " << c.nrHoteluri <<" hoteluri. ";

        out << "\n";

        return out;
    }

    friend istream &operator>> (istream &in, ComplexHotelier &c)
    {
        char aux[100];
        cout << "Introdu numele Complexului: ";
        if(c.numeComplex != NULL)
            delete[] c.numeComplex;

        in.get(aux, 100);
        in.get();

        c.numeComplex = new char[strlen(aux)+1];
        strcpy(c.numeComplex, aux);

        cout << "\nIntrodu nr hotleuri: ";
        in >> c.nrHoteluri;

        cout << "\nIntrodu nr note: ";
        in >> c.nrNote;

        cout << "\nIntrodu notele: ";
        if(c.note != NULL)
            delete[] c.note;
        c.note = new float[c.nrNote];
        for(int i = 0; i< c.nrNote; i++)
            in >> c.note[i];

        cout << "\nIntrodu recomandare(1= da,0 =nu): ";
        in >> c.recomandat;

        return in;

    }

    ComplexHotelier &operator= (const ComplexHotelier &c)
    {
        if(this != &c)
        {
            if(this -> numeComplex != NULL)
                delete[] this -> numeComplex;

            this -> numeComplex = new char[strlen(c.numeComplex)+1];
            strcpy(this -> numeComplex, c.numeComplex);

            this -> nrHoteluri = c.nrHoteluri;
            this -> nrNote = c.nrNote;
            this -> recomandat = c.recomandat;

            if(this -> note != NULL)
                delete[] this -> note;

            this -> note = new float[c.nrNote];
            for(int i = 0; i < c.nrNote; i++)
                this -> note[i] = c.note[i];
        }

        return *this;
    }

    friend bool operator== (const ComplexHotelier &a, const ComplexHotelier &b)
    {
        if(a.idComplex == b.idComplex && strcmp(a.numeComplex, b.numeComplex) == 0 && a.nrHoteluri == b.nrHoteluri)
            return true;
        else
            return false;
    }

    friend bool operator<= (const ComplexHotelier &a, const ComplexHotelier &b)
    {
        if(a.idComplex <= b.idComplex && a.nrHoteluri <= b.nrHoteluri)
            return true;
        else
            return false;
    }

    friend bool operator< (const ComplexHotelier &a, const ComplexHotelier &b)
    {
        if(a.idComplex < b.idComplex && a.nrHoteluri < b.nrHoteluri)
            return true;
        else
            return false;
    }
    friend bool operator> (const ComplexHotelier &a, const ComplexHotelier &b)
    {
        if(a.idComplex > b.idComplex && a.nrHoteluri > b.nrHoteluri)
            return true;
        else
            return false;
    }

    friend bool operator>= (const ComplexHotelier &a, const ComplexHotelier &b)
    {
        if(a.idComplex >= b.idComplex && a.nrHoteluri >= b.nrHoteluri)
            return true;
        else
            return false;
    }

    ComplexHotelier &operator+ (float i)
    {
        int aux = this -> nrNote;

        float* a;

        a = new float[aux];
        for(int j = 0; j < aux; j++)
            a[j] = this -> note[j];

        delete[] this -> note;

        aux++;
        this -> note = new float[aux];
        for(int j = 0; j < this -> nrNote; j++)
            this -> note[j] = a[j];

        this -> note[aux-1] = i;
        this -> nrNote = aux;
        delete[] a;

        return *this;
    }

    const ComplexHotelier operator++ ()
    {
        this -> nrHoteluri ++;

        return *this;
    }

    const ComplexHotelier operator-- ()
    {
        this -> nrHoteluri --;

        return *this;
    }

    const ComplexHotelier operator++ (int)
    {
        ComplexHotelier aux(*this);
        this -> nrHoteluri ++;

        return aux;
    }

    const ComplexHotelier operator-- (int)
    {
        ComplexHotelier aux(*this);
        this -> nrHoteluri --;

        return aux;
    }

    float operator[] (int i)
    {
        i--;

        if(i >= 0 and i< this -> nrNote)
            return this -> note[i];

        else
            return -1;
    }

    explicit operator int()
    {
        return (int) this -> nrHoteluri;
    }

    ~ComplexHotelier()
    {
        if(this -> numeComplex != NULL)
            delete[] this -> numeComplex;
        if(this -> note != NULL)
                delete[] this -> note;
    }
};

class Hotel
{
    const int idHotel;
    char* numeHotel;
    int idComplex;
    bool reconditionat;
    float value;
    int levels;
    int* roomsOnLevel;
    string locatie;

public:

    static void hello()
    {
        cout << " Bun venit la hotelul nostru, speram sa va placa";
    }

    virtual void terasa()
    {
        cout << "Acest hotel nu are terasa";
    }

    Hotel():idHotel(0)
    {
        numeHotel = new char[strlen("unknown")+1];
        strcpy(numeHotel, "unknown");

        idComplex = 0;
        reconditionat = false;
        value = 0;
        levels = 0;
        roomsOnLevel = new int[0];
        locatie ="unknown";
    }

    Hotel(int id, char* nume, ComplexHotelier c, bool recond, float val, int levels, int* rooms, string loc):idHotel(id)
    {
        numeHotel = new char[strlen(nume)+1];
        strcpy(numeHotel, nume);

        idComplex = c.getIdComplex();
        reconditionat = recond;
        value = val;
        this -> levels = levels;

        roomsOnLevel = new int[levels];
        for(int i = 0; i<levels; i++)
            roomsOnLevel[i] =rooms[i];

        locatie = loc;
    }

    Hotel(const Hotel &h): idHotel(h.idHotel)
    {
        this ->numeHotel = new char[strlen(h.numeHotel)+1];
        strcpy(this ->numeHotel, h.numeHotel);

        this -> idComplex = h.idComplex;
        this ->reconditionat = h.reconditionat;
        this -> value = h.value;
        this -> levels = h.levels;

        this ->roomsOnLevel = new int[h.levels];
        for(int i = 0; i<h.levels; i++)
            this -> roomsOnLevel[i] =h.roomsOnLevel[i];

        this -> locatie = h.locatie;
    }

    int getLevels()
    {
        return this -> levels;
    }

    int* getRoomsOnLevel()
    {
        return this -> roomsOnLevel;
    }

    char* getNumeHotel()
    {
        return this -> numeHotel;
    }

    string getLocatie()
    {
        return this -> locatie;
    }

    bool getReconditionat()
    {
        return this -> reconditionat;
    }

    float getValue()
    {
        return this -> value;
    }

    int getIdComplex()
    {
        return this -> idComplex;
    }

    int getIdHotel()
    {
        return (int) this ->idHotel;
    }

    void setNumeHotel(char* a)
    {
        if(this -> numeHotel != NULL)
            delete[] this -> numeHotel;

        this -> numeHotel = new char[strlen(a)+1];
        strcpy(this -> numeHotel, a);
    }

    void setRoomsandLevels(int a, int* b)
    {
        if(this -> roomsOnLevel != NULL)
            delete[] this -> roomsOnLevel;

        this -> levels = a;
        this -> roomsOnLevel = new int[this -> levels];

        for(int i = 0; i < a; i++)
            this -> roomsOnLevel[i] = b[i];

    }

    void setLocatie(string a)
    {
        this -> locatie = a;
    }

    void setIdComplex(int id)
    {
        this -> idComplex = id;
    }

    void setReconditionat(bool a)
    {
        this -> reconditionat = a;
    }

    Hotel &operator= (const Hotel &h)
    {
     if(this != &h)
     {
        if(this -> numeHotel != NULL)
            delete[] this -> numeHotel;

        this ->numeHotel = new char[strlen(h.numeHotel)+1];
        strcpy(this ->numeHotel, h.numeHotel);

        this -> idComplex = h.idComplex;
        this ->reconditionat = h.reconditionat;
        this -> value = h.value;
        this -> levels = h.levels;

        if(this -> roomsOnLevel != NULL)
            delete[] this -> roomsOnLevel;

        this -> roomsOnLevel = new int[h.levels];
        for(int i = 0; i<h.levels; i++)
            this -> roomsOnLevel[i] =h.roomsOnLevel[i];

        this -> locatie = h.locatie;
     }

     return *this;
    }

    friend ostream &operator<< (ostream &out, const Hotel h)
    {
        out << "Hotelul " << h.numeHotel << " al complexului cu id: " << h.idComplex;
        if(h.levels>0)
        {
            out << " are " << h.levels << " etaje fiecare avand urm nr de camere:";

            for(int i = 0; i<h.levels; i++)
                out << " " << h.roomsOnLevel[i];
        }

        else
            out << "nu are etaje";

        out<<"\nAcesta ";
        if(h.reconditionat == true)
            out << "a fost reconditionat";
        else
            out << "nu  a fost recond ";

        out << ". Se afla la " << h.locatie << " si are o valoare de " << h.value << "$.";
        out<< "\n";

        return out;
    }

    friend istream &operator>> (istream &in, Hotel &h)
    {
        cout << "\nIntrodu Numele hotelului: ";
        char aux[100];

        in.get(aux, 100);
        in.get();

        if(h.numeHotel != NULL)
            delete[] h.numeHotel;

        h.numeHotel = new char[strlen(aux)];
        strcpy(h.numeHotel, aux);

        cout << "\nIntrodu id-ul complexului: ";
        in >> h.idComplex;

        cout << "\nIntrodu valoarea: ";
        in >> h.value;

        cout << "\nA fost reconditionat(1=da, 0=nu): ";
        in >> h.reconditionat;

        cout <<"\nIntrodu nr etaje: ";
        in >> h.levels;

        if(h.roomsOnLevel != NULL)
            delete[] h.roomsOnLevel;
        h.roomsOnLevel = new int(h.levels);

        cout << "\nIntrodu nr de camere pe fiecare etaj: ";
        for(int i = 0; i < h.levels; i++)
            in >> h.roomsOnLevel[i];

        cout << "\nIntrodu locatie(mare, munte): ";
        in >> h.locatie;

        return in;

    }

    friend bool operator== (const Hotel &a, const Hotel &b)
    {
        if(strcmp(a.numeHotel, b.numeHotel)== 0 && a.value == b.value && a.idHotel == b.idHotel)
            return true;
        else
            return false;
    }
    friend bool operator<= (const Hotel &a, const Hotel &b)
    {
        if(a.value <= b.value)
            return true;
        else
            return false;
    }

    friend bool operator< (const Hotel &a, const Hotel &b)
    {
        if(a.value < b.value)
            return true;
        else
            return false;
    }

    friend bool operator> (const Hotel &a, const Hotel &b)
    {
        if(a.value > b.value)
            return true;
        else
            return false;
    }

    friend bool operator>= (const Hotel &a, const Hotel &b)
    {
        if(a.value >= b.value)
            return true;
        else
            return false;
    }

    const Hotel operator++ ()
    {
        this -> value = this -> value + 1;

        return *this;
    }

    const Hotel operator-- ()
    {
        this -> value = this -> value - 1;

        return *this;
    }

    const Hotel operator++ (int)
    {
        Hotel aux(*this);
        this -> value = this -> value + 1;

        return aux;
    }

    const Hotel operator-- (int)
    {
        Hotel aux(*this);
        this -> value = this -> value -1;

        return aux;
    }

    Hotel &operator+ (int i)
    {
        int aux = this -> levels;

        int* a;

        a = new int[aux];
        for(int j = 0; j < aux; j++)
            a[j] = this -> roomsOnLevel[j];

        delete[] this -> roomsOnLevel;

        aux++;
        this -> roomsOnLevel = new int[aux];
        for(int j = 0; j < this -> levels; j++)
            this -> roomsOnLevel[j] = a[j];

        this -> roomsOnLevel[aux-1] = i;
        this -> levels = aux;
        delete[] a;

        return *this;
    }

    float operator[] (int i)
    {
        i--;

        if(i >= 0 and i< this -> levels)
            return this -> roomsOnLevel[i];

        else
            return -1;
    }

    explicit operator int()
    {
        return (int) this -> value;
    }

    ~Hotel()
    {
        if(this -> numeHotel != NULL)
            delete[] this -> numeHotel;

        if(this -> roomsOnLevel != NULL)
            delete[] this -> roomsOnLevel;
    }

};

class Worker
{
    const int IdWorker;
    char* workerName;
    int age;
    int gradesNum;
    int* grades;
    float salary;
    int idHotel;
    char gender;

public:
    static void msj()
    {
        cout << "Bun venit la noul tau loc de munca!\n";
    }

    Worker():IdWorker(0)
    {
        workerName = new char[strlen("Unknown")+1];
        strcpy(workerName, "Unknown");

        age = 0;
        gradesNum = 0;
        grades = new int[gradesNum];
        salary = 0;
        idHotel = 0;
        gender = 'N';

    }


    Worker(int id, char* name, int age, char gen, int nrNote, int* note, float salariu, Hotel &h): IdWorker(id)
    {
        workerName = new char[strlen(name)+1];
        strcpy(workerName, name);

        this -> age = age;
        gender = gen;
        gradesNum = nrNote;

        grades = new int[gradesNum];
        for(int i = 0; i < gradesNum; i++)
            grades[i] =note[i];

        salary = salariu;
        this -> idHotel = h.getIdHotel();
    }

    Worker(const Worker &w): IdWorker(w.IdWorker)
    {
        workerName = new char[strlen(w.workerName)+1];
        strcpy(workerName, w.workerName);

        this -> age = w.age;
        this -> gender = w.gender;
        this ->gradesNum = w.gradesNum;

        this -> grades = new int[this -> gradesNum];
        for(int i = 0; i < gradesNum; i++)
            this ->grades[i] =w.grades[i];

        this ->salary = w.salary;
        this -> idHotel = w.idHotel;

    }

    friend ostream &operator<< (ostream &out, const Worker a)
    {
        if (a.gender == 'F')
            out << "Angajata ";
        else
            out << "Angajatul ";

        out << a.workerName<< " are " << a.age << " ani si lucreaza la hotelul cu id:" << a.idHotel;
        out << "*.\nAre un salariu de " << a.salary << "$. De la angajare a obtinut " << a.gradesNum;
        out <<" note:";

        for(int i = 0; i < a.gradesNum; i++)
            out <<" "<< a.grades[i];

        out << "\n";

        return out;
    }

    friend istream &operator>> (istream &in, Worker &a)
    {
        char aux[100];

        cout << "Introdu numele angajatului: ";

        in.get(aux, 100);
        in.get();

        if(a.workerName != NULL)
            delete[] a.workerName;

        a.workerName = new char[strlen(aux)+1];
        strcpy(a.workerName, aux);

        cout << "\nIntrodu varsta: ";
        in >> a.age;

        cout << "\nIntrodu genul: ";
        in >> a.gender;

        cout << "\nIntrodu salariul: ";
        in >> a.salary;

        cout << "\nIntrodu nr de note: ";
        in >> a.gradesNum;

        cout << "\nIntrodu notele: ";
        if(a.grades != NULL)
            delete[] a.grades;
        a.grades = new int[a.gradesNum];
        for(int i = 0; i< a.gradesNum; i++)
            in >> a.grades[i];

        cout << "\nIntrodu ID hotel: ";
        in >> a.idHotel;

        cout << "\n-----------------Inregistrat cu succes---------------------";
        cout << "\n\n";

        return in;
    }

    Worker &operator= (const Worker &w)
    {
        if(this != &w)
        {
            if(this -> workerName != NULL)
                delete[] this -> workerName;

            this ->workerName = new char[strlen(w.workerName)+1];
            strcpy(this -> workerName, w.workerName);

            this -> age = w.age;
            this -> gender = w.gender;
            this ->gradesNum = w.gradesNum;

            if(this -> grades != NULL)
                delete[] this -> grades;

            this -> grades = new int[this -> gradesNum];

            for(int i = 0; i < gradesNum; i++)
                this ->grades[i] =w.grades[i];

            this ->salary = w.salary;
            this -> idHotel = w.idHotel;
        }

        return *this;

    }

    friend bool operator== (const Worker &a, const Worker &b)
    {
        if(strcmp(a.workerName,b.workerName) == 0 and a.age == b.age and a.idHotel == b.idHotel)
            return true;
        else
            return false;
    }

    friend bool operator< (const Worker &a, const Worker &b)
    {
        if(a.age < b.age)
            return true;
        else
            return false;
    }

    friend bool operator<= (const Worker &a, const Worker &b)
    {
        if(a.age <= b.age)
            return true;
        else
            return false;
    }

    friend bool operator> (const Worker &a, const Worker &b)
    {
        if(a.age > b.age)
            return true;
        else
            return false;
    }

    friend bool operator>= (const Worker &a, const Worker &b)
    {
        if(a.age >= b.age)
            return true;
        else
            return false;
    }

    Worker &operator+ (float i)
    {
        salary = salary + i;
        return *this;
    }

    Worker &operator- (float i)
    {
        salary = salary - i;

        return *this;
    }

    const Worker &operator++()
    {
        age++;

        return *this;
    }

    const Worker operator++ (int)
    {
        Worker aux(*this);

        age++;

        return aux;
    }

    const Worker &operator--()
    {
        age--;

        return *this;
    }

    const Worker operator-- (int)
    {
        Worker aux(*this);

        age--;

        return aux;
    }

    int operator[] (int i)
    {
        if(i >= 0 and i < this -> gradesNum)
            return grades[i];

        else
            return -1;
    }

    explicit operator int()
    {
        return (int) salary;
    }

    ~Worker()
    {
        if(workerName != NULL)
            delete[] workerName;

        if(grades != NULL)
            delete[] grades;

    }
};

class Client
{
    const int idClient;
    char* numeClient;
    int varsta;
    float notaAcordata;
    bool clientFidel;
    char gender;

public:
    static void msj()
    {
        cout << "---------Bine ai venit la cazare-------\n";
    }

    Client():idClient(0)
    {
        this -> numeClient = new char[strlen("Unknown")+1];
        strcpy(this -> numeClient, "Unknown");

        this -> varsta = 0;
        this -> notaAcordata = 0;
        this -> gender = 'N';
        this -> clientFidel = false;
    }


    Client(int id, char* numeClient, int varsta, char gen, float nota, bool fidel):idClient(id)
    {
        this -> numeClient = new char[strlen(numeClient)+1];
        strcpy(this -> numeClient, numeClient);

        this -> varsta = varsta;
        this -> gender  = gen;
        this -> notaAcordata = nota;

        this -> clientFidel = fidel;
    }

    Client(const Client &c):idClient(c.idClient)
    {
        this -> numeClient = new char[strlen(c.numeClient)+1];
        strcpy(this -> numeClient, c.numeClient);

        this -> varsta = c.varsta;
        this -> gender  = c.gender;
        this -> notaAcordata = c.notaAcordata;
        this -> clientFidel = c.clientFidel;
    }

    friend ostream &operator<< (ostream &out, const Client &c)
    {
        if(c.gender == 'F')
            out << "Clienta ";
        else
            out << "Clientul ";

        out << c.numeClient << " are " << c.varsta << ", iar ID-ul este:" << c.idClient;

        if (c.clientFidel == true)
            out << "\nA mai fost in trecut la acest hotel. ";

        else
            out <<"\nNu a mai fost in trecut la acest hotel. ";

        out << "In urma serviciilor oferite, nota acordata este: " << c.notaAcordata;
        out << "\n";

        return out;
    }

    friend istream &operator>> (istream &in, Client &c)
    {
        cout << "Introdu numele clientului/ei: ";

        char aux[100];

        in.get(aux,100);
        in.get();

        if(c.numeClient != NULL)
            delete[] c.numeClient;

        c.numeClient = new char[strlen(aux)+1];
        strcpy(c.numeClient, aux);

        cout << "\nIntrodu varsta: ";

        in >> c.varsta;

        cout << "\nIntrodu genul(M/F): ";

        in >> c.gender;

        cout << "\nIntrodu nota acordata: ";
        in >> c.notaAcordata;

       cout << "\nA mai fost la acest hotel?(1=da, 0=nu): ";
        in >> c.clientFidel;

        return in;

    }

    Client &operator= (const Client &c)
    {
        if(this != &c)
        {
            if(numeClient != NULL)
                delete[] numeClient;

            numeClient = new char[strlen(c.numeClient)+1];
            strcpy(numeClient, c.numeClient);

            varsta = c.varsta;
            gender = c.gender;
            notaAcordata = c.notaAcordata;
            clientFidel = c.clientFidel;
        }

        return *this;
    }

    friend bool operator== (const Client &a, const Client &b)
    {
        if (a.varsta == b.varsta && strcmp(a.numeClient, b.numeClient) == 0)
            return true;
        else
            return false;
    }

    friend bool operator< (const Client &a, const Client &b)
    {
        if (a.varsta < b.varsta)
            return true;
        else
            return false;
    }

    friend bool operator<= (const Client &a, const Client &b)
    {
        if (a.varsta <= b.varsta)
            return true;
        else
            return false;
    }

    friend bool operator> (const Client &a, const Client &b)
    {
        if (a.varsta > b.varsta)
            return true;
        else
            return false;
    }

    friend bool operator>= (const Client &a, const Client &b)
    {
        if (a.varsta >= b.varsta)
            return true;
        else
            return false;
    }

    Client &operator+ (float i)
    {
        notaAcordata = (notaAcordata+i)/2;

        return *this;
    }

    const Client operator++ ()
    {
        this -> varsta++;

        return *this;
    }

     const Client operator-- ()
    {
        this -> varsta--;

        return *this;
    }

    const Client operator++ (int)
    {
        Client aux(*this);
        this -> varsta++;

        return aux;
    }

    const Client operator-- (int)
    {
        Client aux(*this);
        this -> varsta--;

        return aux;
    }

    explicit operator int()
    {
        return (int) this -> notaAcordata;
    }

    ~Client()
    {
        if(this -> numeClient != NULL)
            delete[] this -> numeClient;
    }
};

class Oferta
{
    Client client;
    Hotel hotel;
public:

    Oferta()
    {

    }

    Oferta(Client c, Hotel h)
    {
        client = c;
        hotel = h;
    }

    Oferta(const Oferta &o)
    {
        if(this != &o)
        {
            client = o.client;
            hotel = o.hotel;
        }
    }

    Oferta &operator= (const Oferta &o)
    {
        if(this != &o)
        {
            client = o.client;
            hotel = o.hotel;
        }
        return *this;
    }

    friend ostream &operator<< (ostream &out, const Oferta &o)
    {
        out << "Detalii oferta: \n";
        out << o.client << "\nDetalii hotel:\n"<< o.hotel<< "\n";

        return out;
    }

    ~Oferta()
    {

    }
};

class Manager: public Worker
{
    float oreBonus;

public:

    Manager()
    {
        oreBonus = 0;
    }
    Manager(Worker a, float ore): Worker(a)
    {
        oreBonus = ore;
    }

    Manager(const Manager &m): Worker(m)
    {
        oreBonus = m.oreBonus;
    }

    Manager &operator= (const Manager &m)
    {
        if(this != &m)
        {
            Manager(*this) = (Manager&) m;
            this -> oreBonus = m.oreBonus;
        }
        return *this;
    }

    friend ostream &operator<< (ostream &out, Manager &m)
    {
        out << (Worker&) m;

        out << "Acesta a facut " << m.oreBonus << " ore in plus\n";

        return out;

    }

    friend istream &operator>> (istream &in, Manager &m)
    {
        in >> (Worker&) m;

        cout << "Introdu orele bonus: ";

        in >> m.oreBonus;

        return in;
    }

    ~Manager()
    {

    }

};

class HotelCuTerasa: public Hotel
{
    int numarMese;

public:

    void terasa()
    {
        cout << "Acest hotel nu are terasa";
    }

    HotelCuTerasa()
    {
        numarMese = 0;
    }

    HotelCuTerasa(Hotel h, int nr): Hotel(h)
    {
        numarMese = nr;
    }

    HotelCuTerasa(const HotelCuTerasa &ht): Hotel(ht)
    {
        numarMese = ht.numarMese;
    }

    HotelCuTerasa &operator= (const HotelCuTerasa &ht)
    {
        if(this != &ht)
        {
            HotelCuTerasa(*this) = (HotelCuTerasa&) ht;
            numarMese = ht.numarMese;
        }

        return *this;
    }

    friend ostream &operator<< (ostream  &out, HotelCuTerasa &ht)
    {
        out << (Hotel&) ht;

        out << "Acesta are un restaurnat cu: " << ht.numarMese << "\n";

        return out;
    }

    ~HotelCuTerasa()
    {

    }

};


int main()

{
    ifstream file;

    file.open("datecomplex.txt");

    int n;

    file >> n;

    vector<ComplexHotelier> complexe;
    vector<Hotel> hoteluri;
    vector<Worker> workers;
    vector<Client> clienti;
    vector<Oferta> oferte;
    vector<HotelCuTerasa> hoteluriterasa;
    vector<Manager> manageri;

    char name[] = "Steluta";
    char nam3[] = "Raul Rusu";
    float grades[] = {9,4};
    int notes[] = {9,7};

    ComplexHotelier cx1(0,name,3,2,grades,1);
    Hotel h1(0,name,cx1,1,3334,2,notes,"mare");
    Worker w1(0,nam3,19,'M',2,notes,4500,h1);
    Client c1(0,nam3,30,'M',8,1);
    Oferta o1(c1,h1);
    HotelCuTerasa ht1(h1,33);
    Manager m1(w1,54);

    complexe.push_back(cx1);
    hoteluri.push_back(h1);
    workers.push_back(w1);
    clienti.push_back(c1);
    oferte.push_back(o1);
    hoteluriterasa.push_back(ht1);
    manageri.push_back(m1);

    for(int i = 0; i < n; i++)
    {
        char nume[100];
        file.get();
        file.getline(nume, 100);

        int nrHotel, nrNote;
        bool recom;

        file >>nrNote>> nrHotel >> recom;

        float note[nrNote];

        for(int j = 0; j < nrNote; j++)
           file >> note[j];

        ComplexHotelier ch(i,nume,nrHotel,nrNote,note,recom);
        complexe.push_back(ch);

    }

     file.close();

     file.open("datehotel.txt");

     file >> n;

    for(int i = 0; i < n; i++)
    {
        char nume[100];
        int levels;
        float val;
        bool recond;
        string loc;

        file.get();
        file.getline(nume, 100);

        file >> recond >> val >> loc >> levels;

        int rooms[levels];
        for(int j = 0; j < levels; j++)
           file >> rooms[j];

        Hotel h(i,nume,complexe[0],recond,val,levels,rooms,loc);
        hoteluri.push_back(h);

    }

    file.close();

    file.open("dateworkers.txt");
    file >> n;

    for(int i = 0; i < n; i++)
    {
        int age,nrNote;
        char nume[150], gen;
        float salariu;

        file.get();
        file.get(nume, 150);

        file >> age >> gen >> nrNote;

        int note[nrNote];
        for(int j = 0; j < nrNote; j++)
           file >> note[j];

        file >> salariu;

        Worker w(i,nume,age,gen,nrNote,note,salariu,h1);

        workers.push_back(w);
    }

    file.close();

    file.open("dateclient.txt");

    file >> n;

    for(int i = 0; i< n; i++)
    {
        char nume[150], gen;
        int varsta;
        float nota;
        bool fidel;


        file.get();
        file.get(nume, 150);

        file >> varsta >> gen >> nota >> fidel;

        Client c(i,nume,varsta,gen,nota,fidel);

        clienti.push_back(c);
    }

    file.close();

    do
    {
    cout << "\n\n----------Bine ati venit la gestiunea complexului hotelier----------\n\n" << "Lista departamentelor pe care le poti selecta: \n 1.Complex Hotelier \n 2.Hotel \n 3.Angajat \n 4.Client \n 5.Oferta\n 6.Manager \n 7.Hotel cu terasa\n 8.Iesire";
    cout << "\n\nIntrodu departamentul dorit: ";
    cin >> n;

    cout << "\n";

    switch(n)
    {

    case 1:
        {
            do
            {

                cout << "==========Bine ai venit la departamentul Complex hotelier==========\n\n";
                cout << "Lista optiuni: \n 1.Adaugare complex\n 2.Afisare complexe\n 3.Adauga nota\n 4.Scade valoarea bancii\n 5.Iesire\n\nIntrodu optiunea: ";
                cin >> n;

                switch(n)
                {
                    case 1:
                        {
                            cout << "--=== Adaugare complex ===--\n\nIntrodu ID complex: ";
                            int q;
                            cin >> q;
                            ComplexHotelier ch(q);
                            cin.get();
                            cin >> ch;
                            cout << "\n";
                            complexe.push_back(ch);
                            break;
                        }

                    case 2:
                        {
                            cout << "+++--- Afisare complexe ---+++\n\n";
                            for (int x = 0; x < (int)complexe.size(); x++)
                            cout << complexe[x] << "\n";
                            break;
                        }

                    case 3:
                        {
                            int s, q;
                            cout << "--- Adaugare nota ---\n\nIntrodu pozita complexului din 2.Afisare complexe(numerotare de la 0): ";
                            cin >> s;
                            cout << "Introdu valoarea pe care o adaugi: ";
                            cin >> q;
                            complexe[s] = complexe[s]+ q;
                            break;
                        }

                    case 4:
                        {
                            cout << "----- Eliminare complex ------\n\n Introdu complexului ce vrei sa o elimini din 2.Afisare complexe(numerotare de la 0): ";
                            int u;
                            cin >> u;
                            complexe.erase(complexe.begin()+u);
                            break;
                        }

                    case 5:
                        {
                            cout << "--------- Iesire din departametul Complex hotelier ---------\n\n";
                            break;
                        }

                    default:
                        {
                            cout << "\n--- Ai gresit valoarea ---\n\n";
                        }

                }

            }while(n != 5);
            break;
        }

    case 2:
        {
            do
            {
                cout << "==========Bine ai venit la departamentul Hotel==========\n\n";
                cout << "Lista optiuni: \n 1.Adaugare hotel\n 2.Afisare hoteluri\n 3.Adauga nivel\n 4.Eliminare hotel\n 5.Iesire\n\nIntrodu optiunea: ";
                cin >> n;

                switch(n)
                {
                    case 1:
                        {
                            cout << "--=== Adaugare hotel ===--\n\n";
                            Hotel hh;
                            cin.get();
                            cin >> hh;
                            cout << "\n";
                            hoteluri.push_back(hh);
                            break;
                        }

                    case 2:
                        {
                            cout << "+++--- Afisare hotelrui ---+++\n\n";
                            for (int x = 0; x < (int)hoteluri.size(); x++)
                            cout << hoteluri[x] << "\n";
                            break;
                        }

                    case 3:
                        {
                            int s, q;
                            cout << "--- Adauga nivel la hotel ---\n\nIntrodu pozita hotelului din 2.Afisare hoteluri(numerotare de la 0): ";
                            cin >> s;
                            cout << "Introdu nr de camere pe care il adaugi la nivelul nou: ";
                            cin >> q;
                            hoteluri[s] = hoteluri[s]+ q;
                            break;
                        }


                    case 4:
                        {
                            cout << "----- Eliminare hotel ------\n\n Introdu hotelul ce vrei sa il elimini din 2.Afisare hoteluri(numerotare de la 0): ";
                            int u;
                            cin >> u;
                            hoteluri.erase(hoteluri.begin()+u);
                            break;
                        }

                    case 5:
                        {
                            cout << "--------- Iesire din departametul Hotel ---------\n\n";
                            break;
                        }

                    default:
                        {
                            cout << "\n--- Ai gresit valoarea ---\n\n";
                        }
                }

            }while(n != 5);
            break;
        }

    case 3:
        {
            do
            {
                cout << "==========Bine ai venit la departamentul Worker==========\n\n";
                cout << "Lista optiuni: \n 1.Adaugare angajat\n 2.Afisare angajat\n 3.Creste salariu\n 4.Scade salariu\n 5.Eliminare angajat\n 6.Iesire\n\nIntrodu optiunea: ";
                cin >> n;

                switch(n)
                {
                    case 1:
                        {
                            cout << "--==== Adaugare angajat ====--\n\n";
                            Worker bb;
                            cin.get();
                            cin >> bb;
                            cout << "\n";
                            workers.push_back(bb);
                            break;
                        }

                    case 2:
                        {
                            cout << "+++---+ Afisare angajati +---+++\n\n";
                            for (int x = 0; x < (int)workers.size(); x++)
                            cout << workers[x] << "\n";
                            break;
                        }

                    case 3:
                        {
                            int s, q;
                            cout << "--- Creste salariu ---\n\nIntrodu pozita angajatului din 2.Afisare angajati(numerotare de la 0): ";
                            cin >> s;
                            cout << "Introdu valoarea pe care o adaugi: ";
                            cin >> q;
                            workers[s] = workers[s]+ q;
                            break;
                        }

                    case 4:
                        {
                            int s, q;
                            cout << "--- Scade salariul ---\n\nIntrodu pozita sediului din 2.Afisare angajati(numerotare de la 0): ";
                            cin >> s;
                            cout << "Introdu valoarea pe care o scazi: ";
                            cin >> q;
                            workers[s] = workers[s]- q;
                            break;
                        }

                    case 5:
                        {
                            cout << "----- Eliminare angajat ------\n\n Introdu angajatul ce vrei sa il elimini din 2.Afisare angajati(numerotare de la 0): ";
                            int u;
                            cin >> u;
                            workers.erase(workers.begin()+u);
                            break;
                        }

                    case 6:
                        {
                            cout << "--------- Iesire din departametul Worker ---------\n\n";
                            break;
                        }

                    default:
                        {
                            cout << "\n--- Ai gresit valoarea ---\n\n";
                        }
                }

            }while(n != 6);
            break;
        }

    case 4:
        {
            do
            {
                cout << "==========Bine ai venit la departamentul Client==========\n\n";
                cout << "Lista optiuni: \n 1.Adaugare client\n 2.Afisare client\n 3.Adauga nota\n 4.Eliminare client\n 5.Iesire\n\nIntrodu optiunea: ";
                cin >> n;

                switch(n)
                {
                    case 1:
                        {
                            cout << "--==== Adaugare client ====--\n\n";
                            Client bb;
                            cin.get();
                            cin >> bb;
                            cout << "\n";
                            clienti.push_back(bb);
                            break;
                        }

                    case 2:
                        {
                            cout << "+++---+ Afisare clienti +---+++\n\n";
                            for (int x = 0; x < (int)clienti.size(); x++)
                            cout << clienti[x] << "\n";
                            break;
                        }

                    case 3:
                        {
                            int s;
                            float q;
                            cout << "--- Adauga nota ---\n\nIntrodu pozita clientului din 2.Afisare clienti(numerotare de la 0): ";
                            cin >> s;
                            cout << "Introdu nota: ";
                            cin >> q;
                            clienti[s] = clienti[s]+ q;
                            break;
                        }

                    case 4:
                        {
                            cout << "----- Eliminare client ------\n\n Introdu clientul ce vrei sa il elimini din 2.Afisare clienti(numerotare de la 0): ";
                            int u;
                            cin >> u;
                            clienti.erase(clienti.begin()+u);
                            break;
                        }

                    case 5:
                        {
                            cout << "--------- Iesire din departametul Client ---------\n\n";
                            break;
                        }

                    default:
                        {
                            cout << "\n--- Ai gresit valoarea... =( ---\n\n";
                        }
                }

            }while(n != 5);
            break;
        }

    case 5:
        {
            do
            {
                cout << "==========Bine ai venit la departamentul Oferta==========\n\n";
                cout << "Lista optiuni: \n 1.Afisare oferte\n 2.Eliminare oferta\n 3.Iesire\n\nIntrodu optiunea: ";
                cin >> n;

                switch(n)
                {

                    case 1:
                        {
                            cout << "+++---+ Afisare oferte +---+++\n\n";
                            for (int x = 0; x < (int)oferte.size(); x++)
                            cout << oferte[x] << "\n";
                            break;
                        }

                    case 2:
                        {
                            cout << "----- Eliminare oferta ------\n\n Introdu oferta ce vrei sa o elimini din 2.Afisare oferte(numerotare de la 0): ";
                            int u;
                            cin >> u;
                            oferte.erase(oferte.begin()+u);
                            break;
                        }

                    case 3:
                        {
                            cout << "--------- Iesire din departamentul Oferta ---------\n\n";
                            break;
                        }

                    default:
                        {
                            cout << "\n--- Ai gresit valoarea ---\n\n";
                        }
                }

            }while(n != 3);
            break;
        }

    case 6:
        {
            do
            {
                cout << "==========Bine ai venit la departamentul *Manager*==========\n\n";
                cout << "Lista optiuni: \n 1.Adaugare manager\n 2.Afisare manageri\n 3.Eliminare manager\n 4.Iesire\n\nIntrodu optiunea: ";
                cin >> n;

                switch(n)
                {
                    case 1:
                        {
                            cout << "--==== Adaugare manager ====--\n\n";

                            Manager bb;
                            cin.get();
                            cin >> bb;
                            cout << "\n";
                            manageri.push_back(bb);
                            break;
                        }

                    case 2:
                        {
                            cout << "+++---+ Afisare manageri +---+++\n\n";
                            for (int x = 0; x < (int)manageri.size(); x++)
                            cout << manageri[x] << "\n";
                            break;
                        }

                    case 3:
                        {
                            cout << "----- Eliminare manager ------\n\n Introdu managerul ce vrei sa il elimini din 2.Afisare manageri(numerotare de la 0): ";
                            int u;
                            cin >> u;
                            manageri.erase(manageri.begin()+u);
                            break;
                        }

                    case 4:
                        {
                            cout << "--------- Iesire din departametul Manager ---------\n\n";
                            break;
                        }

                    default:
                        {
                            cout << "\n--- Ai gresit valoarea... =( ---\n\n";
                        }
                }

            }while(n != 4);
            break;
        }

    case 7:
        {
            do
            {
                cout << "==========Bine ai venit la departamentul Hotel cu terasa==========\n\n";
                cout << "Lista optiuni: \n 1.Afisare hoteluri cu terasa\n 2.Iesire\n\nIntrodu optiunea: ";
                cin >> n;

                switch(n)
                {

                    case 1:
                        {
                            cout << "+++-- Afisare hoteluri cu terasa --+++\n\n";
                            for (int x = 0; x < (int)hoteluriterasa.size(); x++)
                            cout << hoteluriterasa[x] << "\n";
                            break;
                        }

                    case 2:
                        {
                            cout << "--------- Iesire din departametul hoteluri cu terasa ---------\n\n";
                            break;
                        }

                    default:
                        {
                            cout << "\n--- Ai gresit valoarea ---\n\n";
                        }
                }

            }while(n != 2);
            break;
        }

    case 8:
        {
            cout << "----- La revedere -----\n";
            break;
        }

    default:
        {
        cout << "--- Ai gresit valoarea ---";
        }

    }
    }while(n!= 8);

	return 0;

}

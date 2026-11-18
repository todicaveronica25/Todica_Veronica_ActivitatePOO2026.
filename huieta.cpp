#define _CRT_SECURE_NO_WARNINGS   
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Dyson{
private:
    
    string culoare;
    string model;
    int putere;
    int nrTrepte;
    int nrAccesorii;
    string* accesorii;
    const int id;
    static int contorid;
    static int nrDyson;
    static float tva;
    float pret;

public://  CONSTRUCTORI (fara tip returnat, nici void; numele = numele clasei)
 
class Filtru
{
    private:
    string tip;
    int oreFolosite;

    public:

    Filtru()
    {
        this-> tip="HEPA";
        this->oreFolosite=0;
    }

    Filtru(string tip, int oreFolosite)
    {
        if(tip.length()>0)
        this->tip=tip;
        
        else
        this->tip="HEPA";

        if(oreFolosite>=0)
        this->oreFolosite=oreFolosite;
        else
        this->oreFolosite=0;
    }
    Filtru(const Filtru& f)
    {
        this->tip=f.tip;
        this->oreFolosite=f.oreFolosite;
    }

    ~Filtru();

    string getTip()const
    {
        return this->tip;
    }
    void setTip(string tip)
    {
         if(tip.length()>0)
        this->tip=tip;   
    }

    int getOreFolosite()const{
        return this->oreFolosite;
    }

    void setOreFolosite(int oreFolosite){
        if(oreFolosite>=0)
        this->oreFolosite=oreFolosite;
    }

    Filtru& operator=(const Filtru& f)
    {
        if(this != &f)
        {
            this->tip=f.tip;
            this->oreFolosite=f.oreFolosite;

        }
        return *this;
    }

    void foloseste(int ore)
    {
        if(ore>0)
        this->oreFolosite=oreFolosite+ore;

    }

    bool TrebuieSchimbat(const Dyson& d)const
    {
        return this->oreFolosite>100 || d.putere<10;
    }  
};

friend class Utilizator;
friend float pretFinal(const Dyson& d);

public:
//constructor implicit (fara paramaetri)

 Dyson(): id(++contorid)
{
    this->culoare="alb";
    this->model="airstraight";
    this->putere=4;
    this->nrTrepte=2;
    this->nrAccesorii=2;
    this->accesorii=new string [this->nrAccesorii];
    this->accesorii[0]="perie";
    this->accesorii[1]="duza";
    this->pret=10004.9;

}

//constructor cu parametri

Dyson(string culoare,  string model,  int putere, int nrTrepte, int nrAccesorii, string* accesorii, float pret) : id(++contorid)
{
    if(culoare.length()>0)
        this->culoare=culoare;
    else
    this->culoare="default";

    if(model.length()>0)
        this->model=model;
    else
    this->model="default";

    if(putere>0)
        this->putere=putere;
    else
        this->putere=3;

    if(nrTrepte>0)
        this->nrTrepte=nrTrepte;
    else
        this->nrTrepte=3;

    
    if(nrAccesorii>0 && accesorii !=nullptr)
    {
        this->nrAccesorii=nrAccesorii;
        this->accesorii=new string [this->nrAccesorii];
        for(int i=0;i<nrAccesorii;i++)
        this->accesorii[i]=accesorii[i];
    }

    else 
    {
        this->nrAccesorii=0;
        this->accesorii=nullptr;
    }
    
    if (pret>0)
    this->pret=pret;
    else
    this->pret=1500;
    
}

//constructor de copiere

Dyson( const Dyson& d): id(++contorid)
{
    this->culoare=d.culoare;
    this->model=d.model;
    this->putere=d.putere;
    this->nrTrepte=d.nrTrepte;
     if(d.nrAccesorii>0 && d.accesorii !=nullptr)
    {
        this->nrAccesorii=d.nrAccesorii;
        this->accesorii=new string [this->nrAccesorii];
        for(int i=0;i<d.nrAccesorii;i++)
        this->accesorii[i]=d.accesorii[i];
    }

    else 
    {
        this->nrAccesorii=0;
        this->accesorii=nullptr;
    }
    this->pret=d.pret;

}

//destructor
~Dyson()
{
    delete[]this->accesorii;
}
//operator egal
Dyson& operator=(const Dyson& d)
{
    if(this != &d)
    {

        this->culoare=d.culoare;
        this->model=d.model;
        this->putere=d.putere;
        this->nrTrepte=d.nrTrepte;
        delete[]this->accesorii;
        if(d.nrAccesorii>0 && d.accesorii !=nullptr)
        {
            this->nrAccesorii=d.nrAccesorii;
            this->accesorii=new string [this->nrAccesorii];
            for(int i=0;i<d.nrAccesorii;i++)
            this->accesorii[i]=d.accesorii[i];
         }

        else 
        {
            this->nrAccesorii=0;
            this->accesorii=nullptr;
        }
        this->pret=d.pret;
        
    }
    return *this;
}


string getCuloare() const
{
    return this->culoare;
}
void setCuloare(string culoare)
{
    if(culoare.length()>0)
    this->culoare=culoare;
}

string getModel() const{
    return this->model;
}
void setModel(string model)
{
    if(model.length()>0)
    this->model=model;
}
 
int getPutere()const
{
    return this->putere;
}
void setPutere(int putere)
{
    if(putere>0)
    this->putere=putere;
}

int getTrepte() const
{
    return this->nrTrepte;
}
void setTrepte(int nrTrepte);

int getNrAccesorii()const
{
    return this->nrAccesorii;
}

string* getAccesorii()const
{
    return this->accesorii;
}

void setAccesorii( const string* accesorii, int nrAccesorii)
{
    if(nrAccesorii>0 && accesorii != nullptr)
    {   delete[] this->accesorii;
        this->nrAccesorii=nrAccesorii;
        this->accesorii=new string[this->nrAccesorii];
        for(int i=0;i<this->nrAccesorii; i++)
        this->accesorii[i]=accesorii[i];
    }
}

float getPreti()const{
    return this->pret;

}
void setPret(float pret)
{
    if(pret>0)
    this->pret=pret;
}

////////////////////////////////////////////////////////////////////////////////////

Dyson operator+(const Dyson& d)
{
    Dyson rezultat(*this);
    rezultat.pret=this->pret+d.pret;
    return rezultat;
}

Dyson operator+(float crestere) 
{
    Dyson rezultat(*this);
    rezultat.pret=this->pret+crestere;
    return rezultat;
}

friend Dyson operator+(float crestere, const Dyson& d)
{
    Dyson rezultat=d;
    rezultat.pret=d.pret+crestere;
    return rezultat;
}

Dyson& operator+=(float crestere)
{
    this->pret+=crestere;
    return *this;
}

bool operator==(const Dyson& d)
{
    return this->model==d.model && this->culoare==d.culoare &&this->pret==pret;
}

bool operator<(const Dyson& d)
{
    return this->pret<d.pret;
}
bool operator>(const Dyson& d)
{
    return this->pret>d.pret;
}

bool operator!()
{
    return this->nrAccesorii==0; //nu are accesorii

}

string& operator[](int index)
{
    static string eroare;
    if(index>=0 && index < this->nrAccesorii)
        return this->accesorii[index];
    eroare="(index invalid)";
    return eroare;
}

string operator[](int index) const
{
    if(index>=0 && index<this->nrAccesorii)
        return this->accesorii[index];
    return "(index invalid)";
}

friend ostream& operator<<(ostream& out, const Dyson& d)
{
    out<< "Dyson # "<<d.id<< " | "<< d.model<< " | "<< d.culoare<< " | "<< d.putere<< "watt| "<< d.nrTrepte<< " | "<< d.pret<<endl;
    out << "accesorii: "<<d.nrAccesorii;
    for(int i=0; i<d.nrAccesorii;i++)
        out<<d.accesorii[i]<< "; ";
        out<<endl;
    return out;
}

friend istream& operator>>(istream& in, Dyson& d)
{
    cout<<"introduceti nume model: ";
    in>>d.model;

    cout <<"culoare: ";
    in>>d.culoare;

    cout << "Introduceti putere (W): ";
    in >> d.putere;

    cout << "Introduceti numar trepte: ";
    in >> d.nrTrepte;

    cout << "Introduceti pret: ";
    in >> d.pret;

    cout << "Introduceti numar accesorii: ";
    in >> d.nrAccesorii;

    delete[] d.accesorii;

    if(d.nrAccesorii>0)
    {
        d.accesorii=new string[d.nrAccesorii];
        for (int i=0;i<d.nrAccesorii;i++)
        {
            cout<<"accesoriul "<<i+1;
            in>>d.accesorii[i];
        }

    }
    else
    {
        d.nrAccesorii=0;
        d.accesorii=nullptr;
    }

    return in;
}

Dyson& operator++()
{
    this->putere++;
    return *this;
}
Dyson operator++(int)
{
    Dyson copie=*this;
    this->putere++;
    return copie;
}




    
    
};

class Utilizator
{
    private:
    string nume;
    Dyson aspirator;
    public:

    Utilizator()
    {
        this->nume="Anonim";

    }

    Utilizator(string nume, const Dyson& aspirator)
    {
        this->nume=nume;
        this->aspirator=aspirator;
    }

    bool aspiratorPuternic()const{
        return this->aspirator.putere>150;
    }
};


float pretFinal(const Dyson& d)
{

    return d.pret*(1+Dyson::tva);
}

void Dyson:: setTrepte(int nrTrepte)
{
    if(nrTrepte>0)
    this->nrTrepte=nrTrepte;
}

float Dyson:: tva=0.19f;
int Dyson:: contorid=0;

void main()
{

}
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
    char* accesorii;
    float pret;
    const int id;
    static int contorid;
    static int nrDyson;
    static float tva;
 
protected:
    float pret;

public://  CONSTRUCTORI (fara tip returnat, nici void; numele = numele clasei)
 //constructor implicit (fara paramaetri)

 Dyson(): id(++contorid)


};

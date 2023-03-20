
#ifndef LAB9_10_HOTEL_H
#define LAB9_10_HOTEL_H
#include "Date.h"
#include <iostream>
using namespace std;
class Hotel {
private:
    int cod_unic;
    string nume;
    string oras;
    Date dataInceputDisponibilitate;
    Date dataSfarsitDisponibilitate;
public:
    Hotel();
    Hotel(int cod, string name ,string Oras,Date dataInceput, Date dataSfarsit);
    Hotel& operator=(const Hotel&);
    bool operator==(const Hotel&);
    bool operator!=(const Hotel &);
    int get_cod();
    string get_nume();
    string get_oras();
    Date get_data_inceput();
    Date get_data_sfarsit();
    void set_day_inceput(int);
    void set_day_sfarsit(int);
    friend istream& operator>>(istream &is, Hotel &);
    friend ostream& operator<<(ostream &os, const Hotel &);
};


#endif

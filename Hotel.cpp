

#include "Hotel.h"
#include <string.h>

Hotel::Hotel() {
    this->cod_unic = 0;
    this->nume = "a";
    this->oras = "a";
    this->dataInceputDisponibilitate.set_date(1, 1, 2022);
    this->dataInceputDisponibilitate.set_date(1, 1, 2022);
}

Hotel::Hotel(int cod, string name, string Oras, Date dataInceput, Date dataSfarsit) {
    this->cod_unic = cod;
    this->nume = name;
    this->oras = Oras;
    this->dataInceputDisponibilitate = dataInceput;
    this->dataSfarsitDisponibilitate = dataSfarsit;
}


Hotel &Hotel::operator=(const Hotel &S) {
    if (this != &S) {
        this->oras = S.oras;
        this->nume = S.nume;
        this->cod_unic = S.cod_unic;
        this->dataInceputDisponibilitate = S.dataInceputDisponibilitate;
        this->dataSfarsitDisponibilitate = S.dataSfarsitDisponibilitate;
    }
}

bool Hotel::operator==(const Hotel &S) {
    return ((this->cod_unic == S.cod_unic) && (this->nume==S.nume)
            && (this->oras==S.oras) && (this->dataInceputDisponibilitate == S.dataInceputDisponibilitate)
            && (this->dataSfarsitDisponibilitate == S.dataSfarsitDisponibilitate));
}

bool Hotel::operator!=(const Hotel &S) {
    return ((this->cod_unic != S.cod_unic) || (this->nume!=S.nume)
            || (this->oras!=S.oras) || (this->dataInceputDisponibilitate != S.dataInceputDisponibilitate)
            || (this->dataSfarsitDisponibilitate != S.dataSfarsitDisponibilitate));
}


int Hotel::get_cod() {
    return this->cod_unic;
}

string Hotel::get_nume() {
    return this->nume;
}

string Hotel::get_oras() {
    return this->oras;
}

Date Hotel::get_data_inceput() {
    return this->dataInceputDisponibilitate;
}

Date Hotel::get_data_sfarsit() {
    return this->dataSfarsitDisponibilitate;
}
void  Hotel::set_day_inceput(int dayy) {
    this->dataInceputDisponibilitate.setDay(dayy);
}
void Hotel::set_day_sfarsit(int dayy) {
    this->dataSfarsitDisponibilitate.setDay(dayy);
}
istream &operator>>(istream &is, Hotel &hot) {
    cout << endl;
    cout << "Introduceti numele Orasului: ";
    is>>hot.oras;
    cout << "Introduceti numele Hotelului: ";
    is>>hot.nume;
    is.get();
    cout<<"Introduceti codul unic: ";
    is >> hot.cod_unic;
    cout << "Introduceti data de inceput : ";
    is >> hot.dataInceputDisponibilitate;
    cout << "Introduceti data de sfarsit : ";
    is >> hot.dataSfarsitDisponibilitate;
    return is;
}

ostream &operator<<(ostream &os, const Hotel &S) {
    os << endl;
    os << "Cod_unic:" << S.cod_unic << endl;
    os << "Oras: " << S.oras << endl;
    os << "Nume_Hotel: " << S.nume << endl;
    os << "Data_Inceput: " << S.dataInceputDisponibilitate << endl;
    os << "Data_Sfarsit: " << S.dataSfarsitDisponibilitate << endl;
    return os;
}


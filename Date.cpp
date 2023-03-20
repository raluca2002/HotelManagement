
#include "Date.h"

Date::Date() {}

Date::Date(int zi, int luna, int an) {
    this->zi = zi;
    this->luna = luna;
    this->an = an;

}

void Date::set_date(int zii, int lunaa, int ann) {
    this->an = ann;
    this->luna = lunaa;
    this->zi = zii;
}

Date &Date::operator=(const Date &S) {
    if (this != &S) {
        this->an = S.an;
        this->luna = S.luna;
        this->zi = S.zi;
    }
}

bool Date::operator==(const Date &S) {
    return ((this->zi == S.zi) && (this->luna == S.luna) && (this->an == S.an));
}

bool Date::operator!=(const Date &S) {
    return ((this->zi != S.zi) || (this->luna != S.luna) || (this->an != S.an));
}

bool Date::operator>=(const Date &S) {
    return ((this->zi >= S.zi) && (this->luna >= S.luna) && (this->an >= S.an));
}

bool Date::operator<=(const Date &S) {
    return ((this->zi <= S.zi) && (this->luna <= S.luna) && (this->an <= S.an));
}

istream &operator>>(istream &is, Date &hote) {
    cout << endl;
    cout << "Introduceti anul: ";
    is >> hote.an;
    cout << "Introduceti luna: ";
    is >> hote.luna;
    cout << "Introduceti ziua: ";
    is >> hote.zi;
    return is;
}

ostream &operator<<(ostream &os, const Date &dat) {
    os << dat.zi << "/" << dat.luna << "/" << dat.an << endl;
    return os;
}

int Date::getYear()  {
    return an;
}

void Date::setYear(int ann) {
    Date::an = ann;
}

int Date::getMonth()  {
    return luna;
}

void Date::setMonth(int lunaa) {
    Date::luna = lunaa;
}

int Date::getDay()  {
    return zi;
}

void Date::setDay(int zii) {
    Date::zi = zii;
}

bool Date::operator>(const Date &S) {
    return ((this->zi > S.zi) && (this->luna > S.luna) && (this->an > S.an));
}




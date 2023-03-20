

#ifndef LAB9_10_DATE_H
#define LAB9_10_DATE_H

#include <iostream>

using namespace std;

class Date {
private:
    int an;
    int luna;
    int zi;
public:
    Date();

    Date(int zi, int luna, int an);

    void set_date(int zi, int luna, int an);

    Date &operator=(const Date &);

    bool operator==(const Date &);

    bool operator!=(const Date &);

    int getYear();

    void setYear(int);

    int getMonth();

    void setMonth(int);

    int getDay() ;

    void setDay(int);

    bool operator>=(const Date &);
    bool operator>(const Date &);

    bool operator<=(const Date &);

    friend istream &operator>>(istream &is, Date &);

    friend ostream &operator<<(ostream &os, const Date &);
};


#endif



#ifndef LAB9_10_SERVICE_H
#define LAB9_10_SERVICE_H

#include "Hotel.h"
/*#include "Repository.h"*/
#include "RepoFile.h"
#include <string>

class Service {
private:
    //Repository repo;
    RepoInFile repo;
public:
    Service();

    void setrepository(string);

    Hotel *read();

    void adauga(Hotel &);

    void modificare(Hotel &old, Hotel &new_hotel);

    void sterge(Hotel &);

    void cautare_hotel_oras(string Oras);

    Hotel *cautare_hotel_oras_1(const string &Oras, int &lungime);

    Hotel *rezervare(string, Date, Date, int&);
    void update_dates(Hotel &hot, Date data_inceput, Date data_final);


    int lungime();
};


#endif //LAB9_10_SERVICE_H

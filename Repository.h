

#ifndef LAB9_10_REPOSITORY_H
#define LAB9_10_REPOSITORY_H

#include "Hotel.h"

class Repository {
private:
    int length;
    int capacity;
    Hotel *hoteluri;
public:
    Repository();
    Repository(const Repository &);
    void adaugare(const Hotel&);

    virtual void update(Hotel&, Hotel&);

    virtual void stergere(Hotel&);
    Hotel* get_all();
    int get_length();
};


#endif //LAB9_10_REPOSITORY_H

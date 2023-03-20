
#ifndef LAB9_10_UI_H
#define LAB9_10_UI_H
#include "Repository.h"
#include "Service.h"
#include "RepoFile.h"
class UI {
private:
    Service service;
    Repository repository;

    void adaugare();
    void show_all();
    void stergere();
    void update();
    void cautare_hotel_oras();
    void cautare_hotel_oras_1();
    void rezervari();
public:
    UI();
    UI(RepoInFile&, Service&);
    void show_menu();
};


#endif //LAB9_10_UI_H

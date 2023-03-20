

#include "Tests.h"
#include <cassert>
#include <cstring>
#include "Hotel.h"
#include "Service.h"

/*
void tests() {
    Date data_inceput;
    Date data_sfarsit;
    data_inceput.set_date(1, 1, 2022);
    data_sfarsit.set_date(1, 2, 2023);;
    Hotel hotel_1(1, "Bogdan", "Cluj", data_inceput, data_sfarsit);
    assert(hotel_1.get_nume()=="Bogdan");
    assert(hotel_1.get_oras()=="Cluj");
    assert(hotel_1.get_data_inceput() == data_inceput);
    assert(hotel_1.get_data_sfarsit() == data_sfarsit);
    Repository repo_1;
    repo_1.adaugare(hotel_1);
    assert(repo_1.get_all()[0] == hotel_1);

}*/

void repo_tests() {
    Date data_inceput;
    Date data_sfarsit;
    data_inceput.set_date(1, 1, 2022);
    data_sfarsit.set_date(1, 2, 2023);;
    Hotel hotel_1(1, "Bogdan", "Cluj", data_inceput, data_sfarsit);
    Hotel hotel_2(1, "Vlad", "Cluj", data_inceput, data_sfarsit);
    Hotel hotel_3(1, "Bogdan", "Cluj", data_inceput, data_sfarsit);
    Hotel hotel_4(1, "Ana", "Cluj", data_inceput, data_sfarsit);

    RepoInFile repo_1;
    repo_1.adaugare(hotel_1);
    repo_1.adaugare(hotel_2);
    repo_1.adaugare(hotel_3);


    assert(repo_1.get_all()[0] == hotel_1);
    assert(repo_1.get_all()[1] == hotel_2);
    assert(repo_1.get_all()[2] == hotel_3);

    repo_1.update(hotel_1, hotel_4);

    assert(repo_1.get_all()[0] == hotel_4);
    assert(repo_1.get_all()[2] == hotel_4);

    repo_1.adaugare(hotel_1);

    assert(repo_1.get_all()[3] == hotel_1);
    assert(repo_1.get_length() == 4);

    repo_1.stergere(hotel_1);
    assert(repo_1.get_length() == 3);
    assert(repo_1.get_all()[0] == hotel_4);
    assert(repo_1.get_all()[1] == hotel_2);
    assert(repo_1.get_all()[2] == hotel_4);

    repo_1.adaugare(hotel_4);
    assert(repo_1.get_length() == 4);
    assert(repo_1.get_all()[0] == hotel_4);
    assert(repo_1.get_all()[1] == hotel_2);
    assert(repo_1.get_all()[2] == hotel_4);
    assert(repo_1.get_all()[3] == hotel_4);
}

void service_tests() {
    Date data_inceput;
    Date data_sfarsit;
    data_inceput.set_date(1, 1, 2022);
    data_sfarsit.set_date(1, 2, 2023);;
    Hotel hotel_1(1, "Ana", "Cluj", data_inceput, data_sfarsit);
    Hotel hotel_2(1, "Vlad", "Cluj", data_inceput, data_sfarsit);
    Hotel hotel_3(1, "Bogdan", "Cluj", data_inceput, data_sfarsit);
    Hotel hotel_4(1, "Bogdan", "Cluj", data_inceput, data_sfarsit);
    Hotel hotel_5(1, "Momo", "Cluj", data_inceput, data_sfarsit);
    Hotel hotel_6(1, "Ceva", "Cluj", data_inceput, data_sfarsit);
    Hotel hotel_7(1, "Ceva", "Bucuresti", data_inceput, data_sfarsit);
    Hotel hotel_8(1, "Ceva", "Bucuresti", data_inceput, data_sfarsit);


    RepoInFile repo;
    Service service;
    service.setrepository("TEST");
    repo.clearFile();
    service.adauga(hotel_1);
    service.adauga(hotel_2);
    service.adauga(hotel_3);
    service.adauga(hotel_4);
    service.adauga(hotel_5);
    service.adauga(hotel_6);
    int length;
    Hotel *lst = service.cautare_hotel_oras_1("Cluj", length);
    assert(lst[0] != hotel_7);
    assert(length == 6);

    assert(service.read()[0] == hotel_1);
    assert(service.read()[1] == hotel_2);
    assert(service.read()[2] == hotel_3);
    assert(service.read()[3] == hotel_4);
    assert(service.read()[4] == hotel_5);
    assert(service.read()[5] == hotel_6);


    assert(service.lungime() == 6);
    service.sterge(hotel_6);
    assert(service.lungime() == 5);


    service.adauga(hotel_6);
    service.modificare(hotel_6, hotel_5);

    assert(service.read()[5] == hotel_5);

}

void test2() {
    RepoInFile repo;
    Service service;
    Date data_inceput;
    Date data_sfarsit;
    service.setrepository("TESTE");
    repo.clearFile();
    data_inceput.set_date(1, 1, 2022);
    data_sfarsit.set_date(30, 1, 2022);;
    Hotel hotel_1(1, "Ana", "Cluj", data_inceput, data_sfarsit);
    Hotel hotel_2(1, "Vlad", "Cluj", data_inceput, data_sfarsit);
    Hotel hotel_3(1, "Bogdan", "Cluj", data_inceput, data_sfarsit);
    Hotel hotel_4(1, "Bogdan", "Cluj", data_inceput, data_sfarsit);
    Hotel hotel_5(1, "Momo", "Cluj", data_inceput, data_sfarsit);
    Hotel hotel_6(1, "Ceva", "Cluj", data_inceput, data_sfarsit);
    Hotel hotel_7(1, "Ceva", "Bucuresti", data_inceput, data_sfarsit);
    Hotel hotel_8(1, "Ceva", "Bucuresti", data_inceput, data_sfarsit);
    service.adauga(hotel_1);
    service.adauga(hotel_2);
    service.adauga(hotel_3);
    service.adauga(hotel_4);
    service.adauga(hotel_5);
    service.adauga(hotel_6);

    int length;
    Hotel *lst = service.cautare_hotel_oras_1("Cluj", length);
    assert(lst[0] != hotel_7);
    assert(length == 6);
    assert(lst[0] == hotel_1);
    int lungime = 0;

    Hotel *lst_hoteluri = service.rezervare("Cluj", data_inceput, data_sfarsit, lungime);
    assert(lungime == 6);
    data_inceput.set_date(1,1,2022);
    data_sfarsit.set_date(10,1,2022);
    service.update_dates(lst_hoteluri[0],data_inceput,data_sfarsit);

    data_inceput.set_date(10,1,2022);
    data_sfarsit.set_date(11,1,2022);
    service.update_dates(lst_hoteluri[1],data_inceput,data_sfarsit);
}


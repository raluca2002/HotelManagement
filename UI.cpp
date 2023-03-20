
#include "UI.h"
#include <iostream>

using namespace std;

UI::UI() {
    RepoInFile repository_1;
    this->repository = repository_1;

    Service service_1;
    service_1.setrepository("default.txt");
    this->service = service_1;
}

UI::UI(RepoInFile &repo, Service &service1) {
    this->repository = repo;

    this->service = service1;
    this->service.setrepository("hotel.txt");
}

void menu() {
    cout << endl;
    cout << "1.Citire Hotel" << endl;
    cout << "2.Afisare Hoteluri" << endl;
    cout << "3.Stergere Hotel" << endl;
    cout << "4.Modificare Hotel" << endl;
    cout << "5.Cautare Hotel dupa oras" << endl;
    cout << "6.Afisam toate cazarile ce au hotelul in orasul dorit si are rezervare disponibila" << endl;
    cout << "in perioada dorita sau o perioada in interval de +/+-3zile distanta" << endl;
    cout << "0.Exit" << endl;
}

void UI::show_menu() {
    menu();
    int optiune;
    cout << "Introduceti optiunea: " << endl;
    cin >> optiune;
    while (optiune) {
        switch (optiune) {
            case 1:
                adaugare();
                break;
            case 2:
                show_all();
                break;
            case 3:
                stergere();
                break;
            case 4:
                update();
                break;
            case 5:
                cautare_hotel_oras();
                break;
            case 6:
                rezervari();
                break;
            default:
                cout << "Comanda invalida !" << endl;
        }
        menu();
        cout << "Introduceti optiunea: " << endl;
        cin >> optiune;
    }
}

void UI::adaugare() {
    Hotel hotel_a;
    cin >> hotel_a;
    service.adauga(hotel_a);
}

void UI::show_all() {
    for (int i = 0; i < service.lungime(); i++)
        cout << service.read()[i] << " " << endl;
    cout << endl;
}

void UI::stergere() {
    Hotel hotel_a;
    cin >> hotel_a;
    service.sterge(hotel_a);
}

void UI::update() {
    Hotel hotel_old, hotel_new;
    cout << "Citire Hotel pe care vreti sa l actualizati: ";
    cin >> hotel_old;
    cout << "Citire noile date ale hotelului: ";
    cin >> hotel_new;
    service.modificare(hotel_old, hotel_new);
}

void UI::cautare_hotel_oras() {
    cout << endl;
    string oras;
    cout << "Introduceti numele Orasului : ";
    cin >> oras;
    service.cautare_hotel_oras(oras);
}

void UI::cautare_hotel_oras_1() {
    cout << endl;
    string oras;
    int lungime = 0;
    cout << "Introduceti numele Orasului : ";
    cin >> oras;
    Hotel *lst = service.cautare_hotel_oras_1(oras, lungime);
    for (int i = 0; i < lungime; i++)
        cout << lst[i] << endl;

}

/*
void UI::handle_rezervari() {
    cout << endl;
    string oras;
    Date data_inceputt, data_finall;
    cout << "Introduceti numele orasului in care doriti sa rezervati un hotel:";
    cin >> oras;
    cout << "Introduceti data de inceput: ";
    cin >> data_inceputt;
    cout << "Introduceti data finala: ";
    cin >> data_finall;
    int lungime = 0;
    Hotel *lst = service.rezervare(oras, data_inceputt, data_finall, lungime);
    if (lungime == 0)
        cout << "Nu exista rezervari!";
    else {
        int ok =0;
        int option = -1;
        while (option != lungime && ok ==0) {
            for (int i = 0; i < lungime; i++)
                cout << lst[i].get_nume() << endl << " " << lst[i].get_data_inceput() << " "
                     << lst[i].get_data_sfarsit() << endl;
            cin >> option;
            if (option > lungime)
                cout << "Hotel invalid!";
            else
                for (int i = 0; i < lungime; i++)
                    if (option == i) {
                        Hotel temp;
                        if (data_finall.getDay() <= lst[i].get_data_inceput().getDay()) {
                            temp = lst[i];
                            temp.get_data_inceput().set_date(lst[i].get_data_inceput().getDay() +
                                                             (data_finall.getDay() - data_inceputt.getDay()),
                                                             lst[i].get_data_inceput().getMonth(),
                                                             lst[i].get_data_inceput().getYear());
                            service.update(lst[i], temp);
                        } else if (data_finall.getDay() >= lst[i].get_data_sfarsit().getDay()) {
                            temp = lst[i];
                            temp.get_data_sfarsit().setDay(lst[i].get_data_sfarsit().getDay() -
                                                           (data_finall.getDay() - data_inceputt.getDay()));
                            service.update(lst[i], temp);
                        } else if (data_finall <= lst[i].get_data_sfarsit() &&
                                   data_inceputt >= lst[i].get_data_inceput()) {
                            temp = lst[i];
                            if (data_inceputt >= lst[i].get_data_inceput())
                                temp.get_data_sfarsit().setDay(data_inceputt.getDay());
                            else if (data_inceputt == lst[i].get_data_inceput() &&
                                     data_finall == lst[i].get_data_sfarsit()) {
                                temp.get_data_inceput().setDay(0);
                                temp.get_data_sfarsit().setDay(0);
                            }
                            service.update(lst[i], temp);

                        }
                        ok = 1;
                    }
        }


    }

}
*/

void UI::rezervari() {
    cout << endl;
    string oras;
    Date data_inceputt, data_finall;
    cout << "Introduceti numele orasului in care doriti sa rezervati un hotel:";
    cin >> oras;
    cout << "Introduceti data de inceput: ";
    cin >> data_inceputt;
    cout << "Introduceti data finala: ";
    cin >> data_finall;
    int lungime = 0;
    Hotel *lst = service.rezervare(oras, data_inceputt, data_finall, lungime);
    if (lungime == 0)
        cout << "Nu exista rezervari!";
    else {
        int option = -1;
        int ok = 0;
        while (option != lungime && ok == 0) {
            for (int i = 0; i < lungime; i++)
                cout << i << ") " << lst[i].get_nume() << endl << " Data inceput: " << lst[i].get_data_inceput()
                     << " Data final : "
                     << lst[i].get_data_sfarsit() << endl;
            cin >> option;
            if (option > lungime)
                cout << "Hotel invalid!";
            else
                for (int i = 0; i < lungime; i++)
                    if (option == i) {
                        service.update_dates(lst[i], data_inceputt, data_finall);
                        ok = 1;
                    }
        }


    }

}


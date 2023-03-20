
#include "Service.h"
#include <string>

Service::Service() {

}

void Service::setrepository(string filename) {
    this->repo.set_repo(filename);
}

Hotel *Service::read() {
    return repo.get_all();
}

void Service::adauga(Hotel &hotel) {
    repo.adaugare(hotel);
}

void Service::sterge(Hotel &hotel) {
    repo.stergere(hotel);
}

int Service::lungime() {
    return repo.get_length();
}

void Service::modificare(Hotel &old_hotel, Hotel &new_hotel) {
    repo.update(old_hotel, new_hotel);
}

void Service::cautare_hotel_oras(string Oras) {
    for (int i = 0; i < repo.get_length(); i++)
        if (repo.getAll()[i].get_oras() == Oras)
            cout << repo.getAll()[i] << endl;
}

Hotel *Service::cautare_hotel_oras_1(const string &Oras, int &lungime) {
    Hotel *lst = new Hotel[20];
    int j = 0;
    for (int i = 0; i < repo.get_length(); i++)
        if (repo.getAll()[i].get_oras() == Oras)
            lst[j] = repo.getAll()[i], j++;
    lungime = j;
    return lst;
}


void Service::update_dates(Hotel &hot, Date data_inceput, Date data_final) {
    Hotel temp;
    temp = hot;
    if(hot.get_data_inceput() == data_inceput && data_final <=hot.get_data_sfarsit())
        temp.set_day_inceput(data_final.getDay() +1),repo.update(hot,temp);
    else if(hot.get_data_inceput() <= data_inceput && data_final ==hot.get_data_sfarsit())//ikkk
        temp.set_day_inceput(data_inceput.getDay() -1),repo.update(hot,temp);
    else if (hot.get_data_inceput() <= data_inceput && data_final <=hot.get_data_sfarsit() )
        temp.set_day_sfarsit(data_inceput.getDay()), repo.update(hot, temp);
    else if (data_final.getDay() <= hot.get_data_inceput().getDay())
        temp.set_day_inceput(hot.get_data_inceput().getDay() + (data_final.getDay() - data_inceput.getDay()) +1),repo.update(hot,temp);
    else if(data_inceput.getDay()>=hot.get_data_sfarsit().getDay())
        temp.set_day_sfarsit(hot.get_data_sfarsit().getDay()-(data_final.getDay()-data_inceput.getDay())-1),repo.update(hot,temp);
    else if(data_inceput.getDay()<=hot.get_data_inceput().getDay() && data_final.getDay()>=hot.get_data_inceput().getDay())
        temp.set_day_inceput(hot.get_data_inceput().getDay() + (data_final.getDay() - data_inceput.getDay()) +1),repo.update(hot,temp);
    else if(data_inceput.getDay()<=hot.get_data_sfarsit().getDay() && data_final.getDay()>=hot.get_data_sfarsit().getDay())
        temp.set_day_sfarsit(hot.get_data_sfarsit().getDay()-(data_final.getDay()-data_inceput.getDay())-1),repo.update(hot,temp);
}


Hotel *Service::rezervare(string oras, Date data_inceput, Date data_sfarist, int &lungime) {
    Hotel *lst = new Hotel[30];
    Hotel *lst_2 = new Hotel[30];
    Hotel *lst_3 = new Hotel[30];
    int interval_user = data_sfarist.getDay() - data_inceput.getDay();
    int j = 0;
    int k = 0;
    int l = 0;
    for (int i = 0; i < repo.get_length(); i++) {
        int interval_hotel =
                repo.getAll()[i].get_data_sfarsit().getDay() - repo.getAll()[i].get_data_inceput().getDay();
        if (repo.getAll()[i].get_oras() == oras && repo.getAll()[i].get_data_sfarsit() >= data_inceput &&
            repo.getAll()[i].get_data_inceput() <= data_sfarist &&
            interval_user <= interval_hotel
                ) {
            lst[j] = repo.getAll()[i];
            j++;
        } else if (repo.getAll()[i].get_oras() == oras &&
                   interval_user <= interval_hotel &&
                   (abs(repo.getAll()[i].get_data_inceput().getDay() - data_inceput.getDay()) <= 3)
                ) {
            lst_2[k] = repo.getAll()[i];
            k++;
        } else if (repo.getAll()[i].get_oras() == oras &&
                   interval_user <= interval_hotel &&
                   (abs(data_sfarist.getDay() - repo.getAll()[i].get_data_sfarsit().getDay()) <= 3)) {
            lst_3[l] = repo.getAll()[i];
            l++;
        }
    }
    if (j != 0) {
        lungime = j;
        return lst;
    } else if (k != 0) {
        lungime = k;
        return lst_2;
    } else if (l != 0) {
        lungime = l;
        return lst_3;
    } else
        lungime = 0;
    return lst;
}

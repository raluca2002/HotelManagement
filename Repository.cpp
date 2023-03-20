
#include "Repository.h"

Repository::Repository() {
    this->length = 0;
    this->capacity = 20;
    this->hoteluri = new Hotel[20];
}

Repository::Repository(const Repository &Repo) {
    this->capacity = Repo.capacity;
    this->length = Repo.length;
    this->hoteluri = new Hotel[this->capacity];
    for (int i = 0; i < this->length; i++)
        this->hoteluri[i] = Repo.hoteluri[i];
}

void Repository::adaugare(const Hotel &S) {
    this->hoteluri[length++] = S;
}

void Repository::update(Hotel &old_hotel, Hotel &new_hotel) {
    for (int i = 0; i < length; i++)
        if (hoteluri[i] == old_hotel)
            hoteluri[i] = new_hotel;
}

void Repository::stergere(Hotel &hotel) {
    int i = 0, j = 0;
    Hotel *new_hotel = new Hotel[capacity];
    while (i < length) {
        if (this->hoteluri[i] != hotel)
            new_hotel[j++] = hoteluri[i];
        i++;
    }
    delete[] this->hoteluri;
    this->length = j;
    this->hoteluri = new_hotel;
}

Hotel *Repository::get_all() {
    return this->hoteluri;
}

int Repository::get_length() {
    return this->length;
}

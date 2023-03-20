#include "RepoFile.h"


/*RepoInFile::RepoInFile(string filename) {
    this->fileName = filename;
}*/
RepoInFile::RepoInFile() {
}
void RepoInFile::adaugare(Hotel &hot) {
    Repository::adaugare(hot);
    //loadFile();
    saveToFile();
}

void RepoInFile::stergere(Hotel &hot) {
    Repository::stergere(hot);
    saveToFile();
}

void RepoInFile::update(Hotel &old_hotel, Hotel &new_hotel) {
    Repository::update(old_hotel, new_hotel);
    saveToFile();
}

Hotel *RepoInFile::getAll() {
    return Repository::get_all();
}

void RepoInFile::clearFile() {
    ofstream f(this->fileName);
    f << "";
}

void RepoInFile::saveToFile() {

    if (!this->fileName.empty()) {
        ofstream f(this->fileName);
        for (int i = 0; i < this->get_length(); i++) {
            f << this->getAll()[i];
        }
        f.close();
    }
}

void RepoInFile::set_repo(string &filename) {
    this->fileName = filename;
}

void RepoInFile::loadFile() {
    if(!this->fileName.empty()) {
        ifstream f(this->fileName);
        string Str_cod_unic;
        int cod_unic;
        string Str_nume_hotel;
        string nume_hotel;
        string Str_nume_oras;
        string nume_oras;
        string Str_inceput;
        Date inceput;
        string Str_final;
        Date final;
        while (!f.eof())
        {

            f>>Str_cod_unic;f.get();f>>cod_unic;
            f>>Str_nume_oras>>nume_oras;
            f>>Str_nume_hotel>>nume_hotel;
            f>>Str_inceput;f>>inceput;
            f>>Str_final;f>>final;
            bool ok = false;
            for (int i = 0;i< this->get_length();i++)
                //if (a.getId() == id) { ok = true; }
                if (this->getAll()[i].get_cod()==cod_unic) { ok = true; }
            if(!ok) {
                Hotel hote(cod_unic,nume_hotel,nume_oras,inceput,final);
                this->adaugare(hote);
            }

        }
        f.close();
    }
}

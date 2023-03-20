
#ifndef LAB9_10_REPOFILE_H
#define LAB9_10_REPOFILE_H

#include "Repository.h"
#include "RepoFile.h"
#include <bits/stdc++.h>
#include <fstream>
#include "Repository.h"
#include <cstring>


using namespace std;


class RepoInFile: public Repository{
private:
    string fileName;
public:
    //explicit RepoInfile(string fileName) : Repository(){};
    //explicit RepoInFile(string fileName);
    explicit RepoInFile();
    void set_repo(string& filename);
    void adaugare(Hotel &hot);
    void stergere(Hotel&);
    void update(Hotel &old_hotel, Hotel &new_hotel);
    Hotel * getAll();
    void loadFile();
    void saveToFile();
    void clearFile();
};

#endif //LAB9_10_REPOFILE_H

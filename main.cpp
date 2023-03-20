#include <iostream>
#include "Hotel.h"
#include "Repository.h"
#include "Date.h"
#include "Tests.h"
#include "Service.h"
#include "UI.h"
#include "RepoFile.h"
int main() {
   /* tests();
    repo_tests();*/
    test2();
    service_tests();
    //Repository repo;
    RepoInFile repo;
    Service service;
    service.setrepository("bogdan");
    UI ui(repo,service);
    ui.show_menu();
    return 0;
}

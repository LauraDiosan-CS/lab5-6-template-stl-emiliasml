#include <iostream>
#include "Tests.h"
#include "UI.h"
#include "RepoFile.h"
using namespace std;

//void initService(Service& s) {
//    RepoFile r;
//    r.loadFromFile("Cars.txt");
//    s.setRepo(r);
//}

int main()
{
    cout << "Hello" << endl;
    runTests();
    cout << "everything looks good :)" <<endl;
    Service serv;
    RepoFile r;
    r.loadFromFile("Cars.txt");
    serv.setRepo(r);
    showUI(serv);
    return 0;
}
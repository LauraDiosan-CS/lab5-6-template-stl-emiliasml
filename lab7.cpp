#include <iostream>
#include "Tests.h"
#include "UI.h"
#include "RepoFile.h"
using namespace std;

int main()
{
    cout << "Hello" << endl;
    runTests();
    cout << "tests are ok :)" <<endl;

    Service serv;
    RepoFile r;
    r.loadFromFile("Cars.txt");
    serv.setRepo(r);
    showUI(serv);

    return 0;
}
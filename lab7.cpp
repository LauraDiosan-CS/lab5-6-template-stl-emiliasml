#include <iostream>
#include "Tests.h"
#include "UI.h"
using namespace std;

int main()
{
    cout << "Hello" << endl;
    runTests();
    cout << "everything looks good :)" <<endl;
    Service serv;
    showUI(serv);
    return 0;
}
#include <iostream>
#include <string>
#include <cstdlib>
#include "forum.h"
using namespace std;

int main() {
    srand(time(NULL));
    string d = "--------------------------------------------------------------------------------\n";

    forum F("Object oriented programming");                     //1) creating the forum

    cout << endl << d << endl;
    cout << "Printing Forum By Creator:" << endl;
    F.PrintSorted();                                            //2) printing the forum sorted by creator
}
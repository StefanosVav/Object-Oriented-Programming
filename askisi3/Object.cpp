#include "Object.h"
#include "String.h"
#include <iostream>
using namespace std;

int ID = 1;

Object::Object() {
    cout << "Object created" << endl;
    id = ID++;
}

Object::~Object() {
    cout << "Object about to be destroyed!" << endl;
}

bool Object::identical(Object *ob) const {
    return ob == this;
}

int Object::getID() const {
    return id;
};


//CLONE ENCRYPT AND PRINT FUNCTION

void clone_encrypt_and_print(Object* ob){
    srand(time(NULL));
    Object* ob2 = ob->clone();
    if(ob->equal(ob2))
        cout << "Objects are equal!" << endl;
    else
        cout << "Objects are not equal!" << endl;

    if(ob->identical(ob2))
        cout << "Objects are identical!" << endl;
    else
        cout << "Objects are not identical!" << endl;

    cout << "Using the toString function for the objects: " << endl;
    String a(ob->toString());
    String b(ob2->toString());

    a.print();
    b.print();

    cout << endl << "Updating random characters in the String form of the second object: " << endl;

    for(int i=0; i<b.length(); i++)
    {
        if(rand()%2)
            b.updateAt(i, rand()%94 + 32);
    }

    a.print();
    b.print();

    a.concat(b);
    cout << endl << "Using the concat function for the 2 strings. " << endl;
    cout << "Length after concat is: " << a.length() << endl;

    cout << endl << "Middle character(s) of the string after concat: ";
    if(a.length()%2 == 0)
        cout << a.at(a.length()/2 - 1) << ", " << a.at(a.length()/2) << endl;
    else
        cout << a.at(a.length()/2) << endl;

    a.clear();
    cout << "Length after clearing the string is: " << a.length() << endl;
}
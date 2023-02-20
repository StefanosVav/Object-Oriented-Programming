#include "post.h"
#include "date.h"
#include <iostream>
#include <string>
using namespace std;

//FUNCTIONS FOR POST

post::post(int i, string t, string c, date d, string txt)
        : id(i), title(t), creator(c), doc(d), text(txt){

    cout << "Post no." << id << " was just created: " << "'" << title << "'" << " (by " << creator << ")" << " - " << doc.GetDay() << "/" << doc.GetMonth() << "/" << doc.GetYear() << endl;
}

post::~post(){
    cout << "Post no." << id << " is about to be destroyed" << endl;
}

void post::PrintPost() const {
    cout << "Post no." << id << ": " << "'" << title << "'" << " (by " << creator << ")" << " - " << doc.GetDay() << "/" << doc.GetMonth() << "/" << doc.GetYear() << endl;
    cout << text << endl << endl;
}

int post::GetID() const{
    return id;
}

string post::getCreator() const{
    return creator;
}
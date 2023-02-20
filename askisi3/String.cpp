#include <string>
#include <iostream>
#include "String.h"
using namespace std;

String::String(string s):
str(s)
{
    cout << "String created!" << endl;
}

String::~String() {
    cout << "String about to be destroyed!" << endl;
}

int String::length() const {
    return (int)str.length();
}

void String::clear() {
    str.clear();
}

void String::concat(String &s) {
    str = str + s.get();
}

char String::at(int i) const {
    return str[i];
}

void String::updateAt(int i, char c) {
    str[i] = c;
}

void String::print() const {
    cout << str << endl;
}

string String::get() const{
    return str;
}

bool String::equal(Object *S) const {
    String* sp = dynamic_cast<String *>(S);
    if(sp==NULL)
        return false;
    else
        return (sp->getID() == this->id && sp->str == this->str);
}

Object* String::clone() const {
    String *sp;
    sp = new String(*this);
    return sp;
}

String String::toString() const {
    String toS(str + to_string(id));
    return toS;
}
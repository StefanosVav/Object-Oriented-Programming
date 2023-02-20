#ifndef STRING_H
#define STRING_H

#include <string>
#include "Object.h"
using namespace std;

class String: public Object {
    string str;
public:
    String(string);
    ~String();
    int length() const;
    void clear();
    void concat(String &);
    char at(int) const;
    void updateAt(int, char);
    void print() const;

    string get() const;

    bool equal(Object*) const;
    Object* clone() const;
    String toString() const;
};


#endif

#ifndef OBJECT_H
#define OBJECT_H

#include "time.h"

extern int ID;
class String;

using namespace std;

class Object {
protected:
    int id;
public:
    Object();
    ~Object();

    virtual bool equal(Object*) const = 0;
    virtual Object* clone() const = 0;
    virtual String toString() const = 0;
    bool identical(Object* ob) const;
    int getID() const;
};

void clone_encrypt_and_print(Object* ob);

#endif

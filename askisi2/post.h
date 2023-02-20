#ifndef POST_H
#define POST_H
#include <iostream>
#include <string>
#include "date.h"

using namespace std;

class post{
public:
    post(int, string, string, date, string);
    ~post();
    void PrintPost() const;
    int GetID() const;
    string getCreator() const;
private:
    int id;
    string title;
    string creator;
    date doc;        //doc stands for date of creation
    string text;
};

#endif

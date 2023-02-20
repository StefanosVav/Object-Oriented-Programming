#ifndef THREAD_H
#define THREAD_H
#include <iostream>
#include <string>
#include "date.h"
#include "btree.h"

class post;

using namespace std;

class thread{
public:
    thread(string, string, int, int, int);
    ~thread();
    void PrintThreadSubj() const;
    string GetSubject() const;
    void PrintThread() const;
    void PrintThreadPost(int) const;
    void PrintRandom() const;
    void InsertPosts(btree *);
private:
    int K;                  //number of posts in thread
    string subject;
    string creator;
    date doc;        //doc stands for date of creation
    post **P;
};

#endif

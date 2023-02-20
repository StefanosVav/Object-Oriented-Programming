#ifndef FORUM_H
#define FORUM_H
#include <iostream>
#include <string>
#include "date.h"
class thread;

using namespace std;

extern int ID;
extern string phrases[10];
extern string users[12];

class forum{
public:
    forum(string);
    ~forum();
    void PrintForum() const;
    void PrintForumThread(string) const;
    void PrintForumPost(int) const;
    void PrintRandomPosts() const;
    void PrintSorted();
private:
    int N;          //number of threads in forum
    string title;
    thread **T;
};


#endif

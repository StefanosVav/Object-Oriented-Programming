#include "forum.h"
#include "thread.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//GLOBAL VARIABLES AND ARRAYS

int ID = 1;             //increasing global extern variable used for setting each post's id
string phrases[10] = {"Concerning lists and arrays",
                      "Information concerning this thread",
                      "About this exercise",
                      "Could you explain the first question of the exercise",
                      "Read the notes carefully",
                      "You are free to use any method for this part",
                      "Composition and inheritance",
                      "Structures and classes",
                      "I have a question about note no.4",
                      "Relations between classes" };

string users[12] = {"Giorgos", "Giannis", "Kostas", "Dimitris", "Antonis", "Thanos", "Maria", "Konstantina", "Anna", "ELeni", "Dimitra", "Ioanna"};


//FUNCTIOS FOR FORUM

forum::forum(string t)
        :title(t){

    N = rand()%3 + 2;    	//threads per forum (2-4)

    cout << "--Forum with title: " << "'" << title << "'" << " has just been created" << endl;
    T = new thread*[N];
    T[0] = new thread("Rules and useful information", users[rand()%12], 1+rand() % 31, 1+rand() % 12, 2019);
    for (int i = 1; i<N; i++){
        char num = '1' + i-1;
        string n(1,num);
        T[i] = new thread("Exercise "+n, users[rand()%12], 1+rand() % 31, 1+rand() % 12, 2019);
    }
}

forum::~forum() {
    for (int i = 0; i < N; ++i)
    {
        delete T[i];
    }
    delete[] T;
    cout << "--Forum with title: " << "'" << title << "'" << " is about to be destroyed" << endl;
}

void forum::PrintForum() const  {
    cout << endl << "Forum '" << title << "':" << endl;
    for(int i=0; i<N; i++){
        T[i]->PrintThreadSubj();
    }
    cout << endl;
}

void forum::PrintForumThread(const string GS) const {       //GS stands for Given Subject
    for(int i=0; i<N; i++){
        if(GS == T[i]->GetSubject()){
            T[i]->PrintThread();
        }
    }
}

void forum::PrintForumPost(const int id) const{
    for(int i=0; i<N; i++){
        T[i]->PrintThreadPost(id);
    }
}

void forum::PrintRandomPosts() const{
    for(int i=0; i<N; i++){
        T[i]->PrintRandom();
    }
}

void forum::PrintSorted() {
    btree CreatorTree(T[0]);                    //Creating a tree from the first thread
    for(int i=1; i<N; i++){
        btree ThreadTree(T[i]);                 //Creating tree from each thread
        CreatorTree.enhance(ThreadTree);        //Enhancing the main tree from each ThreadTree
    }
    CreatorTree.inorder_print();                //Print the final tree
}



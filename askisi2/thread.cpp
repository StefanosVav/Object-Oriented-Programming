#include <iostream>
#include <string>
#include <cstdlib>
#include "thread.h"
#include "post.h"
#include "date.h"
#include "forum.h"
using namespace std;

//FUNCTIONS FOR THREAD

thread::thread(string s, string c, int d, int m, int y)
        :subject(s),
         creator(c),
         doc(d,m,y){

    K = rand()%8 + 3;    	//posts per thread (3-10)

    cout << endl << "-Thread with subject: " << "'" << subject << "'" << " has just been created" << " (" << doc.GetDay() << "/" << doc.GetMonth() << "/" << doc.GetYear()  << ")" << endl;
    P = new post*[K];
    date DateOfPost = doc;
    for (int i = 0; i<K; i++){
        P[i] = new post(ID++, phrases[rand()%10], users[rand()%12], DateOfPost, phrases[rand()%10]+"\n"+phrases[rand()%10]);
        DateOfPost.SetDate(DateOfPost.GetDay() + rand()%(32-DateOfPost.GetDay()), DateOfPost.GetMonth(), DateOfPost.GetYear());
    }

}

thread::~thread() {
    for (int i = 0; i < K; ++i)
    {
        delete P[i];
    }
    delete[] P;
    cout << "-Thread with subject: " << "'" << subject << "'" << " is about to be destroyed" << endl;
}

void thread::PrintThreadSubj() const{
    cout << "-" << subject << endl;
}

string thread::GetSubject() const{
    return subject;
}

void thread::PrintThread() const{
    cout << "Thread: '" << subject << "' by " << creator << " - " << doc.GetDay() << "/" << doc.GetMonth() << "/" << doc.GetYear() << endl;
    for(int i=0; i<K; i++){
        P[i]->PrintPost();
    }
    cout << endl;
}

void thread::PrintThreadPost(const int id) const{
    for (int i = 0; i < K; i++) {
        if (id == P[i]->GetID()) {
            P[i]->PrintPost();
        }
    }
}

void thread::PrintRandom() const{
    for (int i = 0; i < K; i++) {
        if (rand()%2) {
            P[i]->PrintPost();
        }
    }
}

void thread::InsertPosts(btree *CreatorTree) {
    for(int i=0; i<K; i++){
        CreatorTree->insert(P[i]);
    }
}

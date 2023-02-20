#include "String.h"
#include "Plane.h"
#include "Employee.h"
#include "Object.h"
#include <iostream>
using namespace std;

int main(){
    String a("James");
    String b("Sirius");
    String c("Remus");

    Plane MyPlane;

    SecurityEmployee SEM(a);
    MaintenanceEmployee MEM(b);
    CleaningEmployee CEM(c);

    cout << "-------------------------------------------------------" << endl << endl;

    MyPlane.process(SEM);
    cout << endl;
    MyPlane.process(MEM);
    cout << endl;
    MyPlane.process(CEM);
    cout << endl;

    if(MyPlane.ready_check())
        cout << "Plane ready to take off!!" << endl;
    else
        cout << "Plane not ready." << endl;

    cout << "-------------------------------------------------------" << endl;
    cout << "Using the clone_encrypt_and_print function for the plane: " << endl << endl;

    clone_encrypt_and_print(&MyPlane);

    cout << "-------------------------------------------------------" << endl << endl;
}
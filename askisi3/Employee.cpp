#include "Employee.h"
#include "PlaneComponent.h"
#include <iostream>
using namespace std;

//FUNCTIONS FOR EMPLOYEE

Employee::Employee(const String &a) : name(a) {
    cout << "Employee has been created!" << endl;
}

Employee::~Employee() {
    cout << "Employee about to be destroyed!" << endl;
}

String Employee::getName() {
    return name;
}

//FUNCTIONS FOR SECURITY EMPLOYEE

SecurityEmployee::SecurityEmployee(const String &s)
:Employee(s){

    cout << "Security Employee created!" << endl;
}

SecurityEmployee::~SecurityEmployee() {
    cout << "Security employee about to be destroyed!" << endl;
}

void SecurityEmployee::WorkOn(PlaneComponent* p) {
    p->setSWD();
}

void SecurityEmployee::Report(PassengerCompartment*) const {
    cout << "Passenger Compartment Security OK!" << endl;
}

void SecurityEmployee::Report(EquipmentCompartment*) const {
    cout << "Equipment Compartment Security OK!" << endl;
}

void SecurityEmployee::Report(CargoBay*) const {
    cout << "Cargo Bay Security OK!" << endl;
}

bool SecurityEmployee::equal(Object *ob) const {
    SecurityEmployee * se = dynamic_cast<SecurityEmployee *>(ob);
    if(se==NULL)
        return false;
    else
        return se->id == this->id && se->name.get() == this->name.get();
}

Object* SecurityEmployee::clone() const {
    SecurityEmployee *se;
    se = new SecurityEmployee(*this);
    return se;
}

String SecurityEmployee::toString() const {
    String toS(to_string(id) + name.get());
    return toS;
}


//FUNCTIONS FOR MAINTENANCE EMPLOYEE

MaintenanceEmployee::MaintenanceEmployee(const String &s)
: Employee(s){

    cout << "Maintenance Employee created!" << endl;
}

MaintenanceEmployee::~MaintenanceEmployee() {
    cout << "Maintenance employee about to be destroyed!" << endl;
}

void MaintenanceEmployee::WorkOn(PlaneComponent *p) {
    p->setMWD();
}

void MaintenanceEmployee::Report(PassengerCompartment*) const {}

void MaintenanceEmployee::Report(EquipmentCompartment*) const {
    cout << "Equipment Compartment Maintenance OK!" << endl;
}

void MaintenanceEmployee::Report(CargoBay*) const {
    cout << "Cargo Bay Maintenance OK!" << endl;
}

bool MaintenanceEmployee::equal(Object *ob) const {
    MaintenanceEmployee * me = dynamic_cast<MaintenanceEmployee *>(ob);
    if(me==NULL)
        return false;
    else
        return me->id == this->id && me->name.get() == this->name.get();
}

Object* MaintenanceEmployee::clone() const {
    MaintenanceEmployee *me;
    me = new MaintenanceEmployee(*this);
    return me;
}

String MaintenanceEmployee::toString() const {
    String toS(to_string(id) + name.get());
    return toS;
}


//FUNCTIONS FOR CLEANING EMPLOYEE

CleaningEmployee::CleaningEmployee(const String &s)
: Employee(s){

    cout << "Cleaning Employee created!" << endl;
}

CleaningEmployee::~CleaningEmployee() {
    cout << "Cleaning employee about to be destroyed!" << endl;
}

void CleaningEmployee::WorkOn(PlaneComponent *p) {
    p->setCWD();
}

void CleaningEmployee::Report(PassengerCompartment*) const {
    cout << "Passenger Compartment Cleaning OK!" << endl;
}

void CleaningEmployee::Report(EquipmentCompartment*) const {}

void CleaningEmployee::Report(CargoBay*) const {
    cout << "Cargo Bay Cleaning OK!" << endl;
}

bool CleaningEmployee::equal(Object *ob) const {
    CleaningEmployee * ce = dynamic_cast<CleaningEmployee *>(ob);
    if(ce==NULL)
        return false;
    else
        return ce->id == this->id && ce->name.get() == this->name.get();
}

Object* CleaningEmployee::clone() const {
    CleaningEmployee *ce;
    ce = new CleaningEmployee(*this);
    return ce;
}

String CleaningEmployee::toString() const {
    String toS(to_string(id) + name.get());
    return toS;
}
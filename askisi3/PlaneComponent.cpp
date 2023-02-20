#include "PlaneComponent.h"
#include "String.h"
#include <iostream>
using namespace std;

//FUNCTIONS FOR PLANE COMPONENT

PlaneComponent::PlaneComponent(string a)
: description(a), SecurityWorkDone(false), CleaningWorkDone(false), MaintenanceWorkDone(false) {

    cout << "Plane component created!" << endl;
}

PlaneComponent::~PlaneComponent() {
    cout << "Plane component about to be destroyed!" << endl;
}

bool PlaneComponent::getCWD() const { return CleaningWorkDone; }

bool PlaneComponent::getMWD() const{ return MaintenanceWorkDone; }

bool PlaneComponent::getSWD() const { return SecurityWorkDone; }

void PlaneComponent::setCWD() {
    CleaningWorkDone = true;
}

void PlaneComponent::setMWD() {
    MaintenanceWorkDone = true;
}

void PlaneComponent::setSWD() {
    SecurityWorkDone = true;
}

String PlaneComponent::getDescription() {
    return description;
}

//FUNCTIONS FOR PASSENGER COMPARTMENT

PassengerCompartment::PassengerCompartment(bool i)
: InnerPComp(i), PlaneComponent("This is a passenger compartment"){

    cout << "Passenger Compartment created!" << endl;
    if(InnerPComp)
        PCom = new PassengerCompartment(false);         //Allocate space for inner Passenger Compartment
    else
        PCom = NULL;
}

PassengerCompartment::~PassengerCompartment() {
    delete PCom;
    cout << "Passenger Compartment about to be destroyed!" << endl;
}

bool PassengerCompartment::ready_check() const {
    if(PCom!=NULL)
        return SecurityWorkDone && CleaningWorkDone && PCom->ready_check();
    else
        return SecurityWorkDone && CleaningWorkDone;
}

void PassengerCompartment::process(Employee &Emp) {
    if(PCom!=NULL) {
        PCom->process(Emp);
        Emp.WorkOn(this);
        Emp.Report(this);
    } else{
        Emp.WorkOn(this);
        Emp.Report(this);
    }
}

bool PassengerCompartment::equal(Object *ob) const {
    PassengerCompartment * pc = dynamic_cast<PassengerCompartment *>(ob);
    if(pc==NULL)
        return false;
    else
        return pc->id == this->id && pc->description.get() == this->description.get();
}

Object* PassengerCompartment::clone() const {
    PassengerCompartment *pc;
    new PassengerCompartment(*this);
    if(PCom!=NULL)
        pc->PCom = new PassengerCompartment(*this->PCom);
    return pc;
}

String PassengerCompartment::toString() const {
    return String(to_string(id) + description.get());
}

//FUNCTIONS FOR PRIVATE COMPARTMENT

PrivateCompartment::PrivateCompartment(string a)
: PlaneComponent(a){

    cout << "Private Compartment created!" << endl;
}

PrivateCompartment::~PrivateCompartment() {
    cout << "Private Compartment about to be destroyed!" << endl;
}

//FUNCTIONS FOR EQUIPMENT COMPARTMENT

EquipmentCompartment::EquipmentCompartment()
: PrivateCompartment("This is an equipment compartment"){

    cout << "Equipment Compartment created!" << endl;
}

EquipmentCompartment::~EquipmentCompartment() {
    cout << "Equipment Compartment about to be destroyed!" << endl;
}

bool EquipmentCompartment::ready_check() const {
    return SecurityWorkDone && MaintenanceWorkDone;
}

void EquipmentCompartment::process(Employee &Emp) {
    Emp.WorkOn(this);
    Emp.Report(this);
}

bool EquipmentCompartment::equal(Object *ob) const {
    EquipmentCompartment * pc = dynamic_cast<EquipmentCompartment *>(ob);
    if(pc==NULL)
        return false;
    else
        return pc->id == this->id && pc->description.get() == this->description.get();
}

Object* EquipmentCompartment::clone() const {
    EquipmentCompartment *pc;
    pc = new EquipmentCompartment(*this);
    return pc;
}

String EquipmentCompartment::toString() const {
    return String(to_string(id) + description.get());
}

//FUNCTIONS FOR CARGO BAY

CargoBay::CargoBay()
: PrivateCompartment("This is a Cargo Bay"){

    cout << "Cargo Bay created!" << endl;
    EC = new EquipmentCompartment;
}

CargoBay::~CargoBay() {
    delete EC;
    cout << "Cargo Bay about to be destroyed!" << endl;
}

bool CargoBay::ready_check() const {
    if(EC!=NULL)
        return SecurityWorkDone && CleaningWorkDone && MaintenanceWorkDone && EC->ready_check();
    else
        return SecurityWorkDone && CleaningWorkDone && MaintenanceWorkDone;
}

void CargoBay::process(Employee &Emp) {
    if(EC!=NULL) {
        EC->process(Emp);
        Emp.WorkOn(this);
        Emp.Report(this);
    }
    else{
        Emp.WorkOn(this);
        Emp.Report(this);
    }
}

bool CargoBay::equal(Object *ob) const {
    CargoBay * pc = dynamic_cast<CargoBay *>(ob);
    if(pc==NULL)
        return false;
    else
        return pc->id == this->id && pc->description.get() == this->description.get();
}

Object* CargoBay::clone() const {
    CargoBay *pc;
    pc = new CargoBay(*this);
    if(EC!=NULL)
        pc->EC = new EquipmentCompartment(*this->EC);
    return pc;
}

String CargoBay::toString() const {
    return String(to_string(id) + description.get());
}
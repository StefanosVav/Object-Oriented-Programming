#include "Plane.h"
#include <iostream>
using namespace std;

Plane::Plane()
: N(2), PassengerCapacity(200), PC(NULL), description("This is a plane"), title("Boeing 707"), EC(NULL) {

    cout << "Plane created!" << endl;
    PC = new PassengerCompartment*[N];
    for(int i = 0; i<N; i++){
        PC[i] = new PassengerCompartment(true);
    }
    EC = new EquipmentCompartment*[3];
    for(int i = 0; i<3; i++) {
        EC[i] = new EquipmentCompartment;
    }
}

Plane::~Plane() {
    for (int i = 0; i < N; ++i)
    {
        delete PC[i];
    }
    delete[] PC;
    for (int i = 0; i < 3; ++i)
    {
        delete EC[i];
    }
    delete[] EC;
    cout << "Plane about to be destroyed!" << endl;
}

String Plane::getTitle() const {
    return title;
}

String Plane::getDesc() const {
    return description;
}

int Plane::getPCapacity() const {
    return PassengerCapacity;
}

CargoBay Plane::getCargoB() const{
    return CargoB;
}

EquipmentCompartment* Plane::getEC() const{
    return *EC;
}

PassengerCompartment* Plane::getPCompartment() const {
    return *PC;
}

bool Plane::ready_check() const{
    bool PCR = true, ECR = true;    //PCR-ECR stand for Passenger-Equipment Compartment Ready
    for(int i = 0; i<N; i++){
        if(!PC[i]->ready_check()) {
            PCR = false;
        }
    }
    for(int i = 0; i<3; i++){
        if(!EC[i]->ready_check()) {
            ECR = false;
        }
    }
    return CargoB.ready_check() && ECR && PCR;
}

void Plane::process(SecurityEmployee &SE) {
    CargoB.process(SE);
    for(int i = 0; i<N; i++){
        PC[i]->process(SE);
    }
    for(int i = 0; i<3; i++) {
        EC[i]->process(SE);
    }
}

void Plane::process(MaintenanceEmployee &ME) {
    CargoB.process(ME);
    for(int i = 0; i<3; i++) {
        EC[i]->process(ME);
    }
}

void Plane::process(CleaningEmployee &CE) {
    CargoB.process(CE);
    for(int i = 0; i<N; i++){
        PC[i]->process(CE);
    }
}

bool Plane::equal(Object *ob) const {
    Plane * p = dynamic_cast<Plane *>(ob);
    if(p==NULL)
        return false;
    else
        return (p->id == this->id && p->description.get() == this->description.get() && p->title.get() == this->title.get() && p->PassengerCapacity == this->PassengerCapacity);
}

Object* Plane::clone() const {
    Plane *p;
    p = new Plane(*this);

    p->EC = new EquipmentCompartment*[3];           //Deep Copy
    for(int i = 0; i<N; i++){
        p->EC[i] = new EquipmentCompartment(*this->EC[i]);
    }

    p->PC = new PassengerCompartment*[N];
    for(int i = 0; i<N; i++){
        p->PC[i] = new PassengerCompartment(*this->PC[i]);
    }
    return p;
}

String Plane::toString() const {
    return String(to_string(id) + title.get() + description.get() + to_string(PassengerCapacity));
}
#ifndef PLANE_H
#define PLANE_H

#include "Object.h"
#include "String.h"
#include "PlaneComponent.h"
#include "Employee.h"

class Plane: public Object {
    String title;
    String description;
    int PassengerCapacity;
    CargoBay CargoB;
    EquipmentCompartment **EC;
    PassengerCompartment **PC;
    int N;          //Number of passenger compartments
public:
    Plane();
    ~Plane();
    String getTitle() const;
    String getDesc() const;
    int getPCapacity() const;
    CargoBay getCargoB() const;
    EquipmentCompartment *getEC() const;
    PassengerCompartment *getPCompartment() const;

    bool ready_check() const;
    void process(SecurityEmployee &);
    void process(MaintenanceEmployee &);
    void process(CleaningEmployee &);

    bool equal(Object*) const;
    Object* clone() const;
    String toString() const;


};


#endif

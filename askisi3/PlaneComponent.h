#ifndef PLANECOMPONENT_H
#define PLANECOMPONENT_H

#include "Object.h"
#include "Employee.h"
#include <string>
using namespace std;

class PlaneComponent : public Object{
protected:
    String description;
    bool SecurityWorkDone;
    bool MaintenanceWorkDone;
    bool CleaningWorkDone;
public:
    PlaneComponent(string);
    ~PlaneComponent();
    bool getSWD() const;          //SWD : SecurityWorkDone
    bool getMWD() const;          //MWD : MaintenanceWorkDone
    bool getCWD() const;          //CWD : CleaningWorkDone
    void setSWD();
    void setMWD();
    void setCWD();
    String getDescription();
    virtual bool ready_check() const = 0;
    virtual void process(Employee &) = 0;
};

class PassengerCompartment : public PlaneComponent{
    PassengerCompartment* PCom;
    bool InnerPComp;        //variable set TRUE if there is an inner Passenger Compartment inside another one **
public:
    PassengerCompartment(bool); //** this bool argument is used to determine whether there is an inner Passenger Compartment
    ~PassengerCompartment();
    bool ready_check() const;
    void process(Employee &);
    bool equal(Object*) const;
    Object* clone() const;
    String toString() const;
};

class PrivateCompartment : public PlaneComponent{
public:
    PrivateCompartment(string);
    ~PrivateCompartment();
};

class EquipmentCompartment : public PrivateCompartment{
public:
    EquipmentCompartment();
    ~EquipmentCompartment();
    bool ready_check() const;
    void process(Employee &);
    bool equal(Object*) const;
    Object* clone() const;
    String toString() const;
};

class CargoBay : public PrivateCompartment{
    EquipmentCompartment* EC;
public:
    CargoBay();
    ~CargoBay();
    bool ready_check() const;
    void process(Employee &);
    bool equal(Object*) const;
    Object* clone() const;
    String toString() const;
};

#endif

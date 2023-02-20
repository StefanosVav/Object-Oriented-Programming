#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "String.h"
class PlaneComponent;
class PassengerCompartment;
class EquipmentCompartment;
class CargoBay;

class Employee : public Object {
protected:
    String name;
public:
    Employee(const String &);
    ~Employee();
    virtual void WorkOn(PlaneComponent*) = 0;
    virtual void Report(PassengerCompartment*) const = 0;
    virtual void Report(EquipmentCompartment*) const = 0;
    virtual void Report(CargoBay*) const = 0;
    String getName();
};

class SecurityEmployee : public Employee{
public:
    SecurityEmployee(const String &);
    ~SecurityEmployee();
    void WorkOn(PlaneComponent*);
    void Report(PassengerCompartment*)const;
    void Report(EquipmentCompartment*)const;
    void Report(CargoBay*) const;

    bool equal(Object*) const;
    Object* clone() const;
    String toString() const;
};

class MaintenanceEmployee : public Employee{
public:
    MaintenanceEmployee(const String &);
    ~MaintenanceEmployee();
    void WorkOn(PlaneComponent*);
    void Report(PassengerCompartment*)const;
    void Report(EquipmentCompartment*)const;
    void Report(CargoBay*) const;

    bool equal(Object*) const;
    Object* clone() const;
    String toString() const;
};

class CleaningEmployee : public Employee {
public:
    CleaningEmployee(const String &);
    ~CleaningEmployee();
    void WorkOn(PlaneComponent*);
    void Report(PassengerCompartment*)const;
    void Report(EquipmentCompartment*)const;
    void Report(CargoBay*) const;

    bool equal(Object*) const;
    Object* clone() const;
    String toString() const;
};

#endif

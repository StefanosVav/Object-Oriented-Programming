package airplane;

abstract public class Employee {
    private String name;

    Employee(String name){
        this.name = name;
    }

    abstract public void WorkOn(PlaneComponent pc);
    abstract public void report(PassengerCompartment pc);
    abstract public void report(EquipmentCompartment ec);
    abstract public void report(CargoBay cb);

    public String getName() {
        return name;
    }
}

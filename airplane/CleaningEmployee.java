package airplane;

public class CleaningEmployee extends Employee {
    CleaningEmployee(String name) {
        super(name);
        System.out.println("Cleaning Employee created!");
    }

    @Override
    public void WorkOn(PlaneComponent pc) {
        pc.setCWD();
    }

    @Override
    public void report(PassengerCompartment pc) {
        System.out.println("Passenger Compartment Cleaning OK!");
    }

    @Override
    public void report(EquipmentCompartment ec) {
        //Cleaning employee does not work in equipment compartments
    }

    @Override
    public void report(CargoBay cb) {
        System.out.println("Cargo Bay Cleaning OK!");
    }

}

package airplane;

public class MaintenanceEmployee extends Employee {
    MaintenanceEmployee(String name) {
        super(name);
        System.out.println("Maintenance Employee created!");
    }

    @Override
    public void WorkOn(PlaneComponent pc) {
        pc.setMWD();
    }

    @Override
    public void report(PassengerCompartment pc) {
        //maintenance employee does not work on passenger compartments
    }

    @Override
    public void report(EquipmentCompartment ec) {
        System.out.println("Equipment Compartment Maintenance OK!");
    }

    @Override
    public void report(CargoBay cb) {
        System.out.println("Cargo Bay Maintenance OK!");
    }
}

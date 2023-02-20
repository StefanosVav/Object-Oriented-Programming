package airplane;

public class SecurityEmployee extends Employee {
    SecurityEmployee(String name) {
        super(name);
        System.out.println("Security Employee created!");
    }

    @Override
    public void WorkOn(PlaneComponent pc) {
        pc.setSWD();
    }

    @Override
    public void report(PassengerCompartment pc) {
        System.out.println("Passenger Compartment Security OK!");
    }

    @Override
    public void report(EquipmentCompartment ec) {
        System.out.println("Equipment Compartment Security OK!");
    }

    @Override
    public void report(CargoBay cb) {
        System.out.println("Cargo Bay Security OK!");
    }
}

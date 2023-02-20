package airplane;

public class EquipmentCompartment extends PrivateCompartment {
    EquipmentCompartment() {
        super("This is an Equipment Compartment");
    }

    @Override
    public boolean ready_check(){
        if(isSWD() && isMWD()) {
            System.out.println("Equipment Compartment READY!");
            return true;
        }
        else{
            return false;
        }
    }

    @Override
    public void process(Employee Emp) {
        Emp.WorkOn(this);
        Emp.report(this);
    }
}

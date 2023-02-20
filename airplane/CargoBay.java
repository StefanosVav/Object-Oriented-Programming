package airplane;

public class CargoBay extends PrivateCompartment {
    private EquipmentCompartment equipmentCompartment;
    CargoBay() {
        super("This is a Cargo Bay");
        equipmentCompartment = new EquipmentCompartment();
    }

    @Override
    public boolean ready_check(){
        if(isSWD() && isMWD() && isCWD() && equipmentCompartment.ready_check()) {
            System.out.println("Cargo Bay READY!");
            return true;
        }
        else{
            return false;
        }
    }

    @Override
    public void process(Employee Emp) {
        equipmentCompartment.process(Emp);
        Emp.WorkOn(this);
        Emp.report(this);
    }

}

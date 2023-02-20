package airplane;
import java.util.Random;

public class PassengerCompartment extends PlaneComponent {
    private PassengerCompartment passengerCompartment;
    private boolean InnerPComp;

    PassengerCompartment(boolean Inner) {
        super("This is a Passenger Compartment");
        InnerPComp = Inner;
        if(InnerPComp){
            Random rand = new Random();
            if(rand.nextInt()%2==1)
                passengerCompartment = new PassengerCompartment(false);
            else
                InnerPComp = false;
        }
    }

    @Override
    public boolean ready_check(){
        if(this.InnerPComp) {
            if (isSWD() && isCWD() && passengerCompartment.ready_check()) {
                System.out.println("Passenger Compartment READY!");
                return true;
            } else {
                return false;
            }
        }
        else{
            if (isSWD() && isCWD()) {
                System.out.println("Passenger Compartment READY!");
                return true;
            } else {
                return false;
            }
        }
    }

    @Override
    public void process (Employee Emp) {
        if(this.InnerPComp) {
            passengerCompartment.process(Emp);
        }
        Emp.WorkOn(this);
        Emp.report(this);
    }
}

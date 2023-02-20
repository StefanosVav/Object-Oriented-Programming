package airplane;
import java.util.Random;

public class Plane {
    private String description;
    private String title;
    private int PassengerCapacity;
    private CargoBay cargoBay;
    private EquipmentCompartment[] equipmentCompartments;
    private PassengerCompartment[] passengerCompartments;
    private Random rand = new Random();
    private int N = (rand.nextInt() & Integer.MAX_VALUE) % 4 + 2;               //number of passenger compartments

    Plane(){
        title = "Boeing 787 Dreamliner";
        description = "This is a plane";
        PassengerCapacity = 200;
        cargoBay = new CargoBay();
        equipmentCompartments = new EquipmentCompartment[3];
        for(int i = 0; i<3; i++){
            equipmentCompartments[i] = new EquipmentCompartment();
        }
        passengerCompartments = new PassengerCompartment[N];
        for(int i = 0; i<N; i++){
            passengerCompartments[i] = new PassengerCompartment(true);
        }
        System.out.println("Plane created!");

    }

    public String getDescription() {
        return description;
    }
    public String getTitle(){
        return title;
    }
    public int getPassengerCapacity() {
        return PassengerCapacity;
    }
    public CargoBay getCargoBay() {
        return cargoBay;
    }
    public EquipmentCompartment[] getEquipmentCompartments() {
        return equipmentCompartments;
    }
    public PassengerCompartment[] getPassengerCompartments() {
        return passengerCompartments;
    }

    public int getN(){
        return N;
    }

    public void ready_check(){
        boolean ECR = true, PCR = true;
        for(int i = 0; i<3; i++){
            if(!equipmentCompartments[i].ready_check())
                ECR = false;
        }
        for(int i = 0; i<N; i++){
            if(!passengerCompartments[i].ready_check())
                PCR = false;
        }
        if(cargoBay.ready_check() && ECR && PCR) {
            System.out.println("Plane ready to take off!!!");
        }
        else{
            System.out.println("Plane not ready.");
        }

    }

    public void process(SecurityEmployee se){
        cargoBay.process(se);
        for(int i = 0; i<3; i++){
            equipmentCompartments[i].process(se);
        }
        for(int i = 0; i<N; i++){
            passengerCompartments[i].process(se);
        }
    }

    public void process(MaintenanceEmployee me){
        cargoBay.process(me);
        for(int i = 0; i<3; i++){
            equipmentCompartments[i].process(me);
        }
    }

    public void process(CleaningEmployee ce){
        cargoBay.process(ce);
        for(int i = 0; i<N; i++){
            passengerCompartments[i].process(ce);
        }
    }

}


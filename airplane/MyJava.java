package airplane;

public class MyJava {
    public static void main(String []args){
        Plane plane = new Plane();
        System.out.println("Plane name: " + plane.getTitle());
        System.out.println("Plane Capacity: " + plane.getPassengerCapacity());
        System.out.println("Plane has " + plane.getN() + " main Passenger Compartments, which might have an inner Passenger Compartment of their own");
        System.out.println("________________________________________________________________________________");

        SecurityEmployee SEM = new SecurityEmployee("James");
        MaintenanceEmployee MEM = new MaintenanceEmployee("Sirius");
        CleaningEmployee CEM = new CleaningEmployee("Remus");

        System.out.println("\nSecurity Employee working:");
        plane.process(SEM);
        System.out.println("\nMaintenance Employee working:");
        plane.process(MEM);
        System.out.println("\nCleaning Employee working:");
        plane.process(CEM);

        System.out.println("________________________________________________________________________________");

        System.out.println("\nChecking if the plane is ready:");
        plane.ready_check();

    }
}

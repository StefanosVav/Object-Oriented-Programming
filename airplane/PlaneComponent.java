package airplane;

abstract public class PlaneComponent {

    private boolean SWD;
    private boolean MWD;
    private boolean CWD;

    private String description;

    PlaneComponent(String d) {
        description = d;
        SWD = MWD = CWD = false;
    }

    abstract public boolean ready_check();
    abstract public void process(Employee Emp);

    public String getDescription(){
        return description;
    }

    public void setSWD() {
        this.SWD = true;
    }

    public void setMWD() {
        this.MWD = true;
    }

    public void setCWD() {
        this.CWD = true;
    }

    public boolean isCWD() {
        return CWD;
    }

    public boolean isMWD() {
        return MWD;
    }

    public boolean isSWD() {
        return SWD;
    }
}



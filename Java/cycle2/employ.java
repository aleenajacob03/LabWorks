package cycle2;

class employee {
    int sal=10000;
    public void display()
    {
        System.out.println("Name of class is");   
    }
    public void calcSalary()
    {
        System.out.println("Salary of employee is "+sal);
    }
}
class engineer extends employee{
    int sal=20000;
}
public class employ{
    public static void main(String args[]) {
        engineer obj=new engineer();
        obj.calcSalary();
}
}

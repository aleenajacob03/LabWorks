package cycle2;
import java.util.*;
class employe {
    int age, phno,sal;
    String name,address;
    public void printSalary()
    {
        System.out.println("Salary is "+sal);
    }
}
class officer extends employe{
        String spectn;
}
class manager extends employe{
        String dept;
}
class employee{
public static void main(String args[])
    {
        officer O=new officer();
        manager M=new manager();
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter officer details\nName: ");
        O.name=sc.nextLine();
        System.out.print("Age: ");
        O.age=sc.nextInt();
        System.out.print("Address: ");
        O.address=sc.nextLine();
        System.out.print("Ph no.: ");
        O.phno=sc.nextInt();
        System.out.print("Salary: ");
        O.sal=sc.nextInt();
        System.out.print("Specializatione: ");
        O.spectn=sc.nextLine();
        System.out.print("Enter manager details\nName: ");
        M.name=sc.nextLine();
        System.out.print("Age: ");
        M.age=sc.nextInt();
        System.out.print("Address: ");
        M.address=sc.nextLine();
        System.out.print("Ph no.: ");
        M.phno=sc.nextInt();
        System.out.print("Salary: ");
        M.sal=sc.nextInt();
        System.out.print("Department: ");
        M.dept=sc.nextLine();
        O.printSalary();
        M.printSalary();
    }
}

package cycle2;
import java.util.*;
class employee {
    int sal,hours;
    void getInfo(int s,int h){
        this.sal=s;
        this.hours=h;
    }
    void AddSal(){
        if (sal<500)
            sal+=10;
    }
    void AddWork(){
        if (hours>6)
            sal+=5;
    }
public static void main(String args[]) {
        int sal,hours;
        employee emp=new employee();
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter salary: ");
        sal=sc.nextInt();
        System.out.print("Enter work hours: ");
        hours=sc.nextInt();
        emp.getInfo(sal,hours);
        emp.AddSal();
        emp.AddWork();
        System.out.println("Final salary: $"+emp.sal);
    }
}

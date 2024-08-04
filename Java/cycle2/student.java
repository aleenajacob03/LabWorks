package cycle2;
import java.util.*;
public class student {
    int age;
    String name,address;
    student(){
        name="unknown";
        age=0;
        address="not available";
    }
    void setInfo(String n,int a){
        this.name=n;
        this.age=a;
    }
    void setInfo(String na,int ag,String ad){
        this.name=na;
        this.age=ag;
        this.address=ad;
    }
    public static void main(String args[]) {
        int i,age;
        String name,add;
        Scanner sc=new Scanner(System.in);
        for (i=0;i<10;i++)
        {
            student stud=new student();
            System.out.println("Enter name: ");
            name=sc.nextLine();
            System.out.println("Enter age: ");
            age=sc.nextInt();
            System.out.println("Enter address: ");
            add=sc.nextLine();
            stud.setInfo(name,age,add);
        }
    }
}

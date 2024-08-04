package cycle2;
import java.util.*;
public class area {
    public static double Area(int r)
    {
        return (Math.PI*r*r);
    }
    public static int Area(int l,int b)
    {
        return (l*b);
    }
    public static double Area(int a,int b,int c)
    {
        int s=(a+b+c)/2;
        return (Math.sqrt(s*(s-a)*(s-b)));
    }
    public static void main(String args[])
    {
        int r,l,b,a,c;
        Scanner sc=new Scanner(System.in);
        System.out.print("Area of circle\nEnter radius: ");
        r=sc.nextInt();
        System.out.println("Area: "+Area(r));
        System.out.print("Area of rectangle\nEnter length and breadth: ");
        l=sc.nextInt();
        b=sc.nextInt();
        System.out.println("Area: "+Area(l,b));
        System.out.print("Area of triangle\nEnter sides: ");
        a=sc.nextInt();
        b=sc.nextInt();
        c=sc.nextInt();
        System.out.println("Area: "+Area(a,b,c));
    }
}

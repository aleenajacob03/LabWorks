package cycle2;
class rectangle {
    int l,b;
    public int area()
    {
        return (l*b);
    }
    public int perimeter() 
    {
        return (2*(l+b));
    }
    rectangle(int len,int bre)
    {
        l=len;
        b=bre;
    }
}
class square extends rectangle{
    square(int len, int bre) {
        super(len, bre);
    }
}
public class area_perimeter{
    public static void main(String args[]){
        rectangle r=new rectangle(10,20);
        square s=new square(5,5);
        System.out.println("Area of rectangle: "+ r.area());
        System.out.println("Perimeter of rectangle: "+r.perimeter());
        System.out.println("Area of square: "+s.area());
        System.out.println("Perimeter of square: "+s.perimeter());
    }
}

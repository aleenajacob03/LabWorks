package cycle2;
class degree {
    void getDegree(){
        System.out.println("I got a degree");
    }
}
class undergraduate extends degree{
    void getDegree(){
        System.out.println("I am an undergraduate");
    }
}
class postgraduate extends degree{
    void getDegree(){
        System.out.println("I am an postgraduate");
    }
}
public class print_degree{
    public static void main(String args[])
    {
        degree ob1=new degree();
        undergraduate ob2=new undergraduate();
        postgraduate ob3=new postgraduate();
        ob1.getDegree();
        ob2.getDegree();
        ob3.getDegree();
    }
}
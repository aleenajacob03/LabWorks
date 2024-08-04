package cycle2;
abstract class Shape {
    abstract int numberOfSides();
}
class Rectangle extends Shape{
    int numberOfSides(){
        return 4;
    }
}
class Triangle extends Shape{
    int numberOfSides(){
        return 3;
    }
}
class Hexagon extends Shape{
    int numberOfSides(){
        return 6;
    }
}
public class Sides{
    public static void main(String[] args) {
        Shape r=new Rectangle();
        Shape t=new Triangle();
        Shape h=new Hexagon();
        System.out.println("No.of sides of rectangle: "+r.numberOfSides());
        System.out.println("No.of sides of triangle: "+t.numberOfSides());
        System.out.println("No.of sides of hexagon: "+h.numberOfSides());
    }
}

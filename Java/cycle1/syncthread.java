import java.util.*;
class display{
    public void display(String str){
        System.out.println(str);
        try{
            Thread.sleep(1000);
        }
        catch(Exception e){
            System.out.println(e);
        }
    }
}
class Sthread extends Thread{
    String str;
    display obj;
    Sthread(display o,String s){
        obj=o;
        str=s;
        start();
    }
    public void run(){
        synchronized(obj){
            obj.display(str);
        }
    }
}
public class syncthread {
    public static void main(String[] args) {
        display d=new display();
        Sthread s1=new Sthread(d,"Hello");
        Sthread s2=new Sthread(d,"Welcome");
        Sthread s3=new Sthread(d,"How are you?");
    }
}

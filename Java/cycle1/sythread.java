import java.io.*; 
import java.lang.*; 
class Counter { 
    synchronized public void count(String tname) { 
        try{ 
            System.out.println("Starting Thread : " + tname); 
            for(int i = 5;i > 0;i--) 
            System.out.println("Counter : " + i); 
            System.out.println("Thread " + tname + " Exits"); 
        } 
        catch(Exception e) { 
            System.out.println(e); 
        } 
    } 
} 
class SThread extends Thread { 
    private Thread t; 
    private String tname; 
    Counter c; 
    SThread(String name, Counter Cn) { 
        tname = name; 
        c = Cn; 
    } 
    public void run() { 
        c.count(tname); 
    } 
} 
 
public class sythread {
    public static void main(String[] args) { 
    Counter Cn = new Counter(); 
    SThread t1 = new SThread("1",Cn); 
    SThread t2 = new SThread("2",Cn); 
    t1.start(); 
    t2.start(); 	
    } 
}

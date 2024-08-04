import java.lang.*; 
class Pthread implements Runnable{ 
    public void run() { 
        System.out.println("Thread running"); 
    } 
}
public class threadpriority{
    public static void main(String args[]){ 
        Thread t1 = new Thread(new Pthread()); 
        Thread t2 = new Thread(new Pthread());
        t1.setPriority(1); 
        t2.setPriority(2);
        System.out.println("Priority of Thread 1: "+t1.getPriority()+"\nPriority of Thread 2: "+t2.getPriority());
        t1.setPriority(t1.MAX_PRIORITY); 
        t2.setPriority(t2.MIN_PRIORITY); 
        System.out.println("After setting priority to maximum(T1) and minimum(T2)");
        System.out.println("Priority of Thread 1: "+t1.getPriority()+"\nPriority of Thread 2: "+t2.getPriority()); 
        System.out.println("Current Running Thread: "+Thread.currentThread().getName()); 
        System.out.println("Priority of "+Thread.currentThread().getName()+": "+Thread.currentThread().getPriority()); 
        System.out.println("Setting priority of current thread to 1"); 
        Thread.currentThread().setPriority(1); 
        System.out.println("Priority of "+Thread.currentThread().getName()+": "+Thread.currentThread().getPriority()); 
    } 
}

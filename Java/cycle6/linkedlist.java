import java.util.*;
public class linkedlist{
    class node{
        int data;
        node prev,next;
    }
    node ptr,head=null,tail=null;
    void display(){
        System.out.println("Values: ");
        for (ptr=head;ptr!=null;ptr=ptr.next)
            System.out.print(ptr.data+" ");
        System.out.println();
    }
    void insert(int item){
        node n=new node();
        if (head==null){
            head=tail=n;
            n.prev=null;
        }
        else{
            tail.next=n;
            n.prev=tail;
            tail=n;
        }
        n.data=item;
        n.next=null;
    }
    void delete(){
        if (head==null){
            System.out.println("Overflow");
            return;
        }
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter item: ");
        int item=sc.nextInt();
        for (ptr=head;ptr.data!=item && ptr!=null;ptr=ptr.next);
        if (ptr==null)
            System.out.println("Not found");
        else if (ptr==head==tail){
            head==tail==null;
        }
        else if (ptr==head){
            ptr.next.prev=null;
            head=ptr.next;    
        }
        else if (ptr==tail){
            ptr.prev.next=null;
            tail=ptr.prev;
        }
        else{
            ptr.prev.next=ptr.next;
            ptr.next.prev=ptr.prev;
        }
        display();
    }
    public static void main(String[] args){
        linkedlist ll=new linkedlist();
        Scanner sc=new Scanner(System.in);
        System.out.print("No.of items: ");
        int no=sc.nextInt();
        System.out.print("Enter values: ");
        for (int i=0;i<no;i++)
            ll.insert(sc.nextInt());
        ll.display();
        System.out.println("Deletion");
        ll.delete();
    }
}

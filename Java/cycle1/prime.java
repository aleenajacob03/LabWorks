package cycle1;
public class prime{
    public static void main(String args[])
    {
        int i,num=3,found=0;
        if (num==0 || num==1)
            System.out.println(num+" is not a prime number");
        else
        {
            for (i=2;i<(num/2);i++)
                if (num%i==0)
                {
                    System.out.println(num+" is not a prime number");
                    found=1;
                    break;
                }
            if (found==0)
                System.out.println(num+" is a prime number");
        }
    }
}
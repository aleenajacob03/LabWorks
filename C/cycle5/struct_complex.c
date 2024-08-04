#include <stdio.h>
struct complex{
    int rp;
    int ip;
};
struct complex read_c(int n)
{
    struct complex C;
    printf("Enter complex number %d:\n",n);
    printf("Enter real part: ");
    scanf("%d",&C.rp);
    printf("Enter imaginary part: ");
    scanf("%d",&C.ip);
    return C;
}
struct complex add_c(struct complex C1,struct complex C2)
{
    /*printf("Sum: %d+i%d\n",C1.rp+C2.rp,C1.ip+C2.ip);*/
    struct complex C_sum;
    C_sum.rp=C1.rp+C2.rp;
    C_sum.ip=C1.ip+C2.ip;
    return C_sum;
}
struct complex diff_c(struct complex C1,struct complex C2) 
{
    struct complex C_diff;
    C_diff.rp=C1.rp-C2.rp;
    C_diff.ip=C1.ip-C2.ip;
    return C_diff;
}
struct complex mult_c(struct complex C1,struct complex C2)
{
    struct complex C_mult;
    C_mult.rp=(C1.rp*C2.rp)-(C1.ip*C2.ip);
    C_mult.ip=(C1.rp*C2.ip)+(C1.ip*C2.rp);
    return C_mult;
}
void main()
{
    struct complex C1,C2,C3,C4,C5;
    C1=read_c(1);
    C2=read_c(2);
    C3=add_c(C1,C2);
    C4=diff_c(C1,C2);
    C5=mult_c(C1,C2);
    printf("Sum: %d+%di\n",C3.rp,C3.ip);
    printf("Difference: %d+%di\n",C4.rp,C4.ip);
    printf("Product: %d+%di\n",C5.rp,C5.ip);
}
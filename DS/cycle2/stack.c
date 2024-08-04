#include <stdio.h>
#include <string.h>
#include <math.h>
extern int top;
void push(char stack[],char item)
{
    top++;
    stack[top]=item;
}
char pop(char stack[])
{
    char item;
    item=stack[top];
    top--;
    return item;
}
int top=-1;
void main()
{
    int i=0,l=0,n,a,b;
    char Q[30],P[30],stack[20],eval[20];
    printf("Enter the expression: ");
    scanf("%s",Q);
    strcat(Q,")");
    push(stack,'(');
    while (Q[i]!='\0')
    {
        while (Q[i]!=')')
        {
            if ((Q[i]>='A' && Q[i]<='Z') || (Q[i]>='a' && Q[i]<='z'))
            {
                P[l]=Q[i];
                l++;
            }
            else
            {
                if (Q[i]=='/' || Q[i]=='*')
                {
                    if (stack[top]=='/' || stack[top]=='*' || stack[top]=='^')
                    {
                        P[l]=pop(stack);
                        l++;
                    }
                }
                else if (Q[i]=='+' || Q[i]=='-')
                {
                    if (stack[top]=='+' || stack[top]=='-' || stack[top]=='/' || stack[top]=='*' || stack[top]=='^')
                    {
                        P[l]=pop(stack);
                        l++;
                    }
                }
                push(stack,Q[i]);
            }
            i++;
        }
        while (stack[top]!='(')
        {
            P[l]=pop(stack);
            l++;
        }
        i++;
        top--;
    }
    P[l]='\0';
    printf("Postfix expression: %s\n",P);
    top=-1;
    for (i=0;P[i]!='\0';i++)
        if ((P[i]>='A' && P[i]<='Z') || (P[i]>='a' && P[i]<='z'))
        {
            printf("Enter %c: ",P[i]);
            scanf("%d",&n);
            push(eval,n);
        }
        else
        {
            a=pop(eval);
            b=pop(eval);
            if (P[i]=='+')
                push(eval,(b+a));
            else if (P[i]=='-')
                push(eval,b-a);
            else if (P[i]=='*')
                push(eval,b*a);
            else if (P[i]=='/')
                push(eval,b/a);
            else
                push(eval,pow(b,a));
        }
    printf("Evaluated value: %d\n",eval[0]);
}

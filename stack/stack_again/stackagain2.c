#include "t12.c"

int main()
{
    char a,b;

    while((a=getchar())!=EOF)
    {
        if(a-'0'>=0&&a-'0'<=9)//数字直接进入output数组中
            push1(a);
        else if(a=='+'||a=='-')//若是符号，则需遍历stack数组，将与其同优先级和更高优先级的符号放入output数组
        {
            b=pop();
            while(b=='-'||b=='+'||b=='*'||b=='/')
            {
                push1(b);
                b=pop();
            }
            if(b!='c')
                push(b);
            push(a);
        }else 
        if(a=='*'||a=='/')//* / 的遍历
        {
            b=pop();
            while(b=='*'||b=='/')
            {
                push1(b);
                b=pop();
            }
            if(b!='c')
                push(b);
            push(a);
        }else if(a==')')
        {
            b=pop();
            while(b!='(')
            {
                push1(b);
                b=pop();
            }
        }
        if(a=='(')
            push(a);   
    }
    a=pop();
    while(a!='c')
    {
        push1(a);
        a=pop();
    }
    pop1();

    system("pause");
    return 0;
}
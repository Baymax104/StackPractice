/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/3/2 14:59
*@Version
*/
#include "ArrayStack.h"
void createStackA(StackA *S)
{
    S->topOfStack=-1;//初始化
    int data;
    printf("请输入数据:(按-1结束输入)\n");
    while(1)
    {
        scanf("%d",&data);
        if(data==-1)
            break;
        pushA(data,S);
    }
    return;
}
void pushA(int data, StackA *S)
{
    if(S->topOfStack==MAXSIZE-1)
    {
        printf("栈已满!\n");
        return;
    }
    S->topOfStack++;
    S->data[S->topOfStack]=data;
    return;
}
int popA(StackA *S)
{
    int data;
    if(S->topOfStack==-1)
    {
        printf("栈为空!\n");
        return 0;
    }
    data=S->data[S->topOfStack];
    S->topOfStack--;
    return data;
}
void printStackA(const StackA *S)
{
    int i=S->topOfStack;
    printf("栈中数据为:");
    while(i!=-1)
    {
        printf("%d ",S->data[i]);
        i--;
    }
    printf("\n");
    return;
}
void projectA(StackA *S)
{
    int op;
    int data;
    int popData;
    do
    {
        printf("1)打印数据\n");
        printf("2)添加数据\n");
        printf("3)弹出栈顶数据\n");
        printf("4)检测栈是否为空\n");
        printf("5)检测栈是否为满\n");
        printf("6)退出\n");
        printf("请输入你的选择:\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printStackA(S);
                break;
            case 2:
                printf("请输入添加数据:\n");
                scanf("%d",&data);
                pushA(data,S);
                printStackA(S);
                break;
            case 3:
                popData=popA(S);
                printf("弹出数据为:%d\n",popData);
                printStackA(S);
                break;
            case 4:
                isEmptyA(S);
                break;
            case 5:
                isFullA(S);
                break;
            case 6:
                printf("Goodbye\n");
                return;
            default:
                break;
        }
    }while(1);
}
void isEmptyA(const StackA *S)
{
    if(S->topOfStack==-1)
        printf("栈为空!\n");
    else
        printf("栈不为空\n");
    return;
}
void isFullA(const StackA *S)
{
    if(S->topOfStack==MAXSIZE-1)
        printf("栈已满!\n");
    else
        printf("栈不为满!\n");
    return;
}


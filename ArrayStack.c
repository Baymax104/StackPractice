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
    S->topOfStack=-1;//��ʼ��
    int data;
    printf("����������:(��-1��������)\n");
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
        printf("ջ����!\n");
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
        printf("ջΪ��!\n");
        return 0;
    }
    data=S->data[S->topOfStack];
    S->topOfStack--;
    return data;
}
void printStackA(const StackA *S)
{
    int i=S->topOfStack;
    printf("ջ������Ϊ:");
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
        printf("1)��ӡ����\n");
        printf("2)�������\n");
        printf("3)����ջ������\n");
        printf("4)���ջ�Ƿ�Ϊ��\n");
        printf("5)���ջ�Ƿ�Ϊ��\n");
        printf("6)�˳�\n");
        printf("���������ѡ��:\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printStackA(S);
                break;
            case 2:
                printf("�������������:\n");
                scanf("%d",&data);
                pushA(data,S);
                printStackA(S);
                break;
            case 3:
                popData=popA(S);
                printf("��������Ϊ:%d\n",popData);
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
        printf("ջΪ��!\n");
    else
        printf("ջ��Ϊ��\n");
    return;
}
void isFullA(const StackA *S)
{
    if(S->topOfStack==MAXSIZE-1)
        printf("ջ����!\n");
    else
        printf("ջ��Ϊ��!\n");
    return;
}


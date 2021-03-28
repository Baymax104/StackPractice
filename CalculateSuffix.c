/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/3/2 15:12
*@Version
*/
#include "CalculateSuffix.h"
void pushS(CNode *head, int data)
{
    CNode *s=(CNode*)malloc(sizeof(CNode));
    s->data=data;
    s->next=head->next;
    head->next=s;
    return;
}
int popS(CNode *head)
{
    if(head->next==NULL)
    {
        printf("栈为空!\n");
        return 0;
    }
    CNode *temp=head->next;
    int data=temp->data;
    head->next=temp->next;
    free(temp);
    return data;
}
void scanExpression(char *expression,CNode *head)
{
    int i=0;
    int dataA,dataB;
    int result;
    while(expression[i]!='\0')
    {
        if(isdigit(expression[i]))
        {
            pushS(head, expression[i] - '0');
        }
        else
        {
            dataA=popS(head);
            dataB=popS(head);
            result=calculation(dataA,dataB,expression[i]);
            pushS(head, result);
        }
        i++;
    }
    return;
}
int calculation(int dataA,int dataB,char op)
{
    int result = 0;
    switch(op)
    {
        case '+':
            result=dataA+dataB;
            break;
        case '-':
            result=dataA-dataB;
            break;
        case '*':
            result=dataA*dataB;
            break;
        case '/':
            result=dataA/dataB;
            break;
        default:
            break;
    }
    return result;
}
void printStack(CNode *head)
{
    printf("结果为:");
    while(head->next)
    {
        head=head->next;
        printf("%d ",head->data);
    }
    printf("\n");
    return;
}


/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/3/2 14:55
*@Version
*/
#include "LinkedStack.h"
void pushL(LNode *head, int data)
{
    LNode *s=(LNode*)malloc(sizeof(LNode));
    s->data=data;
    s->next=head->next;
    head->next=s;
}
int popL(LNode *head)
{
    if(head->next==NULL)
    {
        printf("栈为空!\n");
        return 0;
    }
    LNode *temp=head->next;
    int data=temp->data;
    head->next=temp->next;
    free(temp);
    return data;
}
LNode *createStackL()
{
    LNode *head=(LNode*)malloc(sizeof(LNode));//栈顶
    head->next=NULL;
    int data;
    printf("请输入数据:(按-1结束输入)\n");
    while(1)
    {
        scanf("%d",&data);
        if(data==-1)
            break;
        pushL(head,data);
    }
    return head;
}
void printStackL(LNode *head)
{
    printf("栈中数据为:");
    while(head->next)
    {
        head=head->next;
        printf("%d ",head->data);
    }
    printf("\n");
}
void projectL(LNode *head)
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
        printf("5)退出\n");
        printf("请输入你的选择:\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printStackL(head);
                break;
            case 2:
                printf("请输入添加数据:\n");
                scanf("%d",&data);
                pushL(head,data);
                printStackL(head);
                break;
            case 3:
                popData=popL(head);
                printf("弹出数据为:%d\n",popData);
                printStackL(head);
                break;
            case 4:
                isEmptyL(head);
                break;
            case 5:
                printf("Goodbye\n");
                return;
            default:
                break;
        }
    }while(1);
}
void isEmptyL(LNode *head)
{
    if(head->next==NULL)
    {
        printf("栈为空!\n");
        return;
    }
    printf("栈不为空\n");
}


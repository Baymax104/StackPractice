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
        printf("ջΪ��!\n");
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
    LNode *head=(LNode*)malloc(sizeof(LNode));//ջ��
    head->next=NULL;
    int data;
    printf("����������:(��-1��������)\n");
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
    printf("ջ������Ϊ:");
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
        printf("1)��ӡ����\n");
        printf("2)�������\n");
        printf("3)����ջ������\n");
        printf("4)���ջ�Ƿ�Ϊ��\n");
        printf("5)�˳�\n");
        printf("���������ѡ��:\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printStackL(head);
                break;
            case 2:
                printf("�������������:\n");
                scanf("%d",&data);
                pushL(head,data);
                printStackL(head);
                break;
            case 3:
                popData=popL(head);
                printf("��������Ϊ:%d\n",popData);
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
        printf("ջΪ��!\n");
        return;
    }
    printf("ջ��Ϊ��\n");
}


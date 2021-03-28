#include"stdio.h"
#include"stdlib.h"
#include "LinkedStack.h"
#include "ArrayStack.h"
#include "CalculateSuffix.h"
#include "InfixToSuffix.h"
#include "SymbolMatch.h"
int main () {
    int op;
    LNode *Lhead;
    StackA stack;
    StackA *ptrStack=&stack;
    CNode *Chead=(CNode*)malloc(sizeof(CNode));
    Chead->next=NULL;
    char expression[100] = {'\0'};
    char infix[100] = {'\0'};//��׺ʽ
    char suffix[100] = {'\0'};//��׺ʽ
    INode *head=(INode*)malloc(sizeof(INode));
    head->next=NULL;
    char str[100];
    do {
        puts("1)����ջ");
        puts("2)����ջ");
        puts("3)�����׺���ʽ");
        puts("4)��׺���ʽת��Ϊ��׺���ʽ");
        puts("5)����ƥ��");
        puts("6)�˳�");
        printf("���������ѡ��:\n");
        scanf("%d", &op);
        getchar();
        switch (op) {
            case 1:
                Lhead=createStackL();
                projectL(Lhead);
                break;
            case 2:
                createStackA(ptrStack);
                projectA(ptrStack);
                break;
            case 3:
                printf("�������׺���ʽ:\n");
                scanf("%s", expression);
                scanExpression(expression,Chead);
                printStack(Chead);
                break;
            case 4:
                printf("��������׺���ʽ:\n");
                scanf("%s", infix);
                scanInfix(infix,head,suffix);
                printf("���Ϊ:");
                puts(suffix);
                break;
            case 5:
                printf("���������:\n");
                scanf("%s", str);
                match(str);
                break;
            case 6:
                printf("Goodbye\n");
                return 0;
            default:
                break;
        }
    } while (1);
}
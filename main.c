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
    char infix[100] = {'\0'};//中缀式
    char suffix[100] = {'\0'};//后缀式
    INode *head=(INode*)malloc(sizeof(INode));
    head->next=NULL;
    char str[100];
    do {
        puts("1)链表栈");
        puts("2)数组栈");
        puts("3)计算后缀表达式");
        puts("4)中缀表达式转换为后缀表达式");
        puts("5)括号匹配");
        puts("6)退出");
        printf("请输入你的选择:\n");
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
                printf("请输入后缀表达式:\n");
                scanf("%s", expression);
                scanExpression(expression,Chead);
                printStack(Chead);
                break;
            case 4:
                printf("请输入中缀表达式:\n");
                scanf("%s", infix);
                scanInfix(infix,head,suffix);
                printf("结果为:");
                puts(suffix);
                break;
            case 5:
                printf("请输入符号:\n");
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
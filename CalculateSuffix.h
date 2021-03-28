/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/3/2 15:05
*@Version
*/

#ifndef STACK_CALCULATESUFFIX_H
#define STACK_CALCULATESUFFIX_H

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct cnode
{
    int data;
    struct cnode *next;
}CNode;
void pushS(CNode *head, int data);
int popS(CNode *head);
void scanExpression(char *expression,CNode *head);
int calculation(int dataA,int dataB,char op);
void printStack(CNode *head);

#endif //STACK_CALCULATESUFFIX_H

/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/3/2 14:54
*@Version
*/

#ifndef STACK_LINKEDSTACK_H
#define STACK_LINKEDSTACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct lnode
{
    int data;
    struct lnode *next;
}LNode;

void pushL(LNode *head, int data);
int popL(LNode *head);
LNode *createStackL();
void printStackL(LNode *head);
void projectL(LNode *head);
void isEmptyL(LNode *head);

#endif //STACK_LINKEDSTACK_H

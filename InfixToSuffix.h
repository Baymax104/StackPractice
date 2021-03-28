/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/3/2 15:14
*@Version
*/

#ifndef STACK_INFIXTOSUFFIX_H
#define STACK_INFIXTOSUFFIX_H

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct inode
{
    char infixCharacter;
    struct inode *next;
}INode;

void pushI(INode *head, char infixCharacter);
char popI(INode *head);
void scanInfix(char *infix, INode *head, char *suffix);
int isHigher(char x,char y);
char top(INode *head);
int isEmptyI(INode *head);

#endif //STACK_INFIXTOSUFFIX_H

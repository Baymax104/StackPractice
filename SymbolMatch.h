/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/3/2 15:23
*@Version
*/

#ifndef STACK_SYMBOLMATCH_H
#define STACK_SYMBOLMATCH_H

#include<stdio.h>
#define MAXSIZE 100

typedef struct node{
    char data[MAXSIZE];
    int topOfStack;
}Stack;

void push(char data,Stack *stack);
char pop(Stack *stack);
int isEmpty(Stack *stack);
void match(char *str);

#endif //STACK_SYMBOLMATCH_H

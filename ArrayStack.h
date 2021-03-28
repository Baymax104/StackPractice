/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/3/2 14:58
*@Version
*/

#ifndef STACK_ARRAYSTACK_H
#define STACK_ARRAYSTACK_H

#include<stdio.h>
#define MAXSIZE 100

typedef struct stack
{
    int data[MAXSIZE];
    int topOfStack;
}StackA;

void pushA(int data,StackA *S);
int popA(StackA *S);
void createStackA(StackA *S);
void printStackA(const StackA *S);
void projectA(StackA *S);
void isEmptyA(const StackA *S);
void isFullA(const StackA *S);

#endif //STACK_ARRAYSTACK_H

/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/3/2 15:24
*@Version
*/
#include "SymbolMatch.h"
void push(char data,Stack *stack)
{
    stack->topOfStack++;
    stack->data[stack->topOfStack]=data;
    return;
}
char pop(Stack *stack)
{
    char data;
    data=stack->data[stack->topOfStack];
    stack->topOfStack--;
    return data;
}
int isEmpty(Stack *stack)
{
    if(stack->topOfStack==-1)
        return 1;
    return 0;
}
void match(char *str) {
    Stack stack;
    Stack *ptrStack=&stack;
    stack.topOfStack=-1;
    int i=0;
    while(str[i]!='\0'){
        if(str[i]=='('||str[i]=='['||str[i]=='{')
            push(str[i],ptrStack);
        else if(stack.data[stack.topOfStack]=='('&&str[i]==')')
            pop(ptrStack);
        else if(stack.data[stack.topOfStack]=='['&&str[i]==']')
            pop(ptrStack);
        else if(stack.data[stack.topOfStack]=='{'&&str[i]=='}')
            pop(ptrStack);
        i++;
    }
    if(isEmpty(ptrStack))
        printf("¿®∫≈∆•≈‰!\n");
    else
        printf("¿®∫≈≤ª∆•≈‰!\n");
}

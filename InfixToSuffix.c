/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/3/2 15:15
*@Version
*/
#include "InfixToSuffix.h"
void pushI(INode *head, char infixCharacter)
{
    INode *s=(INode*)malloc(sizeof(INode));
    s->infixCharacter=infixCharacter;
    s->next=head->next;
    head->next=s;
    return;
}
char popI(INode *head)
{
    if(head->next==NULL)
    {
        printf("栈为空!\n");
        return 0;
    }
    INode *temp=head->next;
    char infixCharacter=temp->infixCharacter;
    head->next=temp->next;
    free(temp);
    return infixCharacter;
}
void scanInfix(char *infix,INode *head,char suffix[])//传入字符数组以便修改
{
    int infixIndex=0;
    int suffixIndex=0;
    //char suffixStorage[100];//若形参传入的是指针则不能修改字符，用另一个字符数组存储用来修改字符
    while(infix[infixIndex]!='\0')//遍历中缀式的每个字符，对后缀式做操作
    {
        if(isdigit(infix[infixIndex]))
        {
            //suffixStorage[suffixIndex]=infix[infixIndex];
            suffix[suffixIndex]=infix[infixIndex];
            suffixIndex++;
        }
        else if(infix[infixIndex]==')')
        {
            while(top(head)!='(')
            {
                //suffixStorage[suffixIndex]=popI(head);
                suffix[suffixIndex]=popI(head);
                suffixIndex++;
            }
            popI(head);//弹出左括号
        }
        else
        {
            if(isEmptyI(head))
                pushI(head, infix[infixIndex]);
            else if(isHigher(infix[infixIndex],top(head)))
                pushI(head, infix[infixIndex]);
            else
            {
                while((!isEmptyI(head)) && (!isHigher(infix[infixIndex], top(head))))
                {
                    if(top(head)!='(')
                    {
                        //suffixStorage[suffixIndex]=popI(head);
                        suffix[suffixIndex]=popI(head);
                        suffixIndex++;
                    }
                    else
                        break;
                }
                pushI(head, infix[infixIndex]);
            }
        }
        infixIndex++;
    }
    while(!isEmptyI(head))
    {
        //suffixStorage[suffixIndex]=popI(head);
        suffix[suffixIndex]=popI(head);
        suffixIndex++;
    }
    return;
}
int isHigher(char x,char y)//判断符号优先级
{
    if((x=='(')&&((y=='+')||(y=='-')||(y=='*')||(y=='/')))
        return 1;
    else if(((x=='*')||(x=='/'))&&((y=='+')||(y=='-')))
        return 1;
    else
        return 0;
}
char top(INode *head)
{
    return head->next->infixCharacter;
}
int isEmptyI(INode *head)
{
    if(head->next==NULL)
        return 1;
    return 0;
}


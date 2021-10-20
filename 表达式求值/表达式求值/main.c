//
//  main.c
//  表达式求值
//
//  Created by wlc on 2021/6/2.
//

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MaxSize 100

typedef char ElemType;
typedef int TElemType;

typedef struct
{
    TElemType *data;
    ElemType *base;
    int topone;
    int toptwo;
    int len;
}SNode,*Stack;

void InitStack(Stack S)
{
    S->base=(ElemType *)malloc(MaxSize*sizeof(ElemType));
    S->data=(TElemType *)malloc(MaxSize*sizeof(TElemType));
    if(!S->base||!S->data)
    {
        exit(1);
    }
    S->topone=0;
    S->toptwo=0;
}

void Push(SNode *S,ElemType e)
{
    if(S->topone==MaxSize)
    {
        return ;
    }
    S->base[(S->topone)++]=e;
}


void Pop(SNode *S,ElemType *e)
{
    if(0==S->topone)
    {
        return;
    }
    *e=S->base[--(S->topone)];
}

ElemType GetTop(SNode *S)
{
    if(0!=S->topone)
    {
        return S->base[(S->topone)-1];
    }
    else
    {
        printf("栈已空\n");
        return 0;
    }
}
void Push_data(SNode *S,TElemType e)
{
    if(S->toptwo==MaxSize)
    {
        return ;
    }
    S->data[(S->toptwo)++]=e;
}


void Pop_data(SNode *S,TElemType *e)
{
    if(0==S->toptwo)
    {
        return;
    }
    *e=S->data[--(S->toptwo)];
}

TElemType GetTop_data(SNode *S)
{
    if(0!=S->toptwo)
    {
        return S->data[(S->toptwo)-1];
    }
    else
    {
        return 0;
    }
}

char Precede(char c1,char c2)
{
    int i=0,j=0;
    char op;
    char arr[8][8]={">><<<<>>",">><<<<>>",">>>><<>>",">>>><<>>",">>>>><>>","<<<<<<=!",">>>>>!>>","<<<<<<!="};
    switch(c1)
    {
        case '+': i=0;break;
        case '-': i=1;break;
        case '*': i=2;break;
        case '/': i=3;break;
        case '^': i=4;break;
        case '(': i=5;break;
        case ')': i=6;break;
        case '#': i=7;break;
    }
    switch(c2)
    {
        case '+': j=0;break;
        case '-': j=1;break;
        case '*': j=2;break;
        case '/': j=3;break;
        case '^': j=4;break;
        case '(': j=5;break;
        case ')': j=6;break;
        case '#': j=7;break;
    }
    op=arr[i][j];
    return op;
}

int Operate(int a,char operator,int b)
{
    if(operator=='+')
    {
        return a+b;
    }
    if(operator=='-')
    {
        return a-b;
    }
    if(operator=='*')
    {
        return a*b;
    }
    if(operator=='/')
    {
        return a/b;
    }
    if(operator=='^')
    {
        return pow(a,b);
    }
    return 0;
}

int main()
{
    SNode OPTR;//储存运算符
    SNode OPND;//储存数字
    char ch[31];
    int i=0;//用于循环
    char x;//接受括号
    int a,b;
    int m,f;
    char operator;
    InitStack(&OPTR);
    InitStack(&OPND);
    scanf("%s",ch);
    Push(&OPTR,'#');
    while(ch[i]!='#'||OPTR.base[OPTR.topone-1]!='#')
    {
        if(ch[i]>='0'&&ch[i]<='9')
        {
            m=atoi(&ch[i]);
            Push_data(&OPND,m);
            i++;
        }
        else if(ch[i]=='+'||ch[i]=='-'||ch[i]=='*'||ch[i]=='/'||ch[i]=='^'||ch[i]=='('||ch[i]==')'||ch[i]=='#')
        {
            printf("%c\n",Precede(OPTR.base[OPTR.topone-1],ch[i]));
            switch(Precede(OPTR.base[OPTR.topone-1],ch[i]))
            {
                case '<':
                    Push(&OPTR,ch[i]);
                    i++;
                    break;
                case '>':
                    Pop(&OPTR, &operator);
                    Pop_data(&OPND, &b);
                    Pop_data(&OPND, &a);
                    Push_data(&OPND,f=Operate(a,operator,b));
                    break;
                case '=':
                    Pop(&OPTR,&x);
                    printf("%c %c\n",x,ch[i]);
                    i++;
                    printf("%c\n",ch[i]);
                    break;
            }
        }
    }
    printf("%d\n",GetTop_data(&OPND));
}

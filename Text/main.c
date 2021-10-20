#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT  10
#define MAXBUFFER       10

typedef double ElemType;
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stackSize;
} SqStack;

void InitStack(SqStack *s)
{
    s->base = (ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
    if(s->base==NULL)
    {
        exit(0);
    }
    s->top=s->base;
    s->stackSize=STACK_INIT_SIZE;
}

void Push(SqStack *s,ElemType e)
{
    if((s->top-s->base) == s->stackSize)//栈满，追加空间。
    {
        s->base = (ElemType *)realloc(s->base,(s->stackSize+STACKINCREMENT)*sizeof(ElemType));
        if(!s->base)
        {
            exit(0);
        }
        s->top=s->base+s->stackSize;
        s->stackSize=s->stackSize+STACKINCREMENT;
    }
    *(s->top)=e;
    s->top++;
}
void Pop(SqStack *s,ElemType *e)
{
    if(s->base == s->top)
    {
        exit(0);
    }
    *e= *--(s->top);
}

int StackLength(SqStack s)
{
    return (s.top - s.base);
}

int main(void)
{
    SqStack s;
    ElemType e,d;
    char ch;
    int i=0,len=0;
    char str[MAXBUFFER];
    InitStack(&s);
    printf("请按照逆波兰表达式输入待计算数据，数据与数据之间用空格隔开，以#作为结束标志：");
    scanf("%c",&ch);
    while(ch!= '#')
    {
        //为了把字符转换成double型，自己做一个缓冲区
        while(isdigit(ch) || ch=='.')//isdigit()判断参数是否是数字
        {
            str[i++] = ch;
            str[i]='\0';
            if(i>=10)
            {
                printf("出错：输入的单个数据过大！\n");
                return -1;
            }
            scanf("%c",&ch);
            if(ch==' ')
            {
                d=atof(str);//将字符串转换为浮点型，在头文件stdlib
                Push(&s,d);
                i=0;
                break;
            }
        }
        switch(ch)
        {
            case '+':
                Pop(&s,&e);
                Pop(&s,&d);
                Push(&s,e+d);
                break;
            case '-':
                Pop(&s,&e);
                Pop(&s,&d);
                Push(&s,d-e);
                break;
            case '*':
                Pop(&s,&e);
                Pop(&s,&d);
                Push(&s,e*d);
                break;
            case '/':
                Pop(&s,&e);
                Pop(&s,&d);
                if(e!=0)
                {
                    Push(&s,d/e);
                }
                else
                {
                    printf("\n出错：除数为零！\n");
                    return -1;
                }
                break;
        }
        scanf("%c",&ch);
    }
    Pop(&s,&e);
    printf("\n最终的计算结果为：%lf\n",e);
    return 0;
    
}

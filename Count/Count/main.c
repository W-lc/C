//
//  main.c
//  Count
//
//  Created by wlc on 2021/6/23.
//

#include <stdio.h>
#include<stdlib.h>
#define MAX 100000
#define SIZE 1000
typedef struct
{
    char ch;
    int weight;
}Weight;

void Count(Weight *w)
{
    char str[MAX];
    gets(str);
    int i=0,j=0;
    int num=0;
    w=(Weight *)malloc(SIZE*sizeof(Weight));
    for(i=0;i<SIZE;i++)
    {
        w[i].ch='#';
        w[i].weight=0;
    }
    while(str[j]!='\0')
    {
        for(i=0;i<SIZE;i++)
        {
            if(w[i].ch=='#')
            {
                break;
            }
            if(w[i].ch==str[j])
            {
                w[i].weight++;
                break;
            }
        }
        if(w[i].ch=='#')
        {
            w[i].ch=str[j];
            w[i].weight++;
            num++;
        }
        j++;
    }
    for(i=0;i<num;i++)
    {
        printf("字符：%c,权值:%d\n",w[i].ch,w[i].weight);
    }
    printf("%d",num);
    //暴力计算
    /*char str[MAX];
    gets(str);
    int i=0;
    int f=34;
    *w=(Weight *)malloc(f*sizeof(Weight));
    (*w)[0].ch='a';
    (*w)[1].ch='b';
    (*w)[2].ch='c';
    (*w)[3].ch='d';
    (*w)[4].ch='e';
    (*w)[5].ch='f';
    (*w)[6].ch='g';
    (*w)[7].ch='h';
    (*w)[8].ch='i';
    (*w)[9].ch='j';
    (*w)[10].ch='k';
    (*w)[11].ch='l';
    (*w)[12].ch='m';
    (*w)[13].ch='n';
    (*w)[14].ch='o';
    (*w)[15].ch='p';
    (*w)[16].ch='q';
    (*w)[17].ch='r';
    (*w)[18].ch='s';
    (*w)[19].ch='t';
    (*w)[20].ch='u';
    (*w)[21].ch='v';
    (*w)[22].ch='w';
    (*w)[23].ch='x';
    (*w)[24].ch='y';
    (*w)[25].ch='z';
    (*w)[26].ch='.';
    (*w)[27].ch=' ';
    (*w)[28].ch=',';
    (*w)[29].ch='(';
    (*w)[30].ch=')';
    (*w)[31].ch='1';
    (*w)[32].ch='2';
    (*w)[33].ch='-';
    for(i=0;i<f;i++)
    {
        (*w)[i].weight=0;
    }
    i=0;
    while(str[i]!='\0')
    {
        if(str[i]=='A'||str[i]=='a')
        {
            (*w)[0].ch='a';
            (*w)[0].weight++;
        }
        if(str[i]=='B'||str[i]=='b')
        {
            (*w)[1].ch='b';
            (*w)[1].weight++;
        }
        if(str[i]=='C'||str[i]=='c')
        {
            (*w)[2].ch='c';
            (*w)[2].weight++;
        }
        if(str[i]=='D'||str[i]=='d')
        {
            (*w)[3].ch='d';
            (*w)[3].weight++;
        }
        if(str[i]=='E'||str[i]=='e')
        {
            (*w)[4].ch='e';
            (*w)[4].weight++;
        }
        if(str[i]=='F'||str[i]=='f')
        {
            (*w)[5].ch='f';
            (*w)[5].weight++;
        }
        if(str[i]=='G'||str[i]=='g')
        {
            (*w)[6].ch='g';
            (*w)[6].weight++;
        }
        if(str[i]=='H'||str[i]=='h')
        {
            (*w)[7].ch='h';
            (*w)[i].weight++;
        }
        if(str[i]=='I'||str[i]=='i')
        {
            (*w)[8].ch='i';
            (*w)[8].weight++;
        }
        if(str[i]=='J'||str[i]=='j')
        {
            (*w)[9].ch='j';
            (*w)[9].weight++;
        }
        if(str[i]=='K'||str[i]=='k')
        {
            (*w)[10].ch='k';
            (*w)[10].weight++;
        }
        if(str[i]=='L'||str[i]=='l')
        {
            (*w)[11].ch='l';
            (*w)[11].weight++;
        }
        if(str[i]=='M'||str[i]=='m')
        {
            (*w)[12].ch='m';
            (*w)[12].weight++;
        }
        if(str[i]=='N'||str[i]=='n')
        {
            (*w)[13].ch='n';
            (*w)[13].weight++;
        }
        if(str[i]=='O'||str[i]=='o')
        {
            (*w)[14].ch='o';
            (*w)[14].weight++;
        }
        if(str[i]=='P'||str[i]=='p')
        {
            (*w)[15].ch='p';
            (*w)[15].weight++;
        }
        if(str[i]=='Q'||str[i]=='q')
        {
            (*w)[16].ch='q';
            (*w)[16].weight++;
        }
        if(str[i]=='R'||str[i]=='r')
        {
            (*w)[17].ch='r';
            (*w)[17].weight++;
        }
        if(str[i]=='S'||str[i]=='s')
        {
            (*w)[18].ch='s';
            (*w)[18].weight++;
        }
        if(str[i]=='T'||str[i]=='t')
        {
            (*w)[19].ch='t';
            (*w)[19].weight++;
        }
        if(str[i]=='U'||str[i]=='u')
        {
            (*w)[20].ch='u';
            (*w)[20].weight++;
        }
        if(str[i]=='V'||str[i]=='v')
        {
            (*w)[21].ch='v';
            (*w)[21].weight++;
        }
        if(str[i]=='W'||str[i]=='w')
        {
            (*w)[22].ch='w';
            (*w)[22].weight++;
        }
        if(str[i]=='X'||str[i]=='x')
        {
            (*w)[23].ch='x';
            (*w)[23].weight++;
        }
        if(str[i]=='Y'||str[i]=='y')
        {
            (*w)[24].ch='y';
            (*w)[24].weight++;
        }
        if(str[i]=='Z'||str[i]=='z')
        {
            (*w)[25].ch='z';
            (*w)[25].weight++;
        }
        if(str[i]=='.')
        {
            (*w)[26].ch='.';
            (*w)[26].weight++;
        }
        if(str[i]==' ')
        {
            (*w)[27].ch=' ';
            (*w)[27].weight++;
        }
        if(str[i]==',')
        {
            (*w)[28].ch=',';
            (*w)[28].weight++;
        }
        if(str[i]=='(')
        {
            (*w)[29].ch='(';
            (*w)[29].weight++;
        }
        if(str[i]==')')
        {
            (*w)[30].ch=')';
            (*w)[30].weight++;
        }
        if(str[i]=='1')
        {
            (*w)[31].ch='1';
            (*w)[31].weight++;
        }
        if(str[i]=='2')
        {
            (*w)[32].ch='2';
            (*w)[32].weight++;
        }
        if(str[i]=='-')
        {
            (*w)[33].ch='-';
            (*w)[33].weight++;
        }
        i++;
    }*/

}

int main()
{
    Weight *w=NULL;
    Count(w);
    return 0;
}

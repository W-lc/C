//
//  main.c
//  哈夫曼编码大作业
//
//  Created by wlc on 2021/6/22.
//

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100000
#define SIZE 1000
int num=0;//全局变量，记录字符个数
typedef char **HuffmanCode;
typedef struct
{
    char ch;
    int weight;
}Weight;
typedef struct
{
    int weight;
    char data;
    int parent;
    int lchild;
    int rchild;
}HTNode,*HuffmanTree;
//统计字符个数
void Count(Weight **w)
{
    char str[MAX];
    gets(str);
    int i=0,j=0;
    num=0;
    *w=(Weight *)malloc(SIZE*sizeof(Weight));
    for(i=0;i<SIZE;i++)
    {
        (*w)[i].ch='#';
        (*w)[i].weight=0;
    }
    while(str[j]!='\0')
    {
        for(i=0;i<SIZE;i++)
        {
            if((*w)[i].ch=='#')
            {
                break;
            }
            if((*w)[i].ch==str[j])
            {
                (*w)[i].weight++;
                break;
            }
        }
        if((*w)[i].ch=='#')
        {
            (*w)[i].ch=str[j];
            (*w)[i].weight++;
            num++;
        }
        j++;
    }
}
void Select(HuffmanTree *HT,int upbound,int *s1,int *s2)
{
    int w1,w2,x1,x2;
    w1=1000;
    w2=1000;
    x1=0;
    x2=0;
    int i;
    for(i=1;i<upbound;i++)
    {
        if((*HT)[i].parent==0&&(*HT)[i].weight<w1)
        {
            w2=w1;
            x2=x1;
            w1=(*HT)[i].weight;
            x1=i;
        }
        else if((*HT)[i].parent==0&&(*HT)[i].weight<w2)
        {
            x2=i;
            w2=(*HT)[i].weight;
        }
    }
    *s1=x1;
    *s2=x2;
}
void CreateHuffmanff(HuffmanTree *HT,int n,Weight *w)
{
    if(n<=1)
    {
        return;
    }
    int m;
    int s1,s2;
    m=2*n-1;
    (*HT)=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
    int i;
    for(i=1;i<=m;i++)
    {
        (*HT)[i].parent=0;
        (*HT)[i].lchild=0;
        (*HT)[i].rchild=0;
    }
    for(i=1;i<=m;i++)
    {
        (*HT)[i].data=w[i-1].ch;
        (*HT)[i].weight=w[i-1].weight;
    }
    for(i=n+1;i<=m;i++)
    {
        Select(HT, i, &s1, &s2);
        (*HT)[i].lchild=s1;
        (*HT)[i].rchild=s2;
        (*HT)[s1].parent=i;
        (*HT)[s2].parent=i;
        (*HT)[i].weight=(*HT)[s1].weight+(*HT)[s2].weight;
    }
}

void HuffmanCoding(HuffmanTree HT,HuffmanCode *HC,int n)
{
    *HC=(char**)malloc((n+1)*sizeof(char *));
    char cd[n];
    cd[n-1]='\0';
    int start;
    int i;
    int c,f;
    for(i=1;i<=n;i++)
    {
        start=n-1;
        c=i;
        f=HT[i].parent;
        while(f)
        {
            --start;
            if(HT[f].lchild==c)
            {
                cd[start]='0';
            }
            if(HT[f].rchild==c)
            {
                cd[start]='1';
            }
            c=f;
            f=HT[f].parent;
        }
        (*HC)[i]=(char *)malloc((n-start)*sizeof(char));
        strcpy((*HC)[i],&cd[start]);
    }
}

int main()
{
    HuffmanTree HT;
    HuffmanCode HC;
    int n=0;
    Weight *w;
    Count(&w);
    n=num;
    CreateHuffmanff(&HT,n,w);
    HuffmanCoding(HT,&HC,n);
    for(int i=1;i<=n;i++)
    {
        printf("字符:%c,字符权值:%d,字符编码：%s\n",HT[i].data,HT[i].weight,HC[i]);
    }
    return 0;
}

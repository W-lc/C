//
//  main.c
//  合并有序表
//
//  Created by wlc on 2021/6/28.
//

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *next;
}LNode,*LinkList;

LinkList Read();
LinkList Merge( LinkList L1, LinkList L2 );

int main()
{
    LinkList L1, L2, L,p;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
     if(!L)
     {
         printf("empty");
       return 0;
     }
        p=L->next;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    return 0;
}


/* 请在这里填写答案 */
LinkList Read()
{
    LinkList L=NULL;
    LinkList p_new=NULL,r=NULL;
    ElemType n;
    p_new=(LinkList)malloc(sizeof(LNode));
    p_new->next=NULL;
    L=p_new;
    r=L;
    scanf("%d",&n);
    while(n!=-1)
    {
       p_new=(LinkList)malloc(sizeof(LNode));
       p_new->data=n;
        if(L->next==NULL)
        {
            L->next=p_new;
            p_new->next=NULL;
        }
        else
        {
            r->next=p_new;
            p_new->next=NULL;
        }
        r=p_new;
        scanf("%d",&n);
    }
    return L;
}
//按顺序依次读入元素，生成一个带头结点的单链表，表中元素值排列顺序与输入顺序一致，若输入-1，则创建链表结束（链表中不包含-1）。此处要求元素值按非递减顺序录入
LinkList Merge( LinkList L1, LinkList L2 )
{
    LinkList L3=NULL,p3;
    L3=L1;
    p3=L3;
    LinkList p1,p2;
    p1=L1->next;
    p2=L2->next;
    while(p1!=NULL||p2!=NULL)
    {
        if(p1!=NULL&&p2!=NULL)
        {
            if(p1->data<=p2->data)
            {
                p3->next=p1;
                p3=p1;
                p1=p1->next;
            }
            else
            {
                p3->next=p2;
                p3=p2;
                p2=p2->next;
            }
        }
        if(p1==NULL)
        {
            p3->next=p2;
            break;
        }
        if(p2==NULL)
        {
            p3->next=p1;
            break;
        }
    }
    return L3;
}
//合并L1与L2。已知L1与L2中的元素非递减排列，要求合并后的单链表中元素也按值非递减排列。

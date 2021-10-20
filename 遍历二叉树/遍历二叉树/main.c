//
//  main.c
//  遍历二叉树
//
//  Created by wlc on 2021/6/9.
//

#include <stdio.h>
#include<stdlib.h>

typedef char ElemType;
//线索存储标签
//Link(0):表示指向左右孩子的指针
//Thread(1):表示指向前驱后继的线索
typedef enum {Link,Thread} PointerTag;

typedef struct BiThrNode
{
    ElemType data;
    struct BiThrNode *lchild,*rchild;
    PointerTag ltag;
    PointerTag rtag;
}BiThrNode,*BiThrTree;
//定义全局变量
BiThrTree ptr;
//采用先序遍历创建二叉树
void CreateBiThrTree(BiThrTree *T)
{
    ElemType ch;
    scanf("%c",&ch);
    if(' '==ch)
    {
        *T=NULL;
    }
    else
    {
        *T=(BiThrNode *)malloc(sizeof(BiThrNode));
        (*T)->data=ch;
        (*T)->ltag=Link;
        (*T)->rtag=Link;
        CreateBiThrTree(&((*T)->lchild));
        CreateBiThrTree(&((*T)->rchild));
    }
}
//中序遍历实现线索化
void InThreading(BiThrNode *T)
{
    if(T)
    {
        InThreading(T->lchild);//递归左孩子线索化
        //结点处理
        if(!T->lchild)//如果没有左孩子，则把T->ltag设置为Thread,T->lchild指向前一个结点
        {
            T->ltag=Thread;
            T->lchild=ptr;
        }
        if(!ptr->rchild)//如果没有右孩子，则把ptr->rtag设置为Thread,ptr->rchild指向后继
        {
            ptr->rtag=Thread;
            ptr->rchild=T;
        }
        ptr=T;
        InThreading(T->rchild);//递归右孩子线索化
        //结点处理
    }
}
void InOrderThreading(BiThrTree *p,BiThrTree T)
{
    *p=(BiThrTree)malloc(sizeof(BiThrNode));//初始化头指针
    (*p)->ltag=Link;
    (*p)->rtag=Thread;
    (*p)->rchild=*p;
    if(!T)
    {
        (*p)->lchild=*p;
    }
    else
    {
        (*p)->lchild=T;
        ptr=*p;
        InThreading(T);
        ptr->rchild=*p;
        ptr->rtag=Thread;
        (*p)->rchild=ptr;
    }
}
//中序遍历二叉树，非递归
void InOrderTraverse(BiThrTree T)
{
    BiThrNode *p;
    p=T->lchild;
    
    while(p!=T)
    {
        while(p->ltag==Link)
        {
            p=p->lchild;
        }
        printf("%c",p->data);
        while(p->rtag==Thread&&p->rchild!=T)
        {
            p=p->rchild;
            printf("%c",p->data);
        }
        p=p->rchild;
    }
}
int main()
{
    BiThrTree T=NULL;
    BiThrTree P=NULL;
    CreateBiThrTree(&T);
    InOrderThreading(&P,T);
    printf("输出的中序遍历的线索二叉树为：\n");
    InOrderTraverse(P);
    printf("\n");
    return 0;
}

//
//  main.c
//  先序遍历
//
//  Created by wlc on 2021/5/25.
//

#include <stdio.h>
#include<stdlib.h>

typedef  char TElemType;
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void CreateBiTree(BiTree *T)
{
    char ch;
    scanf("%c",&ch);
    if(ch == '#')
    {
        *T=NULL;
    }
    else
    {
        *T=(BiTNode *)malloc(sizeof(BiTNode));
        (*T)->data=ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}
void PreOrderTraverse(BiTree T)
{
    if(T)
    {
        printf("%c\n",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
    else
    {
        
    }
}
int main()
{
    BiTree T=NULL;
    CreateBiTree(&T);
    PreOrderTraverse(T);
    return 0;
}


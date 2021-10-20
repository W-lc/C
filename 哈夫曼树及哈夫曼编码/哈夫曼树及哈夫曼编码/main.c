//
//  main.c
//  哈夫曼树及哈夫曼编码
//
//  Created by wlc on 2021/6/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int weight;
    int parent;
    int lchild;
    int rchild;
} HTNode, *HuffmanTree;
typedef char ** HuffmanCode;

void SelectTwoMin(int upbound, HuffmanTree HT, int *s1, int *s2);
void HuffmanCoding(HuffmanTree *HT, HuffmanCode *HC, int *w, int n);

int main() {
    HuffmanTree ht;
    HuffmanCode hc;

    int n;
    scanf("%d", &n);

    int *w = (int *) malloc (n * sizeof(int));
    for(int i = 0; i < n; ++ i)
        scanf("%d", &w[i]);

    HuffmanCoding(&ht, &hc, w, n);

    for (int i = 1; i <= 2 * n - 1; ++ i) {
        printf("%d %d %d %d\n",
        ht[i].weight, ht[i].parent, ht[i].lchild, ht[i].rchild);
    }

    for (int i = 1; i <= n; ++ i)
        printf("%s\n", hc[i]);

    free(w);
    free(ht);
    for (int i = 1; i <= n; ++ i)
        free(hc[i]);

    return 0;
}
/* 你的代码将被嵌在这里 */
void SelectTwoMin(int upbound, HuffmanTree HT, int *s1, int *s2)
{
    int i;
    int w1=1000,w2=1000;
    int x1=0;
    int x2=0;
    for(i=1;i<upbound;i++)
    {
        if(HT[i].parent==0&&HT[i].weight<w1)
        {
            w2=w1;//此时w1还未是最小值，即当前的次小值，所以赋值给w2
            x2=x1;//同时把次小值的下标赋给x2
            w1=HT[i].weight;//此时w1为最小值
            x1=i;
        }
        else if(HT[i].parent==0&&HT[i].weight<w2)//如遇到新的权值比w1大，比w2小则执行
        {
            w2=HT[i].weight;
            x2=i;
        }
    }
        *s1=x1;
        *s2=x2;
}
void HuffmanCoding(HuffmanTree *HT, HuffmanCode *HC, int *w, int n)
{
    //创建哈夫曼树
    if(n<=1)
    {
        return ;
    }
    int m,i,f;
    int start;
    int c;
    int s1,s2;
    m=2*n-1;//哈夫曼树一共有2n-1个结点
    *HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));//因为0号位不用，所以申请2n个空间
    for(i=1;i<=m;i++)//初始化哈夫曼树的双亲域和孩子域
    {
        (*HT)[i].parent=0;
        (*HT)[i].lchild=0;
        (*HT)[i].rchild=0;
    }
    for(i=0;i<n;i++)//为前n个结点赋予权值，即储存叶子结点
    {
        (*HT)[i+1].weight=w[i];
    }
    for(i=n+1;i<=m;i++)
    {//通过n-1次的选择，删除，合并来创建哈夫曼树
        SelectTwoMin(i,*HT,&s1,&s2);
        //在HT[k](1<=k<=i-1)中选择两个其双亲域为0且权值最小的结点，并返回它们在HT中的序号s1和s2
        //合并两个权值较小的，得到一个新的结点
        (*HT)[s1].parent=i;
        (*HT)[s2].parent=i;
        //得到新结点i，从森林中删除s1和s2,将s1和s2的双亲域由0改为i
        (*HT)[i].lchild=s1;
        (*HT)[i].rchild=s2;//s1和s2分别作为i的左右孩子
        (*HT)[i].weight=(*HT)[s1].weight+(*HT)[s2].weight;//i的权值为s1和s2权值之和
    }
    //编写哈夫曼编码
    *HC=(char **)malloc((n+1)*sizeof(char *));//分配储存n个字符编码的编码表空间
    char cd[n];//分配临时存放每个字符编码的动态编码数组空间
    cd[n-1]='\0';//编码结束符
    for(i=1;i<=n;i++)//逐个字符求哈夫曼编码
    {
        start=n-1;//start开始指向最后，即编码结束符的位置
        c=i;//c用来记录从叶子结点向上回溯至根结点所经过的结点下标
        f=(*HT)[i].parent;//f指向当前结点的双亲
        while(f!=0)
        {
            --start;
            if((*HT)[f].lchild==c)
            {
                cd[start]='0';
            }
            else
            {
                cd[start]='1';
            }
            c=f;
            f=(*HT)[f].parent;
        }
        (*HC)[i]=(char *)malloc((n-start)*sizeof(char));
        strcpy((*HC)[i],&cd[start]);
    }
}

//
//  main.c
//  最小生成树Kruskal
//
//  Created by wlc on 2021/6/22.
//

#include <stdio.h>
#include<stdlib.h>

#define MAXVEX 100
#define INFINTY 65535

typedef char VertexType;
typedef int EdgeType;

typedef struct
{
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numVertexs,numEdge;
}MGraph;

typedef struct
{
    int Head;
    int  end;
    int weight;
}Edge;

void CreateMGraph(MGraph *G)
{
    int i,j,k;
    printf("输入结点数和边数\n");
    scanf("%d%d",&G->numVertexs,&G->numEdge);
    for(i=0;i<G->numVertexs;i++)
    {
        scanf("%c",&G->vexs[i]);
    }
    for(i=0;i<G->numVertexs;i++)
    {
        for(j=0;j<G->numVertexs;j++)
        {
            G->arc[i][j]=INFINTY;
            if(i==j)
            {
                G->arc[i][j]=0;
            }
        }
    }
    for(k=0;k<G->numEdge;k++)
    {
        printf("请输入边(vi,vj)的下标\n");
        scanf("%d%d",&i,&j);
        scanf("%d",&G->arc[i][j]);
        G->arc[j][i]=G->arc[i][j];
    }
}
void SortEdge(Edge *edges,MGraph G)
{
    int i,j,m=0,k;
    int t;
    for(i=0;i<G.numVertexs;i++)
    {
        for(j=i;j<G.numVertexs;j++)
        {
            if(G.arc[i][j]!=0&&G.arc[i][j]!=INFINTY)
            {
                edges[m].Head=i;
                edges[m].end=j;
                edges[m].weight=G.arc[i][j];
                m++;
            }
        }
    }
    for(i=0;i<=m;i++)
    {
        k=i;
        for(j=i;j<=m;j++)
        {
            if(edges[k].weight>edges[j].weight)
            {
                k=j;
            }
        }
        if(k!=i)
        {
            t=edges[k].Head;
            edges[k].Head=edges[i].Head;
            edges[i].Head=t;
            t=edges[k].end;
            edges[k].end=edges[i].end;
            edges[i].end=t;
            t=edges[k].weight;
            edges[k].weight=edges[i].weight;
            edges[i].weight=t;
        }
    }
}

int Find(int *parent,int f)//查找连线顶点的尾部下标
{
    while(parent[f]>0)
    {
        f=parent[f];
    }
    return f;
}
void MinSpanTree_Kruskal(MGraph G)
{
    int i,n,m;
    Edge edges[G.numEdge];//定义边集数组
    int parent[G.numVertexs];//判断是否形成环路
    for(i=0;i<G.numVertexs;i++)
    {
        parent[i]=0;
    }
    SortEdge(edges, G);
    for(i=0;i<G.numEdge;i++)
    {
        n=Find(parent,edges[i].Head);
        m=Find(parent, edges[i].end);
        if(n!=m)//假如n与m不相等，则说明此边没有与现有生成树构成环路
        {
            parent[n]=m;//将此边的尾结点下标放在下标为起点的parent中
            printf("(%d,%d) %d",edges[i].Head,edges[i].end,edges[i].weight);
        }
    }
}

int main()
{
    MGraph G;
    CreateMGraph(&G);
    MinSpanTree_Kruskal(G);
    return 0;
}

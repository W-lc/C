//
//  main.c
//  深度优先遍历邻接表版
//
//  Created by wlc on 2021/6/21.
//

#include <stdio.h>
#include<stdlib.h>

#define MAXVEX 100
#define INFINTY 65535
typedef enum{false,true} Boolean;
typedef char VertesType;
typedef int EdgeType;
Boolean visited[MAXVEX];

typedef struct EdgeNode//边表结点
{
    int adjvex;//结点下标
    EdgeType weight;//当前结点权值
    struct EdgeNode *nextarc;//链
}EdgeNode;

typedef struct//顶点头表
{
    VertesType data;//顶点域，储存表头数据
    EdgeNode *firstedge;//指针域，边表的都指针
}VertexNode,AdjEdge[MAXVEX];

typedef struct
{
    AdjEdge adjList;
    int numvertexs,numEdge;
}GraphAdjList;


void CreateALGraph(GraphAdjList *G)
{
    int i,j,k;
    EdgeNode *e;
    printf("输入结点数和边数：\n");
    scanf("%d%d",&(G->numvertexs),&(G->numEdge));
    for(i=0;i<G->numvertexs;i++)//初始化表头
    {
        scanf("%c",&(G->adjList[i].data));
        G->adjList[i].firstedge=NULL;
    }
    for(k=0;k<G->numvertexs;k++)
    {
        printf("输入边（vi,vj）上的顶点学号\n");
        scanf("%d%d",&i,&j);
        e=(EdgeNode *)malloc(sizeof(EdgeNode));//申请结点空间，生成边结点
        e->adjvex=j;//邻接号为j
        e->nextarc=G->adjList[i].firstedge;//将e指针域指向当前结点
        G->adjList[i].firstedge=e;//将当前结点指向e
        
        e=(EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex=i;//邻接号为j
        e->nextarc=G->adjList[j].firstedge;//将e指针域指向当前结点
        G->adjList[j].firstedge=e;//将当前结点指向e
    }
}
//邻接表的深度优先递归算法
void DFS(GraphAdjList G,int i)
{
    EdgeNode *p;
    visited[i]=true;
    printf("%c ",G.adjList[i].data);
    p=G.adjList[i].firstedge;
    while(p)
    {
        if(visited[p->adjvex]==false)
        {
            DFS(G,p->adjvex);
        }
        p=p->nextarc;
    }
}

//邻接表的深度遍历
void DFSTravere(GraphAdjList G)
{
    int i;
    for(i=0;i<G.numvertexs;i++)
    {
        visited[i]=false;
    }
    for(i=0;i<G.numvertexs;i++)
    {
        if(visited[i]==false)
        {
            DFS(G, i);
        }
    }
}

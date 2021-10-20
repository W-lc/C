//
//  main.c
//  广度优先遍历邻接表版
//
//  Created by wlc on 2021/6/21.
//

#include <stdio.h>
#include<stdlib.h>

#define MAXVEX 100

typedef char VertType;
typedef int EdgeType;
typedef enum{false,true} Boolean;
Boolean visited[MAXVEX];

typedef struct EdgeNode
{
    int adjvex;
    struct EdgeNode *nextarc;
}EdgeNode;

typedef struct
{
    VertType data;
    EdgeNode *firstedge;
}VertexNode,AdjNode[MAXVEX];

typedef struct
{
    AdjNode adjList;
    int numVertexs,numEdge;
}GraphAdjList;

void CreateALGraph(GraphAdjList *G)
{
    EdgeNode *e;
    int i,j,k;
    printf("输入结点数和边数:\n");
    scanf("%d%d",&G->numVertexs,&G->numEdge);
    for(i=0;i<G->numVertexs;i++)
    {
        scanf("%c",&(G->adjList[i].data));
        G->adjList[i].firstedge=NULL;
    }
    for(k=0;k<G->numEdge;k++)
    {
        printf("输入边(vi,vj)的下标");
        scanf("%d%d",&i,&j);
        e=(EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex=j;
        e->nextarc=G->adjList[i].firstedge;
        G->adjList[i].firstedge=e;
        e=(EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex=i;
        e->nextarc=G->adjList[j].firstedge;
        G->adjList[j].firstedge=e;
    }
}
//广度优先遍历
void BFSTarvese(GraphAdjList G)
{
    EdgeNode *p;
    int i;
    int Q[G.numVertexs];
    int top=0;
    int base=0;
    for(i=0;i<G.numVertexs;i++)
    {
        visited[i]=false;
    }
    for(i=0;i<G.numVertexs;i++)
    {
        if(visited[i]==false)
        {
            visited[i]=true;
            printf("%c ",G.adjList[i].data);
            Q[top++]=i;
            while(top!=base)
            {
                i=Q[base++];
                p=G.adjList[i].firstedge;
                while(p)
                {
                    if(visited[p->adjvex]==false)
                    {
                        visited[p->adjvex]=true;
                        printf("%c ",G.adjList[p->adjvex].data);
                        Q[top++]=p->adjvex;
                    }
                    p=p->nextarc;
                }
            }
        }
    }
    
}

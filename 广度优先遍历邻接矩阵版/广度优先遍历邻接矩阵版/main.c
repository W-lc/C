//
//  main.c
//  广度优先遍历邻接矩阵版
//
//  Created by wlc on 2021/6/21.
//

#include <stdio.h>
#include<stdlib.h>

#define MAXVEX 100
typedef enum{false,true} Boolean;
typedef char VertexType;
typedef int EdgeType;
Boolean visited[MAXVEX];
typedef struct
{
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numVertexs,numEdge;
}MGraph;

void CreateMGraph(MGraph *G)
{
    int i,j,k;
    printf("输入结点数和边数\n");
    scanf("%d%d",&G->numVertexs,&G->numEdge);
    for(i=0;i<G->numVertexs;i++)
    {
        scanf("%c",&(G->vexs[i]));
    }
    for(i=0;i<G->numVertexs;i++)
    {
        for(j=0;j<G->numVertexs;j++)
        {
            G->arc[i][j]=0;
        }
    }
    for(k=0;k<G->numEdge;k++)
    {
        printf("请输入边（vi,vj）的下标\n");
        scanf("%d%d",&i,&j);
        G->arc[i][j]=1;
        G->arc[j][i]=G->arc[i][j];
    }
}

void BFSTraverse(MGraph G)
{
    int i,j;
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
            printf("%c ",G.vexs[i]);
            Q[top++]=i;
        }
        while(top!=base)
        {
            Q[--base]=i;
            for(j=0;j<G.numVertexs;j++)
            {
                if(visited[j]==false&&G.arc[i][j]==1)
                {
                    visited[j]=true;
                    printf("%c ",G.vexs[j]);
                    Q[top++]=j;
                }
            }
        }
    }
}

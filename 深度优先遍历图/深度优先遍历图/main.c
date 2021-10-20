//
//  main.c
//  深度优先遍历图
//
//  Created by wlc on 2021/6/21.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 100

typedef char VertexType;//顶点类型
typedef int EdgeType;//边类型
typedef enum{false,true} Boolean;//布尔类型，用于判断是否遍历过了
Boolean visited[MAXVEX];//访问标志的数组

typedef struct               //定义邻接矩阵
{
    VertexType vexs[MAXVEX];   //顶点表
    EdgeType arc[MAXVEX][MAXVEX];//边表
    int numVertexes,numEdges;     //顶点数和边数
}MGraph;

void CreateMGraph(MGraph *G)
{
    int i,j,k;
    printf("输入顶点数和边数：\n");
    scanf("%d%d",&G->numVertexes,&G->numEdges);
    printf("输入顶点值：\n");
    for(i=0;i<G->numVertexes;i++)//输入顶点信息，初始化顶点表
    {
        scanf("%c",&G->vexs[i]);
    }
    for(i=0;i<G->numVertexes;i++)//初始化边表，即邻接矩阵，全部为0
    {
        for(j=0;j<G->numVertexes;j++)
        {
            G->arc[i][j]=0;
        }
    }
    for(k=1;k<=G->numEdges;k++)//用1表示两邻接点之间有边存在，若为带权值的无向图则要输入权值
    {
        printf("输入边：\n");
        scanf("%d%d",&i,&j);
        G->arc[i][j]=1;
        G->arc[j][i]=G->arc[i][j];//由于无向图的邻接矩阵是对称矩阵所以arc[i][j]=arc[j][i]
    }
}
//邻接矩阵的深度优先递归算法
void DFS(MGraph G,int i)
{
    int j;
    visited[i]=true;
    printf("%c ",G.vexs[i]);
    for(j=0;j<G.numVertexes;j++)
    {
        if(visited[j]==false&&G.arc[i][j]==1)
        {
            DFS(G,j);
        }
    }
}
//邻接矩阵的深度优先遍历
void DFSTraverse(MGraph G)
{
    int i,j;
    for(i=0;i<G.numVertexes;i++)
    {
        visited[i]=false;//初始化标志数组,都为未访问
        printf("%c ",G.vexs[i]);
    }
    printf("\n");
    for(i=0;i<G.numVertexes;i++)
    {
        for(j=0;j<G.numVertexes;j++)
        {
            printf("%d ",G.arc[i][j]);
        }
    }
    for(i=0;i<G.numVertexes;i++)
    {
        if(visited[i]==false)//对未访问过的结点调用DFS，若是连通图则只执行一次
        {
            DFS(G,5);
        }
    }
}
int main()
{
    MGraph G;
    CreateMGraph(&G);
    DFSTraverse(G);
    return 0;
}

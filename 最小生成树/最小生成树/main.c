//
//  main.c
//  最小生成树
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

void CreateMGraph(MGraph *G)
{
    int i,j,k;
    printf("请输入结点数和边数\n");
    scanf("%d%d",&G->numVertexs,&G->numEdge);
    for(i=0;i<G->numVertexs;i++)
    {
        scanf("%c",&(G->vexs[i]));
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
        printf("输入边(vi,vj)的下标\n");
        scanf("%d%d",&i,&j);
        printf("输入权值\n");
        scanf("%d",&G->arc[i][j]);
        G->arc[j][i]=G->arc[i][j];
    }
}

//Prim算法
void MiniSpanTree_Prim(MGraph G)
{
    int min,i,j,k;
    int adjvex[G.numVertexs];//保存相关顶点下标
    int lowcost[G.numVertexs];//保存相关顶点边的权值
    lowcost[0]=0;//初始化第一个权值为0，表示v0加入生成树
    adjvex[0]=0;//初始化第一个下标为0
    for(i=1;i<G.numVertexs;i++)
    {
        lowcost[i]=G.arc[0][i];//将v0顶点与之有边的权值存入数组
        adjvex[i]=0;//全部初始化为0
    }
    for(i=1;i<G.numVertexs;i++)
    {
        min=INFINTY;//初始化最小权值为INFINTY
        j=1;
        k=0;
        while(j<G.numVertexs)
        {
            if(lowcost[j]!=0&&lowcost[j]<min)
            {//如果权值不等于0且权值小于min
                min=lowcost[j];//则让当前权值成为最小权值
                k=j;//记录最小权值的结点下标
            }
            j++;
        }
        printf("(%d,%d)",adjvex[k],k);//打印当前顶点边中权值最小边
        lowcost[k]=0;//将当前结点的权值设置为0，表示结点加入生成树
        for(j=1;j<G.numVertexs;j++)
        {
            if(lowcost[j]!=0&&G.arc[k][j]<lowcost[j])
            {//将下标为k的顶点各边权值下于此前这些顶点未被加入生成树权值
                lowcost[j]=G.arc[k][j];//将较小权值存入lowcost
                adjvex[j]=k;//将下标为k的结点存入adjvex,数组adjvex表示存入下标的k的结点到数组下标j的边
            }
        }
    }
}

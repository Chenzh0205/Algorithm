#include <stdio.h>
#define max 99999999
int main(){
    int m,n;//顶点数和边数
    scanf("%d %d",&m,&n);

    //定义图矩阵、i->j顶点、以及可能存在的i->k->j顶点，以及当前顶点和权重值
    int e[m][m],k,i,j,v1,v2,w;

    //初始化图矩阵，从顶点到自身的距离为0
    for(i=1;i<=m;++i){
        for(j=1;j<=m;++j){
            if (i==j) e[i][j]=0;
            else e[i][j]=max;
        }
    }

    //读取顶点和边的权重
    for(i=1;i<=n;i++){
        scanf("%d %d %d",&v1,&v2,&w);
        e[v1][v2]=w;
    }

    //floyd核心算法
    for(k=1;k<=m;k++)
    for(i=1;i<=m;i++)
    for(j=1;j<=m;j++)
        if(e[i][j]>e[i][k]+e[k][j])
            e[i][j]=e[i][k]+e[k][j];

    //输出矩阵
    for(i=1;i<=m;i++){
        for(j=1;j<=m;j++){
            printf("%10d",e[i][j]);
        }
        printf("\n");
    }
}
//input：
//4 8
//1 2 2
//1 3 6
//1 4 4
//2 3 3
//3 1 7
//3 4 1
//4 1 5
//4 3 12
// output：
//        0         2         5         4
//        9         0         3         4
//        6         8         0         1
//        5         7        10         0 

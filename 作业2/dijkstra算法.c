#include <stdio.h>
#define max 99999999
int main(){
    int m,n;//顶点数和边数
    scanf("%d %d",&m,&n);

    //定义图矩阵、当前顶点和权重值、最短路径估计值数组dis、最短路径顶点确定数组book
    int e[m][m],dis[m],book[m],i,j,v1,v2,w,u,v,min;

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
    
    int a,b;
    scanf("%d %d",&a,&b);//读取从a顶点到b顶点

    //初始化dis数组，使得其值为顶点a到其他顶点的距离
    //初始化book数组，使得所有顶点都不确定。
    for(i=1;i<=m;i++){
        dis[i]=e[a][i];
        book[i]=0;
    }
    book[a]=1; //顶点a加入确定数组
    

    //dijkstra核心算法
    for(i=1;i<=m-1;i++){
        min=max;
        //找离a顶点最近的顶点
        for(j=1;j<=m;j++){
            if(book[j]==0&&dis[j]<min){
                min=dis[j];
                u=j;
            }
        }
        //收录该顶点
        book[u]=1;
        //更新最短路径
        for(v=1;v<=m;v++){
            if(e[u][v]<max){
                if(dis[v]>dis[u]+e[u][v])   dis[v]=dis[u]+e[u][v];
            }
        }
    }

    printf("从顶点%d到顶点%d最短路径=%d",a,b,dis[b]);
}
//input:
//8 11
//1 2 1
//2 4 2
//3 1 2
//4 3 1
//4 6 8
//5 4 2
//5 7 2
//6 5 2
//7 6 3
//7 8 3
//8 6 2
//1 8
//output：
//从顶点1到顶点8最短路径=18 

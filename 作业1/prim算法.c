#include <stdio.h>
#define MAX 100
#define MAXCOST 0x7fffffff

int graph[MAX][MAX];

void prim(int graph[][MAX],int n){
    int mincost[MAX];
    int mst[MAX];
    int i,j,min,minid,sum=0;
    for(i=2;i<=n;i++){
        //�Զ���1Ϊ��ʼ�㣬����Ŷ���1���ڽӵ��·����
        mincost[i]=graph[1][i];
        mst[i]=1;
    }
    mst[1]=0;
    for (i=2;i<=n;i++){
        min=MAXCOST;
        minid=0;
        for(j=2;j<=n;j++){
            //�ҳ�Ȩ����̵�·����id
            if(mincost[j]<min&&mincost[j]!=0){
                min=mincost[j];
                minid=j;
            }
        }
        printf("V%d-V%d=%d\n",mst[minid],minid,min); 
        //��Ȩ�����
        sum+=min;
        //�����·����Ȩ����0��
        mincost[minid]=0;
        for(j=2;j<=n;j++){
            //·������
            if(graph[minid][j]<mincost[j]){
                mincost[j]=graph[minid][j];
                mst[j]=minid;
            }
        }
    }
    printf("��СȨ��֮��=%d\n",sum);
}

int main(){
    int i,j,k,m,n,x,y,cost;
    scanf("%d %d",&m,&n);//mΪ���������nΪ�߸���

    //��ʼ��ͼ
    for (i=1;i<=m;i++)
    {
        for (j=1;j<=m;j++){
            graph[i][j]=MAXCOST;
        }
    }

    //���ߺͶ��㸳ֵ
    for(k=1;k<=n;k++){
        scanf("%d %d %d",&i,&j,&cost);
        graph[i][j]=cost;
        graph[j][i]=cost;
    }

    prim(graph,m);
}
// input:
// 7 12
// 1 2 2
// 1 3 4
// 1 4 1
// 2 4 3
// 2 5 10
// 3 4 2
// 3 6 5
// 4 5 7
// 4 6 8
// 4 7 4
// 5 7 6
// 6 7 1
// output:
// V1-V4=1
// V1-V2=2
// V4-V3=2
// V4-V7=4
// V7-V6=1
// V7-V5=6
// ��СȨ��֮��=16

#include <stdio.h>
#define max 99999999
int main(){
    int m,n;//�������ͱ���
    scanf("%d %d",&m,&n);

    //����ͼ����i->j���㡢�Լ����ܴ��ڵ�i->k->j���㣬�Լ���ǰ�����Ȩ��ֵ
    int e[m][m],k,i,j,v1,v2,w;

    //��ʼ��ͼ���󣬴Ӷ��㵽����ľ���Ϊ0
    for(i=1;i<=m;++i){
        for(j=1;j<=m;++j){
            if (i==j) e[i][j]=0;
            else e[i][j]=max;
        }
    }

    //��ȡ����ͱߵ�Ȩ��
    for(i=1;i<=n;i++){
        scanf("%d %d %d",&v1,&v2,&w);
        e[v1][v2]=w;
    }

    //floyd�����㷨
    for(k=1;k<=m;k++)
    for(i=1;i<=m;i++)
    for(j=1;j<=m;j++)
        if(e[i][j]>e[i][k]+e[k][j])
            e[i][j]=e[i][k]+e[k][j];

    //�������
    for(i=1;i<=m;i++){
        for(j=1;j<=m;j++){
            printf("%10d",e[i][j]);
        }
        printf("\n");
    }
}
//input��
//4 8
//1 2 2
//1 3 6
//1 4 4
//2 3 3
//3 1 7
//3 4 1
//4 1 5
//4 3 12
// output��
//        0         2         5         4
//        9         0         3         4
//        6         8         0         1
//        5         7        10         0 

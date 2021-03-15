#include <stdio.h>
#define max 99999999
int main(){
    int m,n;//�������ͱ���
    scanf("%d %d",&m,&n);

    //����ͼ���󡢵�ǰ�����Ȩ��ֵ�����·������ֵ����dis�����·������ȷ������book
    int e[m][m],dis[m],book[m],i,j,v1,v2,w,u,v,min;

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
    
    int a,b;
    scanf("%d %d",&a,&b);//��ȡ��a���㵽b����

    //��ʼ��dis���飬ʹ����ֵΪ����a����������ľ���
    //��ʼ��book���飬ʹ�����ж��㶼��ȷ����
    for(i=1;i<=m;i++){
        dis[i]=e[a][i];
        book[i]=0;
    }
    book[a]=1; //����a����ȷ������
    

    //dijkstra�����㷨
    for(i=1;i<=m-1;i++){
        min=max;
        //����a��������Ķ���
        for(j=1;j<=m;j++){
            if(book[j]==0&&dis[j]<min){
                min=dis[j];
                u=j;
            }
        }
        //��¼�ö���
        book[u]=1;
        //�������·��
        for(v=1;v<=m;v++){
            if(e[u][v]<max){
                if(dis[v]>dis[u]+e[u][v])   dis[v]=dis[u]+e[u][v];
            }
        }
    }

    printf("�Ӷ���%d������%d���·��=%d",a,b,dis[b]);
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
//output��
//�Ӷ���1������8���·��=18 

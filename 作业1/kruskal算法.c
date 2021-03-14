#include <stdio.h>
#define MAXE 100
#define MAXV 100

typedef struct{
	int v1;                     //�ߵ���ʼ����
	int v2;                      //�ߵ���ֹ����
	int w;                    //�ߵ�Ȩֵ
}edge;
//�����㷨 
int QuickSort(edge e[],int low,int high){
    int key;
    edge x;
    x=e[low];
    key=e[low].w;
    while(low<high){
        while(low<high&&e[high].w>=key)
            high--;
        if(low<high)
            e[low++]=e[high];
        
        while(low<high&&e[low].w<=key)
            low++;
        if(low<high)
            e[high--]=e[low];
    }
    e[low]=x;
    return low;
}

//�淶���ӿ� 
void Quick_Sort(edge e[],int start,int end){
    int pos;
    if(start<end){
        pos=QuickSort(e,start,end);
        Quick_Sort(e,start,pos-1);
        Quick_Sort(e,pos+1,end);
    }
}

void kruskal(edge e[],int m,int n){
    int i,j,v1,v2,s1,s2,k,sum=0;
    int set[m+1];
    //���������ż�
    for(i=1;i<=m;i++){
        set[i]=i;
    }
    //��С�������ĵ�k����
    k=1;
    //�ߵ��±�
    j=0;
    while(k<=n){
    	if (j>n) break;
        //�Ȼ�ȡj�ߵ��ڽӵ㣬�Լ������ļ��ϱ��
	    v1=e[j].v1;
	    v2=e[j].v2;
	    s1=set[v1];
	    s2=set[v2];
	    //������ļ��ϲ�ͬʱ����ʾ�ñ�Ϊ��������һ����
	    if(s1!=s2){
	        printf("V%d-V%d=%d\n",v1,v2,e[j].w);
	        sum+=e[j].w;
	        k++; //��С�������ı�������
	        if(k>=n)    break;
	        for(i=1;i<=m;i++){
	            if(set[i]==s2)  set[i]=s1; //��ʾ�õ��Ѿ�����v1�ļ����У�ͬһ����
	        }
	    }
    j++; //��һ����
    }
    printf("��СȨֵ֮��=%d\n",sum);
}

int main(){
    edge e[MAXE];
    int i,m,n;//�������ͱ���
    scanf("%d %d",&m,&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d",&e[i].v1,&e[i].v2,&e[i].w);
    }
    
    Quick_Sort(e,0,n-1);
    kruskal(e,m,n-1);
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
//output:
//V6-V7=1
//V1-V4=1
//V1-V2=2
//V3-V4=2
//V4-V7=4
//V5-V7=6
//��СȨֵ֮��=16



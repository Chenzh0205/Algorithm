#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
 typedef struct{
     double x;
     double y;
 }Point;
 double INF =1e20;

//排序规则：先按照横坐标排序，横坐标相同就按照纵坐标排序。
 bool cmp(const Point& p1,const Point& p2){
     return p1.x==p2.x?p1.y<p2.y:p1.x<p2.x;
 }

//内联函数获取两点间距离
 inline double dis(const Point& p1,const Point& p2){
     return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
 }

 //最近点对算法，输出left点到right点之间最近两点对的距离
double divide(int left,int right,Point* p){
    Point point[100];
    if(left==right) return INF;
    //分治
    int m=(left+right)/2;
    Point p1;
    p1=p[m];
    //求解左边的点集最短距离和右边的最短距离并取最小
    double d=min(divide(1,m,p),divide(m+1,right,p));
    int i=1,j=m+1,k=0;

    //将左右两边的点根据横坐标再纵坐标排序的规则合并收入临时点数组中
    while(i<=m&&j<=right){
        if(p[i].y<p[j].y) point[k++]=p[i++];
        else point[k++]=p[j++];
    }
    while(i<=m) point[k++]=p[i++];
    while(j<=right) point[k++]=p[j++];
    
    //讨论一点在左半部分一点在右半部分的情况
    //考虑纵坐标差值在d范围内的点，判断最短距离
    k=0;
    for(i=1;i<=right;i++){
        if(fabs(p1.x-point[i-1].x)<d) point[k++]=point[i-1];
    }  
    for(i=0;i<k;i++){
        for(j=i+1;point[j].y-point[i].y<d&&j<k;j++){
            d=min(d,dis(point[i],point[j]));
        }
    }
    return d;
}
int main(){
    int n,i;
    cin>>n;
    Point p[100];
    for(i=0;i<n;i++){
        cin>>p[i].x>>p[i].y;
    }
    sort(p,p+n,cmp);
    cout<<divide(0,n-1,p);
}

// input:
// 11
// -4 -1
// -3 -1
// -3 1
// -2 0
// 0 0
// -0.2 1.4
// 0.4 1.4
// 1 -1
// 2 1
// 2 2
// 3 0
// output:
// 0.6
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string.h>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int n;//图一共有n个顶点
int m;//m种颜色被选择
int k;//图中有k条边
int sum=0;//图的m着色种类
int x[101];//存放当前的着色序列
int a[101][101];//图的邻接矩阵

//判断给点t着色为x[t]是否可行
bool OK(int t){
	//可行的条件是当前点相邻的点不能与之同色
  for(int i=1;i<t;i++)
    if(a[i][t]==1&&x[i]==x[t])
      return false;
	//如果所有与之相邻的点都不与之同色
  return true;
}

void getsum(int i){
  //i>n说明找到了一个可行的涂色方案
  if(i>n){
    sum++;//涂色方案数++

    //输出解向量
    for(int k=1;k<=n;k++)
      cout<<x[k]<<" ";
    cout<<endl;
    return ;
  }
  //还没有到叶子节点，需要给当前节点可行的涂色
  else{
    for(int k=1;k<=m;k++){	//子树是一个m叉树
      x[i]=k;//给第i个顶点着第k种颜色
      if(OK(i))
          getsum(i+1);
      x[i]=0;//如果给第i个顶点着第k种颜色不可行
      //不涂色，便于后续涂色
    }
  }
  return ;//如果当前节点所有颜色都不可行，结束对子树的遍历，返回
}
int main(){
  cout<<"请输入定点数，边数，着色种类数："<<endl;
  cin>>n>>k>>m;//输入定点数，边数，着色种类数
  int x,y;
  memset(a,0,sizeof(a));//给邻接矩阵赋初值
  cout<<"请输入该图的一条边（u，v）："<<endl;
  for(int i=1;i<=k;i++){
      cin>>x>>y;
      a[x][y]=a[y][x]=1;//生成邻接矩阵
  }
  getsum(1);
  if (sum==0) cout<<"NO"<<endl;
  else cout<<"最大可行的着色方案数为："<<sum;//输出最大可行的着色方案数，sum初始值为0
  return 0;
}

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
using namespace std;

const int N=15;
 
int main()
{
  int t[N]={0,1,5,3,10,2}; //任务对应所需的时间
  int m[N][N]; //时间矩阵
  int bp[N][N]={0}; //记录选择状态
  int flag[N]={0}; //初始化任务选择状态，为1代表其中一个机器选择该任务
  int middle=0; //时间总和的一半，实际为背包的最大容量
  int sumTime=0; //时间的总和
  int n=6;

  for(int i=1;i<n;i++){
    sumTime+=t[i];
  }

  middle=sumTime/2;

  memset(m,0,sizeof(m));//初始化矩阵
 
  //01背包问题
  for(int i=1;i<n;i++){
    for(int j=0;j<=middle;j++){   
      if(j>=t[i]){
        if(m[i-1][j]<m[i-1][j-t[i]]+t[i]) bp[i][j]=i;
        // cout<<m[i-1][j]<<" "<<m[i-1][j-t[i]]<<" "<<m[i-1][j-t[i]]+t[i]<<endl;
        m[i][j]=max(m[i-1][j],m[i-1][j-t[i]]+t[i]);
      }
      else{
        // cout<<m[i-1][j]<<endl;
        m[i][j]=m[i-1][j];
      }
    }
  }

  cout<<"总时间矩阵为："<<endl;
  for(int i=1;i<n;i++){
    for(int j=1;j<=middle;j++){
        cout<<setw(2)<<m[i][j]<<' ';
    }
    cout<<endl;
  }

  // 可以选择获取
  // for(int i=1;i<n;i++){
  //   for(int j=0;j<=middle;j++){
  //     cout<<bp[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }

  //从最后开始遍历，获取任务
  int i=n,j=middle;
  while (j && i) {
		if (!bp[i][j]) {
        i--;
        continue;
		}
    flag[i]=1;
		j -= t[i];
		i--;
	}

  cout<<"第1个机器的任务:";
  for(int i=1;i<n;i++){
    if(flag[i]) cout<<"t"<<i<<" ";
  }
  cout<<endl;
  cout<<"第2个机器的任务:";
  for(int i=1;i<n;i++){
    if(!flag[i]) cout<<"t"<<i<<" ";
  }
  cout<<endl;
     
  //输出最短时间
  cout<<"最短时间为："<<m[n-1][middle]<<endl;
}


// output：
// 总时间矩阵为：
//  1  1  1  1  1  1  1  1  1  1 
//  1  1  1  1  5  6  6  6  6  6 
//  1  1  3  4  5  6  6  8  9  9 
//  1  1  3  4  5  6  6  8  9 10 
//  1  2  3  4  5  6  7  8  9 10 
// 第1个机器的任务:t4 
// 第2个机器的任务:t1 t2 t3 t5 
// 最短时间为：10
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
  int t[N]={0,1,5,3,10,2}; //�����Ӧ�����ʱ��
  int m[N][N]; //ʱ�����
  int bp[N][N]={0}; //��¼ѡ��״̬
  int flag[N]={0}; //��ʼ������ѡ��״̬��Ϊ1��������һ������ѡ�������
  int middle=0; //ʱ���ܺ͵�һ�룬ʵ��Ϊ�������������
  int sumTime=0; //ʱ����ܺ�
  int n=6;

  for(int i=1;i<n;i++){
    sumTime+=t[i];
  }

  middle=sumTime/2;

  memset(m,0,sizeof(m));//��ʼ������
 
  //01��������
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

  cout<<"��ʱ�����Ϊ��"<<endl;
  for(int i=1;i<n;i++){
    for(int j=1;j<=middle;j++){
        cout<<setw(2)<<m[i][j]<<' ';
    }
    cout<<endl;
  }

  // ����ѡ���ȡ
  // for(int i=1;i<n;i++){
  //   for(int j=0;j<=middle;j++){
  //     cout<<bp[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }

  //�����ʼ��������ȡ����
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

  cout<<"��1������������:";
  for(int i=1;i<n;i++){
    if(flag[i]) cout<<"t"<<i<<" ";
  }
  cout<<endl;
  cout<<"��2������������:";
  for(int i=1;i<n;i++){
    if(!flag[i]) cout<<"t"<<i<<" ";
  }
  cout<<endl;
     
  //������ʱ��
  cout<<"���ʱ��Ϊ��"<<m[n-1][middle]<<endl;
}


// output��
// ��ʱ�����Ϊ��
//  1  1  1  1  1  1  1  1  1  1 
//  1  1  1  1  5  6  6  6  6  6 
//  1  1  3  4  5  6  6  8  9  9 
//  1  1  3  4  5  6  6  8  9 10 
//  1  2  3  4  5  6  7  8  9 10 
// ��1������������:t4 
// ��2������������:t1 t2 t3 t5 
// ���ʱ��Ϊ��10
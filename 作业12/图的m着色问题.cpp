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

int n;//ͼһ����n������
int m;//m����ɫ��ѡ��
int k;//ͼ����k����
int sum=0;//ͼ��m��ɫ����
int x[101];//��ŵ�ǰ����ɫ����
int a[101][101];//ͼ���ڽӾ���

//�жϸ���t��ɫΪx[t]�Ƿ����
bool OK(int t){
	//���е������ǵ�ǰ�����ڵĵ㲻����֮ͬɫ
  for(int i=1;i<t;i++)
    if(a[i][t]==1&&x[i]==x[t])
      return false;
	//���������֮���ڵĵ㶼����֮ͬɫ
  return true;
}

void getsum(int i){
  //i>n˵���ҵ���һ�����е�Ϳɫ����
  if(i>n){
    sum++;//Ϳɫ������++

    //���������
    for(int k=1;k<=n;k++)
      cout<<x[k]<<" ";
    cout<<endl;
    return ;
  }
  //��û�е�Ҷ�ӽڵ㣬��Ҫ����ǰ�ڵ���е�Ϳɫ
  else{
    for(int k=1;k<=m;k++){	//������һ��m����
      x[i]=k;//����i�������ŵ�k����ɫ
      if(OK(i))
          getsum(i+1);
      x[i]=0;//�������i�������ŵ�k����ɫ������
      //��Ϳɫ�����ں���Ϳɫ
    }
  }
  return ;//�����ǰ�ڵ�������ɫ�������У������������ı���������
}
int main(){
  cout<<"�����붨��������������ɫ��������"<<endl;
  cin>>n>>k>>m;//���붨��������������ɫ������
  int x,y;
  memset(a,0,sizeof(a));//���ڽӾ��󸳳�ֵ
  cout<<"�������ͼ��һ���ߣ�u��v����"<<endl;
  for(int i=1;i<=k;i++){
      cin>>x>>y;
      a[x][y]=a[y][x]=1;//�����ڽӾ���
  }
  getsum(1);
  if (sum==0) cout<<"NO"<<endl;
  else cout<<"�����е���ɫ������Ϊ��"<<sum;//��������е���ɫ��������sum��ʼֵΪ0
  return 0;
}

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
    int v[N]={0,8,10,6,3,7,2};//��ֵ
    int w[N]={0,4,6,2,2,5,1};//����
 
 
    int m[N][N];//�ܼ�ֵ����
    int n=6,c=12;
    memset(m,0,sizeof(m));//��ʼ������
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=c;j++)
        {   

            if(j>=w[i]){
                //ѡ�벻ѡ��ѡ���ܼ�ֵ����һ��
                // cout<<m[i-1][j]<<" "<<m[i-1][j-w[i]]+v[i]<<endl;
                m[i][j]=max(m[i-1][j],m[i-1][j-w[i]]+v[i]);
            }
            else{
                //��������
                //cout<<m[i-1][j]<<endl;
                m[i][j]=m[i-1][j];
            }
                
        }
    }
 
    cout<<"�ܼ�ֵ����Ϊ��"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=c;j++)
        {
            cout<<setw(2)<<m[i][j]<<' ';
        }
        cout<<endl;
    }
    
    //�������ֵ
    cout<<"����ֵΪ��"<<m[n][c]<<endl;
 
    return 0;
}

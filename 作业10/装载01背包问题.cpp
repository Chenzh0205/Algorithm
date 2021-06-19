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
    int v[N]={0,8,10,6,3,7,2};//价值
    int w[N]={0,4,6,2,2,5,1};//重量
 
 
    int m[N][N];//总价值矩阵
    int n=6,c=12;
    memset(m,0,sizeof(m));//初始化矩阵
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=c;j++)
        {   

            if(j>=w[i]){
                //选与不选，选择总价值最大的一种
                // cout<<m[i-1][j]<<" "<<m[i-1][j-w[i]]+v[i]<<endl;
                m[i][j]=max(m[i-1][j],m[i-1][j-w[i]]+v[i]);
            }
            else{
                //重量不够
                //cout<<m[i-1][j]<<endl;
                m[i][j]=m[i-1][j];
            }
                
        }
    }
 
    cout<<"总价值矩阵为："<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=c;j++)
        {
            cout<<setw(2)<<m[i][j]<<' ';
        }
        cout<<endl;
    }
    
    //输出最大价值
    cout<<"最大价值为："<<m[n][c]<<endl;
 
    return 0;
}

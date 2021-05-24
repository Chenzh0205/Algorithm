#include <iostream>
#include <cmath>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <sstream>
using namespace std;

const int MAX=2147483647;
int const M=5;
void Matrix_chain_multiplication(int *p,int Length,int m[][M],int s[][M])
{
	int q,n=Length-1;
	for(int i=1;i<=n;i++) m[i][i]=0;
	for(int l=2;l<=n;l++) 	
	{   // 矩阵链的长度
		for(int i=1;i<=n-l+1;i++) 
		{
			int j=i+l-1;         // 等价于 l=j-i+1 
			m[i][j]=MAX;
			for(int k=i;k<=j-1;k++)
			{   
				q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]; // 通式 
                // 选择最小的值
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
}
//输出最优解括号化方案
void print(int s[][M],int i,int j)
{
	if(i == j) cout<<"A"<<i;
	else
	{
		cout<<"(";
		print(s,i,s[i][j]);
		print(s,s[i][j]+1,j);
		cout<<")";
	}
}
int main()
{
   int p[M]={10,5,4,6,8};
   int m[M][M],s[M][M];
   Matrix_chain_multiplication(p,M,m,s);
   cout<<"当n=4时最优解为: \n"<<m[1][4];
   cout<<"\n括号化方案为：\n"; 
   print(s,1,4);
   return 0;
}

// output:
// 当n=4时最优解为:
// 712
// 括号化方案为：
// ((A1A2)(A3A4))
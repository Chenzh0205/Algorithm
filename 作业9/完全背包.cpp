#include <iostream>
#include <cmath>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <fstream>
using namespace std;

int main(){
    int totalWeight,n;
    cout<<"请输入背包容量和数量："<<endl;
    cin>>totalWeight>>n;
    
    int w[n+1]={0};
    int v[n+1]={0};
    
    cout<<"请输入物品重量和价值："<<endl;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    
    int dp[totalWeight+1] = { 0 };

    for (int i = 1; i <= n; i++)
        for (int j = w[i]; j <= totalWeight;j++)
                dp[j] = max(dp[j],dp[j - w[i]] + v[i]);

    cout << "总的价值为: " << dp[totalWeight] << endl;
    return 0;
}

//input:
//10 4
//2 1
//3 3
//4 5
//7 9
//output:
//12

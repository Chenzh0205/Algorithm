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
char a[100],b[100];
int dp[100][100];

int main() {
    cin>>a+1>>b+1;
    int len1=strlen(a+1);
    int len2=strlen(b+1);
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(a[i]==b[j])  dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[len1][len2]<<endl;
}


//input:
//ABCBDAB
//BDCABA
//OUTPUT:
//4
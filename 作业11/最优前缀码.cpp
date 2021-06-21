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
#define MAX_SIZE 100  

#define MIN_NUM 1000000  
using namespace std;
  

struct hfmcode{  
    int weight;  
    int lchild;  
    int rchild;  
    int parent;
    string code; 
    string ch;
};  
void initHuffmantree(struct hfmcode *tree, int len)  {  
    int i; 
    for(i = 0; i < len; i ++){  
        tree[i].weight = 0;  
        tree[i].lchild = -1;  
        tree[i].rchild = -1;  
        tree[i].parent = -1;  
    }  
}  

void createHuffmantree(struct hfmcode *tree, int n, int m){  
    int m1, m2, i, loc1, loc2, k;
    for(i = n; i < m; i ++){  
        /*初始化最小值、次小值*/  
        m1 = m2 = MIN_NUM;  
        loc1 = loc2 = -1;  
        /*在尚未构造二叉树的节点中查找权值最小的两棵树*/ 
        for(k = 0; k < i; k ++){  
            if(tree[k].parent == -1){  
                if(tree[k].weight < m1){  
                    m2 = m1;  
                    loc2 = loc1;  
                    m1 = tree[k].weight;  
                    loc1 = k;  
                }else if(tree[k].weight < m2){  
                    m2 = tree[k].weight;  
                    loc2 = k;  
                }  
            }  
        }  
        /*修改2个小权重节点的双亲*/ 
        tree[loc1].parent = i;  
        tree[loc2].parent = i;  

        /*修改parent的权重*/   
        tree[i].weight = tree[loc1].weight + tree[loc2].weight;  

        /*修改parent的孩子*/    
        tree[i].lchild = loc1;  
        tree[i].rchild = loc2;  
    }  
}  

void Huff_Code(struct hfmcode *tree, int n)
{
  int i, j, k;
  string s = "";
  for (i = 0; i < n; i++){
    s = "";
    j = i;
    while (tree[j].parent != -1){ //遍历哈夫曼树
      k = tree[j].parent;
      if (j == tree[k].lchild) //左子树为0，右子树为1
        s = s + "0";
      else
        s = s + "1";
      j = tree[j].parent;
    }
    cout << "字符 " << tree[i].ch << " 的编码为：";
    for (int l = s.size() - 1; l >= 0; l--){
      cout << s[l];
      tree[i].code += s[l]; //保存编码
    }
    cout << endl;
  }
}
int main()  

{  
    int n, m, i;  
    struct hfmcode hfmtree[MAX_SIZE];  
    cout<<"请输入编码的字符数：";
    cin>>n;
    /*哈夫曼树总共结点数*/  
    m = 2 * n - 1;  
    /*初始化哈夫曼树*/  
    initHuffmantree(hfmtree, m);  
    /*权限赋值*/  
    cout<<"请输入字符和对应的权重，如（A 30）："<<endl;
    for(i = 0; i < n; i ++)  
    {  
        cin>>hfmtree[i].ch>>hfmtree[i].weight;  
    }  

    /*构造哈夫曼树*/ 
    createHuffmantree(hfmtree, n, m);  
    /*遍历树获取哈夫曼编码*/  
    Huff_Code(hfmtree,n);  
    return 0;  

}  


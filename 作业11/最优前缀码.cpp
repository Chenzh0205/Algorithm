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
        /*��ʼ����Сֵ����Сֵ*/  
        m1 = m2 = MIN_NUM;  
        loc1 = loc2 = -1;  
        /*����δ����������Ľڵ��в���Ȩֵ��С��������*/ 
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
        /*�޸�2��СȨ�ؽڵ��˫��*/ 
        tree[loc1].parent = i;  
        tree[loc2].parent = i;  

        /*�޸�parent��Ȩ��*/   
        tree[i].weight = tree[loc1].weight + tree[loc2].weight;  

        /*�޸�parent�ĺ���*/    
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
    while (tree[j].parent != -1){ //������������
      k = tree[j].parent;
      if (j == tree[k].lchild) //������Ϊ0��������Ϊ1
        s = s + "0";
      else
        s = s + "1";
      j = tree[j].parent;
    }
    cout << "�ַ� " << tree[i].ch << " �ı���Ϊ��";
    for (int l = s.size() - 1; l >= 0; l--){
      cout << s[l];
      tree[i].code += s[l]; //�������
    }
    cout << endl;
  }
}
int main()  

{  
    int n, m, i;  
    struct hfmcode hfmtree[MAX_SIZE];  
    cout<<"�����������ַ�����";
    cin>>n;
    /*���������ܹ������*/  
    m = 2 * n - 1;  
    /*��ʼ����������*/  
    initHuffmantree(hfmtree, m);  
    /*Ȩ�޸�ֵ*/  
    cout<<"�������ַ��Ͷ�Ӧ��Ȩ�أ��磨A 30����"<<endl;
    for(i = 0; i < n; i ++)  
    {  
        cin>>hfmtree[i].ch>>hfmtree[i].weight;  
    }  

    /*�����������*/ 
    createHuffmantree(hfmtree, n, m);  
    /*��������ȡ����������*/  
    Huff_Code(hfmtree,n);  
    return 0;  

}  


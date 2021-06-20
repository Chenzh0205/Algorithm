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

struct Node
{
  double weight;
  string ch;
  string code;
  int lchild, rchild, parent;
};
void Select(Node huffTree[], int *a, int *b, int n)//找权值最小的两个a和b
{
  int i;
  double weight = 0; //找最小的数
  for (i = 0; i <n; i++)
  {
    if (huffTree[i].parent != -1)   //判断节点是否已经选过
      continue;
    else
    {
      if (weight == 0)
      {
        weight = huffTree[i].weight;
        *a = i;
      }
      else
      {
        if (huffTree[i].weight < weight)
        {
          weight = huffTree[i].weight;
          *a = i;
        }
      }
    }
  }
  weight = 0; //找第二小的数
  for (i = 0; i < n; i++)
  {
    if (huffTree[i].parent != -1 || (i == *a))//排除已选过的数
      continue;
    else
    {
      if (weight == 0)
      {
        weight = huffTree[i].weight;
        *b = i;
      }
      else
      {
        if (huffTree[i].weight < weight)
        {
          weight = huffTree[i].weight;
          *b = i;
        }
      }
    }
  }
  int temp;
  if (huffTree[*a].lchild < huffTree[*b].lchild) //小的数放左边
  {
    temp = *a;
    *a = *b;
    *b = temp;
  }
}
void Huff_Tree(Node huffTree[], int w[], string ch[], int n)
{
  for (int i = 0; i < 2 * n - 1; i++) //初始化过程
  {
    huffTree[i].parent = -1;
    huffTree[i].lchild = -1;
    huffTree[i].rchild = -1;
    huffTree[i].code = "";
  }
  for (int i = 0; i < n; i++)
  {
    huffTree[i].weight = w[i];
    huffTree[i].ch = ch[i];
  }
  for (int k = n; k < 2 * n - 1; k++)
  {
    int i1 = 0;
    int i2 = 0;
    Select(huffTree, &i1, &i2, k); //找权值最小的两个i1，i2，将i1，i2节点合成节点k
    huffTree[i1].parent = k;
    huffTree[i2].parent = k;
    huffTree[k].weight = huffTree[i1].weight + huffTree[i2].weight;
    huffTree[k].lchild = i1;
    huffTree[k].rchild = i2;
  }
}
//编码过程
void Huff_Code(Node huffTree[], int n)
{
  int i, j, k;
  string s = "";
  for (i = 0; i < n; i++)
  {
    s = "";
    j = i;
    while (huffTree[j].parent != -1) //从叶子往上找到根节点
    {
      k = huffTree[j].parent;
      if (j == huffTree[k].lchild) //如果是根的左孩子，则记为0
      {
        s = s + "0";
      }
      else
      {
        s = s + "1";
      }
      j = huffTree[j].parent;
    }
    cout << "字符 " << huffTree[i].ch << " 的编码：";
    for (int l = s.size() - 1; l >= 0; l--)
    {
      cout << s[l];
      huffTree[i].code += s[l]; //保存编码
    }
    cout << endl;
  }
}
//解码过程
string Huff_Decode(Node huffTree[], int n,string s)
{
  cout << "解码后为：";
  string temp = "",str="";//保存解码后的字符串
  for (int i = 0; i < s.size(); i++)
  {
    temp = temp + s[i];
    for (int j = 0; j < n; j++)
    {
      if (temp == huffTree[j].code)
      {
        str=str+ huffTree[j].ch;
        temp = "";
        break;
      }
      else if (i == s.size()-1&&j==n-1&&temp!="")//全部遍历后没有
      {
        str= "解码错误！";
      }
    }
  }
  return str;
}
int main()
{
  //编码过程
  int n;
  cout<<"请输入需要编码的字符个数："<<endl;
  cin>>n;
  Node huffTree[2 * n];
  string str[n];
  int w[n];

  cout<<"请输入字符和对应的权重，如（A 30）："<<endl;
  for(int i=0;i<n;i++)
  {
      cin>>str[i]>>w[i];
  }

  Huff_Tree(huffTree, w, str, n);
  Huff_Code(huffTree, n);

  //解码过程
  while(1){
      int choice;
      cout<<"请选择：1.编码 2.退出"<<endl;
      cin>>choice;
      string s;
      switch (choice)
      {
      case 1:
         cout << "输入编码：";
         cin >> s;
         cout << Huff_Decode(huffTree, n, s)<< endl;
         s="";
         break;
      case 2:
         cout<<"退出成功！"<<endl;
         exit(0);
      default:
         cout<<"请输入正确的数字！"<<endl;
         break;
      }
  }
  return 0;
}




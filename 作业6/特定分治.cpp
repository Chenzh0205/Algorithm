#include <iostream>
#include <cmath>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <sstream>
using namespace std;

void insertsort(int a[], int l, int r)//插入排序从小到大排序
{
	int i, j, key;
	for (i = l + 1; i <= r; ++i)
	{
		key = a[i];
		for (j = i - 1; j >= l && key < a[j]; --j)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = key;
	}
}

int partition(int a[], int l, int r, int pivot)
{
	int x, i = l - 1, j;
	for (j = l; j < r; ++j)
	{
		if (a[j] == pivot)	swap(a[j], a[r]);
	}
	x = a[r];
	for (j = l; j < r; ++j)
	{
		if (a[j] <= x)
		{
			++i;
			swap(a[i], a[j]);
		}
	}
	swap(a[r], a[i + 1]);
	return i + 1;
}

int select(int a[], int l, int r, int k)
{
	int group, i, left, right, mid;
	int pivot, p, lnum;
    //规模小直接排序返回
	if (r - l + 1 <= 5)
	{
		insertsort(a, l, r);
		return a[l + k - 1];
	}
    //分组规模
	group = (r - l + 1 + 5) / 5;
    //遍历分组之后对中位数排序
	for (i = 0; i < group; ++i)
	{
		left = l + 5 * i;
		right = (l + 5 * i + 4) > r ? r : l + 5 * i + 4;
		mid = (left + right) / 2;
		insertsort(a, left, right);
		swap(a[l + i], a[mid]);
	}
    // 测试
    // for(i=1;i<=r-l+1;i++) cout<<a[i]<<" ";
    // cout<<endl;
    // cout<<l+group-1<<" "<<(group+1)/2<<" "<<group<<endl;
	pivot = select(a, l, l + group - 1, (group + 1) / 2);
	p = partition(a, l, r, pivot);
    // cout<<pivot<<" "<<p<<endl;
	if (p-l+1 == k)
		return a[p];
    //判断在左区间还是在右区间
	else if (k <= p-l)
		return select(a, l, p - 1, k);
	else
		return select(a, p + 1, r, k-(p-l)-1);
}

int a[1000];
int n, k;

int main()
{
	cin>>n>>k;
	for (int i = 1; i <= n; ++i)	cin>>a[i];
	cout<<select(a, 1, n, k)<<endl;
} 

//input:
//10 4
//5 8 7 14 96 53 41 70 33 82

//output:
//14
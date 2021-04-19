#include<stdio.h> 
#include <iostream>
using namespace std;
#define N 8

int t[N];

void Merge(int a[],int start,int mid,int end){
    int i=start,j=mid+1,k=start;
    while(i<=mid&&j<=end){
        if(a[i]>a[j])
            t[k++]=a[j++];
        else
            t[k++]=a[i++];
    }
    while(i<=mid)t[k++]=a[i++];
    while(j<=end)t[k++]=a[j++];
    for(int m=start;m<=end;m++)
        a[m]=t[m];
}

void MergeSort(int a[],int start,int end){
    int mid=(start+end)/2;
    if(start<end){
        MergeSort(a,start,mid);
        MergeSort(a,mid+1,end);
        Merge(a,start,mid,end);
    }
}

int main(){
    int a[N]={ 56,46,76,99,67,31,72,87 };
    MergeSort(a,0,N-1);
    for(int i=0;i<N;i++)
        cout<<a[i]<<" ";
}




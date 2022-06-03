// 전형적인 쉽게 생각하면 편함.
//1. 끝나는 시간으로 정렬 후 
//2. 시작시간이 끝보다 크면
//3. 세자.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,temp1,temp2;
    int count=1;
    pair<int,int> arr[100001];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&temp1,&temp2);
        arr[i]={temp2,temp1}; // 끝나는 시간으로 정렬위해 순서바꿈
    }
    sort(arr,arr+n); // 끝나는 시간으로 정렬
    int end=arr[0].first;
    for(int i=1;i<n;i++){
        if(arr[i].second >= end){
            count++;
            end = arr[i].first;
        }
    }
    printf("%d",count);
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dp[301];
int arr[301];
int max(int a,int b){
    return a>b?a:b;
}
void dynamic(int n){
    dp[0]=arr[0];//10
    dp[1]=arr[0]+arr[1];//10 20 -> 30
    dp[2]=max(arr[0]+arr[2], arr[1]+arr[2]);// 20 15 -> 35
    for(int i=3;i<n;i++){
        dp[i]=max(dp[i-3]+arr[i]+arr[i-1],dp[i-2]+arr[i]); // 10 25-> 35 , 30 25 -> 55  
    }
    printf("%d", dp[n-1]);
}
int main(){
    int stairs;
    scanf("%d", &stairs);
    for(int i=0;i<stairs;i++){
        scanf("%d", &arr[i]);
    }
    dynamic(stairs);
}
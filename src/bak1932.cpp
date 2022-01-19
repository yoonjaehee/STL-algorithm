#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[501][501];
int DP[501][501] = {0};
int n,res;
void dp(){
    DP[1][1]=arr[1][1];
    for(int i=2;i<=n;i++){
        for(int t=1;t<=i;t++){ // dp[0][-1] 일경우 불가...
            DP[i][t] = max(DP[i-1][t-1],DP[i-1][t])+arr[i][t];
        }
    }
    for(int i=1;i<=n;i++){
        if(res < DP[n][i]){
            res = DP[n][i];
        }
    }
    printf("%d",res);
}
int main(){
    int temp;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int t=1;t<=i;t++){
            scanf("%d",&temp);
            arr[i][t]=temp;
        }
    }
    res=0;
    dp();
}
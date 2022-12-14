#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int dp[100001];
int before[100001];
int main(){
    int x;
    scanf("%d",&x);
    memset(dp,0,sizeof(int)*(x+1));
    memset(before,0,sizeof(int)*(x+1));
    before[1] = -1;
    for(int i=2;i<=x;i++){
        dp[i] = dp[i-1] + 1;
        before[i] = i-1;
        if((i%2 == 0) && (dp[i] > dp[i/2] + 1)){
            dp[i] = dp[i/2] + 1;
            before[i] = i/2;
        }
        if((i%3 == 0) && dp[i] > dp[i/3] + 1){
            dp[i] = dp[i/3] + 1;
            before[i] = i/3;
        }
    }
    printf("%d\n",dp[x]);
    int temp = x;
    while(temp != 1){
        printf("%d ",temp);
        temp = before[temp];
    }
    printf("1");

}
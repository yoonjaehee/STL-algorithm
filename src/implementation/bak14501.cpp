#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int>> vec;
int main(){
    int n,time,cost,mx;
    scanf("%d",&n);
    int dp[n+1] = {0,};
    for(int i=0;i<n;i++){
        scanf("%d %d",&time,&cost);
        vec.push_back({time,cost});
    }
    mx = 0;
    for(int i=0;i<=n;i++){
        dp[i] = max(mx,dp[i]);
        if(vec[i].first + i <= n){
            dp[vec[i].first + i] = max(vec[i].second + dp[i],dp[vec[i].first + i]);
        }
        mx = max(mx,dp[i]);
    }
    printf("%d",mx);
}
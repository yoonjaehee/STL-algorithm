#include <iostream>
#include <vector>
using namespace std;
int mx = 0;
vector<pair<pair<int,int>,int>> vec;
int main(){
    int n,st,ed;
    scanf("%d",&n);
    int dp[n+1] = {0,};
    for(int i=0;i<n;i++){
        scanf("%d %d",&st,&ed);
        vec.push_back({{i+1,i+st},ed});
    }
    for(int i=0;i<vec.size();i++){
        if(vec[i].first.second > n){
            continue;
        }
        dp[vec[i].first.second] = max(dp[vec[i].first.second],dp[vec[i].first.first-1] + vec[i].second);
        if(mx < dp[vec[i].first.second]){
            mx = dp[vec[i].first.second];
        }
        for(int t=vec[i].first.second+1;t<=n;t++){
            if(dp[t] < dp[vec[i].first.second]){
                dp[t] = dp[vec[i].first.second];
            }
            else{
                break;
            }
        }
    }
    printf("%d",mx);
}

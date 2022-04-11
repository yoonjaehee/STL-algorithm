#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,temp;
    vector<int> vec;
    int res=0;
    scanf("%d", &n);
    vector<int> dp(n,1);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        vec.push_back(temp);
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<i;t++){
            if(vec[t]<vec[i]){
                dp[i] = max(dp[t]+1,dp[i]);
            }
        }
    }
    for(int i=0;i<n;i++){
        res = max(res,dp[i]); 
    }
    printf("%d",res);
}
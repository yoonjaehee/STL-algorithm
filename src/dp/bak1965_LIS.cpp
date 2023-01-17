#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,temp,res;
    scanf("%d",&n);
    int dp[n]={0,};
    vector<int> vec;
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        vec.push_back(temp);
    }
    int len=vec.size();
    for(int k=0;k<len;k++){
        dp[k] = 1;
        for(int i=0;i<k;i++){
            if(vec[i]<vec[k]){
                dp[k] = max(dp[k],dp[i]+1);
            }
        }
    }
    printf("%d",dp[len-1]);
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,k,val;
    int max = 0;
    vector<int> vec;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        vec.push_back(val);
        if(val > max){
            max = val;
        }
    }
    sort(vec.begin(),vec.end(),greater<int>());
    int dp[max+k+1] = {0,};
    int si = vec.size();
    for(int i=0;i<si;i++){ // 큰수마다 돌림
        dp[vec[i]] = 1;
        for(int t=0;t<=k;t++){ // 이미 있는 수들 갯수 더하기
            if(dp[t] != 0){ //  
                if((dp[t+vec[i]] != 0) && (dp[t+vec[i]] > dp[t]+1)){
                    continue;
                }
                else{
                    dp[t+vec[i]]=dp[t]+1;
                }
            }
            else{ // 0일때 
                continue;
            }
        }     
    }
    printf("%d",dp[k]);
}
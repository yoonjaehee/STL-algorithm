#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n,m;
int dp[1001][1001];
int main(){
    scanf("%d %d",&n,&m);
    string str;
    cin.ignore();
    long long res=0;
    for(int i=0;i<n;i++){
        getline(cin,str);
        for(int t=0;t<m;t++){
            dp[i][t] = str[t]-'0';
            if(dp[i][t] == 1 && i>0 && t>0){
                dp[i][t] = min(dp[i-1][t-1],min(dp[i-1][t],dp[i][t-1]))+dp[i][t];
            }
            if(dp[i][t] > res){
                res = dp[i][t];
            }
        }
        
    }
    cout<<res*res;
}
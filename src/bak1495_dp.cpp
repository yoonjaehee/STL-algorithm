// 2차원 배열로 dp[i][x] 에서 i번째 x를 방문했으면 true로 해 최대값 구함.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,s,m;
    scanf("%d %d %d",&n,&s,&m);
    bool DP[n+1][m+1]={false,};
    int temp[n+2]={0,}; 
    for(int i=1;i<=n;i++){
        scanf("%d",&temp[i]);
    }
    if(s+temp[1] <= m){
        DP[1][s+temp[1]] = true;
    }
    if(s-temp[1] >= 0){
        DP[1][s-temp[1]] = true;
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(DP[i-1][j] == true){
                if(j+temp[i] <= m){
                    DP[i][temp[i]+j] = true;
                }
                if(j-temp[i] >= 0){
                    DP[i][j-temp[i]] = true;
                }
            }
        }
    }
    for(int i=m;i>=0;i--){
        if(DP[n][i] == true){
            printf("%d",i);
            return;
        }
    }
    printf("-1");

}
#include <iostream>
#include <vector>
using namespace std;
int n,m;
int arr[501][501];
int dp[501][501];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
void dfs(int y,int x){
    if(y == n-1 && x == m-1){
        return 1;
    }
    if(dp[y][x] != 0){
        return dp[y][x];
    }
    dp[y][x] = 0;
    for(int i=0;i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= 0 && ny < n && nx >= 0 && nx < m){
            if(arr[ny][nx] < arr[y][x]){
                dp[y][x] = dp[y][x] + dfs(ny,nx);
            }
        }
    }
    return dp[y][x];
}
int main(){
    int answer = 0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            scanf("%d",&arr[i][t]);
        }
    }
    answer = dfs(0,0);
    printf("%d",answer);
}
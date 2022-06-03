#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> vec;
int dp[1025][1025];
int main(){
    int n,m,res;
    scanf("%d %d",&n,&m);
    vec = vector<vector<int>>(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int t=1;t<=n;t++){
            scanf("%d",&vec[i][t]);
            dp[i][t] = dp[i-1][t]+dp[i][t-1]-dp[i-1][t-1]+vec[i][t];
        }
    }
    for(int i=0;i<m;i++){
        int x1,x2,y1,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        res = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
        printf("%d\n",res);
    }
}
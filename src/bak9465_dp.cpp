#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int n,t;
int vec[2][100001];
int dp[2][100001];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int sum=0;
        scanf("%d",&t);
        for(int p=1;p<=t;p++){
            scanf("%d",&vec[0][p]);
        }
        for(int p=1;p<=t;p++){
            scanf("%d",&vec[1][p]);
        }
        dp[0][1] = vec[0][1];
        dp[1][1] = vec[1][1];
        dp[0][2] = vec[1][1]+vec[0][2];
        dp[1][2] = vec[0][1]+vec[1][2];
        for(int y=3;y<=t;y++){
            dp[0][y] = max((dp[1][y-2] + vec[0][y]),(dp[1][y-1] + vec[0][y]));
            dp[1][y] = max((dp[0][y-2] + vec[1][y]),(dp[0][y-1] + vec[1][y]));
        }
        sum = max(dp[0][t],dp[1][t]);
        printf("%d",sum);
    }
}
#include <iostream>
#include <algorithm>
using namespace std;
int w[101]={0,};
int v[101]={0,};
int DP[101][100001];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&w[i],&v[i]);
    }
    for(int i=1;i<=n;i++){
        for(int t=1;t<=k;t++){
            if(t>=w[i]){
                DP[i][t] = max(DP[i-1][t],DP[i-1][t-w[i]] + v[i]);
            }
            else{
                DP[i][t] = DP[i-1][t];
            }
        }
    }
    printf("%d",DP[n][k]);
}
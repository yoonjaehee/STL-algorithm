#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main(){
    int n,m,temp,a,b;
    scanf("%d %d",&n,&m);
    vector<int> vec;
    vector<pair<int,int>> res;
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        vec.push_back(temp);
    }
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        res.push_back({a,b});
    }
    int DP[100001]={0,};
    memset(DP,0,sizeof(int)*(n+2));
    DP[0] = 0;
    DP[1] = vec[0];
    for(int i=2;i<n+1;i++){
        DP[i] = DP[i-1]+vec[i-1];
    }
    for(int i=0;i<m;i++){
        printf("%d",DP[res[i].second] - DP[res[i].first -1]);
    }
}
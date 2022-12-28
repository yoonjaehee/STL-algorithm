#include <iostream>
#include <vector>
using namespace std;
int n,k;
vector<int> vec;
int main(){
    int val;
    int max = 0;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        vec.push_back(val);
        if(val > max){
            max = val; 
        }
    }
    int dp[k+1+max]={0,};
    int t = vec.size();
    dp[0] = 1;
    for(int i=0;i<t;i++){
        dp[vec[i]]++;
        for(int p=1;p<=k;p++){
            dp[p+vec[i]]+=dp[p];
        }
    }
    for(int i=0;i<=k;i++){
        printf("%d:%d ",i,dp[i]);
    }
}
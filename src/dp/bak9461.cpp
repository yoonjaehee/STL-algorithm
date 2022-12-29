#include <iostream>
#include <vector>
using namespace std;
long long dp[101]={0,};
vector<int> vec;
int main(){
    int t,temp;
    int max = 0;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&temp);
        vec.push_back(temp);
        if(temp > max){
            max = temp;
        }
    }
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 2;
    dp[5] = 3;
    dp[6] = 4;
    dp[7] = 5;
    dp[8] = 7;
    dp[9] = 9;
    for(int i=10;i<=max;i++){
        dp[i] = dp[i-2] + dp[i-3];
    }
    for(int i=0;i<vec.size();i++){
        printf("%lld\n",dp[vec[i]-1]);
    }
}
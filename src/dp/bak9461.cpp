#include <iostream>
#include <vector>
using namespace std;
int dp[101]={0,};
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
    for(int i=5;i<=max;i++){
        dp[i] = dp[i-1] + dp[i-5];
    }
    for(int i=0;i<vec.size();i++){
        printf("%d\n",dp[vec[i]-1]);
    }
}
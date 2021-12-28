#include <iostream>
#include <vector>
using namespace std;
vector<int> dp;
int main(){
    int num;
    scanf("%d", &num);
    dp.push_back(1);
    dp.push_back(2);
    for(int i=2;i<num;i++){
        dp.push_back((dp[i-1]+dp[i-2])%10007);
    }
    printf("%d",dp[num-1]);
}
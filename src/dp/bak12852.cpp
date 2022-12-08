#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int mx = INT_MAX;
vector<int> res;
priority_queue<int,vector<int>,greater<int>> pq;
void DP(int start,int count,vector<int> vec){
    vector<int> ans;
    if(start == 1){
        if(mx > count){
            mx = count;
            res = vec;
        }
        return;
    }
    if(start%3 == 0){
        ans = vec;
        ans.push_back(start/3);
        DP(start/3,count+1,ans);
    }
    if(start%2 == 0){
        ans = vec;
        ans.push_back(start/2);
        DP(start/2,count+1,ans);
    }
    ans = vec;
    ans.push_back(start-1);
    DP(start-1,count+1,ans);
}
int main(){
    int x;
    vector<int> temp;
    scanf("%d",&x);
    temp.push_back(x);
    DP(x,0,temp);
    printf("%d\n",mx);
    for(int i=0;i<res.size();i++){
        printf("%d ",res[i]);
    }
}
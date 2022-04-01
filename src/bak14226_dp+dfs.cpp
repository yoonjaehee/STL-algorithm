#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int s;
vector<int> dp;
queue<pair<int,int>> q;
void bfs(int start){
    q.push({1,0});
    while(!q.empty()){
        pair<int,int> cur=q.front();
        q.pop();
        if(cur.first == s){
            return cur.second;
        } 
        if(cur.first > )
    }
}
int main(){
    scanf("%d",&s);
    visited = vector<int>(s+1,false);
    dp = vector<int>(s+1,0);
    bfs(1);
    printf("%d",dp[s]);
}
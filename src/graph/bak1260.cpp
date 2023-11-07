#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
int n,m,start;
vector<vector<int>> vec;
bool visited[1001];
queue<int> q;
void bfs(int st){
    visited[st] = true;
    q.push(st);
    while(!q.empty()){
        int py=q.front();
        printf("%d ",py);
        q.pop();
        for(int i=0;i<vec[py].size();i++){
            if(!visited[vec[py][i]]){
                visited[vec[py][i]] = true;
                q.push(vec[py][i]);
            }
        }
    }
}
void dfs(int st){
    visited[st] = true;
    for(int i=0;i<vec[st].size();i++){
        if(!visited[vec[st][i]]){
            visited[vec[st][i]] = true;
            printf("%d ",vec[st][i]);
            dfs(vec[st][i]);
        }
    }
}
int main(){
    scanf("%d %d %d",&n,&m,&start);
    vec.resize(n+1);
    for(int i=0;i<m;i++){
        int temy,temx;
        scanf("%d %d",&temy,&temx);
        vec[temy].push_back(temx);
        vec[temx].push_back(temy);
    }
    for(int i=1;i<=n;i++){
        sort(vec[i].begin(),vec[i].end());
    }
    printf("%d ",start);
    dfs(start);
    memset(visited,false,sizeof(bool)*(n+1));
    printf("\n");
    bfs(start);
}
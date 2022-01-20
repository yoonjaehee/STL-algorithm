//트리의 지름 구하기... dfs 이용.
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n,temp,ed,res;
vector<pair<int,int>> graph[10001];
bool visited[10001]={false,};
void dfs(int start,int len){
    if(visited[start]){
        return;
    }
    if(res < len){
        res=len;
        ed=start;
    }
    visited[start]=true;
    for(int t=0;t<graph[start].size();t++){
        pair<int,int> cur=graph[start][t];
        dfs(cur.first,len+cur.second);
    }
}
int main(){
    int s,e,t;
    ed=0;
    res=0;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        scanf("%d %d %d",&s,&e,&t);
        graph[s].push_back({e,t});
        graph[e].push_back({s,t});
    }
    dfs(1,0);
    memset(visited,false,sizeof(visited));
    dfs(ed,0);
    printf("%d",res);
}
//트리의 지름 구하기... dfs 이용.
#include <iostream>
#include <vector>
using namespace std;
int n,temp,end,res;
vector<pair<int,int>> graph[10001];
bool visited[10001]={false,};
void dfs(int start,int len){
    visited[start]=true;
    for(int t=0;t<graph[start].size();t++){
        pair<int,int> cur=graph[start][t];
        if(!visited[cur.first]){
            dfs(cur.first,cur.second);
            end=cur.first;
            res=cur.second;
        }
    }
}
int main(){
    int s,e,t;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&s,&e,&t);
        graph[s].push_back({e,t});
        graph[e].push_back({s,t});
    }
    dfs(1,0);
    memset(visited,false,sizeof(visited));
    dfs(end,0);
    printf("%d",len);
}
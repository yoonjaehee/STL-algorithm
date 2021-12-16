#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<vector<int>> adj;
vector<bool>visited;
void dfs(int number){
    visited[number]=true;
    for(int t=0;t<n;t++){
        if(!visited[t] && adj[number][t]==1){
            dfs(t);
        }
    }

}
int main(){
    int start,end;
    int res=0;
    scanf("%d %d", &n,&m);
    adj = vector<vector<int>>(n,vector<int>(n,0));
    visited = vector<bool>(n,false);
    for(int i=0;i<m;i++){
        scanf("%d %d", &start, &end);
        adj[start-1][end-1]=1;
        adj[end-1][start-1]=1;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i);
            res++;
        }
    }
    printf("%d", res);
}
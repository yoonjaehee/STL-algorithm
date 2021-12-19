#include <iostream>
#include <vector>
using namespace std;
vector<int> adj[101];
vector<int> visited;
void dfs(int p){
    for(int i=0;i<adj[p].size();i++){
        if(!visited[adj[p][i]]){
            visited[adj[p][i]]=1;
            dfs(adj[p][i]);
        }
    }
}
int main(){
    int num,tem;
    scanf("%d", &num);
    for(int i=0;i<num;i++){
        for(int t=0;t<num;t++){
            scanf("%d",&tem);
            if(tem){
                adj[i].push_back(t);
            }
        }
    }
    for(int i=0;i<num;i++){
        visited=vector<int>(num);
        dfs(i);
        for(int t=0;t<num;t++){
            printf("%d ", visited[t]);
        }
        printf("\n");
    }
}
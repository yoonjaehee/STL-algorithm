#include <iostream>
#include <vector>
using namespace std;
int n,m,h,count;
vector<vector<int>> adj;
vector<vector<bool>>visited;
int px[6], py[6];
void dfs(int x, int y){
    visited[x][y]=true;
    for(int i=0;i<6;i++){
        int nx = x + px[i];
        int ny = y + py[i];
        if(nx>=0 && nx<n && ny>=0 && ny<(m*h)){
            if(adj[nx][ny]==0 && !visited[nx][ny]){
                adj[nx][ny]=1;
                dfs(nx,ny);
            }
        }
    }
    count++;
}
int main(){
    int tom;
    count = 0; 
    scanf("%d %d %d", &n,&m,&h);
    int px[]={1,-1,0,0,0,0};
    int py[]={0,0,1,-1,(-1*h),h};
    int cols=m*h;
    for(int p=0;p<h;p++){
        for(int i=0;i<n;i++){
            for(int t=0;t<m;t++){
                scanf("%d ", &tom);
                adj[i][t+(p*t)] = tom;
            }
        }
    }
    visited= vector<vector<bool>>(n,vector<bool>(m*h,false));
    for(int i=0;i<n;i++){
        for(int t=0;t<cols;t++){
            if(!visited[i][t] && adj[i][t]==1){
                dfs(i,t);
                count++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<cols;t++){
            if(adj[i][t]==0){
                printf("-1");
                return 0;
            }
        }
    }
    printf("%d", count);
}
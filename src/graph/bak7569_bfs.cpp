#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m,h,count=0;
int adj[101][101][101];
int px[6]={1,-1,0,0,0,0};
int py[6]={0,0,1,-1,0,0};
int ph[6]={0,0,0,0,1,-1};
queue<pair<pair<int,int>,int>>q;
int max(int a, int b){
    return a > b ? a : b;
}
void bfs(){
    while(!q.empty()){
        pair<pair<int,int>,int> current = q.front();
        q.pop();
        for(int i=0;i<6;i++){
            int nx = current.first.first + px[i];
            int ny = current.first.second + py[i];
            int nh = current.second + ph[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && nh>=0 && nh<h){
                if(adj[nx][ny][nh]==0){
                    adj[nx][ny][nh]=adj[current.first.first][current.first.second][current.second]+1;
                    q.push({{nx,ny},nh});
                }
            }
        }
    }  
}
int main(){
    int tom,start,Max=0;
    scanf("%d %d %d",&n,&m,&h);
    for(int p=0;p<h;p++){
        for(int i=0;i<m;i++){
            for(int t=0;t<n;t++){
                scanf("%d", &adj[t][i][p]);
                if(adj[t][i][p]==1){
                    q.push({{t,i},p});
                }
            }
        }
    }
    bfs();
    for(int p=0;p<h;p++){
        for(int i=0;i<m;i++){
            for(int t=0;t<n;t++){
                if(adj[t][i][p]==0){
                    printf("-1");
                    return 0;
                }
                Max = max(Max,adj[t][i][p]);
            }
        }
    }
    printf("%d", Max-1);
}
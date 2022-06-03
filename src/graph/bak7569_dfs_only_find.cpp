#include <iostream>
#include <vector>
using namespace std;
int n,m,h,count=0;
int adj[101][101][101];
vector<vector<vector<bool>>>visited;
int px[6]={1,-1,0,0,0,0};
int py[6]={0,0,1,-1,0,0};
int ph[6]={0,0,0,0,1,-1};
int max(int a, int b){
    return a > b ? a : b;
}
void dfs(int x, int y, int z){
    visited[x][y][z]=true;
    for(int i=0;i<6;i++){
        int nx = x + px[i];
        int ny = y + py[i];
        int nh = z + ph[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m && nh>=0 && nh<h){
            if((adj[nx][ny][nh]==0) && (!visited[nx][ny][nh])){
                adj[nx][ny][nh]=adj[x][y][z]+1;
                dfs(nx,ny,nh);
            }
        }
    }
    count++;
}
int main(){
    int tom;
    int Max=0;
    scanf("%d %d %d",&n,&m,&h);
    visited=vector<vector<vector<bool>>>(n,vector<vector<bool>>(m,vector<bool>(h,false)));
    for(int p=0;p<h;p++){
        for(int i=0;i<m;i++){
            for(int t=0;t<n;t++){
                scanf("%d", &tom);
                adj[t][i][p] = tom;
            }
        }
    }
    for(int p=0;p<h;p++){
        for(int i=0;i<m;i++){
            for(int t=0;t<n;t++){
                if(!visited[t][i][p] && adj[t][i][p]==1){
                    dfs(t,i,p);
                }
            }
        }
    }
    for(int p=0;p<h;p++){
        for(int i=0;i<m;i++){
            for(int t=0;t<n;t++){
                printf("%d ",adj[t][i][p]);
            }
            printf("\n");
        }
    }
    for(int p=0;p<h;p++){
        for(int i=0;i<m;i++){
            for(int t=0;t<n;t++){
                if(adj[t][i][p]==0){
                    printf("-1");
                    return 0;
                }
            }
        }
    }
    printf("%d", count);
}
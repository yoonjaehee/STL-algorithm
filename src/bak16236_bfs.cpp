#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m;
int baby = 2;
int arr[20][20];
int ax[4] = {0,0,1,-1};
int ay[4] = {1,-1,0,0};
queue<pair<int,int>> q;
vector<vector<int>> visited;
void bfs(){
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + ax[i];
            int ny = cur.second + ay[i];
            if(nx<0 || nx>=n || ny<0 || ny>=n){ // out of range
                continue;
            }
            if(visited[nx][ny]==0 && arr[nx][ny]<=baby){
                visited[nx][ny]=visited[cur.first][cur.second]+1;
                if(arr[nx][ny] < baby && arr[nx][ny] > 0){
                    if(distance >= visited[nx][ny]){
                        distance = visited[nx][ny];
                    }
                }
            }
            q.push({nx,ny});
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    visited = vector<vector<int>>(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&arr[i][t]);
            if(arr[i][t]==9){
                q.push({i,t});
            }
        }
    }
    bfs();

}
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n,m;
int px[4]={0,0,-1,1};
int py[4]={1,-1,0,0};
char graph[1001][1001]={0,};
queue<pair<pair<int,int>,int>> q;
int visited[1001][1001][2]={0,};
int cur_x,cur_y,block,nx,ny;
int bfs(){
    q.push({{0,0},1});
    visited[0][0][1]=1;
    while(!q.empty()){
        cur_x = q.front().first.second;
        cur_y = q.front().first.first;
        block = q.front().second;
        q.pop();
        if((cur_x == m) && (cur_y == n)){
            return visited[cur_y][cur_x][block];
        }
        for(int i=0;i<4;i++){
            int nx = cur_x + px[i];
            int ny = cur_y + py[i];
            if(nx>=0 && nx<m && ny>=0 && ny<n){
                if(graph[ny][nx]=='0' && visited[ny][nx][block] == 0){
                    visited[ny][nx][block] = visited[cur_y][cur_x][block]+1;
                    q.push({{ny,nx},block});
                }
                if(graph[ny][nx]=='1' && block){
                    visited[ny][nx][block-1] = visited[cur_y][cur_x][block]+1;
                    q.push({{ny,nx},block-1});
                }
            }
        }
    }
    return -1;
}
int main(){
    int res;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",&graph[i][0]);
    }
    res = bfs();
    printf("%d",res);
}
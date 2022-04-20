#include <iostream>
#include <algorithm>
using namespace std;
int cnt,n,m;
int arr[101][101]={0,};
bool visited[101][101] = {false,};
int px[4] = {1,-1,0,0};
int py[4] = {0,0,1,-1};
void dfs(int y,int x){
    visited[y][x] = true;
    for(int i=0;i<4;i++){
        int nx = x + px[i];
        int ny = y + py[i];
        if(visited[ny][nx] == false && arr[ny][nx] == 1){
            if(ny>0 && nx>0 && ny<=n && nx<=m){
                cnt++;
                dfs(ny,nx);
            }
        }
    }
}
int main(){
    int k,temp_x,temp_y;
    int res = 0;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<k;i++){
        scanf("%d %d",&temp_y,&temp_x);
        arr[temp_y][temp_x] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int t=1;t<=m;t++){
            if(visited[i][t] == false && arr[i][t] == 1){
                cnt=1;
                dfs(i,t);
                res = max(res,cnt);
            }
        }
    }
    printf("%d",res);
}
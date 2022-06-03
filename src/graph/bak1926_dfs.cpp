#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[501][501]={0,};
int n,m;
int cnt;
int px[4] = {1,-1,0,0};
int py[4] = {0,0,1,-1};
bool visited[501][501] = {false,};
void dfs(int y,int x){
    visited[y][x] = true;
    cnt++;
    for(int i=0;i<4;i++){
        int nx = x + px[i];
        int ny = y + py[i];
        if(nx >=0 && ny >= 0 && nx<m && ny<n){
            if((arr[ny][nx]==1) && !visited[ny][nx]){
                dfs(ny,nx);
            }
        }
    }
}
int main(){
    int img=0;
    int Max=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            scanf("%d",&arr[i][t]);
        }
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            if(!visited[i][t] && arr[i][t] == 1){
                cnt=0;
                img++;
                dfs(i,t);
                Max = max(cnt,Max);
            }
        }
    }
    printf("%d\n",img);
    printf("%d",Max);
}
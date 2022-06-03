#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int arr[101][101];
int ax[4] = {1,-1,0,0};
int ay[4] = {0,0,1,-1};
vector<vector<bool>> visited;
void dfs(int x,int y,int t){
    visited[y][x]=true;
    for(int i=0;i<4;i++){
        int nx = x + ax[i];
        int ny = y + ay[i];
        if(nx>=0 && nx<n && ny>=0 && ny<n){
            if((!visited[ny][nx]) && (arr[ny][nx]>t)){
                dfs(nx,ny,t);
            }
        }
        else{
            continue;
        }  
    }
}
int main(){
    int Max = 0;
    int total = 1;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&arr[i][t]);
            Max = max(Max,arr[i][t]);
        }
    }
    for(int p=1;p<=Max;p++){
        int count =0;
        visited = vector<vector<bool>>(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            for(int t=0;t<n;t++){
                if(arr[i][t]>p && !visited[i][t]){
                    count++;
                    dfs(t,i,p);
                }
            }
        }
        total = max(total, count);
    }
    printf("%d",total);
}
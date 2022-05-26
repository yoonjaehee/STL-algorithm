#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<int> q;
int n;
int count = 0;
int arr[101][101]={0,};
int visited[101]={0,};
void bfs(int start,int end){
    q.push(start);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0;i<=n;i++){
            if(arr[cur][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = visited[cur] + 1;
            }
        } 
    }
}
int main(){
    int start,end,m,x,y,res;
    scanf("%d",&n);
    scanf("%d %d",&start,&end);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    bfs(start,end);
    if(visited[end] == 0){
        visited[end] = -1;
    }
    printf("%d",visited[end]);
}
#include <iostream>
#include <queue>
using namespace std;
int n,m;
int arr[101][101];
int px[4] = {1,-1,0,0};
int py[4] = {0,0,1,-1};
int count1=0;
int count2=0;
queue<pair<int,int>> q;
bool visited[101][101];
void bfs(int x,int y){
    visited[y][x]=true;
    q.push({y,x});
    while(!q.empty()){
        pair<int,int> cur=q.front(); 
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.second + px[i];
            int ny = cur.first + py[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m){
                if((arr[ny][nx] != 0) && (arr[ny][nx] == arr[y][x]) && !visited[ny][nx]){
                    if(arr[ny][nx] == 1){
                        count1++;
                    }
                    else if(arr[ny][nx] == 2){
                        count2++;
                    }
                    visited[ny][nx] = true;
                    q.push({ny,nx});
                }
            }
        }
    }
}
int main(){
    char sol;
    int result1=0;
    int result2=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<101;i++){
        for(int t=0;t<101;t++){
            arr[i][t]=0;
            visited[i][t]=false;
        }
    }
    for(int i=0;i<m;i++){
        for(int t=0;t<n;t++){
            scanf("%1s",&sol);
            if(sol=='W'){
                arr[i][t] = 1; 
            }
            else if(sol=='B'){
                arr[i][t] = 2;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int t=0;t<n;t++){
            if(arr[i][t] == 1 && !visited[i][t]){
                count1=1;
                bfs(t,i);
                result1+=(count1*count1);
            }
            else if(arr[i][t] == 2 && !visited[i][t]){
                count2=1;
                bfs(t,i);
                result2+=(count2*count2);
            }
        }
    }
    printf("%d %d",result1,result2);
    return 0;
}
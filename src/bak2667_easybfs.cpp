#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int num;
queue<pair<int,int>> q;
vector<vector<bool>> visited;
vector<int> total;
int adj[26][26];
int px[4] = {0,0,1,-1};
int py[4] = {1,-1,0,0};
void bfs(int a,int b){
    q.push({a,b});
    visited[a][b]=true;
    int temp=1;
    while(!q.empty()){
        int c=q.front().first;
        int d=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = c+px[i];
            int ny = d+py[i];
            if(nx>=0 && nx<num && ny>=0 && ny<num){
                if(!visited[nx][ny] && adj[nx][ny]==1){
                    q.push({nx,ny});
                    visited[nx][ny]=true;
                    temp++;
                }
            }
            else{
                continue;
            }
        }
    }
    total.push_back(temp);
}
int main(){
    int count=0;
    scanf("%d",&num);
    visited = vector<vector<bool>>(num,vector<bool>(num,false));
    for(int i=0;i<num;i++){
        for(int t=0;t<num;t++){
            scanf("%1d",&adj[i][t]);
        }
    }
    for(int i=0;i<num;i++){
        for(int t=0;t<num;t++){
            if(!visited[i][t] && adj[i][t]==1){
                bfs(i,t);
                count++;
            }
        }
    }
    printf("%d\n",count);
    sort(total.begin(),total.end());
    for(int i=0;i<count;i++){
        printf("%d\n",total[i]);
    }
}
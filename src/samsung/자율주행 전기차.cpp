#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <limits.h>
#include <algorithm>
using namespace std;
int arr[21][21]; // 장애물
int remain[21][21]; // 사람이 남아있나
int stny,stnx,n,m,k;
vector<vector<int>> people; // 사람들 정보
vector<int> dis;
int py[4] = {-1,0,0,1};
int px[4] = {0,-1,1,0};
int res = -1;
int rescue = 0;
bool visited[401];
bool visited2[21][21];
queue<pair<pair<int,int>,int>> q;
int min,tary,tarx;
int cnt = 0;
void bfs(int sty,int stx,int edy,int edx,int idx){
    q = queue<pair<pair<int,int>,int>>();
    q.push({{sty,stx},0});
    for(int i=0;i<n;i++){
        memset(visited2[i],false,sizeof(bool) * n);
    }
    if(sty == edy && stx == edx){
        dis[idx] = 0;
        return;
    }
    visited2[sty][stx] = true;
    while(!q.empty()){
        int tmy = q.front().first.first;
        int tmx = q.front().first.second;
        int cur_bat = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ny = tmy + py[i];
            int nx = tmx + px[i];
            if(ny >= 0 && ny < n && nx >= 0 && nx < n){
                if(arr[ny][nx] == 0 && !visited2[ny][nx]){
                    if(ny == edy && nx == edx){
                        dis[idx] = cur_bat +1;
                        visited2[ny][nx] = true;
                        return;
                    }
                    visited2[ny][nx] = true;
                    q.push({{ny,nx},cur_bat+1});
                } 
            }
        }
    }
    if(!visited2[edy][edx]){
        dis[idx] = -1;
    }
}
void dfs(int starty,int startx,int bat){ 
    if(cnt == m){
        res = bat;
        return;
    }
    cnt+=1;
    int min = INT_MAX;
    int minidx = 0;
    for(int i=0;i<people.size();i++){ // 지금 시점으로부터 시작하는 깃발로 감
        if(!visited[i]){
            bfs(starty,startx,people[i][0],people[i][1],i);
            if(dis[i] == -1){
                return;
            }
            if(dis[i] < min){
                min = dis[i];
                minidx = i;
            }
        }
    }
    if(bat - min < 0){
        return;
    }
    bat -= min;
    printf("cur bat : %d min : %d ||",bat,min);
    visited[minidx] = true;
    bfs(people[minidx][0],people[minidx][1],people[minidx][2],people[minidx][3],minidx); // 도착 하는 지점
    if(dis[minidx] == -1){
        return;
    }
    if((bat - dis[minidx]) < 0){
        return;
    }
    else{
        bat+=dis[minidx];
    }
    printf("%d %d -> %d %d bat : %d\n",people[minidx][0],people[minidx][1],people[minidx][2],people[minidx][3],bat);
    dfs(people[minidx][2],people[minidx][3],bat);
}
int main(){
    int temp;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&arr[i][t]);
        }
    }
    scanf("%d %d",&stny,&stnx);
    for(int i=0;i<m;i++){
        vector<int> temp;
        int sy,sx,ey,ex;
        scanf("%d %d %d %d",&sy,&sx,&ey,&ex);
        temp.push_back(sy-1);
        temp.push_back(sx-1);
        remain[sy-1][sx-1] = i+1;
        temp.push_back(ey-1);
        temp.push_back(ex-1);
        people.push_back(temp);
        dis.push_back(0);
    }
    sort(people.begin(),people.end());
    dfs(stny-1,stnx-1,k);
    printf("%d",res);
}
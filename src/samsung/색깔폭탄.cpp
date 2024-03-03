#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <limits.h>
using namespace std;
int n,m,ny,nx;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int temp[21][21];
int arr[21][21];
bool visited[21][21];
int res = 0;
int mx;
int posy, posx;
queue<pair<int,int>> q;
vector<pair<int,int>> ins_red;
vector<pair<int,int>> rem;
void init(){
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            visited[i][t] = false;
        }
    }
}
int bfs(int sty,int stx,int cnt){
    visited[sty][stx] = true;
    q.push({sty,stx});
    while(!q.empty()){
        pair<int,int> temp = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int ny = temp.first + dy[i];
            int nx = temp.second + dx[i];
            if(!visited[ny][nx] && ny >= 0 && ny < n && nx >= 0 && nx < n){
                if((arr[ny][nx] == arr[sty][stx]) || (arr[ny][nx] == 0)){
                    if(arr[ny][nx] == 0){
                        ins_red.push_back({ny,nx});
                    }
                    cnt+=1;
                    visited[ny][nx] = true;
                    q.push({ny,nx});
                }
            }
        }
    }
    return cnt;
}
void find(){
    init();
    mx = 0;
    int min_red = INT_MAX;
    for(int i=n-1;i>=0;i--){
        for(int t=0;t<n;t++){
            for(int p=0;p<ins_red.size();p++){ // red만 초기화
                visited[ins_red[p].first][ins_red[p].second] = false;
            }
            ins_red.clear();
            if(arr[i][t] == 0){ // 빨간거로만 되어있음 패스
                continue;
            }
            else if(!visited[i][t] && arr[i][t] > 0){
                int comp = bfs(i,t,1);
                if(comp >= 2){ // (1) 조건
                    if(mx < comp){
                        mx = comp;
                        min_red = ins_red.size();
                        posy = i;
                        posx = t;
                    }
                    else if(mx == comp){
                        if(ins_red.size() < min_red){
                            min_red = ins_red.size();
                            posy = i;
                            posx = t;
                        }
                    }
                }
            }
        }
    }
}
void Remove(){
    init();
    mx=bfs(posy,posx,1);
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            if(visited[i][t]){
                rem.push_back({i,t});
            }
        }
    }
    for(int i=0;i<rem.size();i++){
        arr[rem[i].first][rem[i].second] = -2;
    }
    rem.clear();
}
void Gravity(){
    for(int i=n-2;i>=0;i--){
        for(int t=0;t<n;t++){
            if(arr[i][t] >=0){
                bool change = false;
                int sty = i;
                int stx = t;
                while(1){
                    if((arr[sty+1][stx] == -2) && (sty < n-1)){
                        sty+=1;
                        change = true;
                    }
                    else{
                        break;
                    }
                }
                if(change){
                    arr[sty][stx] = arr[i][t];
                    arr[i][t] = -2;
                }
            }
        }
    }
}
void Rotate(){
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            temp[i][t] = arr[i][t];
        }
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            arr[n-1-t][i] = temp[i][t];
        }
    }
}
bool simulate(){
    find();
    if(mx == 0){
        return false;
    }
    Remove();
    Gravity();
    Rotate();
    Gravity();
    res+=(mx * mx);
    return true;
} 

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&arr[i][t]);
        }
    }
    while(1){
        bool keep = simulate();
        if(!keep){
            break;
        }
    }
    printf("%d",res);
}
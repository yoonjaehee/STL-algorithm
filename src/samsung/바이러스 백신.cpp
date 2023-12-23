#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <limits.h>
using namespace std;
int n,m;
int arr[51][51];
int arr2[51][51];
int res = 0;
int ans = INT_MAX;
int virus = 0;
int py[4] = {1,-1,0,0};
int px[4] = {0,0,-1,1};
vector<pair<int,int>> vec; // 전체 병원
vector<pair<int,int>> vec2; // 고른 병원
bool visited[51][51];
bool can;
int cnt2;
queue<pair<pair<int,int>,int>> q;
void bfs(){
    cnt2 = 0;
    res = 0;
    can = false;
    while(!q.empty()){
        if(cnt2 >= virus){
            break;
        }
        int sty = q.front().first.first;
        int stx = q.front().first.second;
        int time = q.front().second;
        visited[sty][stx] = true;
        q.pop();
        for(int i=0;i<4;i++){
            if(cnt2 >= virus){
                continue;
            }
            int ny = sty + py[i];
            int nx = stx + px[i];
            if((ny >= 0) && (ny < n) && (nx < n) && (nx >= 0)){
                if((arr[ny][nx] == 2 || arr[ny][nx] == 0) && (!visited[ny][nx])){
                    if(arr[ny][nx] == 0){
                        cnt2++;
                        if((time+1) > res){
                            res = time+1;
                        }
                    }
                    visited[ny][nx] = true;
                    q.push({{ny,nx},time+1});
                }
            }
        }
    }
    if(cnt2 >= virus){
        if(res < ans){
            ans = res;
        }
        printf("%d\n",res);
    }
    return;
}
void dfs(int start,int cnt){ // m개 골랐음
    if(start == m){
        bool can2 = false;
        for(int i=0;i<n+1;i++){
            memset(visited[i],false,sizeof(bool)*(n+1));
        }
        for(int i=0;i<m;i++){
            q.push({{vec2[i].first,vec2[i].second},0});
            printf("{%d %d}",vec2[i].first,vec2[i].second);
        }

        bfs();
        while(!q.empty()){
            q.pop();
        }
        return;
    }
    for(int i=cnt;i<vec.size();i++){
        if(i >= 1){
            if(vec2[start-1].first > vec[i].first){
                continue;
            }
            else if(vec2[start-1].first == vec[i].first){
                if(vec2[start-1].second >= vec[i].second){
                    continue;
                }
            }
        }
        vec2.push_back({vec[i].first,vec[i].second});
        dfs(start+1,cnt+1);
        vec2.pop_back();
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&arr[i][t]);
            if(arr[i][t] == 2){
                vec.push_back({i,t});
            }
            if(arr[i][t] == 0){
                virus+=1;
            }
        }
    }
    dfs(0,0);
    if(ans == INT_MAX){
        ans = -1;
    }
    if(virus == 0){
        ans = 0;
    }
    printf("%d",ans);
}
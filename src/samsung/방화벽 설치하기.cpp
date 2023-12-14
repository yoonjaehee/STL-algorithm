#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int n,m;
int arr[9][9];
pair<int,int> a;
vector<pair<int,int>> vec; // 방화벽 가능한 것들
vector<pair<int,int>> tmp; // 방화벽 실제로 설치한것
vector<pair<int,int>> fire;
bool visited[9][9];
int mx = 0;
int py[4] = {1,0,-1,0};
int px[4] = {0,1,0,-1};
int cnt = 0;
int cnt2 = 0;
int pow = 0;
void fid(int sty,int stx){
    visited[sty][stx] = true;
    for(int t=0;t<4;t++){
        int ny = sty + py[t];
        int nx = stx + px[t];
        if(ny >= 0 && ny < n && nx >= 0 && nx <m){
            if((!visited[ny][nx]) && (arr[ny][nx] == 0)){
                fid(ny,nx);
            }
        }
    }
}
void dfs(int start,int cnt){
    if(start == 3){
        for(int i=0;i<n;i++){
            memset(visited[i],false,sizeof(bool)*m);
        }
        cnt = 0;
        for(int i=0;i<3;i++){
            a = tmp[i];
            arr[a.first][a.second] = 1;
        }
        for(int i=0;i<fire.size();i++){
            a = fire[i];
            fid(a.first,a.second);
        }
        for(int i=0;i<n;i++){
            for(int t=0;t<m;t++){
                if(visited[i][t]){
                    cnt++;
                }
            }
        }
        int temp = (m * n) - cnt - cnt2 - 3;
        if(temp > mx){
            mx = temp;
        }
        for(int i=0;i<3;i++){
            a = tmp[i];
            arr[a.first][a.second] = 0;
        }
        return;
    }
    for(int i=cnt;i<vec.size();i++){
        if(tmp.size() >= 1){
            if(tmp.back().first > vec[i].first){
                continue;
            }
            else if(tmp.back().first == vec[i].first){
                if(tmp.back().second >= vec[i].second){
                    continue;
                }
            }
        }
        tmp.push_back({vec[i].first,vec[i].second});
        dfs(start+1,cnt+1);
        tmp.pop_back();
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            scanf("%d",&arr[i][t]);
            if(arr[i][t] == 0){
                vec.push_back({i,t});
            }
            else if(arr[i][t] == 2){
                fire.push_back({i,t});
            }
            else if(arr[i][t] == 1){
                cnt2++;
            }
        }
    }
    dfs(0,0);
    printf("%d",mx);
}
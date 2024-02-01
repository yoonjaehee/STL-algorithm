// 남아있는 것만 턴수 조정했어야했는데 모든 말의 턴수 k로업데이트했음... 다음엔 조심하자
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int n,m,k; // m = 플레이어 수, k = 독점 계약 턴 수
vector<pair<int,int>> pos(401,{0,0}); // 말의 위치
vector<vector<int>> pri; // 우선순위
vector<int> cur_dir; // 말의 방향
vector<bool> remain(401,true);
bool visited[21][21];
int arr[21][21]; // 말의 소유권
int turn[21][21]; // 남은 턴수
int py[4] = {-1,1,0,0};
int px[4] = {0,0,-1,1};
int res = -1;
int remain_num = 0;
void dfs(int cnt){
    if(cnt > 1000){
        res = -1;
        return;
    }
    if(remain_num == m-1){
        res = cnt;
        return;
    }
    // 방향 선택 + 이동
    for(int i=0;i<n;i++){
        memset(visited[i],false,sizeof(bool)*n);
    }
    for(int i=0;i<m;i++){
        if(!remain[i]){
            continue;
        }
        bool change = false;
        for(int t=0;t<4;t++){
            int dir = pri[i*4 + cur_dir[i]][t]-1;
            int ny = py[dir] + pos[i].first;
            int nx = px[dir] + pos[i].second;
            if(ny >= 0 && ny < n && nx >= 0 && nx < n){
                if(turn[ny][nx] == 0){
                    if(visited[ny][nx]){
                        remain[i] = false;
                        remain_num+=1;
                        change = true;
                        break;
                    }
                    change = true;
                    cur_dir[i] = dir;
                    pos[i].first = ny;
                    pos[i].second = nx;
                    arr[ny][nx] = i+1;
                    visited[ny][nx] = true;
                    break;
                }
            }
        }
        if(!change){
            for(int t=0;t<4;t++){
                int dir = pri[i*4 + cur_dir[i]][t]-1;
                int ny = py[dir] + pos[i].first;
                int nx = px[dir] + pos[i].second;
                if(ny >= 0 && ny < n && nx >= 0 && nx < n){
                    if(arr[ny][nx] == (i+1)){
                        if(visited[ny][nx]){
                            remain[i] = false;
                            remain_num+=1;
                            break;
                        }
                        cur_dir[i] = dir;
                        pos[i].first = ny;
                        pos[i].second = nx;
                        arr[ny][nx] = i+1;
                        visited[ny][nx] = true;
                        break;
                    }
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        if(remain[i]){
            turn[pos[i].first][pos[i].second] = k;
        }
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            if(turn[i][t] > 0 && (!visited[i][t])){
                turn[i][t]-=1;
            }
            if(turn[i][t] == 0){
                arr[i][t] = 0;
            }
        }
    }
    /*for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            printf("%d ",turn[i][t]);
        }
        printf("\n");
    }
    printf("\n");
    */
    // k감소
    dfs(cnt+1);
}
int main(){
    int temp;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&temp);
            if(temp != 0){
                pos[temp-1] = {i,t};
                turn[i][t] = k;
                arr[i][t] = temp;
            }
        }
    }
    for(int i=0;i<m;i++){
        scanf("%d",&temp);
        cur_dir.push_back(temp-1);
    }
    for(int i=0;i<m;i++){
        for(int t=0;t<4;t++){
            vector<int> prior;
            for(int q=0;q<4;q++){
                scanf("%d",&temp);
                prior.push_back(temp);
            }
            pri.push_back(prior);
        }
    }
    dfs(0);
    printf("%d",res);
}
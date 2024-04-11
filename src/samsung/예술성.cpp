#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
using namespace std;
map<pair<int,int>,int> ma;
bool visited[30][30];
int arr[30][30];
int tmp[30][30];
int group[30][30];
int res = 0;
int n,cnt;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
vector<pair<int,int>> vec;
void init(){
    vec.clear();
    ma.clear();
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            visited[i][t] = false;
            tmp[i][t] = 0;
        }
    }
}
void search(int y,int x,int id){
    visited[y][x] = true;
    group[y][x] = id;
    for(int i=0;i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n){
            continue;
        }
        if(arr[y][x] != arr[ny][nx]){
            if(visited[ny][nx]){ // 맞닿은거 
                ma[{group[ny][nx],group[y][x]}]++; // 작은거,큰거 변 맞닿은거 갯수 ++
            }
            else{
                continue;
            }
        }
        else{
            if(!visited[ny][nx]){
                cnt++;
                search(ny,nx,id);
            }
        }
    }
}
void cal(){
    int idx = 0;
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            if(!visited[i][t]){
                cnt = 1;
                search(i,t,idx);
                vec.push_back({arr[i][t],cnt});
                idx++;
            }
        }
    }
    int len = vec.size();
    for(int i=0;i<len;i++){
        for(int t=i+1;t<len;t++){
            res += (vec[i].second + vec[t].second) * vec[i].first * vec[t].first * ma[{i,t}];
        }
    }
}
void rotate(){
    int sy,sx;
    sy = 0;
    sx = 0;
    for(int i=sy;i<n/2;i++){
        for(int t=sx;t<n/2;t++){
            int tempy = i-sy; // [0,0] 기준으로 치환 시작 범위 y
            int tempx = t-sx; // [0,0] 기준으로 치환 시작 범위 x
            // 회전 이후 좌표 = {y,x} -> {x,size-y-1} 
            int temp2y = tempx; 
            int temp2x = n/2-1-tempy;
            // x + ([0,0] 가준으로 바꿨던 만큼 + 해주기), y도 똑같이
            tmp[i][t] = arr[temp2y+sy][temp2x + sx];
        }
    }
    sy = 0;
    sx = n/2+1;
    for(int i=sy;i<n/2;i++){
        for(int t=sx;t<n;t++){
            int tempy = i-sy; // [0,0] 기준으로 치환 시작 범위 y
            int tempx = t-sx; // [0,0] 기준으로 치환 시작 범위 x
            // 회전 이후 좌표 = {y,x} -> {x,size-y-1} 
            int temp2y = tempx; 
            int temp2x = n/2-1-tempy;
            // x + ([0,0] 가준으로 바꿨던 만큼 + 해주기), y도 똑같이
            tmp[i][t] = arr[temp2y+sy][temp2x + sx];
        }
    }
    sy = n/2+1;
    sx = 0;
    for(int i=sy;i<n;i++){
        for(int t=sx;t<n/2;t++){
            int tempy = i-sy; // [0,0] 기준으로 치환 시작 범위 y
            int tempx = t-sx; // [0,0] 기준으로 치환 시작 범위 x
            // 회전 이후 좌표 = {y,x} -> {x,size-y-1} 
            int temp2y = tempx; 
            int temp2x = n/2-1-tempy;
            // x + ([0,0] 가준으로 바꿨던 만큼 + 해주기), y도 똑같이
            tmp[i][t] = arr[temp2y+sy][temp2x + sx];
        }
    }
    sy = n/2+1;
    sx = n/2+1;
    for(int i=sy;i<n;i++){
        for(int t=sx;t<n;t++){
            int tempy = i-sy; // [0,0] 기준으로 치환 시작 범위 y
            int tempx = t-sx; // [0,0] 기준으로 치환 시작 범위 x
            // 회전 이후 좌표 = {y,x} -> {x,size-y-1} 
            int temp2y = tempx; 
            int temp2x = n/2-1-tempy;
            // x + ([0,0] 가준으로 바꿨던 만큼 + 해주기), y도 똑같이
            tmp[i][t] = arr[temp2y+sy][temp2x + sx];
        }
    }
    tmp[n/2][n/2] = arr[n/2][n/2];
    queue<int> cha;
    stack<int> cha2;
    for(int i=0;i<n;i++){
        cha.push(arr[i][n/2]);
        cha2.push(arr[n/2][i]);
    }
    for(int i=0;i<n;i++){
        tmp[i][n/2] = cha2.top();
        tmp[n/2][i] = cha.front(); 
        cha.pop();
        cha2.pop();
    }
}
void dfs(int start){
    if(start == 4){
        return;
    }
    init();
    cal();
    rotate();
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            arr[i][t]=tmp[i][t];
        }
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            printf("%d ",tmp[i][t]);
        }
        printf("\n");
    }
    printf("\n");
    dfs(start+1);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&arr[i][t]);
        }
    }
    dfs(0);
    printf("%d",res);
}
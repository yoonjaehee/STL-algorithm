#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> vec(6,0); // 위,앞,왼옆,오옆,뒤,아래
int n,m;
int arr[21][21];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int answer = 0;
bool visited[21][21];
int cury,curx,curdir;
queue<pair<int,int>> q;
void bfs(int y,int x){
    q.push({y,x});
    visited[y][x] = true;
    int cnt = 1;
    while(!q.empty()){
        pair<int,int> tem = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int ny = tem.first + dy[i];
            int nx = tem.second + dx[i];
            if(ny >= 0 && ny < n && nx >= 0 && nx < n){
                if(!visited[ny][nx] && arr[ny][nx] == arr[y][x]){
                    cnt+=1;
                    visited[ny][nx] = true;
                    q.push({ny,nx});
                }
            }
        }
    }
    answer+=(cnt * arr[y][x]);
}
void mov(int dir,int y,int x){
    int ny = dy[dir] + y;
    int nx = dx[dir] + x;
    if(ny >= 0 && ny < n && nx >= 0 && nx < n){
        cury = ny;
        curx = nx;
        curdir = dir;
    }
    else{
        cury = y - dy[dir];
        curx = x - dx[dir];
        curdir = (dir + 2)%4;
    } // 방향고르고 위치 정함
    // 이제 정육면체 위치별 자리 바꿈
    vector<int> temp;
    temp = vec;
    if(curdir == 0){ // 오 왼
        vec[0] = temp[3];
        vec[2] = temp[0];
        vec[3] = temp[5];
        vec[5] = temp[2];
    }
    else if(curdir == 3){ //아래
        vec[0] = temp[1];
        vec[1] = temp[5];
        vec[4] = temp[0];
        vec[5] = temp[4];
    }
    else if(curdir == 2){
        vec[0] = temp[2];
        vec[2] = temp[5];
        vec[3] = temp[0];
        vec[5] = temp[3];
    }
    else if(curdir == 1){ // 위
        vec[0] = temp[4];
        vec[1] = temp[0];
        vec[4] = temp[5];
        vec[5] = temp[1];
    }
    return;
}
int choose_dir(int dir){
    int toreturn;
    if(arr[cury][curx] < vec[5]){ // 왼 오
        toreturn = (dir+1)%4;
    }
    else if(arr[cury][curx] == vec[5]){
        toreturn = dir;
    }
    else{
        toreturn = (dir+3)%4;
    }
    return toreturn;
}
void dfs(int start,int cur_dir,int sty,int stx){
    if(start == 0){
        return;
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            visited[i][t] = false;
        }
    }
    mov(cur_dir,sty,stx);
    bfs(cury,curx);
    int next_dir = choose_dir(curdir);
    dfs(start-1,next_dir,cury,curx);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<6;i++){
        vec[i] = i+1;
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&arr[i][t]);
        }
    }
    dfs(m,0,0,0);
    printf("%d",answer);
}
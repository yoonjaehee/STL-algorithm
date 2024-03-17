#include <iostream>
#include <vector>
using namespace std;
int n,m,k,x,y,d,s;
bool visited[21][21];
vector<int> isgun[21][21];
int arr[21][21]; // 지금 있는 사람 인덱스
vector<vector<int>> vec; // {y,x,d,초기,지금};
vector<int> res;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
void collect(int y,int x,int idx){
    int mx = vec[idx][4] - vec[idx][3];
    int cur = vec[idx][4] - vec[idx][3];
    int mxidx = isgun[y][x].size();
    for(int t=0;t<isgun[y][x].size();t++){
        if(mx < isgun[y][x][t]){
            mx = isgun[y][x][t];
            mxidx = t;
        }
    }
    if(mxidx != isgun[y][x].size()){
        isgun[y][x].erase(isgun[y][x].begin() + mxidx);
        vec[idx][4] = (vec[idx][3] + mx);
        if(cur!=0){
            isgun[y][x].push_back(cur);
        }
    }
}
void move(){
    for(int i=0;i<vec.size();i++){ // 이동
        arr[vec[i][0]][vec[i][1]] = -1;
        int ny = vec[i][0] + dy[vec[i][2]];
        int nx = vec[i][1] + dx[vec[i][2]];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n){ 
            ny = vec[i][0] - dy[vec[i][2]];
            nx = vec[i][1] - dx[vec[i][2]];
            vec[i][2] = (vec[i][2] + 2)%4;
        }
        if(arr[ny][nx] == -1){ // 1번 
            if(!isgun[ny][nx].empty()){
                collect(ny,nx,i);
            }
            vec[i][0] = ny;
            vec[i][1] = nx;
            arr[ny][nx] = i;
        }
        else{
            int didx = arr[ny][nx]; // 다른애
            int win,lose;
            if(vec[didx][4] > vec[i][4]){ // 플레이어가 지면
                win = didx;
                lose = i;
            }
            else if(vec[didx][4] == vec[i][4]){ // 같으면 초기 능력치 비교
                if(vec[didx][3] > vec[i][3]){
                    win = didx;
                    lose = i;
                }
                else{
                    win = i;
                    lose = didx;
                }
            }
            else{  
                win = i;
                lose = didx;
            }
            res[win] += (vec[win][4] - vec[lose][4]); // 2-2-1
            vec[win][0] = ny;
            vec[win][1] = nx;
            arr[ny][nx] = win;
            isgun[ny][nx].push_back(vec[lose][4] - vec[lose][3]); // 2-2-2
            vec[lose][4] = vec[lose][3];
            vec[lose][0] = ny;
            vec[lose][1] = nx;
            for(int t=0;t<5;t++){
                ny = vec[lose][0] + dy[(vec[lose][2]+t)%4];
                nx = vec[lose][1] + dx[(vec[lose][2]+t)%4];
                if(arr[ny][nx] >= 0 || ny >= n || ny < 0 || nx >= n || nx < 0){
                    continue;
                }
                vec[lose][2] = (vec[lose][2] + t)%4;
                break;
            }
            vec[lose][0] = ny;
            vec[lose][1] = nx;
            arr[ny][nx] = lose;
            if(!isgun[ny][nx].empty()){
                collect(ny,nx,lose);
            }
            if(!isgun[vec[win][0]][vec[win][1]].empty()){
                collect(vec[win][0],vec[win][1],win);
            }
        }
        /*printf("\n");
        for(int p=0;p<n;p++){
            for(int q=0;q<n;q++){
                if(arr[p][q] != -1){
                    printf("{%d %d}",arr[p][q],vec[arr[p][q]][4]);
                }
                else{
                    printf("%d ",arr[p][q]);
                }
            }
            printf("\n");
        }
        */
    }
}
void dfs(int start){
    if(start == k){
        return;
    }
    move();
    dfs(start+1);
}
int main(){
    int tmp;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&tmp);
            if(tmp > 0){
                isgun[i][t].push_back(tmp);
            }
            arr[i][t] = -1;
        }
    }
    for(int i=0;i<m;i++){
        vector<int> temp;
        scanf("%d %d %d %d",&x,&y,&d,&s);
        arr[x-1][y-1] = i;
        temp.push_back(x-1);
        temp.push_back(y-1);
        temp.push_back(d);
        temp.push_back(s);
        temp.push_back(s);
        vec.push_back(temp);
        res.push_back(0);
    }
    dfs(0);
    for(int i=0;i<res.size();i++){
        printf("%d ",res[i]);
    }
}

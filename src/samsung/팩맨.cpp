#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> vec; // 애들 있는 곳
int m,t,packy,packx;
int arr[4][4]; // mon갯수
int dead[4][4]; //시체
bool visited[4][4];
vector<vector<int>> egg;
vector<vector<int>> todel;
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int dx[8] = {0,-1,-1,-1,0,1,1,1};
void copy(){
    for(int i=0;i<vec.size();i++){
        egg.push_back(vec[i]);
    }
}
void awake(){
    for(int i=0;i<egg.size();i++){
        vec.push_back(egg[i]);
    }
}
void monmove(){
    for(int i=0;i<vec.size();i++){
        int cnt = 0;
        arr[vec[i][0]][vec[i][1]]-=1;
        for(int t=0;t<8;t++){
            int temdir = (vec[i][2] + t)%8;
            int ny = vec[i][0] + dy[temdir];
            int nx = vec[i][1] + dx[temdir];
            if(((ny == packy && nx == packx) || (dead[ny][nx] > 0)) || ny < 0 || ny >= 4 || nx < 0 || nx >= 4 ){
                if(cnt == 7){
                    arr[vec[i][0]][vec[i][1]]+=1;
                    break;
                }
                else{
                    cnt++;
                    continue;
                }
            }
            else{
                vec[i][0] = ny;
                vec[i][1] = nx;
                vec[i][2] = temdir;
                arr[ny][nx] +=1;
                break;
            }
        }
    }
}
void sim(vector<int> p){
    bool visited[4][4] = {0,};
    int y = packy;
    int x = packx;
    int ans = 0;
    for(int i=0;i<3;i++){
        int dir = p[i];
        y += dy[dir];
        x += dx[dir];
        if(y >= 0 && y < 4 && x >= 0 && x < 4){
            if(visited[y][x] == 0){
                ans += arr[y][x];
                visited[y][x] = true;
            }
        }
    }
}
void find(int start,vector<int> &s){
    if(start == 3){
        todel.clear();
        int tmp = sim(s);
    }
}
void packmove(){
    vector<int> ins;
    find(3,ins);

}
void remove(){
    for(int i=0;i<4;i++){
        for(int t=0;t<4;t++){
            if(dead[i][t] > 0){
                dead[i][t]-=1;
            }
        }
    }
}
void dfs(int start){
    if(start == t){
        return;
    }
    egg.clear();
    copy();
    monmove();
    for(int i=0;i<vec.size();i++){
        int ny = vec[i][0];
        int nx = vec[i][1];
        arr[i][t]+=1;
    }
    packmove();
    remove();
    awake();
}
int main(){
    scanf("%d %d",&m,&t);
    scanf("%d %d",&packy,&packx);
    for(int i=0;i<m;i++){
        int temy,temx,temdir;
        scanf("%d %d %d",&temy,&temx,&temdir);
        vector<int> temp;
        temp.push_back(temy-1);
        temp.push_back(temx-1);
        temp.push_back(temdir-1);
        arr[temy-1][temx-1] += 1;
        vec.push_back(temp);
    }
    dfs(0);
}
// 방향설정에서 기존 대각선이 모두 대각선이면 상하좌우인데 , 대각선 3개가 합쳐졌을때 대각선으로 나오는거 주의 짝홀...!
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int wei[51][51];
int speed[51][51];
int dircheck[51][51];
bool dircheck2[51][51];
int arr[51][51];
vector<vector<int>> vec2;
bool visited[51][51]; // 좌표에 이미 담겼나
bool visited2[51][51]; // 이미 나눈거 체크한 구역인가
int num[51][51];
int n,m,k;
int py[8] = {-1,-1,0,1,1,1,0,-1};
int px[8] = {0,1,1,1,0,-1,-1,-1};
int res = 0;
void dfs(int time,vector<vector<int>> vec){
    if(vec.size() == 0){
        return;
    }
    if(time == k){
        for(int i=0;i<vec.size();i++){
            res+=vec[i][2];
        }
        return;
    }
    vector<pair<int,int>> todivide; 
    vector<vector<int>> vec3;
    for(int i=0;i<n;i++){
        memset(num[i],0,sizeof(int) * n);
        memset(arr[i],0,sizeof(int) * n);
        memset(visited[i],false,sizeof(bool) * n);
        memset(wei[i],0,sizeof(int) * n);
        memset(speed[i],0,sizeof(int) * n);
        memset(visited2[i],false,sizeof(bool) * n);
        memset(dircheck[i],0,sizeof(int) * n);
        memset(dircheck2[i],false,sizeof(bool) * n);
    }
    for(int i=0;i<vec.size();i++){ // 이동
        int tp1 = ((py[vec[i][4]])*vec[i][3])%n;
        int tp2 = ((px[vec[i][4]])*vec[i][3])%n;
        //printf("%d %d -> %d %d -> %d %d\n",vec[i][0],vec[i][1],tp1,tp2,vec[i][0] + tp1,vec[i][1] + tp2);
        int ny = vec[i][0] + tp1;
        int nx = vec[i][1] + tp2;
        // 거리 1000일때 고려
        if(ny >= n){
            ny -= n;
        }
        else if(ny < 0){
            ny = n+ny;
        }
        if(nx >= n){
            nx -= n;
        }
        else if(nx < 0){
            nx = n+nx;
        }
        vec[i][0] = ny;
        vec[i][1] = nx;
        wei[ny][nx] += vec[i][2];
        speed[ny][nx] += vec[i][3];
        if(visited[ny][nx]){ // 이미 있으면 방향체크하고 방향바꿀지도 결정
            todivide.push_back({ny,nx});
            if((dircheck[ny][nx] + vec[i][4])%2 == 1){ // 방향에서 잘못... 
                dircheck2[ny][nx] = true;
            }
            arr[ny][nx] = 0;
            num[ny][nx]+=1;
            visited[ny][nx] = true;
        }
        else if(!visited[ny][nx]){
            visited[ny][nx] = true;
            arr[ny][nx] = i+1; // 
            num[ny][nx] +=1;
        }
        dircheck[ny][nx] = vec[i][4];
    }
    for(int i=0;i<todivide.size();i++){
        int posy = todivide[i].first;
        int posx = todivide[i].second;
        if(visited2[posy][posx]){
            continue;
        }
        // 질량 계산하고 나눔
        if(wei[posy][posx] < 5){
            continue;
        }
        int weight = wei[posy][posx] / 5;
        for(int t=0;t<4;t++){
            vector<int> temp;
            temp.push_back(posy);
            temp.push_back(posx);
            temp.push_back(weight);
            temp.push_back(speed[posy][posx] / num[posy][posx]);
            if(!(dircheck2[posy][posx])){
                temp.push_back(t*2);
            }
            else{
                temp.push_back((t*2)+1);
            }
            vec3.push_back(temp); 
        }
        visited2[posy][posx] = true;
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            if(arr[i][t] != 0){
                vec3.push_back(vec[arr[i][t] - 1]);
            }
        }
    }
    /*for(int i=0;i<vec3.size();i++){
        printf("%d %d %d %d %d\n",vec3[i][0],vec3[i][1],vec3[i][2],vec3[i][3],vec3[i][4]);
    }
    printf("\n");
    */
    dfs(time+1,vec3);
}
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<m;i++){
        int x,y,w,s,d;
        vector<int> tmp;
        scanf("%d %d %d %d %d",&x,&y,&w,&s,&d);
        tmp.push_back(x-1);
        tmp.push_back(y-1);
        tmp.push_back(w);
        tmp.push_back(s);
        tmp.push_back(d);
        vec2.push_back(tmp);
    }
    dfs(0,vec2);
    printf("%d",res);
}
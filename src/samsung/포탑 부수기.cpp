#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <string>
#include <limits.h>
#include <sstream>
using namespace std;
int n,m,k,temp;
bool visited[11][11]; // 공격 무관
bool visited2[11][11]; // bfs
pair<int,int> arr[11][11]; // 공격력/최근사용된턴
int aty,atx,tary,tarx;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int dt[8] = {1,1,1,-1,-1,-1,0,0};
int dp[8] = {1,-1,0,0,1,-1,1,-1};
queue<pair<pair<int,int>,string>> q;
bool chan = false;
void choatk(){
    int cand1 = INT_MAX;
    int cand2 = 0;
    int cand3 = 0;
    int cand4 = 0;
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            bool change = false;
            if(arr[i][t].first == 0){
                continue;
            }
            if(cand1 > arr[i][t].first){
                change = true;
            }
            else if(cand1 == arr[i][t].first){
                if(cand2 < arr[i][t].second){
                    change = true;
                }
                else if(cand2 == arr[i][t].second){
                    if(cand3 < (i+1+t+1)){
                        change = true;
                    }
                    else if(cand3 == (i+t+2)){
                        if(cand4 < t){
                            change = true;
                        }
                    }
                }
            }
            if(change){
                aty = i;
                atx = t;
                cand1 = arr[i][t].first;
                cand2 = arr[i][t].second;
                cand3 = i+t+2;
                cand4 = t;
            }
        }
    }
}
void chotar(){
    int cand1 = 0;
    int cand2 = 0;
    int cand3 = 0;
    int cand4 = 0;
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            if(arr[i][t].first == 0){
                continue;
            }
            if((i == aty) && (t == atx)){
                continue;
            }
            bool cha = false;
            if(cand1 < arr[i][t].first){
                cha = true;
            }
            else if(cand1 == arr[i][t].first){
                if(cand2 > arr[i][t].second){
                    cha = true;
                }
                else if(cand2 == arr[i][t].second){
                    if(cand3 > (i+t+2)){
                        cha = true;
                    }
                    else if(cand3 == (i+t+2)){
                        if(cand4 > t){
                            cha = true;
                        }
                    }
                }
            }
            if(cha){
                tary = i;
                tarx = t;
                cand1 = arr[i][t].first;
                cand2 = arr[i][t].second;
                cand3 = i+t+2;
                cand4 = t;
                chan = true;
            }
        }
    }
}
void attack(){
    bool exist = false;
    q = queue<pair<pair<int,int>,string>>();
    q.push({{aty,atx},""});
    visited[aty][atx] = true;
    string track;
    while(!q.empty()){
        pair<pair<int,int>,string> tmp= q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int ny = (tmp.first.first + dy[i] + n)%n;
            int nx = (tmp.first.second + dx[i] + m)%m;
            if((!visited[ny][nx]) && (arr[ny][nx].first > 0 )){
                visited[ny][nx] = true;
                q.push({{ny,nx},tmp.second + to_string(i+1)});
                if((ny == tary) && (nx == tarx)){
                    exist = true;
                    track = tmp.second;
                    break;
                }
            }
        }
    }
    if(!exist){
        visited2[aty][atx] = true;
        visited2[tary][tarx] = true;
        int ny,nx;
        for(int t=0;t<8;t++){
            ny = (tary + dt[t]);
            nx = (tarx + dp[t]);
            if(ny >= n){
                ny = 0;
            }
            if(ny < 0){
                ny = n-1;
            }
            if(nx >= m){
                nx = 0;
            }
            if(nx < 0){
                nx = m-1;
            }
            if(arr[ny][nx].first > 0 && !((ny == aty) && (nx == atx))){
                visited2[ny][nx] = true;
                if(arr[ny][nx].first - ((arr[aty][atx].first)/2) < 0){
                    arr[ny][nx].first = 0;
                }
                else{
                    arr[ny][nx].first -= (arr[aty][atx].first / 2);
                }
            }
        }
    }
    else{ // 추적
        int sty = aty;
        int stx = atx;
        visited2[sty][stx] = true;
        visited2[tary][tarx] = true;
        if(track== "0"){
            return;
        }
        for(int i=0;i<track.size();i++){
            sty += dy[track[i] - '1'];
            stx += dx[track[i] - '1'];
            if(sty >= n){
                sty = 0;
            }
            if(sty < 0){
                sty = n-1;
            }
            if(stx >= m){
                stx = 0;
            }
            if(stx < 0){
                stx = m-1;
            }
            arr[sty][stx].first -= (arr[aty][atx].first/2);
            if(arr[sty][stx].first < 0){
                arr[sty][stx].first = 0;
            }
            visited2[sty][stx] = true;
        }

    }
}
void dfs(int start){
    if(start == k){
        return;
    }
    chan = false;
    // 공격자 선정
    choatk();
    chotar();
    if(!chan){
        return;
    }
    arr[aty][atx].first += (n+m);
    arr[aty][atx].second = start+1;
    attack();
    arr[tary][tarx].first -= arr[aty][atx].first;
    if(arr[tary][tarx].first < 0){
        arr[tary][tarx].first = 0;
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            if(!visited2[i][t] && arr[i][t].first > 0){
                arr[i][t].first += 1;
            }
            visited[i][t] = false;
            visited2[i][t] = false;
        }
    }
    /*printf("\n");
    printf("{%d %d}",aty,atx);
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            printf("%d ",arr[i][t].first);
        }
        printf("\n");
    }*/
    dfs(start+1);
}
int main(){
    int fir;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            scanf("%d",&fir);
            arr[i][t].first = fir;
            arr[i][t].second = 0;
        }
    }
    dfs(0);
    int res = 0;
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            if(res < arr[i][t].first){
                res = arr[i][t].first;
            }
        }
    }
    printf("%d",res);
}
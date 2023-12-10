#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,temp;
int arr[8][8];
bool visited[8][8];
int px[4] = {-1,0,1,0};
int py[4] = {0,1,0,-1};
vector<int> vec2;
vector<pair<pair<int,int>,int>> vec;
int mx = 0;
int ny,nx;
void mov(int sty,int stx,int direc){
    while(1){
        visited[sty][stx] = true;
        ny = sty + py[direc];
        nx = stx + px[direc];g
        if(arr[ny][nx] != 6 && ny >= 0 && nx < 8 && nx >=0 && ny < 8){
            stx = nx;
            sty = ny;
        }
        else{
            break;
        }
    }
}
int cur_dir = 0;
void action(vector<pair<pair<int,int>,int>> tmp,vector<int> tmp2){
    for(int i=0;i<n;i++){
        memset(visited[i],false,sizeof(bool)*m);
    }
    for(int i=0;i<tmp.size();i++){
        int cur_ch=tmp[i].second;
        int cury = tmp[i].first.first;
        int curx = tmp[i].first.second;
        int cur_dir = tmp2[i];
        visited[cury][curx] = true;
        if(cur_ch == 1){
            mov(cury,curx,cur_dir);
        }
        else if(cur_ch == 2){
            mov(cury,curx,(cur_dir+1) % 4);
            mov(cury,curx,(cur_dir+3) % 4);
        }
        else if(cur_ch == 3){
            mov(cury,curx,cur_dir);
            mov(cury,curx,(cur_dir+1)%4);
        }
        else if(cur_ch == 4){
            mov(cury,curx,cur_dir);
            mov(cury,curx,(cur_dir+1)%4);
            mov(cury,curx,(cur_dir+3)%4);
        }
        else if(cur_ch == 5){
            mov(cury,curx,cur_dir);
            mov(cury,curx,(cur_dir+1)%4);
            mov(cury,curx,(cur_dir+2)%4);
            mov(cury,curx,(cur_dir+3)%4);
        }
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            if(visited[i][t] || (arr[i][t] == 6)){
                cnt+=1;
            }
        }
    }
    if(mx < cnt){
        for(int i=0;i<n;i++){
            for(int t=0;t<m;t++){
                printf("%d ",visited[i][t]);
            }
            printf("\n");
        }
    }
    mx=max(mx,cnt);
}
void dfs(int cmp){
    if(cmp == vec.size()){
        action(vec,vec2);
        return;
    }
    for(int i=0;i<4;i++){
        vec2.push_back(i);
        dfs(cmp+1);
        vec2.pop_back();
    }
    
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            scanf("%d",&temp);
            arr[i][t] = temp;
        }
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            if(arr[i][t]!=0 && arr[i][t] != 6){
                vec.push_back({{i,t},arr[i][t]});
            }
        }
    }
    dfs(0);
    printf("%d",n*m-mx);
}
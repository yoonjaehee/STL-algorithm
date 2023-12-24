#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int n,m,h;
bool arr2[271][11];
int arr[271][11];
bool can;
int mx = -1;
bool visited[271][11];
bool can2;
vector<pair<int,int>> vec;
bool dfs2(int sty,int stx,int stn){
    visited[sty][stx] = true;
    if(sty > h){
        if(stn == stx){
            return true;
        }
        else{
            return false;
        }
    }
    if(arr2[sty][stx]){
        return dfs2(sty+1,stx+1,stn);
    }
    else if(arr2[sty][stx-1]){
        return dfs2(sty+1,stx-1,stn);
    }
    else{
        return dfs2(sty+1,stx,stn);
    }
}
void dfs(int start,int end){ // 1~2개 고르기
    if(can2){
        return;
    }
    if(start == end){
        can = true;
        for(int p=0;p<n;p++){
            for(int q=0;q<m;q++){
                memset(visited[q],false,sizeof(bool)*(h+1));
            }
            if(dfs2(0,p,p)){
                continue;
            }
            else{
                can = false;
                break;
            }
        }
        if(!can){
            return;
        }
        if(mx < end){
            mx = end;
            can2 = true;
            return;
        }
        return;
    }
    for(int i=0;i<h;i++){
        for(int t=0;t<n-1;t++){
            if(t>=1 && t<n-1){
                if(arr2[i][t-1] || arr[i][t+1]){
                    continue;
                }
            }
            else if(t == 0){
                if(arr2[i][1]){
                    continue;
                }
            }
            if(!arr2[i][t]){
                vec.push_back({i,t});
                arr2[i][t] = true;
                dfs(start+1,end);
                arr2[i][t] = false;
                vec.pop_back();
            }
        }
    }
}
int main(){
    int y,x;
    scanf("%d %d %d",&n,&m,&h);
    if(m == 0){
        printf("0");
        return 0;
    }
    for(int i=0;i<m;i++){
        scanf("%d %d",&y,&x);
        arr2[y-1][x-1] = true; 
    }
    for(int i=0;i<=3;i++){
        can2 = false;
        dfs(0,i);
        if(can2){
            break;
        }
    }
    printf("%d",mx);
}
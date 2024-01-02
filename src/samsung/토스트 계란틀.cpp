#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int from,to,n;
int arr[51][51];
bool visited[51][51];
int py[4] = {1,-1,0,0};
int px[4] = {0,0,1,-1};
int sum,cnt;
bool can;
int arr2[51][51];
int res = 0;
vector<pair<int,int>> vec;
void dfs(int sty,int stx){
    visited[sty][stx] = true;
    vec.push_back({sty,stx});
    for(int i=0;i<4;i++){
        int ny = py[i] + sty;
        int nx = px[i] + stx;
        if((ny>= 0) && (ny< n) && (nx >= 0) && (nx < n)){
            if((!visited[ny][nx]) && (abs(arr[sty][stx] - arr[ny][nx]) >= from) && (abs(arr[sty][stx] - arr[ny][nx]) <= to)){
                sum+=(arr[ny][nx]);
                cnt++;
                dfs(ny,nx);
            }
        }
    }
    return;
}
int main(){
    scanf("%d %d %d",&n,&from,&to);
    for(int i=0;i<n;i++){
        memset(arr[i],0,sizeof(int)*n);
        memset(arr2[i],0,sizeof(int)*n);
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&arr[i][t]);
        }
    }
    while(1){
        for(int i=0;i<n;i++){
            for(int t=0;t<n;t++){
                arr2[i][t] = arr[i][t];
            }
        }
        can = true;
        for(int i=0;i<n;i++){
            memset(visited[i],false,sizeof(bool)*(n));
        }
        for(int i=0;i<n;i++){
            for(int t=0;t<n;t++){
                if(!visited[i][t]){
                    vec.clear();
                    cnt = 1;
                    sum = arr[i][t];
                    dfs(i,t);
                }
                for(int i=0;i<vec.size();i++){ // 중간에 다른방향 커브있는거때문에 나중에 다 한번에 초기화해야됨.
                    arr[vec[i].first][vec[i].second] = sum/cnt;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int t=0;t<n;t++){
                if(arr2[i][t] != arr[i][t]){
                    can = false;
                }
            }
        }
        if(can){
            break;
        }
        else{
            res++;
        }
    }
    printf("%d",res);
}
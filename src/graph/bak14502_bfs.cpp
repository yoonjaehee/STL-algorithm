#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n,m;
int res = 0;
int arr[8][8]={0,};
int arr2[8][8]={0,};
queue<pair<int,int>> q;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
vector<pair<int,int>> virus;
int bfs(){
    for(int i=0;i<virus.size();i++){
        q.push({virus[i].first,virus[i].second});
    }
    while(!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >=0 && ny >= 0 && nx < m && ny < m){
                if(arr2[ny][nx] == 0){
                    arr2[ny][nx] = 2;
                    q.push({ny,nx});
                }
            }
        }
    }
    int total = 0;
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            if(arr2[i][t]==0){
                total++;
            }
        }
    }
    res = max(res,total);
    return res;
}
int protect(int count){
    if(count == 3){
        for(int i=0;i<n;i++){
            for(int t=0;t<m;t++){
                arr2[i][t] = arr[i][t];
            }
        }
        return bfs();
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            if(arr[i][t]==0){
                arr[i][t]=1;
                protect(count+1);
                arr[i][t]=0;
            }
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            scanf("%d",&arr[i][t]);
            if(arr[i][t]==2){
                virus.push_back({i,t});
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            if(arr[i][t]==0){
                arr[i][t]=1;
                protect(1);
                arr[i][t]=0;
            }
        }
    }
    printf("%d",res);
}
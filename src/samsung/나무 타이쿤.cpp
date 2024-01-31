#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int n,m;
int arr[16][16];
vector<vector<int>> order; // 리브로수 이동 방향
vector<pair<int,int>> lib; // 영양제
int py[8] = {0,-1,-1,-1,0,1,1,1};
int px[8] = {1,1,0,-1,-1,-1,0,1};
int my[4] = {1,1,-1,-1};
int mx[4] = {1,-1,1,-1};
bool check[16][16];
void dfs(int start){
    if(start == m){
        return;
    }
    vector<int> vec = order[start];
    // 영양제 이동, 투입
    for(int i=0;i<lib.size();i++){
        int ny = lib[i].first + (py[vec[0]])*vec[1];
        int nx = lib[i].second + (px[vec[0]])*vec[1];
        if(ny >= n){
            ny = ny-n;
        }
        else if(ny < 0){
            ny = n+ny;
        }
        if(nx >= n){
            nx = nx - n;
        }
        else if(nx < 0){
            nx = n+nx;
        }
        arr[ny][nx]+=1;
        lib[i].first = ny;
        lib[i].second = nx;
    }
    for(int i=0;i<n;i++){
        memset(check[i],false,sizeof(bool)*n);
    }
    // 대각선인접한 방향에 높이 1이상 갯수 높이에 더하기
    for(int i=0;i<lib.size();i++){
        check[lib[i].first][lib[i].second] = true;
        for(int t=0;t<4;t++){
            int ny = lib[i].first + my[t];
            int nx = lib[i].second + mx[t];
            if(ny < n && ny >= 0 && nx < n && nx >= 0){
                if(arr[ny][nx] >= 1){
                    arr[lib[i].first][lib[i].second]+=1;
                }
            }
        }
    }
    lib.clear();
    // 높이 2 이상인 리브로수는 높이 2 베어서 특수 영양제 올려두둠
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            if(arr[i][t] >= 2 && !check[i][t]){
                arr[i][t] -= 2;
                lib.push_back({i,t});
            }
        }
    }
    dfs(start+1);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&arr[i][t]);
        }
    }
    for(int i=0;i<m;i++){
        vector<int> temp;
        int d,p;
        scanf("%d %d",&d,&p);
        temp.push_back(d-1);
        temp.push_back(p);
        order.push_back(temp);
    }
    lib.push_back({n-1,0});
    lib.push_back({n-1,1});
    lib.push_back({n-2,0});
    lib.push_back({n-2,1});
    dfs(0);
    int sum = 0;
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            sum+=arr[i][t];
        }
    }
    printf("%d",sum);
}
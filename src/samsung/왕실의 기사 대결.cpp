// index는 0부터인데 그래프에 자꾸 0을 넣어버리네...
// 1. move 가능한지 확인 2. move확인하면서 tmp에 순서대로 넣기 3. damage줌. 근데 첫번째건 skip
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int n,m,q;
int arr[41][41];//함정과 벽들
int arr2[41][41];//지금 knight 있는곳들
vector<vector<int>> order;
vector<vector<int>> knight;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
bool die[31];
vector<int> first;
vector<int> tmp;
bool visited[31];
int res = 0;
void damage(int taridx,int dir,int cnt){
    int trap = 0;
    int row = knight[taridx][2];
    int col = knight[taridx][3];
    for(int i=0;i<row;i++){
        for(int t=0;t<col;t++){
            int ny = knight[taridx][0] + i;
            int nx = knight[taridx][1] + t;
            arr2[ny][nx] = -1;
        }
    }
    for(int i=0;i<row;i++){
        for(int t=0;t<col;t++){
            int ny = knight[taridx][0] + dy[dir] + i;
            int nx = knight[taridx][1] + dx[dir] + t;
            if(arr[ny][nx] == 1){
                trap++;
            }
            arr2[ny][nx] = taridx;
        }
    }
    knight[taridx][0] += dy[dir];
    knight[taridx][1] += dx[dir];
    if(cnt == 0){
        return;
    }
    knight[taridx][4] -= trap;
    if(knight[taridx][4] <= 0){
        for(int i=0;i<row;i++){
            for(int t=0;t<col;t++){
                int ny = knight[taridx][0] + i;
                int nx = knight[taridx][1] + t;
                arr2[ny][nx] = -1;
            }
        }
        die[taridx] = true;
    }
}
bool move(int taridx,int dir){
    tmp.push_back(taridx);
    visited[taridx] = true;
    int row = knight[taridx][2];
    int col = knight[taridx][3];
    bool can = true;
    for(int i=0;i<row;i++){
        for(int t=0;t<col;t++){
            int ny = knight[taridx][0] + dy[dir] + i;
            int nx = knight[taridx][1] + dx[dir] + t;
            if(ny < 0 || ny >= n || nx < 0 || nx >= n || (arr[ny][nx] == 2)){
                can = false;
                return can;
            }
            if(arr2[ny][nx] != -1){
                if(!visited[arr2[ny][nx]]){
                    can = move(arr2[ny][nx],dir);  
                }       
            }
            if(!can){
                return can;
            }
        }
    }
    return can;
}
void dfs(int start){
    if(start == q){
        return;
    }
    tmp.clear();
    memset(visited,false,sizeof(bool) * m);
    bool flag = false;
    if(!die[order[start][0]]){
        int temp = order[start][0];
        flag= move(temp,order[start][1]);
    }
    if(flag){
        for(int i=tmp.size()-1;i>=0;i--){
            damage(tmp[i],order[start][1],i);
        }
    }
    /*for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            printf("%d ",arr2[i][t]);
        }
        printf("\n");
    }
    printf("\n");
    */
    dfs(start+1);
}
int main(){
    scanf("%d %d %d",&n,&m,&q);
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&arr[i][t]);
        }
    }
    for(int i=0;i<n;i++){
        memset(arr2[i],-1,sizeof(int) * n);
    }
    for(int i=0;i<m;i++){
        int y,x,h,w,k;
        vector<int> temp;
        scanf("%d %d %d %d %d",&y,&x,&h,&w,&k);
        temp.push_back(y-1);
        temp.push_back(x-1);
        temp.push_back(h);
        temp.push_back(w);
        temp.push_back(k);
        knight.push_back(temp);
        for(int t=0;t<h;t++){
            for(int p=0;p<w;p++){
                arr2[t+y-1][p+x-1] = i;
            }
        }
        first.push_back(k);
    }
    for(int i=0;i<q;i++){
        int from,to;
        vector<int> temp;
        scanf("%d %d",&from,&to);
        temp.push_back(from-1);
        temp.push_back(to);
        order.push_back(temp);
    }
    dfs(0);
    for(int i=0;i<m;i++){
        if(!die[i]){
            res+=(first[i] - knight[i][4]);
        }
    }
    printf("%d",res);
}
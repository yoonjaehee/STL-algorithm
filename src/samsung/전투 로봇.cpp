#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <limits.h>
using namespace std;
int n;
vector<vector<int>> vec;
vector<int> robot;
vector<int> temp;
int time = 0;
int px[4]={0,-1,1,0};
int py[4] = {-1,0,0,1};
bool visited[21][21];
int arr[21][21];
int arr2[21][21];
queue<pair<int,int>> q;
vector<vector<int>> tmp2;
int mx = 0;
int ans = 0;
struct cmp{
    bool operator()(vector<int> &a,vector<int> &b){
        if(a[2] > b[2]){
            return true;
        }
        else if(a[2] == b[2]){
            if(a[0] > b[0]){
                return true;
            }
            else if(a[0] == b[0]){
                if(a[1] > b[1]){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }    
};
priority_queue<vector<int>,vector<vector<int>>,cmp> pq; // 적들 타임과 위치 저장 
void bfs(vector<int> &rt,int len){
    for(int i=0;i<len;i++){
        memset(visited[i],false,sizeof(bool)*len);
        memset(arr2[i],0,sizeof(int) * len);
    }
    pq = priority_queue<vector<int>,vector<vector<int>>,cmp>();
    int y = rt[0];
    int x = rt[1];
    visited[y][x] = true;
    q.push({y,x});
    arr2[y][x] = 0;
    int mn = INT_MAX;
    int cnt = 0;
    while(!q.empty()){
        int temy =q.front().first;
        int temx = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ny = temy + py[i];
            int nx = temx + px[i];
            if((nx>=0) && (nx<n) && (ny>=0) && (ny<n)){
                if(!visited[ny][nx]){
                    if(rt[2] < arr[ny][nx]){
                        continue;
                    }
                    arr2[ny][nx] = arr2[temy][temx] + 1; // 이거 조심!
                    q.push({ny,nx});
                    visited[ny][nx] = true;
                    if(arr[ny][nx] != 0 && rt[2] > arr[ny][nx] ){
                        temp = {ny,nx,arr2[ny][nx]};
                        pq.push(temp);
                        cnt++;
                    }
                }
            }
        }
    }
    if(cnt == 0){
        printf("%d",ans);
        return;
    }
    else{
        temp = pq.top();
        arr[temp[0]][temp[1]] = 0;
        for(int i=0;i<pq.size();i++){
            pq.pop();
        }
        rt[0] = temp[0];
        rt[1] = temp[1];
        ans += temp[2];
        rt[3]+=1;
        if(rt[3] >= rt[2]){
            rt[2] += 1;
            rt[3] = 0;
        }
        bfs(rt,len);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&arr[i][t]);
            if(arr[i][t]>=1 && arr[i][t] <= 6){ 
                temp.clear();
                temp.push_back(i);
                temp.push_back(t);
                temp.push_back(arr[i][t]);
            }
            else if(arr[i][t] == 9){
                robot.push_back(i);
                robot.push_back(t);
                robot.push_back(2);
                robot.push_back(0);
                arr[i][t] = 0;
            }
        }
    }
    bfs(robot,n);
}
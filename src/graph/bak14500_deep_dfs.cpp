// bruthforce를 가장한 dfs문제.
// dfs로 사방을 탐색하여 도형을 만들어내고 예외상황들만 적어주기.
// back tracking필요.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int res=0;
int arr[501][501]={0,};
int ax[4]={0,0,1,-1};
int ay[4]={1,-1,0,0};
vector<vector<bool>> visited;
vector<int> maximum;
void dfs(int a,int b,int count,int sum){
    if(count == 4){
        if(res < sum){
            res = sum;
        }
        return;
    }
    for(int i=0;i<4;i++){
        int nx=a+ax[i];
        int ny=b+ay[i];
        if(nx<1 || nx>m || ny<1 || ny>n || visited[nx][ny]){
            continue;
        }
        else{
            visited[nx][ny]=true;
            dfs(nx,ny,count+1,sum+arr[nx][ny]);
            visited[nx][ny]=false; //backtracking
        }
    }
    if(a-1 >= 1 && b-1 >= 1 && a+1 <= n) { 
        res = max(res, (arr[a-1][b] + arr[a][b-1] + arr[a][b] + arr[a+1][b]));
    }
    if(a-1 >= 1 && b+1 <= m && a+1 <= n) {
        res = max(res, (arr[a-1][b] + arr[a][b+1] + arr[a][b] + arr[a+1][b]));
    }
    if(b-1 >= 1 && b+1 <= m && a+1 <= n) { 
        res = max(res, (arr[a][b] + arr[a+1][b] + arr[a+1][b-1] + arr[a+1][b+1]));
    }
    if(b-1 >= 1 && b+1 <= m && a+1 <= n) {
        res = max(res, (arr[a][b-1] + arr[a][b] + arr[a][b+1] + arr[a+1][b]));
    }
}
int main(){
    int num;
    scanf("%d %d",&n,&m);
    visited = vector<vector<bool>>(n+1,vector<bool>(m+1,false));
    for(int i=1;i<=n;i++){
        for(int t=1;t<=m;t++){
            scanf("%d",&num);
            arr[i][t]=num;
        }
    }
    for(int i=1;i<=n;i++){
        for(int t=1;t<=m;t++){
            visited[i][t]=true;
            dfs(i,t,1,arr[i][t]);
            visited[i][t]=false; // backtracking
        }
    }
    printf("%d",res);
    return 0;
}
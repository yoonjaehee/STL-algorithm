#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int count = 0;
queue<pair<int,int>> q;
int n;
int arr[101][101]={0,};
void bfs(int sty,int stx,int total){
    q.push({sty,stx});
    while(!q.empty()){
        pair<int,int> tem=q.front();
        q.pop();
        if((tem.first == n-1) && (tem.second == n-1)){
            count++;
            continue;
        }
        if(tem.first + arr[tem.first][tem.second] <= n-1){
            q.push({tem.first+arr[tem.first][tem.second],tem.second});
        }
        if(tem.second + arr[tem.first][tem.second] <= n-1){
            q.push({tem.first,tem.second+arr[tem.first][tem.second]});
        }
    }
}
int main(){
    int temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        memset(arr[i],0,sizeof(int)*(n));
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&temp);
            arr[i][t] = temp;
        }
    }
    bfs(0,0,count);
    printf("%d",count);
}
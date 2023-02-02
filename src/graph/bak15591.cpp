#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
int n,q;
int arr[5001][5001];
queue<pair<int,int>> que;
vector<bool> visited;
int bfs(int start,int end,int count,int counting){
    int temp,res;
    que.push({start,count});
    visited[start] = true;
    for(int i=0;i<visited.size();i++){
        printf("%d",visited[i]);
    }
    printf("\n");
    while(!que.empty()){
        printf("queue existed");
        temp = que.front().first;
        res = que.front().second;
        que.pop();
        for(int i=0;i<n;i++){
            if(arr[temp][i] > 0){
                if((res+arr[temp][i] <end) && !visited[i]){
                    visited[i] = true;
                    counting++;
                    que.push({i,res+arr[temp][i]});
                }
            }
        }
    }
    return counting;
}
int main(){
    int p,t,r,k,v;
    int total;
    scanf("%d %d",&n,&q);
    for(int i=0;i<n+1;i++){
        memset(arr[i],0,sizeof(int)*(n+1));
    }
    for(int i=0;i<n-1;i++){
        scanf("%d %d %d",&p,&t,&r);
        arr[p][t] = r;
        arr[t][p] = r;
    } 
    for(int i=0;i<q;i++){
        scanf("%d %d",&k,&v);
        vector<bool> visited(n+1,false);
        total = bfs(k,v,0,0);
        printf("%d",total);
    }
}
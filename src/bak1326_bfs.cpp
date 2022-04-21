#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int n,from,to;
int arr[10001]={0,};
int arr2[10001]={0,};
int visited[10001]={false,};
void bfs(int start,int end){
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        if(q.front() == end){
            return;
        }
        for(int i=temp+arr[temp];i<=n;i+=arr[temp]){
            if(!visited[i]){
                arr2[i] = arr2[temp] + 1;
                q.push(i);
                visited[i]=true;
            }
        }
        for(int i=temp-arr[temp];i>=1;i-=arr[temp]){
            if(!visited[i]){
                arr2[i] = arr2[temp]+1;
                q.push(i);
                visited[i]=true;
            }
        }
    }
}
int main(){
    int res;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d %d",&from,&to);
    if(from == to){
        printf("0");
        return 0;
    }
    bfs(from,to);
    res = arr2[to];
    if(res == 0){
        printf("-1");
    }
    else{
        printf("%d",res);
    }   
}
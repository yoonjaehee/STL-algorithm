#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<pair<int,int>> q;
vector<bool>visited(100001,false);
void bfs(int a, int b){
    q.push({a,0});
    visited[a]=true;
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        int line=cur.first;
        int time=cur.second;
        if(line == b){
            printf("%d", time);
        } 
        if(!visited[line+1] && line+1<100001){
            q.push({line+1,time+1});
            visited[line+1]=true;
        }
        if(!visited[line-1] && line-1>=0){
            q.push({line-1,time+1});
            visited[line-1]=true;
        }
        if(!visited[line*2] && (line*2)<100001){
            q.push({line*2,time+1});
            visited[line*2]=true;
        }
    }
}

int main(){
    int start,end;
    scanf("%d %d",&start,&end);
    bfs(start,end);
}
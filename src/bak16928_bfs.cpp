#include <iostream>
#include <queue>
using namespace std;
int n,m;
int stair[101]={0,};
int snake[101]={0,};
queue<pair<int,int>> q;
vector<int> visited(101,false);
void bfs(int a, int b){
    q.push({a,b});
    visited[a]=true;
    while(!q.empty()){
        pair<int,int> cur=q.front();
        q.pop();
        int numb=cur.first;
        int count=cur.second;
        if(numb == 100){
            printf("%d",count);
            return;
        }
        for(int i=1;i<7;i++){
            if(!visited[numb+i] && numb+i<101){
                if(numb+i<stair[numb+i]){
                    q.push({stair[numb+i],count+1});
                    visited[stair[numb+i]]=true;
                }
                else if(snake[numb+i]!=0){
                    q.push({snake[numb+i],count+1});
                    visited[snake[numb+i]]=true;
                }
                else{
                    q.push({numb+i,count+1});
                    visited[numb+i]=true;
                }
            }
            else{
                continue;
            }
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        int start,end;
        scanf("%d %d",&start,&end);
        stair[start]=end;        
    }
    for(int i=0;i<m;i++){
        int start,end;
        scanf("%d %d",&start,&end);
        snake[start]=end;
    }
    bfs(1,0);
}
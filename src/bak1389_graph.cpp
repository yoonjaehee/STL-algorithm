#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<int>q;
vector<vector<bool>>conn;
int n,m;
int arr[100][100]={0,};
void bfs(int start){
    int tem[n]={0,}
    q.push(start);
    while(!q.empty()){
        int current = q.front();
        q.pop();  
        
    }  
}
int main(){
    scanf("%d %d",&n,&m);
    conn=vector<vector<bool>>(n,vector<bool>(n,false));
    for(int i=0;i<m;i++){
        int temp1, temp2;
        scanf("%d %d",&temp1,&temp2);
        conn[temp1][temp2]=true;
        conn[temp2][temp1]=true;
        q.push(temp1);
    }
    bfs();
}
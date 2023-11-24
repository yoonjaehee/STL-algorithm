#include <iostream>
#include <vector>
using namespace std;
int num,conn,y,x;
bool visited[100];
vector<int> vec[101];
void dfs(int start){
    visited[start] = true;
    for(int i=0;i<vec[start].size();i++){
        dfs(vec[start][i]);
    }
}
int main(){
    scanf("%d",&num);
    scanf("%d",&conn);
    for(int i=0;i<conn;i++){
        scanf("%d %d",&x,&y);
        vec[x].push_back(y); 
    }
    dfs(1);
    int answer = 0;
    for(int i=2;i<=num;i++){
        if(visited[i]){
            answer++;
        }
    }
    printf("%d",answer);
}
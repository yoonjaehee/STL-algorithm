#include <iostream>
#include <queue>
#include <climits>
using namespace std;
queue<int> q;
vector<int> vec;
int a,b;
void bfs(int start){
    q.push(start); 
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        if((vec[cur*2] >= vec[cur]+1) && ((cur*2)<=b)){
            vec[cur*2] = vec[cur]+1;
            q.push(cur*2);
        }
        if((vec[cur*10+1] >= vec[cur]+1) && ((cur*10+1)<=b)){
            vec[cur*10+1] = vec[cur]+1;
            q.push((cur*10)+1);
        }
    }
}
int main(){
    scanf("%d %d",&a,&b);
    vec = vector<int>(b+1,INT_MAX);
    vec[a] = 1;
    bfs(a);
    if(vec[b] == INT_MAX){
        printf("-1");
    }  
    else{
        printf("%d",vec[b]);
    }
}

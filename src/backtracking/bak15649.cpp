#include <iostream>
using namespace std;
int n,m;
int cur_array[9];
bool visited[9];
void dfs(int a,int b,int cnt){
    if(cnt > b){ // 글자수 길이가 최대일때
        for(int i=1;i<=b;i++){
            printf("%d ",cur_array[i]);
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cur_array[cnt] = i;
            visited[i] = true;
            dfs(n,m,cnt+1);
            visited[i] = false;
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    dfs(n,m,1);
}
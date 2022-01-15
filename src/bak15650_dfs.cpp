#include <iostream>
#include <vector>
using namespace std;
vector<bool> visited;
int arr[9]={0,};
int n,m;
void dfs(int num, int count){
    if(count == m){
        for(int i=0;i<m;i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    else{
        for(int i=num;i<=n;i++){
            if(!visited[i]){
                visited[i] = true;
                arr[count]=i;
                dfs(i+1,count+1);
                visited[i] = false;
            }
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    visited = vector<bool>(9,false);
    dfs(1,0);
}
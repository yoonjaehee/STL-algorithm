#include <iostream>
#include <string.h>
using namespace std;
int arr[7];
int n,m;
void dfs(int big,int si,int cur){
    if(cur > m){
        for(int i=1;i<=si;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++){
        arr[cur] = i;
        dfs(n,m,cur+1);
    }

}
int main(){
    scanf("%d %d",&n,&m);
    memset(arr,0,sizeof(int)*(n+1));
    dfs(n,m,1);
}
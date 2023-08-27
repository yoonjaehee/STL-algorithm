#include <iostream>
using namespace std;
int arr[9];
void dfs(int big,int si,int cur){
    if(cur > si){
        for(int i=1;i<=si;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1;i<=big;i++){
        if(arr[cur-1] > i){
            continue;
        }
        arr[cur] = i;
        dfs(big,si,cur+1);
    }
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    dfs(n,m,1);
}
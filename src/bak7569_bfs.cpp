#include <iostream>
#include <queue>
#include <vector>
int n,m,h,count;
int arr[100][100][100];
int px[6]={1,-1,0,0,0,0};
int py[6]={0,0,-1,1,0,0};
int ph[6]={0,0,0,0,1,-1};

int main(){
    count = 0; 
    scanf("%d %d %d", &n,&m,&h);
    int cols=m*h;
    for(int p=0;p<h;p++){
        for(int i=0;i<n;i++){
            for(int t=0;t<m;t++){
                scanf("%d ", &arr[i][t][p]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<cols;t++){
            if(!visited[i][t] && adj[i][t]==1){
                dfs(i,t);
                count++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<cols;t++){
            if(adj[i][t]==0){
                printf("-1");
                return 0;
            }
        }
    }
    printf("%d", count);
}
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX INT_MAX
int n,m,a,b,c;
int arr[101][101];
queue<pair<int,int>> q;
void floyd(){
    for(int i=1;i<=n;i++){
        for(int t=1;t<=n;t++){
            for(int j=1;j<=n;j++){
                if(arr[t][i] != MAX && arr[i][j] != MAX){
                    arr[t][j] = min(arr[t][j], arr[t][i] + arr[i][j]);
                } 
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1;i<=n;i++){
        for(int t=1;t<=n;t++){
            arr[i][t] = MAX;
        }
    }
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&a,&b,&c);
        if(arr[a][b] > c){
            arr[a][b] = c;
        }
    }
    floyd();
    for(int i=1;i<=n;i++){
        for(int t=1;t<=n;t++){
            if(arr[i][t] == MAX || i==t){
                printf("0 ");
            }
            else{
                printf("%d ",arr[i][t]);
            }
        }
        printf("\n");
    }
}
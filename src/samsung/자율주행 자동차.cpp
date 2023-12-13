#include <iostream>
using namespace std;
int n,m,temp;
int sty,stx,tem;
int arr[51][51];
bool visited[51][51];
int mx = 0;
void dfs(int y,int x,int dir,int sum){
    bool can = false;
    bool can2 = true;
    int stdir = dir;
    visited[y][x] = true;
    if(mx < sum){
        mx = sum;
    }
    for(int i=0;i<5;i++){
        dir = (stdir + 7 - i)%4;
    if(dir == 0){
        if(y - 1 >= 0 && arr[y-1][x] == 0 && !visited[y-1][x]){
            dfs(y-1,x,dir,sum+1);
            return;
        }
        if(i == 4){
            if(x-1 < 0){
                return;
            }
            if(x-1 >= 0){
                if(arr[y][x-1] != 0){
                    return;
                }
            }
            dfs(y,x-1,stdir,sum);
            return;
        }
    }
    else if(dir == 1){
        if(x + 1 < m && arr[y][x+1] == 0 && !visited[y][x+1]){
            dfs(y,x+1,dir,sum+1);
            return;
        }
        if(i == 4){
            if(y-1 < 0){
                return;
            }
            if(y-1 >= 0){
                if(arr[y-1][x] != 0){
                    return;
                }
            }
            dfs(y-1,x,stdir,sum);
            return;
        }
    }
    else if(dir == 2){
        if(y + 1 < n && arr[y+1][x] == 0 && !visited[y+1][x]){
            dfs(y+1,x,dir,sum+1);
            return;
        }
        if(i == 4){
            if(x+1 >= m){
                return;
            }
            if(x+1 < m){
                if(arr[y][x+1] != 0){
                    return;
                }
            }
            dfs(y,x+1,stdir,sum);
            return;
        }
        
    }
    else if(dir == 3){
        if(x - 1 >= 0 && arr[y][x-1] == 0 && !visited[y][x-1]){
            dfs(y,x-1,dir,sum+1);
            return;
        }
        if(i == 4){
            if(y+1 >= n){
                return;
            }
            if(y+1 < n){
                if(arr[y+1][x] != 0){
                    return;
                }
            }
            dfs(y+1,x,stdir,sum);
            return;
        }
    }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    scanf("%d %d %d",&sty,&stx,&tem);
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            scanf("%d",&temp);
            arr[i][t] = temp;
        }
    }
    dfs(sty,stx,tem,1);
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            printf("%d",visited[i][t]);
        }
        printf("\n");
    }
    printf("%d",mx);
}
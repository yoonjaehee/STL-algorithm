#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
int n;
int arr[21][21];
bool visited[21][21];
priority_queue<int> pq;
int py[4] = {-1,1,0,0};
int px[4] = {0,0,-1,1};
pair<int,int> moving(vector<vector<int>> vec2,int y,int x,int dir2){
    while(1){
        int ny = y + py[dir2];
        int nx = x + px[dir2];
        if(ny >= 0 && nx >= 0 && ny < n && nx < n && vec2[ny][nx] == 0){
            y = ny;
            x = nx;
        }
        else{
            break;
        }
    }
    return {y,x};
}
int a,b;
int mx = 0;
void mov(vector<vector<int>> tmp,int start,int dir){
    if(start == 5){
        return;
    }
    for(int i=0;i<n;i++){
        memset(visited[i],false,sizeof(bool)*n);
    }
    if(dir == 0){ // 위
        for(int i=1;i<n;i++){
            for(int t=0;t<n;t++){
                pair<int,int> temp=moving(tmp,i,t,dir);
                a = temp.first;
                b = temp.second;
                tmp[a][b] = tmp[i][t];
                if(a != i || b != t){
                    tmp[i][t] = 0;
                }
                if(a >= 1){ // 변화되는 부분이 맞는지 확인 절차 !!! 이것때매 30분날림.. 
                    if(tmp[a-1][b] == tmp[a][b] && !visited[a-1][b]){
                        tmp[a-1][b]*=2;
                        if(tmp[a-1][b] > mx){
                            mx = tmp[a-1][b];
                        }
                        tmp[a][b] = 0;
                        visited[a-1][b] = true;
                    }
                }
            }
        }
    }
    else if(dir == 1){ // 아래
        for(int i=n-2;i>=0;i--){
            for(int t=n-1;t>=0;t--){
                pair<int,int> temp=moving(tmp,i,t,dir);
                a = temp.first;
                b = temp.second;
                tmp[a][b] = tmp[i][t];
                if(a != i || b != t){
                    tmp[i][t] = 0;
                }
                if(a < n-1){
                    if((tmp[a+1][b] == tmp[a][b]) && (!visited[a+1][b])){
                        (tmp[a+1][b])*=2;
                        if(tmp[a+1][b] > mx){
                            mx = tmp[a+1][b];
                        }
                        tmp[a][b] = 0;
                        visited[a+1][b] = true;
                    }
                }
            }
        }
    }
    else if(dir == 2){ // 왼쪽
        for(int t=1;t<n;t++){
            for(int i=0;i<n;i++){
                pair<int,int> temp=moving(tmp,i,t,dir);
                a = temp.first;
                b = temp.second;
                tmp[a][b] = tmp[i][t];
                 if(a != i || b != t){
                    tmp[i][t] = 0;
                }
                if(b >= 1){
                    if(tmp[a][b-1] == tmp[a][b] && !visited[a][b-1]){
                        tmp[a][b-1]*=2;
                        if(tmp[a][b-1] > mx){
                            mx = tmp[a][b-1];
                        }
                        tmp[a][b] = 0;
                        visited[a][b-1] = true;
                    }
                }
            }
        }
    }
    else if(dir == 3){ // 오른쪽
        for(int t=n-2;t>=0;t--){
            for(int i=n-1;i>=0;i--){
                pair<int,int> temp=moving(tmp,i,t,dir);
                a = temp.first;
                b = temp.second;
                tmp[a][b] = tmp[i][t];
                 if(a != i || b != t){
                    tmp[i][t] = 0;
                }
                if(b < n-1){
                    if(tmp[a][b+1] == tmp[a][b] && !visited[a][b+1]){
                        tmp[a][b+1]*=2;
                        if(tmp[a][b+1] > mx){
                            mx = tmp[a][b+1];
                        }
                        tmp[a][b] = 0;
                        visited[a][b+1] = true;
                    }
                }
            }
        }
    }
    mov(tmp,start+1,0);
    mov(tmp,start+1,1);
    mov(tmp,start+1,2);
    mov(tmp,start+1,3);
}
int main(){
    scanf("%d",&n);
    vector<vector<int>> vec(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&arr[i][t]);
            vec[i][t] = arr[i][t];
            if(mx < vec[i][t]){
                mx = vec[i][t];
            }
        }
    }
    mov(vec,0,0);
    mov(vec,0,1);
    mov(vec,0,2);
    mov(vec,0,3);
    printf("%d",mx);
}
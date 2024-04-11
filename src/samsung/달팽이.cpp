#include <iostream>
using namespace std;
int n,pos;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int main(){
    scanf("%d",&n);
    scanf("%d",&pos);
    int maxlen = n;
    int curlen = 1;
    int cur = 0; // 방향
    int len = 0; // 길이
    int arr[n][n];
    int dir = 0;
    int sty = n/2;
    int stx = n/2;
    int cnt = 0;
    int temp = 1;
    arr[sty][stx] = 1;
    int ansy = sty;
    int ansx = stx;
    for(int i=1;i<n*n;i++){
        temp++;
        int ny = sty + dy[dir];
        int nx = stx + dx[dir];
        arr[ny][nx] = temp;
        if(temp == pos){
            ansy = ny;
            ansx = nx;
        }
        len++;
        if(len == curlen){
            len = 0;
            cnt++;
            if(dir == 3){
                dir = 0;
            }
            else{
                dir++;
            }
        }
        if(cnt == 2){
            cnt = 0;
            curlen++;
        }
        sty = ny;
        stx = nx;
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            printf("%d ",arr[i][t]);
        }
        printf("\n");
    }
    printf("%d %d",ansy+1,ansx+1);
}
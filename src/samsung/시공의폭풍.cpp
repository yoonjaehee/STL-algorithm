#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
vector<pair<int,int>> torn;
int n,m,t;
int arr[51][51];
int px[4]={1,-1,0,0};
int py[4] = {0,0,1,-1};
int add[51][51]={0,};
int minu[51][51]={0,};
int ret=0;
void spread(int y,int x){
    if(arr[y][x] == -1){
        return;
    }
    for(int i=0;i<4;i++){
        int sty = py[i] + y;
        int stx = px[i] + x;
        if(arr[sty][stx] == -1){
            continue;
        }
        int temp = arr[y][x]/5;
        if(sty >=0 && stx>=0 && sty<n && stx <m){
            add[sty][stx] += temp;
            minu[y][x]+=temp;
        }
    }
}
void clean(){
    int tny1 = torn[0].first;
    int tny2 = torn[1].first;
    arr[tny1][0] = 0;
    arr[tny2][0] = 0;
    for(int i=tny1;i>0;i--){
        arr[i][0] = arr[i-1][0];
    }
    for(int i=0;i<m-1;i++){
        arr[0][i] = arr[0][i+1]; 
    }
    for(int i=0;i<tny1;i++){
        arr[i][m-1] = arr[i+1][m-1];
    }
    for(int i=m-1;i>1;i--){
        arr[tny1][i] = arr[tny1][i-1]; 
    }
    arr[tny1][0] = 0;
    arr[tny1][1] = 0;
    for(int i=n-1;i>tny2;i--){
        arr[i-1][0]=arr[i][0];
    }
    for(int i=0;i<m-1;i++){
        arr[n-1][i] = arr[n-1][i+1];
    }
    for(int i=n-1;i>tny2;i--){
        arr[i][m-1] = arr[i-1][m-1];
    }
    for(int i=m-1;i>0;i--){
        arr[tny2][i] = arr[tny2][i-1];
    }
    arr[tny2][0] = 0;
    arr[tny2][1] = 0;
}
void tim(int timing){
    if(timing==0){ // 시간만큼 돌음
        return;
    }
    for(int i=0;i<n;i++){
        memset(add[i],0,sizeof(int)*m);
        memset(minu[i],0,sizeof(int)*m);
    }
    for(int i=0;i<n;i++){ // 먼지확산
        for(int t=0;t<m;t++){
            spread(i,t);
        }
    }
    for(int i=0;i<n;i++){ // 먼지 확산 계산
        for(int t=0;t<m;t++){
            arr[i][t] += add[i][t];
            arr[i][t] -= minu[i][t];
        }
    }
    clean(); // 돌풍 이동
    tim(timing-1);
}
int main(){
    scanf("%d %d %d",&n,&m,&t);
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            scanf("%d",&arr[i][t]);
            if(arr[i][t] == -1){
                torn.push_back({i,t});
            }
        }
    }
    tim(t); // 
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            ret+=(arr[i][t]);
        }
    }
    printf("%d",ret);
}
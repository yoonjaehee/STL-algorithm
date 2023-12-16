#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int n,m,k,x,y,s,d,b;
int arr[101][101];
vector<vector<int>> vec;
int mx = 0;
bool visited[101][101];
void mov(vector<int> tmp,int cnt){
    int sty = tmp[0];
    int stx = tmp[1];
    int dir = tmp[3];
    int amount = tmp[2];
    if(dir == 1){ // 위
        if(amount - sty >= 0){
            if((((amount-sty)/(n-1)))%2 == 0){
                dir = 2;
                sty = ((amount-sty)%(n-1));
            }
            else{
                dir = 1;
                sty = n-1 - ((amount-sty)%(n-1));
            }
        }
        else{
            sty = sty - amount;
        }
    }
    else if(dir == 2){  // 아래
        if(amount - (n-1-sty) >= 0){
            if((((amount-(n-1-sty))/(n-1)))%2 == 0){
                dir = 1;
                sty = (n-1)-((amount-(n-1-sty))%(n-1));
            }
            else{
                dir = 2;
                sty = ((amount-(n-1-sty))%(n-1));
            }
        }
        else{
            sty = sty + amount;
        }
    }
    else if(dir ==3){ // 오른쪽
        if(amount - (m-1-stx) >= 0){
            if(((amount-(m-1-stx))/(m-1))%2 == 0){
                dir = 4;
                stx = (m-1) - ((amount-(m-1-stx))%(m-1));
            }
            else{
                dir = 3;
                stx = ((amount-(m-1-stx))%(m-1));
            }
        }
        else{
            stx = stx + amount;
        }
    }
    else if(dir == 4){ // 왼쪽
        if(amount - stx >= 0){
            if(((amount-stx)/(m-1))%2 == 0){
                dir = 3;
                stx = ((amount-stx)%(m-1));
            }
            else{
                dir = 4;
                stx = (m-1) - ((amount-stx)%(m-1));
            }
        }
        else{
            stx = stx - amount;
        }
    }
    if(visited[sty][stx]){
        if(tmp[4] > arr[sty][stx] && arr[sty][stx] != 0){ // 이미 옮겼는데 겹침.
            for(int i=0;i<cnt;i++){
                if(vec[i][0] == sty && vec[i][1] == stx){
                    vec[i][5] = 1;
                }
            }
            arr[sty][stx] = tmp[4];
        }
        else{
            vec[cnt][5] = 1;
        }
    }
    else{
        arr[sty][stx] = tmp[4];
    }
    visited[sty][stx] = true;
    vec[cnt][0] = sty;
    vec[cnt][1] = stx;
    vec[cnt][3] = dir;
}
void dfs(int start){
    if(start == m){
        return;
    }
    for(int i=0;i<n;i++){
        memset(visited[i],0,sizeof(bool)*m);
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            printf("%d ",arr[i][t]);
        }
        printf("\n");
    }
    printf("\n");
    bool can = true;
    for(int i=0;i<n;i++){ // 제거 후 비활성화
        if(arr[i][start] != 0){
            mx+=(arr[i][start]);
            arr[i][start] = 0;
            for(int t=0;t<vec.size();t++){
                if(i == vec[t][0] && start == vec[t][1] && vec[t][5] == 0){
                    can = false;
                    vec[t][5] = 1;
                    break;
                }
            }
            if(!can){
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            arr[i][t] = 0;
        }
    }
    for(int i=0;i<vec.size();i++){ // 3번 곰팡이 이동
        if(vec[i][5] == 0){
            mov(vec[i],i);
        }
    }
    dfs(start+1); // 오른쪽열 이동
}
int main(){
    vector<int> vec1;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<k;i++){
        scanf("%d %d %d %d %d",&y,&x,&s,&d,&b);// s=거리, d=방향,b=크기
        vec1.clear();
        vec1.push_back(y-1);
        vec1.push_back(x-1);
        vec1.push_back(s);
        vec1.push_back(d);
        vec1.push_back(b);
        vec1.push_back(0);
        arr[y-1][x-1] = b;
        vec.push_back(vec1);
    }
    dfs(0);
    printf("%d",mx);
}
/*
6 5 5
1 5 1 4 5
2 3 0 3 1
3 5 4 1 4
4 2 5 2 2
1 2 5 3 3
*/
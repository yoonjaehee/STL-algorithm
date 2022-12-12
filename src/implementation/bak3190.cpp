#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n,k,l;
int arr[101][101];
queue<pair<int,char>> q; // 방향 전환
queue<pair<int,char>> tail; // 꼬리 현황
void dfs(int cnt,char dir,int starty,int startx){
    int tmx,tmy;
    if(starty == n || startx == n || ((starty != 0) && (startx != 0) && (arr[starty][startx] == 2)) || startx < 0 || starty < 0){
        printf("%d",cnt);
        return;
    }
    if(dir == 'R'){
        tail.push({starty,startx+1});
        //사과가 있을때 없을때 구분
        if(arr[starty][startx+1] == 1){
            arr[starty][startx+1] = 2;
        }
        else{
            tmy=tail.front().first;
            tmx = tail.front().second;
            arr[tmy][tmx] = 0;
            tail.pop();
            arr[starty][startx+1] = 2;
        }
        //방향 전환이 있을때
        if(q.front().first == cnt){
            if(q.front().second == 'R'){
                q.pop();
                dfs(cnt+1,'D',starty,startx+1);
            }
            else if(q.front().second == 'L'){
                q.pop();
                dfs(cnt+1,'U',starty,startx+1);
            }
        }
        //방향 전환이 없을때
        else{
            dfs(cnt+1,'R',starty,startx+1);
        }
    }
    else if(dir == 'L'){
        tail.push({starty,startx-1});
        //사과가 있을때
        if(arr[starty][startx-1] == 1){
            arr[starty][startx-1] = 2;
        }
        //사과가 없을때
        else{
            tmy=tail.front().first;
            tmx = tail.front().second;
            arr[tmy][tmx] = 0;
            tail.pop();
            arr[starty][startx-1] = 2;
        }
        //방향 전환이 있을때
        if(q.front().first == cnt){
            if(q.front().second == 'R'){
                q.pop();
                dfs(cnt+1,'U',starty,startx-1);
            }
            else if(q.front().second == 'L'){
                q.pop();
                dfs(cnt+1,'D',starty,startx-1);
            }
        }
        //방향 전환이 없을때
        else{
            dfs(cnt+1,'L',starty,startx-1);
        }
    }
    else if(dir == 'D'){
        tail.push({starty+1,startx});
        //사과가 있을때 없을때 구분
        if(arr[starty+1][startx] == 1){
            arr[starty+1][startx] = 2;
        }
        else{
            tmy=tail.front().first;
            tmx = tail.front().second;
            arr[tmy][tmx] = 0;
            tail.pop();
            arr[starty+1][startx] = 2;
        }
        //방향 전환이 있을때
        if(q.front().first == cnt){
            if(q.front().second == 'R'){
                q.pop();
                dfs(cnt+1,'L',starty+1,startx);
            }
            else if(q.front().second == 'L'){
                q.pop();
                dfs(cnt+1,'R',starty+1,startx);
            }
        }
        //방향 전환이 없을때
        else{
            dfs(cnt+1,'D',starty+1,startx);
        }
    }
    else if(dir == 'U'){
        tail.push({starty-1,startx});
        //사과가 있을때 없을때 구분
        if(arr[starty-1][startx] == 1){
            arr[starty-1][startx] = 2;
        }
        else{
            tmy=tail.front().first;
            tmx = tail.front().second;
            arr[tmy][tmx] = 0;
            tail.pop();
            arr[starty-1][startx] = 2;
        }
        //방향 전환이 있을때
        if(q.front().first == cnt){
            if(q.front().second == 'R'){
                q.pop();
                dfs(cnt+1,'R',starty-1,startx);
            }
            else if(q.front().second == 'L'){
                q.pop();
                dfs(cnt+1,'L',starty-1,startx);
            }
        }
        //방향 전환이 없을때
        else{
            dfs(cnt+1,'U',starty-1,startx);
        }
    }
}
int main(){
    int x,y,temp;
    char turn;
    scanf("%d",&n);
    scanf("%d",&k);
    for(int i=0;i<n+1;i++){
        memset(arr,0,sizeof(int)*(n+1));
    }
    for(int i=0;i<k;i++){
        scanf("%d %d",&y,&x);
        arr[y-1][x-1]=1;
    }
    scanf("%d",&l);
    for(int i=0;i<l;i++){
        scanf("%d %c",&temp,&turn);
        q.push({temp,turn});
    }
    int count = 0;
    arr[0][0] = 2;
    tail.push({0,0});
    dfs(count,'R',0,0);
}
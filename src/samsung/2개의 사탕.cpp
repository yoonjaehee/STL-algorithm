#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int arr[11][11];
bool arr2[10][10];
priority_queue<int> pq;
queue<pair<pair<pair<int,int>,pair<int,int>>,int>> q; 
int endy,endx;
int n,m,ny,nx;
int redy, redx,bly,blx;
int py[4] = {-1,0,1,0};
int px[4] = {0,1,0,-1};
void mov2(int y,int x,int dir,bool blue){
    arr[y][x] = 1; 
    while(1){
        ny = y + py[dir];
        nx = x + px[dir];
        if(arr[ny][nx] == 1 && ny >= 0 && ny < n && nx >= 0 && nx < m){
            if(ny == endy && nx == endx){
                y=ny;
                x=nx;
                break;
            }
            y = ny;
            x = nx;
        }
        else{
            break;
        }
    }
    if(blue){
        bly = y;
        blx = x;
        if(bly == endy && blx == endx){
            arr[bly][blx] = 1;
        }
        else{
            arr[bly][blx] = 0;
        }
    }
    else{
        redy = y;
        redx = x;
        if(y == endy && x == endx){
            arr[redy][redx] = 1;
        }
        else{
            arr[redy][redx] = 0;
        }
        
    }
}
void mov(){
    while(!q.empty()){
        int ry = q.front().first.first.first;
        int rx = q.front().first.first.second;
        int by = q.front().first.second.first;
        int bx = q.front().first.second.second;
        int time = q.front().second;
        q.pop();
        if(time > 10){
            continue;
        }
        for(int i=0;i<4;i++){
            if(i == 0){
                if(ry < by){
                    mov2(ry,rx,i,0);
                    mov2(by,bx,i,1);
                }
                else{
                    mov2(by,bx,i,1);
                    mov2(ry,rx,i,0);
                }
            }
            else if(i == 1){
                if(rx < bx){
                    mov2(by,bx,i,1);
                    mov2(ry,rx,i,0);
                }
                else{
                    mov2(ry,rx,i,0);
                    mov2(by,bx,i,1);
                }
            }
            else if(i == 2){
                if(ry > by){
                    mov2(ry,rx,i,0);
                    mov2(by,bx,i,1);
                }
                else{
                    mov2(by,bx,i,1);
                    mov2(ry,rx,i,0);
                }
            }
            else if(i == 3){
                if(rx < bx){
                    mov2(ry,rx,i,0);
                    mov2(by,bx,i,1);
                }
                else{
                    mov2(by,bx,i,1);
                    mov2(ry,rx,i,0);
                }
            }
            if(bly == endy && blx == endx){
                arr[ry][rx] = 1;
                arr[by][bx] = 1;
                arr[bly][blx] = 1;
                arr[redy][redx] = 1;
            }
            else{
                if(redy == endy && redx == endx){
                    pq.push(time);
                    return;
                }
                else{
                    q.push({{{redy,redx},{bly,blx}},time+1});
                    arr[ry][rx] = 1;
                    arr[by][bx] = 1;
                    arr[bly][blx] = 1;
                    arr[redy][redx] = 1;
                }
            }
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    string str;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,str);
        for(int t=0;t<m;t++){
            if(str[t] == '#'){
                arr[i][t] = 0;
            }
            else if(str[t] == '.'){
                arr[i][t] = 1;
            }
            else if(str[t] == 'R'){
                arr[i][t] = 1;
                redy = i;
                redx = t;
            }
            else if(str[t] == 'B'){
                arr[i][t] = 1;
                bly = i;
                blx = t;
            }
            else{
                arr[i][t] = 1;
                endy = i;
                endx = t;
            }
        }
    }
    q.push({{{redy,redx},{bly,blx}},1});
    mov();
    if(pq.empty()){
        printf("-1");
    }
    else{
        printf("%d",pq.top());
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string.h>
using namespace std;
int n,m,p,c,d;
int luy,lux;
vector<vector<int>> vec;
bool die[31];
int arr[51][51];
int faint[31];
int dy[8] = {1,1,1,-1,-1,-1,0,0};
int dx[8] = {1,0,-1,1,0,-1,1,-1};
int dy2[4] = {-1,0,1,0};
int dx2[4] = {0,1,0,-1};
vector<int> res(31,0);
void move(int idx, int dir,int flag){
    int sty = vec[idx][1];
    int stx = vec[idx][2];
    arr[sty][stx] = -1;
    if(flag == 1){
        vec[idx][1] -= dy2[dir];
        vec[idx][2] -= dx2[dir];
    }
    else{
        vec[idx][1] += dy[dir];
        vec[idx][2] += dx[dir];
    }
    if(vec[idx][1] < 0 || vec[idx][1] >= n || vec[idx][2] < 0 || vec[idx][2] >= n){
        die[idx] = true;
        return;
    }
    else if(arr[vec[idx][1]][vec[idx][2]] != -1){
        move(arr[vec[idx][1]][vec[idx][2]],dir,flag);
    }
    arr[vec[idx][1]][vec[idx][2]] = idx;
}
void ludmove(){
    int clidx = 0;
    int besum = INT_MAX;
    int tempy,tempx;
    // 루돌프 목표 설정
    for(int i=0;i<p;i++){
        int sum = 0;
        if(die[i]){
            continue;
        }
        sum += ((luy-vec[i][1]) * (luy-vec[i][1]));
        sum += ((lux-vec[i][2]) * (lux-vec[i][2]));
        if(sum < besum){
            clidx = i;
            besum = sum;
            tempy = vec[i][1];
            tempx = vec[i][2];
        }
        else if(sum == besum){
            if(tempy > vec[i][1]){
                continue;
            }
            else if(tempy == vec[i][1]){
                if(tempx > vec[i][2]){
                    continue;
                }
            }
            clidx = i;
            besum = sum;
            tempy = vec[i][1];
            tempx = vec[i][2];
        }
    }
    // 루돌프 움직임 
    int closet = INT_MAX;
    int dir;
    for(int i=0;i<8;i++){
        int ny = luy + dy[i];
        int nx = lux + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n){
            continue;
        }
        int calc = (abs(ny-vec[clidx][1]) * abs(ny-vec[clidx][1])) + (abs(nx - vec[clidx][2]) * abs(nx - vec[clidx][2]));
        if(closet > calc){
            closet = calc;
            tempy = ny;
            tempx = nx;
            dir = i;
        }
    }
    luy = tempy;
    lux = tempx;
    //충돌했을때 + 상호작용
    if(closet == 0){
        faint[clidx] = 2;
        arr[vec[clidx][1]][vec[clidx][2]] = -1;
        res[clidx] += c;
        vec[clidx][1] += (dy[dir] * (c));
        vec[clidx][2] += (dx[dir] * (c));
        if(vec[clidx][1] < 0 || vec[clidx][1] >= n || vec[clidx][2] < 0 || vec[clidx][2] >= n){
            die[clidx] = true;
            return;
        }
        else if(arr[vec[clidx][1]][vec[clidx][2]] != -1){
            move(arr[vec[clidx][1]][vec[clidx][2]],dir,0);
        }
        arr[vec[clidx][1]][vec[clidx][2]] = clidx;
    }
}
void santamove(){
    for(int i=0;i<p;i++){
        if(die[i] || (faint[i] >= 1)){
            continue;
        }
        int closet = (abs(vec[i][1] - luy) * abs(vec[i][1] - luy)) + (abs(vec[i][2] - lux) * abs(vec[i][2] - lux));
        int tempy,tempx,dir;
        tempy = vec[i][1];
        tempx = vec[i][2];
        for(int t=0;t<4;t++){
            int ny = vec[i][1] + dy2[t];
            int nx = vec[i][2] + dx2[t];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n || arr[ny][nx] != -1){
                continue;
            }
            int cal = ((ny-luy) * (ny-luy)) + ((nx - lux) * (nx - lux));
            if(closet > cal){
                closet = cal;
                tempy = ny;
                tempx = nx;
                dir = t;
            }
        }
        // 충돌했을때
        if(closet == 0){
            res[i] += d;
            int clidx = i;
            faint[clidx] = 2;
            arr[vec[clidx][1]][vec[clidx][2]] = -1;
            vec[clidx][1] -= (dy2[dir] * (d-1));
            vec[clidx][2] -= (dx2[dir] * (d-1));
            if(vec[clidx][1] < 0 || vec[clidx][1] >= n || vec[clidx][2] < 0 || vec[clidx][2] >= n){
                die[clidx] = true;
                continue;
            }
            else if(arr[vec[clidx][1]][vec[clidx][2]] != -1){
                move(arr[vec[clidx][1]][vec[clidx][2]],dir,1);
            }
            arr[vec[clidx][1]][vec[clidx][2]] = clidx;
        }
        else{
            arr[vec[i][1]][vec[i][2]] = -1;
            vec[i][1] = tempy;
            vec[i][2] = tempx;
            arr[vec[i][1]][vec[i][2]] = i;
        }
    }
}
void dfs(int start){
    if(start == m){
        return;
    }
    for(int i=0;i<p;i++){
        if(faint[i] > 0){
            faint[i]--;
        }
    }
    ludmove();
    santamove();
    /*for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            if(luy == i && lux == t){
                printf("S ");
                continue;
            }
            printf("%d ",arr[i][t]);
        }
        printf("\n");
    }
    printf("\n");
    */
    for(int i=0;i<p;i++){
        if(!die[i]){
            res[i]++;
        }
    }
    dfs(start+1);
}
int main(){
    scanf("%d %d %d %d %d",&n,&m,&p,&c,&d);
    scanf("%d %d",&luy,&lux);
    for(int i=0;i<n;i++){
        memset(arr[i],-1,sizeof(int) * n);
    }
    luy-=1;
    lux-=1;
    for(int i=0;i<p;i++){
        vector<int> tmp;
        int num,y,x;
        scanf("%d %d %d",&num,&y,&x);
        tmp.push_back(num-1);
        tmp.push_back(y-1);
        tmp.push_back(x-1);
        vec.push_back(tmp);
        arr[y-1][x-1] = num-1;
    }
    sort(vec.begin(),vec.end());
    dfs(0);
    for(int i=0;i<p;i++){
        printf("%d ",res[i]);
    }
}
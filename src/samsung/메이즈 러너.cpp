// 회전할때 이미 회전한거 확인해야한다. 그래서 flag를 설치해서 이미 회전한것들은 회전안시키게 했다!
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <string.h>
using namespace std;
int n,m,k;
int exy,exx;
int arr[11][11];
int tmp[11][11];
vector<int> vecs[11][11];
vector<vector<int>> vec;
int res = 0;
int cnt = 0;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,1,-1};
int ry,rx,cy,cx; // 가장 가까운 정사각형 idx
vector<vector<int>> vec2;
void move(){
    int comp = INT_MAX; // 가장 가까운 정사각형
    int cnt2 = 0;
    for(int i=0;i<vec.size();i++){
        bool erase = false;
        for(int t=0;t<4;t++){
            int ny = vec[i][0] + dy[t];
            int nx = vec[i][1] + dx[t];
            int dis = abs(exy - vec[i][0]) + abs(exx - vec[i][1]);
            if(ny < 0 || ny >= n || nx < 0 || nx >= n){
                continue;
            }
            if(arr[ny][nx] == 0){
                int dis2 = abs(ny-exy) + abs(nx-exx);
                if(dis > dis2){
                    res++;
                    if((ny == exy) && (nx == exx)){
                        erase = true;
                        cnt++;
                        break;
                    }
                    vec[i][0] = ny;
                    vec[i][1] = nx;
                    break;
                }
            }
        }
        if(erase){
            continue;
        }
        vec2.push_back(vec[i]);
        vecs[vec[i][0]][vec[i][1]].push_back(cnt2);
        cnt2++;
        // 정사각형 범위 구하기
        int distance = max(abs(exy-vec[i][0]),abs(exx-vec[i][1]));
        int temp = distance * distance;
        int temry,temrx,temcy,temcx;
        temcy = max(vec[i][0], exy);
        temcx = max(vec[i][1], exx);
        temry = temcy - distance;
        temrx = temcx - distance;
        if(temry < 0){
            temcy -= temry;
            temry = temcy - distance;
        }
        if(temrx < 0){
            temcx -= temrx;
            temrx = temcx - distance;
        }
        bool change = false;
        if(temp < comp){
            change = true;
        }
        else if(temp == comp){
            if(ry > temry){
                change = true;
            }
            else if(ry == temry){
                if(rx > temrx){
                    change = true;
                }
            }
        }
        if(change){
            comp = temp;
            ry = temry;
            rx = temrx;
            cy = temcy;
            cx = temcx;
        }
    }
}
void rotate(){
    for(int i=ry;i<=cy;i++){
        for(int t=rx;t<=cx;t++){
            tmp[i][t] = arr[i][t];
        }
    }
    bool flag = false;
    vector<bool> flag2(m,false);
    for(int i=ry;i<=cy;i++){
        for(int t=rx;t<=cx;t++){
            int temy = i-ry;
            int temx = t-rx;
            int tem2y = temx;
            int tem2x = (cy-ry) - temy; 
            arr[tem2y + ry][tem2x + rx] = tmp[i][t];
            if(arr[tem2y + ry][tem2x + rx] <= 9 && arr[tem2y + ry][tem2x + rx] >= 1){
                arr[tem2y + ry][tem2x + rx]--;
            }
            if((exy == (i)) && (exx == (t))){
                if(!flag){
                    exy = (tem2y + ry);
                    exx = (tem2x + rx);
                    flag = true;
                }
            }
            if(!vecs[i][t].empty()){
                for(int p=0;p<vecs[i][t].size();p++){
                    if(!flag2[vecs[i][t][p]]){
                        vec2[vecs[i][t][p]][0] = tem2y + ry;
                        vec2[vecs[i][t][p]][1] = tem2x + rx;
                        flag2[vecs[i][t][p]] = true;
                    }
                }
            }
        }
    }
}
void dfs(int start){
    vec2.clear();
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            vecs[i][t].clear();
        }
    }
    if(start == k){
        return;
    }
    if(cnt >= m){
        return;
    }
    ry = n+1;
    rx = n+1;
    cy = n+1;
    cx = n+1;
    move();
    if(cnt >= m){
        return;
    }
    rotate();
    vec = vec2;
    /*printf("--%d %d to %d %d--\n",ry,rx,cy,cx);
    printf("-%d %d-\n",exy,exx);
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            printf("%d ",arr[i][t]);
        }
        printf("\n");
    }
    for(int i=0;i<vec.size();i++){
        printf("{%d %d} ",vec[i][0],vec[i][1]);
    }
    printf("\n");
    */
    dfs(start+1);
}
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&arr[i][t]);
        }
    }
    int x,y;
    for(int i=0;i<m;i++){
        vector<int> tmp;
        scanf("%d %d",&y,&x);
        tmp.push_back(y-1);
        tmp.push_back(x-1);
        vec.push_back(tmp);
    }
    scanf("%d %d",&y,&x);
    exy = y-1;
    exx = x-1;
    dfs(0);
    printf("%d\n%d %d",res,exy+1,exx+1);
}
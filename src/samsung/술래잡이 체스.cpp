#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// 시간이 오래걸렸던 이유 : 문제에서 지금!!!!! 술래의 위치!!! 만을 제한둔거임. 0으로 바뀐칸은 가도됨... -> 문제를 잘읽자!
int arr[8][8];
int px[8] = {0,-1,-1,-1,0,1,1,1};
int py[8] = {-1,-1,0,1,1,1,0,-1};
pair<int,int> arr3[4][4];
bool visited[4][4];
int mx = 0;
int mx2 = 0;
vector<vector<int>> pq;
bool cmp(vector<int> &a,vector<int> &b){
    if(a[0] > b[0]){
        return false;
    }
    else{
        return true;
    }
}
void dfs(int sty,int stx,int cnt,vector<vector<pair<int,int>>> arr2,int st){
    pq.clear();
    if(mx2 < cnt){
        return;
    }
    if((sty + py[arr2[sty][stx].second] < 0)|| (stx + px[arr2[sty][stx].second] < 0) ||
    (sty + py[arr2[sty][stx].second] >= 4)|| (stx + px[arr2[sty][stx].second] >=4)){
        if(mx < cnt){ // 새로 도착한게 밖으로 가려할때 리턴.
            mx = cnt;
        }
        return;
    }
    if(mx < cnt){
        mx = cnt;
    }
    arr2[sty][stx].first = 0;
    for(int i=0;i<4;i++){ // pq 채우기
        for(int t=0;t<4;t++){
            if(arr2[i][t].first != 0){
                vector<int> tp = {arr2[i][t].first,arr2[i][t].second,i,t};
                pq.push_back(tp);
            }
        }
    }
    if(pq.empty()){
        return;
    }
    sort(pq.begin(),pq.end(),cmp);
    int dir = arr2[sty][stx].second;
    for(int i=0;i<pq.size();i++){ // 변경
        vector<int> tem=pq[i];
        int firstcir = tem[1];
        int count = 0;
        bool flag = false;
        while((py[tem[1]] + tem[2] >= 4) || (px[tem[1]] + tem[3] >= 4) || (py[tem[1]] + tem[2] < 0) || (px[tem[1]] + tem[3] < 0) || 
            ((py[tem[1]] + tem[2] == sty) && (px[tem[1]] + tem[3] == stx))){
            if(count >= 8){
                flag = true;
                break;
            }
            tem[1] = (tem[1]+1)%8;
            count++;
        }
        if(flag){
            continue;
        }
        int temp = arr2[tem[2]][tem[3]].first;
        int chy = tem[2] + py[tem[1]];
        int chx = tem[3] + px[tem[1]];
        int cury = tem[2];
        int curx = tem[3]; 
        int temp2 = arr2[chy][chx].first;
        // arr2 고치기
        if(arr2[chy][chx].first == 0){
            arr2[chy][chx].first = arr2[cury][curx].first;
            arr2[chy][chx].second = tem[1];
            arr2[cury][curx].first = 0;
            arr2[cury][curx].second = 0;
        }
        else{
            arr2[cury][curx].first = arr2[chy][chx].first; 
            arr2[chy][chx].first = temp;
            arr2[cury][curx].second =arr2[chy][chx].second;
            arr2[chy][chx].second = tem[1];
        }
        // vec2 고치기
        tem.clear();
        for(int p=i;p<pq.size();p++){ // pq[p] = 이게 몇번째 인지 
            if(pq[p][0] == temp2){
                pq[p][2] = cury;
                pq[p][3] = curx;
            }
        }
    }
    while(1){
        int ny = sty + py[dir];
        int nx = stx + px[dir];
        if(ny >= 0 && ny < 4 && nx < 4 && nx >= 0){
            if(arr2[ny][nx].first == 0){
                sty+=py[dir];
                stx+=px[dir];
                continue;
            }
            else{
                dfs(ny,nx,cnt+arr2[ny][nx].first,arr2,st+1);
                sty+=py[dir];
                stx+=px[dir];
            }
        }
        else{
            return;
        }
    }
}
int main(){
    vector<vector<pair<int,int>>> vec(4,vector<pair<int,int>>(4,{0,0}));
    for(int i=0;i<4;i++){
        for(int t=0;t<8;t++){
            scanf("%d",&arr[i][t]);
        }
        for(int t=0;t<4;t++){
            vec[i][t].first = arr[i][t*2];
            vec[i][t].second = arr[i][t*2+1]-1;
            mx2+=arr[i][t*2];
        }
    }
    visited[0][0] = true;
    dfs(0,0,arr[0][0],vec,0);
    printf("%d",mx);
}
// 공백 찾는거에서 blank 최대는 mx 최대 일때는 다시 초기화해야댐. 
#include <iostream>
#include <vector>
using namespace std;
int n,len;
int py[4] = {1,-1,0,0};
int px[4] = {0,0,1,-1};
int arr[21][21]={0,};
int vec[401][5]={0,};
void dfs(int start){
    if(start == len){
        return;
    }
    vector<pair<pair<int,int>,int>> cand2;
    vector<pair<int,int>> cand3;
    vector<int> order; // 좋아하는 친구의 수
    vector<int> blank;
    int mx = 0;
    int fav_cnt = 1;
    int blmax = 0;
    int cnt2 = 0;
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            int bl = 0;
            int cnt = 0;
            if(arr[i][t]==0){
                for(int p=0;p<4;p++){
                    int ny = i + py[p];
                    int nx = t + px[p];
                    if(ny >= 0 && nx >= 0 && nx < n && ny < n){
                        if(arr[ny][nx] == 0){ // for 2번
                            bl += 1;
                        }
                        for(int q=1;q<=4;q++){ // vec에 포함되는 갯수셈.
                            if(arr[ny][nx] == vec[start][q]){
                                cnt+=1;
                                break;
                            }
                        }
                    }
                }
            }
            else{
                continue;
            }
            blank.push_back(bl);
            if(mx < cnt){
                blmax = bl;
                fav_cnt = 1;
                mx = cnt;
                cand2.clear();
                cand2.push_back({{i,t},cnt2});
            }
            else if(mx == cnt){
                if(blmax < bl){
                    blmax = bl;
                }
                fav_cnt+=1;
                cand2.push_back({{i,t},cnt2});
            }
            cnt2+=1;
        }
    }
    if(fav_cnt > 1){
        for(int i=0;i<cand2.size();i++){
            int idx =cand2[i].second;
            if(blank[idx] == blmax){
                cand3.push_back({cand2[i].first.first,cand2[i].first.second});
            }
        }
    }
    else{ 
        arr[cand2[0].first.first][cand2[0].first.second] = vec[start][0];
        dfs(start+1);
        return;
    }
    arr[cand3[0].first][cand3[0].second] = vec[start][0];
    dfs(start+1);
    return;
}
int main(){
    scanf("%d",&n);
    len = n*n;
    vector<vector<int>> vec2(len,vector<int>(5,0));
    vector<vector<int>> comp(len+1,vector<int>(4,0));
    for(int i=0;i<len;i++){
        scanf("%d %d %d %d %d",&vec[i][0],&vec[i][1],&vec[i][2],&vec[i][3],&vec[i][4]);
        comp[vec[i][0]][0] = vec[i][1];
        comp[vec[i][0]][1] = vec[i][2];
        comp[vec[i][0]][2] = vec[i][3];
        comp[vec[i][0]][3] = vec[i][4];
    }
    dfs(0);
    vector<int> res(5,0);
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            int temp = 0;
            for(int p=0;p<4;p++){
                int ny = i+py[p];
                int nx = t+px[p];
                if(ny >= 0 && ny < n && nx >= 0 && nx < n){
                    for(int q=0;q<4;q++){
                        if(arr[ny][nx] == comp[arr[i][t]][q]){
                            temp+=1;
                            break;
                        }
                    }
                }
            }
            res[temp] += 1;
        }
    }
    int sta = 0;
    int sum = 0;
    for(int i=0;i<res.size();i++){
        sum+=(res[i] * sta);
        if(sta == 0){
            sta = 1;
        }
        else{
            sta *= 10;
        }
    }
    printf("%d",sum);
}
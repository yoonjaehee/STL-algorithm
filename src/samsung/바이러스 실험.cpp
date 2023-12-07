#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,k,temp,age,y,x,temy,temx,cp;
vector<int> vec3;
vector<pair<pair<int,int>,int>> vec; // 바이러스
vector<pair<pair<int,int>,int>> vec2; // 죽은 바이러스
vector<pair<pair<int,int>,int>> vec4; // 다음바이러스
int arr[11][11]; // 양분
int arr2[11][11];
int py[8] = {1,1,1,0,0,-1,-1,-1};
int px[8] = {0,-1,1,1,-1,0,1,-1};
void dfs(int cnt){
    sort(vec.begin(),vec.end());
    if(cnt == 0){
        return;
    }
    cp = 0;
    for(int i=0;i<vec.size();i++){
        temy = vec[i].first.first;
        temx = vec[i].first.second;
        if(arr[temy][temx] >= vec[i].second){ // 양분 섭취
            arr[temy][temx]-=(vec[i].second);
            vec[i].second=vec[i].second+1;
        }
        else{
            vec2.push_back({{temy,temx},vec[i].second});
            continue;
        }
        vec4.push_back({{temy,temx},vec[i].second});
    }
    
    for(int i=0;i<vec2.size();i++){ // 죽은거 양분변화
        temy = vec2[i].first.first;
        temx = vec2[i].first.second;
        arr[temy][temx] += ((vec2[i].second)/2);
    }
    vec.clear();
    for(int i=0;i<vec4.size();i++){
        vec.push_back(vec4[i]);
    }
    for(int i=0;i<vec.size();i++){ // 번식
        if(vec[i].second % 5 == 0 && vec[i].second > 0){
            for(int t=0;t<8;t++){
                temy = vec[i].first.first + py[t];
                temx = vec[i].first.second + px[t];
                if(temy < n && temx < n && temy >= 0 && temx >= 0){
                    vec.push_back({{temy,temx},1});
                }
            }
        }
    }
    for(int i=0;i<n;i++){ // 양분 추가
        for(int t=0;t<n;t++){
            arr[i][t]+=(arr2[i][t]);
        }
    }
    
    vec2.clear();   
    vec3.clear();
    vec4.clear();
    dfs(cnt-1);
}
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&temp);
            arr2[i][t]=temp;
            arr[i][t] = 5;
        }
    }
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&y,&x,&age);
        vec.push_back({{y-1,x-1},age});
    }
    dfs(k);
    printf("%d",vec.size());
}
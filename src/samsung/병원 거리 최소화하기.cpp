#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;
int n,m;
int arr[51][51];
vector<pair<int,int>> vec; // 병원
vector<pair<int,int>> vec2; // 병원 고른것들
vector<pair<int,int>> vec3; // 사람
bool visited[14];
priority_queue<int,vector<int>,greater<int>> pq;
void dfs(int len,int cnt,int cpp){
    if(len == m){
        int sum = 0;
        for(int i=0;i<vec3.size();i++){
            int cmp = INT_MAX;
            for(int t=0;t<vec2.size();t++){
                int calc = abs(vec3[i].first - vec2[t].first) + abs(vec3[i].second - vec2[t].second);
                if(cmp > calc){
                    cmp = calc;
                }
            }
            sum += (cmp);
        }
        pq.push(sum);
        return;
    }
    for(int i=cnt;i<vec.size();i++){
        if(len >= 1){
            if(vec[i].first < vec2.back().first){
                continue;
            }
            else if(vec[i].first == vec2.back().first){
                if(vec[i].second < vec2.back().second){
                    continue;
                }
            }
        }
        if(!visited[i]){
            visited[i] = true;
            vec2.push_back({vec[i].first,vec[i].second});
            dfs(len+1,cnt+1,cpp);
            vec2.pop_back();
            visited[i] = false;
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&arr[i][t]);
            if(arr[i][t] == 2){
                vec.push_back({i,t});
            }
            else if(arr[i][t] == 1){
                vec3.push_back({i,t});
            }
        }
    }
    int a = 1;
    int b = 1;
    for(int i=0;i<m;i++){
        a*=(vec.size() - i);
        b*=(i+1);
    }
    dfs(0,0,a/b);
    printf("%d",pq.top());
}
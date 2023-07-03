#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
queue<pair<int,int>> q;
vector<int> ans;
vector<vector<pair<int,int>>>vec;
int main(){
    int n,m;
    int start,end,dis;
    scanf("%d %d",&n,&m);
    vector<vector<pair<int,int>>>vec(n+1);
    for(int i=0;i<m;i++){
        scanf("%d %d %d",start,end,dis);
        vec[start].push_back({end,dis});
    }
    q.push({1,0});
    while(!q.empty()){
        int temp = q.front().first;
        int temp2 = q.front().second;
        q.pop();
        for(int i=0;i<vec[temp].size();i++){
            if(vec[temp][i].first == n){
                ans.push_back(temp2 + vec[temp][i].second);
            }
            else{
                q.push({vec[temp][i].first,temp2 + vec[temp][i].second});
            }
        }
    }
    sort(ans.begin(),ans.end());
    int tp=ans[0];
    for(int i=tp;i>0;i++){
        for(int t=2;t<=sqrt(i);t++){
            if(i%tp == 0){
                break;
            }
            if(t == sqrt(i)){
                printf("%d",i);
                return 0;
            }
        }
    }
}
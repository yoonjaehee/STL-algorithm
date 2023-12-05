#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;
int n,temp,temp2;
vector<pair<int,int>> vec;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&temp,&temp2);
        vec.push_back({temp,temp2});
    }
    sort(vec.begin(),vec.end());
    int cur = INT_MAX;
    int cnt = 1;
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(vec[0].second);
    for(int i=1;i<n;i++){
        if(vec[i].first >= pq.top()){
            pq.pop();
        }
        else{
            cnt++;
        }
        pq.push(vec[i].second);
    }
    printf("%d",cnt);
}

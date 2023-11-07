#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n,bag;
vector<int> vec;
vector<pair<int,int>> vec2;
priority_queue<pair<int,int>> pq;
int main(){
    scanf("%d %d",&n,&bag);
    for(int i=0;i<n;i++){
        int we,val;
        scanf("%d %d",&we,&val);
        pq.push({val,we});
    }
    long long sum = 0;
    for(int i=0;i<bag;i++){
        int temp;
        scanf("%d",&temp);
        vec.push_back(temp);
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<bag;i++){
        vec2.clear();
        while(pq.top().second > vec[i]){
            pair<int,int> tem=pq.top();
            vec2.push_back(tem);
            pq.pop();
        }
        sum+=(pq.top().first);
        pq.pop();
        for(int t=0;t<vec2.size();t++){
            pq.push({vec2[t].first,vec2[t].second});
        }
    }
    printf("%d",sum);
}
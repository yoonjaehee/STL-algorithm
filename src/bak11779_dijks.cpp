#include <iostream>
#include <climits>
#include <queue>
using namespace std;
int n,m,start,end,cost,city;
priority_queue<pair<int,int>> pq;
vector<pair<int,int>> arr[1001];
vector<int> visit;
int dist[1001];
void dijks(int st, int ed){
    dist[st] = 0;
    pq.push({0,st});
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;

    }
}
int main(){
    int st,ed,ti;
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1;i<=n;i++){
        dist[i]=INT_MAX;
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&st,&ed,&ti);
        arr[st].push_back({ed,ti});
    }
    scanf("%d %d",&start,&end);
    dijks(start,end);
    printf("%d\n%d",cost,city);
    for(int i=0;i<visit.size();i++){
        printf("%d ",visit[i]);
    }
}
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
priority_queue<pair<int,int>> pq;
int n,m;
vector<pair<int,int>> graph[1001];
int dist[1001];
void dijks(int start){
    dist[start]=0;
    pq.push({0,start});
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < cost){
            continue;
        }
        for(int i=0;i<graph[here].size();i++){
            int next = graph[here][i].first;
            int next_cost = graph[here][i].second;
            if(dist[next] > cost + next_cost){
                dist[next] = cost + next_cost;
                pq.push({-dist[next],next});
            }
        }
    }
}
int main(){
    int s,e,t,sta,des;
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&s,&e,&t);
        graph[s].push_back({e,t});
    }
    for(int i=0;i<=n;i++){
        dist[i] = INT_MAX;
    }
    scanf("%d %d",&sta,&des);
    dijks(sta);
    printf("%d",dist[des]);
}
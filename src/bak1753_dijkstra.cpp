#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
priority_queue<pair<int,int>> pq;
vector<pair<int,int>> graph[20001];
int dist[20001];
void dijkstra(int st){
    dist[st]=0;
    pq.push({0,st});
    while(!pq.empty()){ // 내가 파악하기에 -를 붙이는 이유가 
    //사실 다음까지의 거리만 두고 봤을때 계산하기 쉬우라고 한듯.
    //cost + next_cost 해석 편하라고...
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for(int i=0;i<graph[cur].size();i++){
            int next = graph[cur][i].first;
            int next_cost = graph[cur][i].second;
            if(dist[next]> cost + next_cost){
                dist[next] = cost + next_cost;
                pq.push({-dist[next],next});
            }
        }
    }
}
int main(){
    int v,e,start,u,ver,w;
    scanf("%d %d",&v,&e);
    scanf("%d",&start);
    for(int i=0;i<e;i++){
        scanf("%d %d %d",&u,&ver,&w);
        graph[u].push_back({ver,w});
    }
    for(int i=1;i<=v;i++){
        dist[i]=INT_MAX;
    }
    dijkstra(start);   
    for(int i=1;i<=v;i++){
        if(dist[i]==INT_MAX){
            printf("INF\n");
            continue;
        }
        printf("%d\n",dist[i]);
    }
}
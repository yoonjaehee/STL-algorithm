#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
int n,e,start,mu_st,mu_ed,;
int dist[801];
priority_queue<pair<int,int>> pq;
vector<pair<int,int>> graph[801];
void dijks(int start){
    int dist[start]=0;
    pq.push({0,start});
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second; 
        pq.pop();
        for(int i=0;i<graph[cur].size();i++)
        { // end로부터 시작하는 모든 도착지들
            int next = graph[cur][i].first;
            int next_cost = graph[cur][i].second;
            if(cost + next_cost < dist[next]) {
                // 다음 것의 거리가 지금까지의 코스트보다 높을 때
                dist[next] = cost + next_cost;
                pq.push({-dist[next],next});
            }
        }
    }
}
int main(){
    int a,b,c;
    scanf("%d %d",&n,&e);
    for(int i=0;i<e;i++){
        scanf("%d %d %d",&a,&b,&c);
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    scanf("%d %d",&mu_st,&mu_ed);
    for(int i=1;i<=n;i++){
        dist[i]=INT_MAX;
    }
    dijks(1);

    
}
//1->A->B->N
//1->B->A->N 이렇게 두가지 방법이 있음.
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int n,e,start,mu_st,mu_ed;
int dist[801];
priority_queue<pair<int,int>> pq;
vector<pair<int,int>> graph[801];
void dijks(int start){
    dist[start]=0;
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
    bool config1=true;
    bool config2 = true;
    int a,b,c,dis_a,dis_b,res;
    scanf("%d %d",&n,&e);
    for(int i=0;i<e;i++){
        scanf("%d %d %d",&a,&b,&c);
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    scanf("%d %d",&mu_st,&mu_ed);
    // 1로부터의 모든 거리 측정
    for(int i=1;i<=n;i++){
        dist[i]=INT_MAX;
    }
    dijks(1);
    dis_a=dist[mu_st]; // 1부터 a까지
    dis_b=dist[mu_ed]; // 1부터 b까지
    if(dis_a == INT_MAX){
        config1 = false;
    }
    if(dis_b == INT_MAX){
        config2 = false;
    }
    for(int i=1;i<=n;i++){
        dist[i]=INT_MAX;
    }
    dijks(mu_st);
    // 필수a에서 필수 b사이의 거리를 각각 더해줌
    if(config1 == true){
        dis_a+=dist[mu_ed];
    }
    if(config2 == true){
        dis_b+=dist[mu_ed];
    }
    //1 다음에 b를 방문할 경우 
    for(int i=1;i<=n;i++){
        dist[i]=INT_MAX;
    }
    dijks(mu_ed);
    if(config1 == true){
        dis_a+=dist[n]; 
    }
    //1 다음에 a를 방문할 경우
    for(int i=1;i<=n;i++){
        dist[i]=INT_MAX;
    }
    dijks(mu_st);
    if(config2 == true){
        dis_b += dist[n];
    }
    if((config1 == false) && (config2 == false)){
        res = -1;
    }
    else{
        res = min(dis_a,dis_b);
    }
    if(res == INT_MAX){
        res = -1;
    }
    printf("%d",res);
}
#include <iostream>
#include <climits>
#include <queue>
using namespace std;
int n,m,tocost,count;
priority_queue<pair<int,int>> pq;
vector<pair<int,int>> arr[1001];
vector<int> visit;
int route[1001];
int dist[1001];
void dijks(int st, int ed){
    dist[st] = 0;
    pq.push({0,st});
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        for(int i=0;i<arr[here].size();i++){
            int next = arr[here][i].first;
            int next_cost = arr[here][i].second;
            if(dist[next] > cost + next_cost){
                route[next] = here;
                dist[next] = cost + next_cost;
                pq.push({-dist[next],next});
            }
        }
    } 
}
int main(){
    int sta,des,ti,start,end;
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1;i<=n;i++){
        dist[i]=INT_MAX;
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&sta,&des,&ti);
        arr[sta].push_back({des,ti});
    }
    scanf("%d %d",&start,&end);
    dijks(start,end);
    int some = end;
    while(some){
        visit.push_back(some);
        some = route[some];       
    }
    printf("%d\n%d\n",dist[end],visit.size());
    for(int i=visit.size()-1;i>=0;i--){
        printf("%d ",visit[i]);
    }
}
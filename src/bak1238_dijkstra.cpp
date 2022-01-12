#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;
int n,m,x; // n=start point,m=end point,x=time
vector<pair<int,int>> vec[1001];
int dis[1001],res[1001];
void dijkstra(int star){
    priority_queue<pair<int,int>> pq;
    dis[star]=0;
    pq.push({0,star});
    while(!pq.empty()){
        int len=-pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        for(int i=0;i<vec[cur].size();i++){
            int next=vec[cur][i].first;
            int next_len = vec[cur][i].second;
            if(dis[next] > len+next_len){
                dis[next] = len+next_len;
                pq.push({-dis[next],next});
            }
        } 
    }
}
void sol(){
    for(int i=1;i<=n;i++){
        for(int t=1;t<=n;t++){
            dis[t]=INT_MAX;
        }
        dijkstra(i);
        res[i] = dis[x];
    }
    for(int i=1;i<=n;i++){
        dis[i]=INT_MAX;
    }
    dijkstra(x);
    for(int i=1;i<=n;i++){
        res[i]+=dis[i];
    }
    sort(res+1,res+n+1);
    printf("%d",res[n]);
}
int main(){
    int start,end,time;
    scanf("%d %d %d",&n,&m,&x);
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&start,&end,&time);
        vec[start].push_back({end,time});
    }
    sol();
}
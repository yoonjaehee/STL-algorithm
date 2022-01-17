#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
#define max INT_MAX
priority_queue<pair<int,int>> pq;
vector<pair<int,int>> graph[501];
vector<pair<int,int>> dimi[201];
vector<int> dist;
int n,m,w,tc;
bool cycle;
void bellman(){
    for(int i=1;i<=n;i++){
        cycle = false;
        for(int t=1;t<=n;t++){
            for(int p=0;p<size;p++){
                int there = graph[t].first; 
                int cost = graph[t].second;
                if(dist[t] + cost <dist[there]){
                    dist[t]
                }
            }
        }
    }
    if(!cycle){
        break;
    }
}
int main(){
    scanf("%d",&tc);
    for(int i=0;i<tc;i++){
        int s,e,t;
        scanf("%d %d %d",&n,&m,&w);
        for(int p=0;p<m;p++){
            scanf("%d %d %d",&s,&e,&t);
            graph[s].push_back({e,t});
            graph[e].push_back({s,t});
        }
        for(int q=0;q<w;q++){
            scanf("%d %d %d",&s,&e,&t);
            dimi[s].push_back({e,t});
        }
    }
    bellman();
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
queue<int> q;
vector<int> v[50001];
int dist[20001];
int len;
int bfs(int start){
    q.push(start);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<v[cur].size();i++){
            if(dist[v[cur][i]]==0 && v[cur][i]!=1){
                //dist[v[cur]] = 목적지 까지의 길이가 0
                dist[v[cur][i]] = dist[cur] + 1;
                q.push(v[cur][i]);
                len = max(len, dist[v[cur][i]]);
            }
        }
    }
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(int i=0;i<edge.size();i++){
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    bfs(1);
    for(int i=1;i<=n;i++){
        if(len == dist[i]){
            answer++;
        }
    }
    return answer;
}
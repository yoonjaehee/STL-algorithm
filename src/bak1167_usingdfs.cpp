//어떤 지점(루트가 편할듯)에서 기준점을 잡고, 가장 먼 정점을 찾는다.
// 그 가장 먼 정점에서 가장 먼 정점을 찾으면 그게 가장 긴 지름의 길이가 나온다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<pair<int,int>> vec[100001];
bool visited[100001];
vector<int> cou;
int v,num,temp,temp2;
int max1=0;
int length=0;
int farfrom=0;
void dfs(int node,int cost){
    if(visited[node]){
        return;
    }
    visited[node]=true;
    if(length<cost){
        length = cost;
        farfrom = node;
    }
    for(int i=0;i<vec[node].size();i++){
        dfs(vec[node][i].first,vec[node][i].second+cost);
    }
}
int main(){
    scanf("%d",&v);
    for(int i=0;i<v;i++){
        scanf("%d", &num);
        if(max1<num){
            max1=num;
        }
        while(1){
            scanf("%d", &temp);
            if(temp == -1){
                break;
            }
            scanf("%d", &temp2);
            vec[num].push_back({temp,temp2});
        }
    }   
    memset(visited,false,sizeof(visited));
    dfs(1,0);
    memset(visited,false,sizeof(visited));
    length=0;
    dfs(farfrom,0);
    printf("%d",length);
}
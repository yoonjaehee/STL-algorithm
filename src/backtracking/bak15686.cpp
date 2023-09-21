#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;
int arr[51][51];
int n,m,cnt;
vector<pair<int,int>> chi,house;
priority_queue<int,vector<int>,greater<int>> pq;
vector<pair<int,int>> cur_chi;
bool visited[51];
int calc(){
    int sum = 0;
    for(int i=0;i<house.size();i++){
        int tempy = house[i].first;
        int tempx = house[i].second;
        int comp = INT_MAX;
        for(int t=0;t<cur_chi.size();t++){
            int py=cur_chi[t].first;
            int px=cur_chi[t].second;
            int tem = abs(tempy-py) + abs(tempx - px);
            comp = min(comp,tem);
        }
        sum+=comp;
    }
    return sum;
}
void solving(int idx, int count){
    if(count == m){
        pq.push(calc());
        return;
    }
    for(int i=idx;i<chi.size();i++){
        if(!visited[i]){
            cur_chi.push_back({chi[i].first,chi[i].second});
            visited[i] = true;
            solving(i,count+1);
            cur_chi.pop_back();
            visited[i] = false;
        }
    }
}
int main(){
    int temp;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&temp);
            arr[i][t] = temp;
            if(temp == 1){
                house.push_back({i,t});
            }
            else if(temp == 2){
                chi.push_back({i,t});
            }
        }
    }
    solving(0,0);
    printf("%d",pq.top());
}
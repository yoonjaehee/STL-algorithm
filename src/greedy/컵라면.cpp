#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,greater<int>> pq;
bool comp(pair<int,int> &a, pair<int,int> &b){
    if(a.first > b.first){
        return false;
    }
}
int main(){
    int n;
    vector<pair<int,int>> vec;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int st, plu;
        scanf("%d %d",&st,&plu);
        vec.push_back({st,plu});
    }
    sort(vec.begin(),vec.end(),comp);
    int tim = 0;
    int sum = 0;
    for(int i=0;i<n;i++){
        if(pq.size() < vec[i].first){
            pq.push(vec[i].second);
        }
        else{
            if(pq.top() < vec[i].second){
                pq.pop();
                pq.push(vec[i].second);
            }
        }
    }
    while(!pq.empty()){
        sum+=pq.top();
        pq.pop();
    }
    printf("%d",sum);
}
#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<pair<int,int>> pq;
    pq.push({1,3});
    pq.push({3,5});
    pq.push({2,11});
    pq.push({11,7});
    pq.push({7,2});
    int elec = -pq.top().first;
    printf("%d",elec);
}
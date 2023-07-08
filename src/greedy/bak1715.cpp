#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int n,temp,data,data2,sum;
    scanf("%d",&n);
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        pq.push(temp);
    }
    while(pq.size() != 1){
        data = pq.top();
        pq.pop();
        data2=pq.top();
        pq.pop();
        sum += data + data2;
        pq.push(data+data2);
    }
    printf("%d",sum);
}
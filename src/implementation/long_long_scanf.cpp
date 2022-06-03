#include <iostream>
#include <queue>
using namespace std;
int main() {
    priority_queue<long long> pq;
    int n, m;
    long long num, answer = 0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%lld",&num);
        pq.push(-num);
    }
    for(int i=0;i<m;i++) {
        long long first = -pq.top();
        pq.pop();
        long long second = -pq.top();
        pq.pop();
        long long sum = first + second;
        pq.push(-sum);
        pq.push(-sum);
    }
    while(!pq.empty()) {
        answer += (-pq.top());
        pq.pop();
    }
    printf("%lld",answer);
    return 0;
}
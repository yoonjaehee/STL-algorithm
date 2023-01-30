#include <iostream>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,greater<int>> minHeap;
priority_queue<int> maxHeap;
int main(){
    int n,temp,ch1,ch2;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        // 집합크기 맞추기 
        if(maxHeap.size()>=minHeap.size()){
            maxHeap.push(temp);
        }
        else{
            minHeap.push(temp);
        }
        // 두번째 부터
        if(maxHeap.size()!=0 && minHeap.size()!=0){
            if(maxHeap.top() > minHeap.top()){
                ch1 = maxHeap.top();
                ch2 = minHeap.top();
                maxHeap.pop();
                minHeap.pop();
                maxHeap.push(ch2);
                minHeap.push(ch1);
            }
        }
        printf("%d\n",maxHeap.top());
    }
}

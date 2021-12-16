#include <iostream>
#include <queue>
using namespace std;
int main(){
    int count,temp;
    priority_queue<int> pq;
    scanf("%d", &count);
    for(int i=0;i<count;i++){
        scanf("%d",&temp);
        if(temp==0){
            if(pq.empty()){
                printf("0\n");
            }
            else{
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else{
            pq.push(temp);
        }
    }
}
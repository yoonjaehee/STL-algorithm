#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main(){
    int num,cal,n;
    char d;
    priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> pq;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq2;
    bool visited[1000001];
    scanf("%d", &num);
    for(int i=0;i<num;i++){
        scanf("%d",&cal);
        for(int t=0;t<cal;t++){
            scanf("%c %d",&d,&n);
            if(d=='I'){
                pq.push({n,t});
                pq2.push({n,t});
                visited[t]=true;
            }
            else{
                if(n==1){
                    while(!pq.empty() && !visited[pq.top().second]){
                        pq.pop();
                    }
                    if(!pq.empty()){
                        visited[pq.top().second]=false;
                        pq.pop();
                    }
                }
                else{
                    while(!pq2.empty() && !visited[pq2.top().second]){
                        pq2.pop();
                    }
                    if(!pq2.empty()){
                        visited[pq2.top().second]=false;
                        pq2.pop();
                    }
                }
            }
        }
        while(!pq.empty() && !visited[pq.top().second]){
            pq.pop();
        }
        while(!pq2.empty() && !visited[pq2.top().second]){
            pq2.pop();
        }
        if(pq.empty() && pq2.empty()){
            printf("EMPTY\n");
        }
        else{
            printf("%d %d", pq.top().first, pq2.top().first);
        }
    }
}

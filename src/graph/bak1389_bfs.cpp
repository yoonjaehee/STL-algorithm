#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<int>q;
vector<int> conn[101];
int arr[101][101];
int n,m;
void bfs(int start){
    int temp[101]={0,};
    q.push(start);
    temp[start]=1;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int t=0;t<conn[current].size();t++){
            if(temp[conn[current][t]]==0){
                temp[conn[current][t]]=1;
                arr[conn[current][t]][start] = arr[current][start] +1;
                arr[start][conn[current][t]] = arr[start][current] + 1;
                q.push(conn[current][t]);
            }
        }
    }  
}  
int main(){
    int sum=0;
    int re=0;
    int min = 99999999;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int temp1, temp2;
        scanf("%d %d",&temp1,&temp2);
        conn[temp1].push_back(temp2);
        conn[temp2].push_back(temp1);
    }
    for(int i=1;i<=n;i++){
        bfs(i);
    }
    for(int i=1;i<=n;i++){
        sum=0;
        for(int t=1;t<=n;t++){
            sum+=arr[i][t];
        }
        if(min>sum){
            min = sum;
            re=i;
        }
    }
    printf("%d\n",re);
}
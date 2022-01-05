#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> adj;
int n;
int count[2]={0,};
void partition(int size,int x,int y){
    bool isAll=true;
    int cur = adj[y][x];
    for(int i=y;i<y+size;i++){
        for(int t=x;t<x+size;t++){
            if(adj[i][t] != cur){
               isAll=false;
               break; 
            }
        }
    }
    if(isAll){
        count[cur]++;
        return;
    }
    partition(size/2,x,y);
    partition(size/2,x,y+size/2);
    partition(size/2,x+size/2,y);
    partition(size/2,x+size/2,y+size/2);
}
int main(){
    scanf("%d",&n);
    adj = vector<vector<int>>(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&adj[i][t]);
        }
    }
    partition(n,0,0);
    for(int i=0;i<2;i++){
        printf("%d\n",count[i]);
    }
}
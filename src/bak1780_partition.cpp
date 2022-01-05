#include <iostream>
#include <vector>
using namespace std;
int arr[3001][3001]={0,};
int count[3]={0,};
void partition(int size,int x,int y){
    bool all=true;
    int cur = arr[y][x];
    for(int i=y;i<y+size;i++){
        for(int t=x;t<x+size;t++){
            if(cur != arr[i][t]){
                all=false;
                break;        
            }
        }
    }
    if(all){
        count[arr[y][x]+1]++;
        return;
    }
    for(int i=y;i<y+size;i+=size/3){
        for(int t=x;t<x+size;t+=size/3){
            partition(size/3,t,i);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&arr[i][t]);
        }
    }
    partition(n,0,0);
    for(int i=0;i<3;i++){
        printf("%d\n",count[i]);
    }
}
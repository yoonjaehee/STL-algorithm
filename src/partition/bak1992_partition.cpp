#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
int arr[64][64];

void partition(int x,int y,int size){
    int cur = arr[y][x];
    for(int i=y;i<y+size;i++){
        for(int t=x;t<x+size;t++){
            if(arr[i][t]!=cur){
                printf("(");
                partition(x,y,size/2); //2
                partition(x+size/2,y,size/2); //1
                partition(x,y+size/2,size/2); //3
                partition(x+size/2,y+size/2,size/2); //4
                printf(")");
                return;
            }
        }
    }
    printf("%d",cur);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%1d",&arr[i][t]);
        }
    }
    partition(0,0,n);
}
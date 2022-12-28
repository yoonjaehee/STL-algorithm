#include <iostream>
#include <cstring>
using namespace std;
int arr[51][51];
int dfs(int starty,int startx,int dir){
    arr[starty][startx]=2;
    //종료조건
    if(){

    } 
    else{
        //서쪽
        if(){

        } 
        //동쪽
        else if(){

        }
    }
}
int main(){
    int n,m,r,c,d,temp;
    scanf("%d %d",&n,&m);
    int arr[51][51];
    for(int i=0;i<n;i++){
        memset(arr,0,sizeof(int)*m);
    }
    scanf("%d %d %d",&r,&c,&d);
    for(int i=0;i<n;i++){
        for(int t=0;t<m;t++){
            scanf("%d",&temp);
            arr[i][t] = temp;
        }
    }
    dfs(r,c,d);
}
#include <iostream>
#include <queue>
using namespace std;
int n;
int arr[17][17];
int count=0;
queue<pair<pair<int,int>,int>> q;
void bfs(){
    q.push({{1,0},1}); // 파이프 가로 = 1, 파이프 세로 =2 , 파이프 대각선 = 3
    while(!q.empty()){
        pair<pair<int,int>,int> pip = q.front();
        int x=pip.first.first;
        int y=pip.first.second; 
        q.pop();
        if(x == n-1 && y == n-1){
            count++;
            continue;
        }
        if(pip.second == 1){
            if(arr[y][x+1]!=1 && x+1<n && y<n){
                q.push({{x+1,y},1});
            }
            if(arr[y+1][x+1]!=1 && arr[y+1][x]!=1 && arr[y][x+1]!=1 && x+1<n && y+1<n){
                q.push({{x+1,y+1},3});
            }
        }
        else if(pip.second == 2){
            if(arr[y+1][x]!=1 && x<n && y+1<n){
                q.push({{x,y+1},2});
            }
            if(arr[y+1][x+1]!=1 && arr[y+1][x]!=1 && arr[y][x+1]!=1 && x+1<n && y+1<n){
                q.push({{x+1,y+1},3});
            }
        }
        else if(pip.second == 3){
            if(arr[y][x+1]!=1 && x+1<n && y<n){
                q.push({{x+1,y},1});
            }
            if(arr[y+1][x]!=1 && x<n && y+1<n){
                q.push({{x,y+1},2});
            }
            if(arr[y+1][x+1]!=1 && arr[y+1][x]!=1 && arr[y][x+1]!=1 && x+1<n && y+1<n){
                q.push({{x+1,y+1},3});
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d", &arr[i][t]);
        }
    }
    bfs();
    printf("%d",count);
}
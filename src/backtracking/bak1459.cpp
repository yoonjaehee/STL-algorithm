#include <iostream>
#include <set>
using namespace std;
int w,s;
multiset<int> mul;
void dfs(int endx,int endy,pair<int,int> start,int total){
    if(start.first > endx || start.second > endy){
        return;
    }
    if((endy == start.second) && (endx == start.first)){
        mul.insert(total);
    }
    dfs(endx,endy,{start.first+1,start.second+1},total+s);
    dfs(endx,endy,{start.first+1,start.second},total+w);
    dfs(endx,endy,{start.first,start.second+1},total+w);
}
int main(){
    int posx,posy;
    scanf("%d %d %d %d",&posx,&posy,&w,&s);
    dfs(posx,posy,{0,0},0);
    printf("%d",*(mul.begin()));
}
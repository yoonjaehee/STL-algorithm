#include <iostream>
#include <vector>
using namespace std;
int n,ed;
int answer = 0;
bool visited[21];
vector<int> vec;
void dfs(int start,int count){
    if(count == n){
        return;
    }
    if(start +vec[count] == ed){
        answer++;
        return;
    }
    dfs(start,count+1);
    dfs(start+vec[count],count+1);
}
int main(){
    int temp;
    scanf("%d %d",&n,&ed);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        vec.push_back(temp);
    }
    dfs(0,0);
    printf("%d",answer);
}
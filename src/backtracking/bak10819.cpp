#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec;
int n;
int answer = 0;
vector<int> arr;
bool visited[21];
void dfs(int count){
    if(count == n){
        int res = 0;
        for(int i=0;i<n-1;i++){
            res+=abs(arr[i+1]-arr[i]);
        }
        answer = max(answer,res);
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i]= true;
            arr[count] = vec[i];
            dfs(count+1);
            visited[i] = false;
        }
    }
}
int main(){
    int temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        vec.push_back(temp);
    }
    arr.resize(n+1,0);
    dfs(0);
    printf("%d",answer);
}
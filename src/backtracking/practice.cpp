#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int n;
int answer = 0;
vector<int> vec;
int arr[3]={0,};
bool visited[5];
void dfs(vector<int> res,int cur, int cnt,int idx){
    if(cnt == 3){
        for(int i=0;i<3;i++){
            printf("[%d] ",arr[i]);
        }
        printf("sum : %d\n", cur);
        return;
    }
    for(int i=idx;i<vec.size();i++){
        if(!visited[i]){
            visited[i] = true;
            arr[cnt] = vec[i];
            dfs(res,cur+vec[i],cnt+1,i+1);
            visited[i] = false;
        }
    }
}
int main(){
    scanf("%d",&n);
    int temp;
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        vec.push_back(temp);
    }
    dfs(vec,0,0,0);
}
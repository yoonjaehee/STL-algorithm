#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int n,k;
vector<int> vec;
bool visited[101];
long long res= 0;
void dfs(int start,long long cnt){
    if(start >= k){
        res = cnt;
        return;
    }
    // 1. 무빙워크가 한 칸 회전
    int st = vec[2*n-1];
    for(int i=2*n-1;i>0;i--){
        vec[i] = vec[i-1];
        if(i <= n-1){
            visited[i] = visited[i-1];
        }
    }
    vec[0] = st;
    visited[0] = false;
    if(visited[n-1]){
        visited[n-1] = false;
    }
    // 2. 비어있으면 한칸 이동
    for(int i=n-2;i>=1;i--){
        if(visited[i]){
            if(!visited[i+1] && (vec[i+1] >= 1)){
                visited[i+1] = true;
                vec[i+1]-=1;
                visited[i] = false;
                if(vec[i+1] == 0){
                    start+=1;
                }
            }
        }
    }
    if(visited[n-1]){
        visited[n-1] = false;
    }
    // 3. 1번칸에 사람이 없고 안정성이 0이 아니라면 사람을 한명 더 올림
    if(!visited[0] && vec[0] != 0){
        vec[0]-=1;
        visited[0] = true;
        if(vec[0] == 0){
            start+=1;
        }
    }
    // 4. 안정성이 0인 칸이 k개이상이면 과정 종료
    if(start >= k){
        res = cnt;
        return;
    }
    dfs(start,cnt+1);
}
int main(){
    scanf("%d %d",&n,&k);
    memset(visited,false,sizeof(bool)*(n+1));
    int temp;
    for(int i=0;i<2*n;i++){
        scanf("%d",&temp);
        vec.push_back(temp);
    }
    dfs(0,1);
    printf("%lld",res);
}
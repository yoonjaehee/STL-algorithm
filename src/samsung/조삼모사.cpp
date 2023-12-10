#include <iostream>
#include <vector>
#include <limits.h>
#include <string.h>
#include <map>
using namespace std;
int n;
int arr[21][21];
vector<int> vec;
vector<int> vec2;
int sum = 0;
int sum2= 0;
int sum3 = 0;
int arr2[2];
bool visited[21];
map<string,int> ma;
void dfs2(vector<int> &tmp){
    for(int i=0;i<n/2;i++){
        for(int t=i+1;t<n/2;t++){
            int tmp1 = tmp[i];
            int tmp2 = tmp[t];
            sum3+=(arr[tmp1][tmp2] + arr[tmp2][tmp1]);
        }
    }
}
int cmp = 0;
int mx = INT_MAX;
void dfs(int start,int cnt){
    if(start == (n/2)){
        for(int i=0;i<n;i++){
            if(!visited[i]){
                vec2.push_back(i);
            }
        }
        dfs2(vec);
        sum = sum3;
        sum3 = 0;
        dfs2(vec2);
        sum2 = sum3;
        if(abs(sum2-sum) < mx){
            mx = abs(sum2-sum);
        }
        sum = 0;
        sum2 = 0;
        sum3 = 0;
        cmp++;
        vec2.clear();
        return;
    }
    for(int i=cnt;i<n;i++){
        if(!visited[i]){
            if(start >= 1){
                if(vec[start-1] > i){
                    continue;
                }
            }
            /*if(cmp > (n*n+1)/2){
                return;
            }
            */
            vec.push_back(i);
            visited[i] = true;
            dfs(start+1,cnt+1);
            visited[i] = false;
            vec.pop_back();
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&arr[i][t]);
        }
    }
    dfs(0,0);
    printf("%d",mx);
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int n,temp;
vector<int> vec;
int main(){
    scanf("%d",&n);
    int mx = 0;
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        vec.push_back(temp);
        mx += temp;
    }
    bool visited[mx*2];
    memset(visited,false,sizeof(bool)*(mx+mx));
    sort(vec.begin(),vec.end());
    mx = 0;
    for(int i=0;i<n;i++){
        for(int t=1;t<=mx;t++){
            if(visited[t]){
                visited[t+vec[i]] = true;
            }
        }
        mx += vec[i];
        visited[i] = true;
    }
    for(int i=1;i<=mx;i++){
        if(!visited[i]){
            printf("%d",i);
            break;
        }
    }
    
}
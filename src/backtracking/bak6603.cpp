#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
vector<int> vec;
int n;
bool visited[14];
int arr[14];
void track(int count,int len){
    if(len == 6){
        for(int t=0;t<6;t++){
            printf("%d ",arr[t]);
        }
        printf("\n");
        return;
    }
    for(int p=count;p<n;p++){
        if(!visited[p]){
            arr[len] = vec[p];
            track(p+1,len+1);
        }
    }
}
int main(){
    while(1){
        scanf("%d",&n);
        if(n == 0){
            return 0;
        }
        vec.clear();
        memset(visited,false,sizeof(bool)*n);
        for(int i=0;i<n;i++){
            int temp;
            scanf("%d",&temp);
            vec.push_back(temp);
        }
        track(0,0);
        printf("\n");
    }
}
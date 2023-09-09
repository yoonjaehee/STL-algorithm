#include <iostream>
using namespace std;
int n;
int arr[8];
bool visited[8];
void track(int temp){
    if(temp == n){
        for(int t=0;t<n;t++){
            printf("%d ",arr[t]);
        }
        printf("\n");
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            arr[temp] = i; 
            visited[i] = true;
            track(temp+1);
            visited[i] = false;
        }
    }
}
int main(){
    scanf("%d",&n);
    track(0);
}
#include <iostream>
#include <cstring>
using namespace std;
int arr[5001][5001];
int main(){
    int temp,num;
    scanf("%d",&num);
    int vec[num+1]={0,};
    for(int i=0;i<num+2;i++){
        memset(arr[i],0,sizeof(int)*(num+1));
    }
    for(int i=1;i<=num;i++){
        scanf("%d",&temp);
        vec[i]=temp;
    }
    for(int i=1;i<num+1;i++){
        arr[i][num]=0;
        if(vec[num]<i){
            arr[i][num-1]=1;
        }
        else{
            arr[i][num-1]=0;
        }
        for(int t=num-2;t>0;t--){
            if(vec[t+1]<i){
                arr[i][t] = arr[i][t+1]+1;
            }
            else{
                arr[i][t] = arr[i][t+1];
            }
        }
    }
    int count=0;
    for(int i=1;i<num-1;i++){
        for(int t=i+1;t<num;t++){
            if(vec[i]<vec[t]){
                count += arr[vec[i]][t];
            }
        }
    }
    printf("%d",count);
}
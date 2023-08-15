#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    long n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    long start = 1;
    long end = k;
    long res = 0;
    while(start<=end){
        long mid = (start+end)/2;
        long cnt = 0;
        for(int i=1;i<=n;i++){
            cnt += min(mid/i,n);
        }
        if(cnt<k){
            start = mid+1;
        }
        else{
            res=mid;
            end=mid+1;
        }
    }
    printf("%d",res);
}
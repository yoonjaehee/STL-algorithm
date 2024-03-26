#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
long long n,m,temp;
vector<int> vec;
int main(){
    long long mx = 0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        vec.push_back(temp);
        if(mx < temp){
            mx = temp;
        }
    }
    long long start = 0;
    long long end = mx * m;
    long long answer = INT_MAX;
    while(start <= end){
        long long mid = (start + end)/2;
        long long sum = 0;
        for(int i=0;i<vec.size();i++){
            sum += (mid/vec[i]);
        }
        if(sum >= m){
            if(sum >= m){
                answer = min(answer,mid); 
            }
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    printf("%lld",answer);
}
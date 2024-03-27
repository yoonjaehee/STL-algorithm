#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
unsigned long long n,m,temp;
vector<long long> vec;
int main(){
    unsigned long long mx = 0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin>>temp;
        vec.push_back(temp);
        if(mx < temp){
            mx = temp;
        }
    }
    unsigned long long start = 1;
    unsigned long long end = mx * m;
    unsigned long long answer = 0;
    while(start <= end){
        unsigned long long mid = (start + end)/2;
        unsigned long long sum = 0;
        for(int i=0;i<vec.size();i++){
            sum += (mid/vec[i]);
        }
        if(sum >= m){
            if(answer > mid || answer == 0){
                answer = mid;
            }
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    printf("%lld",answer);
}
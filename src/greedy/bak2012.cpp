#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vec;
int main(){
    int n,temp;
    int total = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        vec.push_back(temp);
    }
    sort(vec.begin(),vec.end());
    for(int i=1;i<=n;i++){
        if((vec[i-1]-i)<0){
            total+=(i-vec[i-1]);
        }
        else{
            total+=(vec[i-1]-i);
        }
    }
    printf("%d",total);
}
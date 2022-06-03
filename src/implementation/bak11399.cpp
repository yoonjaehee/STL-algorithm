#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,time;
vector<int> vec;
int sum=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&time);
        vec.push_back(time);
    }
    sort(vec.begin(),vec.end());
    int si=vec.size();
    for(int i=0;i<si;i++){
        sum+=(si-i)*vec[i];
    }
    printf("%d",sum);
}

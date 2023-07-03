#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,m,sum;
    vector<int> vec;
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        vec.push_back(temp);
    }
    sort(vec.begin(),vec.end());
    int sidx = 0;
    int eidx = n-1;
    int count = 0;
    while(sidx < eidx){
        sum = vec[sidx] + vec[eidx];
        if(sum == m){
            count++;
            sidx++;
            eidx--;
        }
        else if(sum < m){
            sidx++;
        }
        else{
            eidx--;
        }
    }
    printf("%d",count);
}
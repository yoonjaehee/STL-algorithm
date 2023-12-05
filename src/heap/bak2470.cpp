#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int n,temp;
int main(){
    scanf("%d",&n);
    vector<int> vec;
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        vec.push_back(temp);
    }
    sort(vec.begin(),vec.end());
    int stidx = 0; 
    int eidx = n-1;
    int sum=0;
    int comp = INT_MAX;
    int res1,res2;
    while(stidx < eidx){
        sum = vec[stidx] + vec[eidx];
        if(comp > abs(sum)){
            comp = abs(sum);
            res1 = stidx;
            res2 = eidx;
        }
        if(sum == 0){
            break;
        }
        if(sum < 0){
            stidx++;
        }
        else{
            eidx--;
        }
    }
    printf("%d %d",vec[res1],vec[res2]);
}
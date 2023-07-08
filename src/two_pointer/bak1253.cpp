#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,sidx,eidx,sum;
    vector<int> vec;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        vec.push_back(temp);
    }
    int count = 0;
    sort(vec.begin(),vec.end());
    for(int i=0;i<n;i++){
        int find = vec[i];
        sidx = 0;
        eidx = n-1;
        while(sidx < eidx){
            sum=vec[sidx] + vec[eidx];
            if(sum == find){
                if(sidx != i && eidx != i){
                    count++;
                    break;
                }
                else if(sidx == i){
                    sidx++;
                }
                else if(eidx == i){
                    eidx--;
                }
            }
            else if(sum < find){
                sidx++;
            }
            else{
                eidx--;
            }
        }
    }
    printf("%d",count);
}
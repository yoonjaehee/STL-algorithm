#include <iostream>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int st_idx=1,ed_idx=1;
    int sum = 1;
    int cnt = 1;
    while(ed_idx != n){
        if(sum == n){
            cnt++;
            ed_idx++;
            sum+=ed_idx;
        }
        else if(sum > n){
            sum-=st_idx;
            st_idx++;
        }
        else{
            ed_idx++;
            sum+=ed_idx;
        }
    }
    printf("%d",cnt);
}
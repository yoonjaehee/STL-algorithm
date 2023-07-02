#include <iostream>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int count = 1;
    int sum = 1;
    int sidx = 1;
    int eidx = 1;
    while(eidx != n){
        if(sum == n){
            count++;
            eidx++;
            sum+=eidx;
        }
        else if(sum > n){
            sum-=sidx;
            sidx++;
        }
        else{
            eidx++;
            sum+=eidx;
        }
    }
    printf("%d",count);
}
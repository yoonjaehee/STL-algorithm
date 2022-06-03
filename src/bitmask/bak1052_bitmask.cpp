#include <iostream>
#include <vector>
using namespace std;
vector<int> vec;
int main(){
    int n,k;
    int c=24;
    int ans = 0;
    scanf("%d %d",&n,&k);
    while(c>k){
        c=0;
        int temp=n; 
        while(temp>0){
            c+=1;
            temp&=temp-1;
        } // c 는 1의 갯수(즉 n의 1의 갯수를셈)
        if(c>k){
            ans += 1;
            n+=1;
        } // 1씩증가시켜서 해당 1의 갯수가 k값과 동일할때 반환
    }
    printf("%d",ans);
}
#include <iostream>
using namespace std;
int result;
void DP(int total){
    int a,b;
    a = total/5;
    b = total/3;
    if((total-(a*5)) % 3 == 0 ){
        b = (total-(a*5))/3;
        result=a+b;
        return;
    } 
    if((total-(b*3)) % 5 == 0){
        a = (total-(3*b))/5;
        result = a+b;
        return;
    }
    result = -1;
    
}
int main(){
    int n;
    scanf("%d",&n);
    DP(n);
    printf("%d",result);
}
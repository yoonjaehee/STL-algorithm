#include <iostream>
#include <vector>
using namespace std;
int d[1000001];
void cal(int a){
    d[1]=0;
    for(int i=2;i<=a;i++){
        d[i]=d[i-1]+1;
        if(i%2==0 && d[i]>(d[i/2])+1){
            d[i] = d[i/2]+1;
        }
        if(i%3==0 && d[i]>(d[i/3])+1){
            d[i] = d[i/3]+1;
        }
    }
    printf("%d",d[a]);
}
int main(){
    int num;
    scanf("%d", &num);
    cal(num);
}
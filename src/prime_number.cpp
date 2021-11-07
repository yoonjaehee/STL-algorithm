#include <iostream>
using namespace std;
int main(){
    int start,end,t,i;
    scanf("%d %d",&start, &end);
    for(i=start;i<=end;i++){
        if(i==1){
            continue;
        }
        for(t=2;t<i;t++){
            if(i%t==0){
                break;
            }
        }
        if(i==t){
            printf("%d\n", t);
        }
    }
}
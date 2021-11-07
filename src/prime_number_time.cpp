#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int min, max, start;
    scanf("%d %d", &min, &max);
    for(int i=min;i<=max;i++){
        int point = (int)sqrt(i); // 이 기준점 대칭으로 똑같음 
        if(i!=1 && point==1){
            printf("%d\n", i);
        }
        for(start=2; start<=point;start++){
            if(i%start==0){
                break;
            }
            if(start==point){
                printf("%d\n", i);
            }
        }
    }
}
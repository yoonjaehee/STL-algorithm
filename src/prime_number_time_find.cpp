#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main(){
    int number, num, start;
    int count=0;
    scanf("%d", &number);
    vector <int> vec;
    for(int t=0; t<number; t++){
        scanf("%d", &num);
        vec.push_back(num);
    }
    for(int p=0;p<number;p++){
        int point = (int)sqrt(vec[p]); // 이 기준점 대칭으로 똑같음 
        if(vec[p]!=1 && point==1){
            count+=1;
        }
        for(start=2; start<=point;start++){
            if(vec[p]%start==0){
                break;
            }
            if(start==point){
                count+=1;
            }
        }
    }
    printf("%d", count);
}
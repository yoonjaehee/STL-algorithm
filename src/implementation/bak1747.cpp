#include <iostream>
#include <string>
#include <math.h>

using namespace std;
int num;
bool ispelin(int start){
    string temp = to_string(start);
    bool rt=true;
    int len = temp.size();
    for(int i=0;i<len/2;i++){
        if(temp[i] != temp[len-1-i]){
            rt = false;
        }
    }
    return rt;
}
bool conf(int start){
    bool rt2 = true;
    for(int i=2;i<=sqrt(start);i++){
        if(start%i == 0){
            rt2 = false;
        }  
    }
    return rt2;
}
int main(){
    scanf("%d",&num);
    while(1){
        if(num == 1){
            continue;
        }
        if(ispelin(num) && conf(num)){
            printf("%d",num);
            return 0;
        }
        num++;
    }
    return 0;
}
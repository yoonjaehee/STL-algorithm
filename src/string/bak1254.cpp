#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int len;
string str;
int palin(int n){
    int half = (len-n)/2;
    for(int t=0;t<half;t++){
        if(str[n+t] != str[len-t-1]){
            return false;
        }
    }
    return true;
}
int main(){
    getline(cin,str);
    len = str.size();
    for(int i=0;i<len;i++){
        if(palin(i)){
            printf("%d",len+i);
            return 0;
        }
    }
}
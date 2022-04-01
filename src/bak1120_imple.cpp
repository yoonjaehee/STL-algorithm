#include <iostream>
#include <string>
using namespace std;
int main(){
    int min = 50;
    int count;
    string a,b;
    cin>>a>>b;
    for(int i=0;i<=b.length() - a.length();i++){
        count = 0;
        for(int t=0;t<a.length();t++){
            if(a[t] != b[i+t]){
                count++;
            }
        }
        if(min > count){
            min = count;
        }
    }
    printf("%d",min);
}
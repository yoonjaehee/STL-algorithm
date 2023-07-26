#include <iostream>
#include <string.h>
using namespace std;
int main(){
    int n;
    int count = 0;
    int arr[100] = {0,};
    scanf("%d",&n);    
    string str;
    for(int i=0;i<n;i++){
        getline(cin,str);
        for(int t=0;t<str.size()-1;t++){
            if(arr[str[t+1]] != 0){
                count++;
            }
            if(str[t] != str[t+1]){
                arr[str[t]]++;
            }
        }
    }
    printf("%d",n-count);
}
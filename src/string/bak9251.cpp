#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;
int arr[1001][1001]={0,};
int main(){
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    int len1 = str1.size();
    int len2 = str2.size();
    for(int i=0;i<len1+1;i++){
        memset(arr[i],0,sizeof(int)*(len2+1));
    }
    for(int i=1;i<=len1;i++){
        for(int t=1;t<=len2;t++){
            if(str1[i-1] == str2[t-1]){
                arr[i][t] = arr[i-1][t-1]+1;
            }
            else{
                arr[i][t] = max(arr[i-1][t],arr[i][t-1]);
            }
        }
    }
    printf("%d",arr[len1][len2]);
}
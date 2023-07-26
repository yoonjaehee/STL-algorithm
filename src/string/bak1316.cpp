#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
bool arr[27] = {false,};
int main(){
    int n;
    int count = 0;
    scanf("%d",&n);    
    string str;
    char cur = 0;
    cin.ignore();
    for(int i=0;i<n;i++){
        memset(arr,false,sizeof(bool)*27);
        getline(cin,str);
        for(int t=0;t<str.size();t++){
            if(arr[str[t]-'a'] && cur != str[t]){
                count++;
                break;
            }
            else{
                arr[str[t]-'a'] = true;
            }
            cur = str[t];
        }
    }
    printf("%d",n-count);
}
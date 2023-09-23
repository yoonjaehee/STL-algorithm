#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int comp[26];
int main(){
    string str;
    getline(cin,str);
    int len = str.size();
    for(int i=0;i<len;i++){
        char temp=str[i];
        comp[temp-'A']++;
    }
    int ispos=0;
    int mid = -1;
    for(int i=0;i<26;i++){
        if(comp[i]%2!=0){
            ispos++;
            mid = i;
        }
    }
    if(ispos > 1){
        printf("I'm Sorry Hansoo");
        return 0;
    }
    string tmp = "";
    char temp2;
    for(int i=0;i<26;i++){
        int pick=comp[i];
        if(pick!=0){
            temp2=(i+'A');
            for(int t=0;t<pick/2;t++){
                tmp+=temp2;
            }
        }
    }
    string str2 = tmp;
    string str3 = "";
    reverse(str2.begin(),str2.end());
    if(mid != -1){
        temp2 = (mid+'A');
        tmp+=(temp2);
    }
    string answer = (tmp+str2);
    cout<<answer;
}
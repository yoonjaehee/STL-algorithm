#include <iostream>
#include <string>
#include <set>
using namespace std;
set<string> se;
int main(){
    string str;
    getline(cin,str);
    int len = str.size();
    for(int i=1;i<=len;i++){
        string temp = "";
        for(int t=0;t<len;t++){
            temp = str.substr(t,i);
            if(temp.size()<i){
                continue;
            }
            se.insert(temp);
        }
    }
    printf("%d",se.size());
}
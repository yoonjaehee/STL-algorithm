#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
map<string,int> m;
int main(){
    int n;
    int result = 0;
    string str;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>str;
        m[str]++;
    }
    for(auto i=m.begin();i!=m.end();i++){
        result = max(result,i->second);
    }
    for(auto i=m.begin();i!=m.end();i++){
        if(result == i->second){
            cout<<i->first;
            return 0;
        }
    }
}
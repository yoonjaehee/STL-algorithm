#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(){
    string str;
    set<string> se;
    getline(cin,str);
    string temp = "";
    for(int i=str.size()-1;i>=0;i--){
        temp=(str[i])+temp;
        se.insert(temp);
    }
    for(auto i:se){
        cout<<i<<"\n";
    }
}
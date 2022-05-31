#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
map<string,double>vec;
int main(){
    int total = 0;
    string s;
    while(getline(cin,s)){ // eof 까지 입력받기
        total++;
        vec[s]++;
    }
    cout<<fixed;
    cout.precision(4);
    for(auto it = vec.begin();it!=vec.end();it++){
        cout<<it->first<<" "<<it->second/total*100<<"\n";
    }
    
}
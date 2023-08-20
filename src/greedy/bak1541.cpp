#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int main(){
    string st,word;
    getline(cin,st);
    stringstream ss;
    ss.str(st);
    vector<string> vec;
    vector<int> vec2;
    while(getline(ss,word,'-')){
        vec.push_back(word);
    }
    for(int i=0;i<vec.size();i++){
        int sum = 0;
        stringstream s2;
        s2.str(vec[i]);
        while(getline(s2,word,'+')){
            sum+=(stoi(word));
        }
        vec2.push_back(sum);
        printf("%d ",vec2[i]);
    }
    int res = vec2[0];
    for(int i=1;i<vec2.size();i++){
        res-=vec2[i];
    }
    printf("%d",res);
}
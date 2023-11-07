#include <iostream>
#include <string>
using namespace std;
int n;
string s;
int main(){
    scanf("%d",&n);
    cin.ignore();
    getline(cin,s);
    string first;
    string second;
    for(int i=0;i<s.size();i++){
        if(s[i] == '*'){
            first = s.substr(0,i);
            second = s.substr(i+1,s.size()-i);
        }
    }
    string str;
    for(int i=0;i<n;i++){
        bool flag = true;
        getline(cin,str);
        if(str.length() < first.length() + second.length()){
            cout<<"NE\n";
            continue;
        }
        string cmpfi = str.substr(0,first.length());
        string cmpse = str.substr(str.length()-second.length(),str.length());
        if(cmpfi == first && cmpse == second){
            cout<<"DA\n";
        }
        else{
            cout<<"NE\n";
        }
    }
}
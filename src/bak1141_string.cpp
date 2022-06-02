#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> vec;
int main(){
    int n;
    string s;
    scanf("%d",&n);
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        vec.push_back(s);
    }
    for(int i=0;i<vec.size();i++){
        for(int t=0;t<vec[i].size();t++){
            printf("%c",vec[i][t]);
        }
    }
}
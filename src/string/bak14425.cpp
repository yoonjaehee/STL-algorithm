#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int n,m;
    string str;
    scanf("%d %d",&n,&m);
    vector<string> vec;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,str);
        vec.push_back(str);
    }
    int count = 0;
    cin.ignore();
    for(int i=0;i<m;i++){
        getline(cin,str);
        auto it = find(vec.begin(),vec.end(),str);
        if(it != vec.end()){
            count++;
        }
    }
    printf("%d",count);
}
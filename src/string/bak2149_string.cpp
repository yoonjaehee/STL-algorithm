#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<pair<char,int>> vec;
char v[101][101];
int main(){
    string temp,s;
    getline(cin,temp);
    for(int i=0;i<temp.size();i++){
        vec.push_back({temp[i],i});
    }
    sort(vec.begin(),vec.end());
    getline(cin,s);
    int count = s.size()/temp.size();
    char res[temp.size()][count]={0,};
    for(int i=0;i<count;i++){
        for(int t=0;t<temp.size();t++){
            v[i][vec[t].second] = s[t*count + i];
        }
    }
    for(int i=0;i<count;i++){
        for(int t=0;t<temp.size();t++){
            printf("%c",v[i][t]);
        }
    }

}
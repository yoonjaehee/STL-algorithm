#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
vector<string> vec;
vector<string> era;
int main(){
    string s;
    int point = 0;
    scanf("%d %d",&n,&m);
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        vec.push_back(s);
    }
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    for(int i=0;i<m;i++){
        getline(cin,s);
        for(int t=0;t<s.size();t++){
            if(s[t] == ','){
                era.push_back(s.substr(0,t));
                point = t;
            }
        }
        era.push_back(s.substr(point+1,s.size()+1));
        for(int t=0;t<era.size();t++){
            auto it = find(vec.begin(),vec.end(),era[t]);
            if(it != vec.end()){
                vec.erase(it);
            }
        }
        printf("%d",vec.size());
   }
}
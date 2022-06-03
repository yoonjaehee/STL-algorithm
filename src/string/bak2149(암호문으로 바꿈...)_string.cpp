#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<pair<char,int>> vec;
vector<char>v[101];
int main(){
    string temp,s;
    getline(cin,temp);
    vector<char> v[101];
    for(int i=0;i<temp.size();i++){
        vec.push_back({temp[i],i});
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<temp.size();i++){
        cout<<vec[i].first<<" "<<vec[i].second<<endl;
    }
    getline(cin,s);
    int count = s.size()/temp.size();
    char res[temp.size()][count]={0,};
    for(int i=0;i<count;i++){
        for(int t=0;t<temp.size();t++){
            v[i].push_back(s[i*temp.size() + t]);
        }
    }
    for(int i=0;i<count;i++){
        for(int t=0;t<temp.size();t++){
            res[i][vec[t].second] = v[i][t];
        }
    }
    for(int i=0;i<temp.size();i++){
        for(int t=0;t<count;t++){
            cout<<res[t][i];
        }
        cout<<endl;
    }
}
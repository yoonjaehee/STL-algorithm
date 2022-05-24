#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> vec;
vector<char> res;
int main(){
    int n;
    scanf("%d",&n);
    vector<vector<int>>bl(0,vector<int>(n,0));
    for(int i=0;i<n;i++){
        string s;
        int temp=0;
        getline(cin,s);
        for(int t=0;t<s.size();t++){
            if(s[t] == ' '){
                bl[i].push_back(t+1);
            }
        }
        // 1. s[0] 없으면 넣기. 2. 단어 처음 문자 없으면 넣기 3. 순서대로 넣기.
        for(int t=0;t<res.size();t++){
            if(res[t] == s[0]){
                temp=1;
                break;
            }
            res.push_back(s[0]);
            s.insert(0,1,'[');
            s.insert(2,1,']');
        } // s[0] res에 없으면 넣음
        if(temp == 1){
            char count=0;
            for(int t=0;t<bl[i].size();t++){
                if(count != 0){
                    break;
                }
                for(int p=0;p<res.size();p++){
                    if(res[p] == s[bl[i][t]]){
                        count=s[bl[i][t]];
                        s.insert(bl[i][t]-1,1,'[');
                        s.insert(bl[i][t]+1,1,']');
                        break;
                    }
                }
            }
        } // 단어 처음 문자 없으면 넣음
        if(temp == 2){
            int tp=0;
            for(int t=0;t<s.size();t++){
                auto it = find(res.begin(),res.end(),s[t]);
                if(it != res.end()){
                    s.insert(*it,1,'[');
                    s.insert(*it+2,1,'[');
                }
            }
        } // 순서대로 없으면 넣음.
        vec.push_back(s);
    }
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<"\n";
    }
}
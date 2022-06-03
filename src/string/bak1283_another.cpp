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
    cin.ignore();
    for(int i=0;i<n;i++){
        string s;
        string ste="";
        vector<int>bl;
        int temp=0;
        getline(cin,s);
        for(int t=0;t<s.size();t++){
            if(s[t] == ' '){
                bl.push_back(t);
            }
        } // 공백 다음 위치 넣어줌.
        auto it = find(res.begin(),res.end(),s[0]);
        if(it == res.end()){
            res.push_back(s[0]);
            if(s[0] < 'a'){
                res.push_back(s[0]+32);
            }
            else{
                res.push_back(s[0]-32);
            }
            ste.insert(0,1,'[');
            ste.insert(1,s);
            ste.insert(2,1,']');
            temp = 1;
        } // s[0]이 res에 없으면 res에 넣어줌
        if(temp == 0){
            for(int t=0;t<bl.size();t++){
                auto it = find(res.begin(),res.end(),s[bl[t]+1]);
                if(it == res.end()){
                    res.push_back(s[bl[t]+1]);
                    if(s[bl[t]+1] < 'a'){
                        res.push_back(s[bl[t]+1]+32);
                    }
                    else{
                        res.push_back(s[bl[t]+1]-32);
                    }
                    ste.insert(0,s);
                    ste.insert(bl[t]+1,1,'[');
                    ste.insert(bl[t]+3,1,']');
                    temp=2;
                    break;
                }
            }
        } // blank 다음거마다 찾아보고 행렬에 있으면 암것도안하고 없으면 추가
        if(temp == 0){
            for(int t=0;t<s.size();t++){
                if(s[t]!= ' '){
                    auto it = find(res.begin(),res.end(),s[t]);
                    if(it == res.end()){ // 없을경우
                        res.push_back(s[t]);
                        if(s[t] < 'a'){
                            res.push_back(s[t]+32);
                        }
                        else{
                            res.push_back(s[t]-32);
                        }
                        ste.insert(0,s);
                        ste.insert(t,1,'[');
                        ste.insert(t+2,1,']');
                        break;
                    }
                }
            }
        }
        if(ste.empty()){
            ste = s;
        }
        vec.push_back(ste);
    }
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<"\n";
    }
}
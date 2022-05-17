#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
vector<string> vec;
int main(){
    int n;
    int ans=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        reverse(s.begin(),s.end());
        vec.push_back(s);
    }
    while(1){
        set<string> a;
        for(int i=0;i<vec.size();i++){
            a.insert(vec[i].substr(0,ans));
        }
        if(a.size() == vec.size()){
            break;
        }
        else{
            ans++;
        }
    }
    printf("%d",ans);
}
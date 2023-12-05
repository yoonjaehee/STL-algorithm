#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,tem;
string temp;
vector<string> vec;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&tem);
        vec.clear();
        cin.ignore();
        for(int t=0;t<tem;t++){
            getline(cin,temp);
            vec.push_back(temp);
        }
        sort(vec.begin(),vec.end());
        bool flag = false;
        for(int i=0;i<tem-1;i++){
            if(vec[i] == vec[i+1].substr(0,vec[i].size())){
                flag = true;
            }
        }
        if(flag){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
}
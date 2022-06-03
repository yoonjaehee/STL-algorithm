#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> vec;
vector<int> ans[101];
int main(){
    int n;
    int res=1;
    string s;
    char temp;
    scanf("%d",&n);
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        vec.push_back(s);
    }
    for(int i=0;i<vec.size();i++){
        for(int t=0;t<vec.size();t++){
            int found = vec[t].find(vec[i]);
            if(found == string::npos){
                continue;
            }
            else{
                if((found==0) && (t!=i)){
                    ans.push_back(found);
                }
                else{
                    continue;
                }
            }
            
        }
    }
    for(int i=0;i<ans.size();i++){
        printf("%d ",ans[i]);
    }
}
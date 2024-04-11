#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n,k;
string str1;
int main(){
    scanf("%d %d",&n,&k);
    cin.ignore();
    getline(cin,str1);
    vector<int> vec;
    int len = str1.size();
    for(int i=0;i<len;i++){
        int temp = str1[i] - '0';
        if(vec.empty()){
            vec.push_back(temp);
            continue;
        }
        while((k > 0) && (vec.back() < temp) && (!vec.empty())){
            k--;
            vec.pop_back();
        }
        vec.push_back(temp);
    }
    string res="";
    for(int i=0;i<vec.size()-k;i++){
        res += to_string(vec[i]);
    }
    cout<<res;
}
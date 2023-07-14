#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<string> vec;
void stackprint(stack<char> temp){
    while(!temp.empty()){
        cout<<temp.top();
        temp.pop();
    }
}
int main(){
    string s;
    getline(cin,s);
    int count = 0;
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i] == '<'){
            stackprint(st);
            while(1){
                cout<<s[i];
                if(s[i] == '>'){
                    break;
                }
                i++;
            }
        }
        else if(s[i] ==' '){
            stackprint(st);
            printf(" ");
        }
        else{
            st.push(s[i]);
        }
    }
    stackprint(st);
}
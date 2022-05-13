#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
vector<string> vec;
string counting(string str){
    stack<char> st;
    int len = str.length();
    for(int i=0;i<len;i++){
        if(str[i] == '(' || str[i] == '['){
            st.push(str[i]);
        }
        else{
            if(str[i] == ')'){
                if(st.top() == '('){
                    st.pop();
                }
                else{
                    return "no";
                }
            }
            else{
                if(str[i] == ']'){
                    if(st.top() == '['){
                        st.pop();
                    }
                    else{
                        return "no";
                    }
                }
            }
        }
    }
    if(st.empty()){
        return "yes";
    }
    else{
        return "no";
    }
}
int main(){
    int count = 0; 
    while(1){
        string s,temp;
        cin.ignore();
        getline(cin,s);
        if(s == "."){
            break;
        }
        temp=counting(s);
        cout<<temp;
        vec.push_back(temp);
        count++;
    }
    for(int i=0;i<count;i++){
        cout<<vec[i]<<endl;
    }
}

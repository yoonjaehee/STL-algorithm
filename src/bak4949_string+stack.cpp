#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
vector<string> vec;
string counting(string str){
    printf("%s",str);
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
                else if(st.top() == '['){
                    return "NO";
                }
            }
            else{
                if(str[i] == ']'){
                    if(st.top() == '['){
                        st.pop();
                    }
                    else if(st.top() == '('){
                        return "NO";
                    }
                }
            }
        }
    }
    if(st.empty()){
        return "YES";
    }
    else{
        return "NO";
    }
}
int main(){
    int count = 0; 
    while(1){
        string temp;
        char arr[101];
        scanf("%s",arr);
        if(arr == "."){
            break;
        }
        temp=counting(arr);
        vec.push_back(temp);
        count++;
    }
    for(int i=0;i<count;i++){
        cout<<vec[i]<<endl;
    }
}

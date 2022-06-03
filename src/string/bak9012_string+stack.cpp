// ( 일때는 push 해주고 )일때는 pop 해주는데, pop 할게 없으면 No return 해주고,
// 모두가 pop 되면 통과로 YES 출력
// stack이 남아있으면 NO 출력
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
vector<string> vec;
string counting(string s){
    stack<char> st;
    int str = s.length();
        for(int t=0;t<str;t++){
            if(s[t] == '('){
                st.push(s[t]);
            }
            else if(s[t]==')'){
                if(!st.empty()){
                    if('(' == st.top()){
                        st.pop();
                    }
                }
                else{
                    return "NO";
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
    int n;
    string s;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        string temp;
        cin>>s;
        temp=counting(s);
        vec.push_back(temp);
    }
    for(int i=0;i<n;i++){
        cout<<vec[i]<<endl;
    }
}
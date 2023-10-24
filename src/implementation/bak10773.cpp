#include <iostream>
#include <stack>
using namespace std;
int n,temp;
long long sum;
int main(){
    scanf("%d",&n);
    stack<int> st;
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        if(temp == 0){
            sum-=(st.top());
            st.pop();
        }
        else{
            sum+=temp;
            st.push(temp);
        }
    }
    printf("%lld",sum);
}
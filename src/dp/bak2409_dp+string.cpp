#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n,m;
string arr[101][101];
string adding(string num1,string num2){
    int sum=0;
    string res;
    while(!num1.empty() || !num2.empty() || sum){
        if(!num1.empty()){
            sum+=num1.back() -'0';
            num1.pop_back();
        }
        if(!num2.empty()){
            sum+=num2.back() - '0';
            num2.pop_back();
        }
        res.push_back((sum%10)+'0');
        sum/=10;
    }
    reverse(res.begin(),res.end());
    return res;
}
string comb(int a,int b){
    if(a==b || b==0){
        return "1";
    }
    string &res = arr[a][b];
    if((a/2 == 0) && (b > a/2)){
        b = a-b; 
    }
    if(res != ""){
        return res;
    }
    res = adding(comb(a-1,b-1),comb(a-1,b));
    return res;
}
int main(){
    scanf("%d %d",&n,&m);
    cout<<comb(n,m);
}
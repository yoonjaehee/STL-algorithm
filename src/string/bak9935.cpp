#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool flag;
string str,bomb,temp,res;
int check;
int len,len2;
void checking(string comp,string era){
    int count = 0;
    if(comp.empty()){
        printf("FRULA");
        return;
    }
    for(int i=0;i<comp.size();i++){
        if(era[count] == comp[i]){
            count++;
        }
        else{
            count = 0;
            if(era[0] == comp[i]){
                count++;
            }
        }
        if(count == len2){
            comp.erase(i-count+1,count);
            if(res.size()>comp.size()){
                res = comp;
            }
            checking(comp,era);
        }
    }
}
int main(){
    getline(cin,str);
    res = str;
    getline(cin,bomb);
    len = str.size();
    len2 = bomb.size();
    checking(str,bomb);
    cout<<res;
}
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m,ch,count;
    string some;    
    scanf("%d",&n);
    scanf("%d",&m);
    cin>>some;
    int res=0;
    for(int i=0;i<m-1;i++){
        count=0;
        if(some[i]=='O'){
            continue;
        }
        else{
            while(some[i+1]='O' && some[i+2]=='I'){
                count++;
                if(count == n){
                    count --;
                    res++;
                }
                i+=2;
            }
            count=0;
        }
    }
    printf("%d",res);
}
#include <iostream>
#include <vector>
using namespace std;
vector<char> sign;
vector<int> numb;
void calmax(int max){
    for(char i=0;i<sign.size();i++){
        if(sign[i]=='-'){
            for(char t=i+1;t<sign.size();t++){
                if(sign[t]=='+'){
                    sign[t]='-';
                }
                else{
                    break;
                }
            }
        }
    }
    for(char i=0;i<sign.size();i++){
        if(sign[i]=='-'){
            max-=numb[i];
        }
        else{
            max+=numb[i];
        }
    }
    printf("%d",max);
}
int main(){
    int num;
    scanf("%d",&num);
    while(1){
        char temp;
        int tem;
        scanf("%c",&temp);
        if(temp=='\n'){
            break;
        }
        scanf("%d", &tem);
        sign.push_back(temp);
        numb.push_back(tem);
    }
    calmax(num);
}
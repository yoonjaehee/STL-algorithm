#include <iostream>
#include <vector>
using namespace std;
vector<pair<string,int>> dex;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        char name[21];
        scanf("%s",&name);
        dex.push_back({name,i});
    }
    for(int i=0;i<m;i++){
        int num_temp;
        char temp[21];
        scanf("%s",&temp);
        if(isdigit(temp[0])==true){ // 숫자받음
            num_temp = stoi(temp);
            char* pri=&*(dex[num_temp-1].first).begin();
            printf("%s\n",pri);
        }
        else{ // 문자받음
            for(int i=0;i<n;i++){
                if(temp == dex[i].first){
                    printf("%d\n",i+1);
                    break;
                }
            }
            
        }
    }
}
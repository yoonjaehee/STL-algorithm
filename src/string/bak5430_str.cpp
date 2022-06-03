#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main(){
    char arr[100001];
    deque<int> q;
    int t,p,n,temp;
    char c;
    scanf("%d", &t);
    vector<string> s;
    for(int i=0;i<t;i++){
        int flag=0;
        string st;
        scanf("%s", &arr);
        scanf("%d",&n);
        scanf("%c",&c);
        if(n!=0){
            for(int l=0;l<n;l++){
                scanf("%d%c",&temp,&c);
                q.push_back(temp);
            }
        }
        else{
            scanf("%c%c",&c,&c);
        }
        for(int y=0;arr[y]!='\n';y++){
            if(arr[y] == 'R'){
                reverse(q.begin(), q.end());
            }
            else if(arr[y] == 'D'){
                if(q.empty()){
                    flag=1;
                    break;
                }
                else{
                    q.pop_front();
                }
            }
        }
        if(flag==0){
            int size= q.size();
            s[i].append("[");
            for(int v=0;v<size;v++){
                string st=to_string(q.front());
                s[i].append(st);
                q.pop_front();
                if(v != size-1){
                    s[i].append(",");
                }
            }
            s[i].append("]\n");
        }
        else{
            s[i].append("error");
        }
    }
    for(int i=0;i<n;i++){
        printf("%s",s[i]);
    }
}
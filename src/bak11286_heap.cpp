#include <iostream>
#include <queue>
#include <cstdlib>
#include <vector>
using namespace std;

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
vector<int> ans,tem_ans; 
void del(){
    int temp_count=0;
    vector<pair<int,int>> tem; 
    int temp=pq.top().first;
    while(pq.top().first == temp){
        tem.push_back({pq.top().first,pq.top().second});
        pq.pop();
        temp_count++;
        if(pq.empty()){
            break;
        }
    }
    if(temp_count==1){
        ans.push_back(tem_ans[tem.front().second]);
        tem.pop_back();
    }
    else{
        int real = tem_ans[tem.front().second];
        int real2 = 1;
        for(int t=1;t<temp_count;t++){
            if(tem_ans[tem[t-1].second] >= tem_ans[tem[t].second]){
                real=tem_ans[tem[t].second];
                real2=t+1;
            }
        }
        tem.erase(tem.begin()+(real2-1));
        for(int t=0;t<temp_count-1;t++){
            pq.push({tem[t].first,tem[t].second});
            printf("%d %d\n",tem[t].first,tem[t].second);
        }
        for(int t=0;t<temp_count-1;t++){
            tem.pop_back();
        }
        ans.push_back(real);
    }
}
int main(){
    int count,num,ab;
    scanf("%d",&count);
    for(int i=0;i<count;i++){
        scanf("%d", &num);
        if(num==0){
            if(pq.empty()){
                ans.push_back(0);
                tem_ans.push_back(0);
            }
            else{
                tem_ans.push_back(0);
                del();
            }
        }
        else{
            tem_ans.push_back(num);
            ab=abs(num);
            pq.push({ab,i});
        }
    }
    printf("\n");
    for(int i=0;i<ans.size();i++){
        printf("%d\n", ans[i]);
    }
}
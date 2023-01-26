#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> p;
    printf("자신이 선택할 수만큼 입력해 주세요! :");
    int a=0;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        int ins;
        printf("%d번째 선택한 수를 입력해 주세요!: ",i+1);
        scanf("%d",&ins);
        p.push_back(ins);
    }
    random_device rd;
    for(int t=0;t<5;t++){
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(1,45);
        vector<int> u=p;
        for(int i=0;i<7-a;i++){
            while(1){
                int res=dis(gen);
                auto it = find(u.begin(),u.end(),res);
                if (it == u.end()){
                    u.push_back(res);
                    break;
                }
            }
        }
        printf("%d번째 로또 번호: ", t+1);
        int bonus = u[6];
        u.pop_back();
        sort(u.begin(),u.end());
        for(int i=0;i<6;i++){
            printf(" %d",u[i]);
        }
        printf(" + bonus:%d \n",bonus);
    }

}
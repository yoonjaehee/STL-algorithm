#include <iostream>
#include <vector>
using namespace std;
int main(){
    int t_case;
    vector <int> v1;
    scanf("%d", &t_case);
    for(int i=0;i<t_case;i++){
        int rows=0, cols=0, num=0;
        scanf("%d %d %d", &rows,&cols,&num);
        vector <vector <int>>v(rows,vector<int>(cols,0)); // 0으로 초기화
        for(int p=0;p<num;p++){
            int x,y;
            scanf("%d %d", &x, &y);
            v[x][y]=1;
        }
        for(int t=0;t<rows-1;t++){
            for(int u=0;u<cols-1;u++){
                if(v[t][u]==1){
                    if(v[t+1][u]==1 && v[t][u+1]==1 && v[t+1][u+1]==0){
                        v[t][u]=0;
                        num-=2;
                        continue;
                    }
                    if(v[t+1][u]==1 || v[t][u+1]==1){
                        v[t][u]=0;
                        num-=1;
                    }

                }
            }
        }
        for(int u=0;u<cols-1;u++){
            if(v[rows-1][u]==1){
                if(v[rows-1][u+1]==1){
                    v[rows-1][u]=0;
                    num-=1;
                }
            }
        }
        for(int t=0;t<rows-1;t++){
            if(v[t][cols-1]==1){
                if(v[t+1][cols-1]==1){
                    v[t][cols-1]=0;
                    num-=1;
                }
            }
        }
        v1.push_back(num);
    }
    for(int i=0;i<t_case;i++){
        printf("%d\n",v1[i]);
    }
}
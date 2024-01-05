#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n,lefty,righty,topy,downy;
int leftx,rightx,topx,downx;
int arr[21][21];
int total = 0;
int mn = 19999;
priority_queue<int,vector<int>,greater<int>> pq;
void dfs(int sty, int stx){
    topy = sty;
    topx = stx;
    for(int i=1;i<n-topy;i++){
        lefty = topy+i;
        leftx = topx-i;
        if(lefty >= n || leftx < 0){
            continue;
        }
        for(int t=1;t<n-lefty;t++){
            downy = lefty+t;
            downx = leftx+t;
            if(downy >= n || downx >= n){
                continue;
            }
            righty = downy - (lefty-topy);
            rightx = (lefty-topy) + downx;
            if(righty < 0 || rightx >= n){
                continue;
            }
            // 맨위 더하기
            int sum = 0; // 경계안
            int sum1 = 0; // 왼위
            int sum2 = 0; // 오위
            int sum3 = 0; // 왼아래
            int sum4 = 0; // 오아래
            for(int p=0;p<topy;p++){
                for(int q=0;q<=topx;q++){
                    sum1+=arr[p][q];
                }
                for(int q=topx+1;q<n;q++){
                    sum2+=arr[p][q];
                }
            }
            // 맨아래 더하기
            for(int p=downy+1;p<n;p++){
                for(int q=0;q<downx;q++){
                    sum4+=arr[p][q];
                }
                for(int q=downx;q<n;q++){
                    sum3+=arr[p][q];
                }
            }
            //왼위
            for(int p=topy;p<lefty;p++){
                for(int q=0;q<=topx-(p-topy+1);q++){
                    sum1+=arr[p][q];
                }
            }
            //오른위
            for(int p=topy;p<=righty;p++){
                for(int q=n-1;q>=topx+(p-topy+1);q--){
                    sum2+=arr[p][q];
                }
            }
            //오른아래
            for(int p=downy;p>righty;p--){
                for(int q=n-1;q>=downx+(downy-p+1);q--){
                    sum3+=arr[p][q];
                }
            }
            for(int p=downy;p>=lefty;p--){
                for(int q=0;q<=downx-(downy-p+1);q++){
                    sum4+=arr[p][q];
                }
            }
            sum=total-sum1-sum2-sum3-sum4;
            int a=min(min(min(min(sum,sum1),sum2),sum3),sum4);
            int b=max(max(max(max(sum,sum1),sum2),sum3),sum4);
            pq.push(b-a);
            if(mn > b-a){
                printf("{%d %d}{%d %d}{%d %d}{%d %d} : %d {%d}{%d}{%d}{%d}{%d}\n",topy,topx,lefty,leftx,downy,downx,righty,rightx,b-a,sum,sum1,sum2,sum3,sum4);
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int t=0;t<n;t++){
            scanf("%d",&arr[i][t]);
            total+=arr[i][t];
        }
    }
    for(int i=0;i<n-2;i++){
        for(int t=1;t<n-1;t++){
            dfs(i,t); // 위 기준
        }
    }
    for(int i=0;i<pq.size();i++){
        printf("%d ",pq.top());
        pq.pop();
    }
}
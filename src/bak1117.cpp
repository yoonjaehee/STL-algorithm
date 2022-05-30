#include <iostream>
using namespace std;
int main(){
    int h,w,f,c,x1,x2,y1,y2;
    scanf("%d %d %d %d %d %d %d %d",&w,&h,&f,&c,&x1,&y1,&x2,&y2);
    int arr[h][w]={0,};
    for(int i=0;i<h;i++){
        for(int t=0;t<w;t++){
            arr[i][t]=0;
        }
    }
    int recy=(h/(c+1));
    int recx=w-f;
    for(int t=y1;t<=y2-1;t++){
        for(int i=x1;i<=x2-1;i++){
            arr[h-t-1][f+i]=1;
            for(int p=1;p<=c+1;p++){
                if(p%2 == 0){
                    arr[h-t-1-(recy*p)][f+i]=1;
                }
                else{
                    arr[h-((p+1)*recy)+t][f+i]=1;
                }
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int t=0;t<w;t++){
            printf("%d ",arr[i][t]);
        }
        printf("\n");
    }
    for(int i=0;i<h;i++){
        for(int t=0;t<f;t++){
            if(f+t>=w){
                continue;
            }
            arr[i][t] = arr[i][f+t];
        }
    }
    int res=0;
    for(int i=0;i<h;i++){
        for(int t=0;t<w;t++){
            printf("%d ",arr[i][t]);
        }
        printf("\n");
    }
}
#include <stdio.h>
int main(){
    int M, n, val;
    char cmd[10];
    val = 0;
    scanf("%d", &M);
    for(int i=0;i<M;i++){
        scanf("%s", &cmd);
        if(cmd[0]=='a' && cmd[1]=='d'){
            scanf("%d", &n);
            val = val|(1<<n);
        }
        else if(cmd[0]=='r'){
            scanf("%d", &n);
            val &= ~(1<<n);
        }
        else if(cmd[0]=='c'){
            scanf("%d", &n);
            if(val&(1<<n)) printf("1\n");
            else printf("0\n");
        }
        else if(cmd[0]=='t'){
            scanf("%d", &n);
            val ^= (1<<n);
        }
        else if(cmd[0]=='a'){
            val = (1<<21)-1;
        }
        else if(cmd[0]=='e'){
            val = 0;
        }
    }
    return 0;
}
#include <iostream>
#include <string>
using namespace std;
int main(){
    char kingx,stx;
    int kingy,sty,n;
    string s;
    scanf("%c%d %c%d %d",&kingx,&kingy,&stx,&sty,&n);
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        char ix = kingx;
        int iy = kingy;
        char tx = stx;
        int ty = sty;
        if(s=="R"){
            ix++;
            if(tx == ix && ty==iy){
                tx++;
            }
        }
        else if(s=="L"){
            ix--;
            if(tx == ix && ty==iy){
                tx--;
            }
        }
        else if(s=="B"){
            iy--;
            if(tx == ix && ty==iy){
                ty--;
            }
        }
        else if(s=="T"){
            iy++;
            if(tx == ix && ty==iy){
                ty++;
            }
        }
        else if(s=="RT"){
            iy++;
            ix++;
            if(tx == ix && ty==iy){
                tx++;
                ty++;
            }
        }
        else if(s=="LT"){
            ix--;
            iy++;
            if(tx == ix && ty == iy){
                tx--;
                ty++;
            }
        }
        else if(s=="RB"){
            ix++;
            iy--;
            if(tx == ix && ty == iy){
                tx++;
                ty--;
            }
        }
        else if(s=="LB"){
            iy--;
            ix--;
            if(tx == ix && ty == iy){
                tx--;
                ty--;   
            }
        }
        if(ix > 'H' || ix < 'A' || iy < 1 || iy > 8 || tx >'H' || tx < 'A' || ty < 1 || ty > 8){
            continue;                      
        }
        else{
            kingx = ix;
            kingy = iy;
            stx = tx;
            sty = ty;
        }
    }
    printf("%c%d\n%c%d",kingx,kingy,stx,sty);
}
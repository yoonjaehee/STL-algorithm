
#include <iostream>
using namespace std;
int main() {
    int n;
    scanf("%d",&n);
    int a,b;
    a = n/5;
    while(1)
    {
        if(a < 0)
        {
            printf("-1");
            return 0;
        }
        if((n-(5*a))%3 == 0)
        {
            b = (n-(5*a))/3;
            break;
        }
        a--;
    }
    printf("%d",a+b);
    return 0;
}
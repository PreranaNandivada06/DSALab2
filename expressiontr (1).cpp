#include <iostream>
#include "explist.h"
int main(){
    int c;
    printf("enter ow many characters");
    scanf("%d",&c);
    char x[c+1];
    printf("enter te word");
    scanf("%c",x);
    list l;
    int i=0;
    while (x[i] != '\0')
    {
        printf("%c\n",x[i]);
        if (x[i]!= '+'){
            l.push(c);
        }
        else{
            l.pop();
        }
        i=i+1;
        l.peek();
    }
    l.display();
    
}
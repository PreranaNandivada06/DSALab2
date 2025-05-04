#include <iostream>
#include "arrsl.h"
int main(){
    int choice=0;
    while(choice!=2){
        
    printf("enter1.check balance, 2.exit");
    scanf("%d",&choice);
    if (choice==1){
        int st1;
        int st2;
        printf("enter input of left paranthesis");
        char arr[100];
        scanf("%s", &arr);
        printf("%s", arr);
        int i=0;
        while (arr[i]!=0)
        {
            st1=st1+1;
            i=i+1;
        }
        printf("enter input of ri paranthesis");
        char arrr[100];
        scanf("%s", &arrr);
        printf("%s", arrr);
        int j=0;
        while (arrr[j]!=0)
        {
            st2=st2+1;
            j=j+1;
        }
        if (st2==st1){
            printf("equal");
        }
        else{
            printf("not equal");
        }

        
    }
    }
}

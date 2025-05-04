#include <iostream>
#include "rrbs.h"
int main() {
    rrs rs;
    printf("enter values");
    int value;
    scanf("%d",&value);
    while (1) {
        int choice;
        printf("enter 1.to enter,2. execute, 3.exit");
        scanf("%d",&choice);
        if (choice==1){
            int sno;
            printf("enter sno");
            scanf("%d",&sno);
            int num;
            printf("enter number");
            scanf("%d",&num);
            rs.insert(sno,num);
        }
        else if(choice==2){
            rs.execute(value);
        }
        else if(choice==3){
            break;
        }

    }
}
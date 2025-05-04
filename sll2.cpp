#include <iostream>
#include "sll.h"
int main(){
    sigli sl1;
    sigli sl2;
    while(1){
        printf("1.insert, 2.display,3.merge, 4.exit: ");
        int choice;
        scanf("%d",&choice);
        if (choice==1){
            printf("1.list 1, 2.list2: ");
            int ck;
            scanf("%d",&ck);
            int number;
            printf("enter number: ");
            scanf("%d",&number);
            if (ck==1){sl1.insert(number);}
            else {sl2.insert(number);}
        }
        else if(choice==2){
            printf("sl1: ");
            sl1.display();
            printf("sl2: ");
            sl2.display();
        }
        else if(choice ==3){
            sigli *str;
            str=sl1.merge(&sl1, &sl2);
            str->display();
        }
        else if(choice==4){
            break;
        }
    }
    return 0;
}
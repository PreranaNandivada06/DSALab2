# include <iostream>
# include "sortheader.h"
void linsearch(int,int*,int);
void binsearch(int,int*,int);
int main()
{
int choice=0;
    int n;
    printf("enter how many entries");
    scanf("%d",&n);
    int arr[n];
    for(int k=0;k<n;k++){
        scanf("%d",&arr[k]);
    }
    while(1)
    {
        printf("enter choice 1 for linear search, 2 for binary search, 3 for exit\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("what would you like to search for\n");
            int num;
            scanf("%d",&num);
            linsearch(num,arr,n);
        }
        else if (choice==2)
        {
            printf("what would you like to search for\n");
            int num;
            scanf("%d",&num);
            binsearch(num,arr,n);
        }
        else if (choice==3)
        {
            printf("end of\n");
            break;
        }
        else
        {
            printf("invalid response\n");
        }

    }
}

void linsearch(int num,int* arr,int n){
    printf("begin linear search\n");
    for(int i=0;i<n;i++){
        if (arr[i]==num)
        {
            printf("NUMBER FOUND\n");
            return;
        }
    }
    printf("NUMBER NOT FOUND\n");
}
void binsearch(int num,int* arr,int n){
    printf("begin binary search\n");
    int choice;
    printf("which sorting method would you prefer 1 for bubble, 2 for selection, 3 for insertion");
    scanf("%d", &choice);
        if (choice == 1)
        {
            bubsort(arr,n);
        }
        else if (choice==2)
        {
            selsort(arr,n);
        }
        else if (choice==3)
        {
            insort(arr,n);
        }
        else
        {
            printf("invalid response, default bubble sort will take over\n");
            bubsort(arr,n);
        }


    
    int start=0;
    int end=n-1;
    while (start<=end)
    {
        int mid= (start+end)/2;
        if (num==arr[mid])
        {
            printf("NUMBER FOUND\n");
            return;
        }
        else if (arr[mid]>num)
        {
            end=mid-1;
        }
        else 
        {
            start=mid+1;
        }
    }
    printf("NUMBER NOT FOUND\n");

}
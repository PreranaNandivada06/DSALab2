#include <iostream>
void bubsort(int*, int);
void selsort(int*, int);
void insort(int*, int);

int main()
{
    int choice=0;
    int n;
    
    while(1)
    {
        printf("enter how many entries");
        scanf("%d",&n);
        int arr[n];
        for(int k=0;k<n;k++){
            scanf("%d",&arr[k]);
        }
        printf("enter choice 1 for bubble sort, 2 for selection sort, insertion sort, 4 for exit\n");
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
        else if(choice==4)
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
void bubsort(int* arr, int n)
{
    printf("checkpoint1\n");
    for (int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for (int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
void selsort(int* arr, int n)
{
    printf("checkpoint2\n");
    for (int i=0;i<n-1;i++){
        int mindex=i;
        int j=i+1;
        for(j;j<n;j++)
            if (arr[j]<arr[mindex])
            {mindex=j;}
        int temp=arr[mindex];
        arr[mindex]=arr[i];
        arr[i]=temp;
    }
    for (int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }   
}
void insort(int* arr, int n)
{
    printf("checkpoint3\n");
    for(int j=1;j<n;j++)
    {
        int key=arr[j];
        int i=j-1;
        while (i>-1 && arr[i]>key){
            arr[i+1]=arr[i];
            i=i-1;
        }
        arr[i+1]=key;
    }
    for (int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
   
}